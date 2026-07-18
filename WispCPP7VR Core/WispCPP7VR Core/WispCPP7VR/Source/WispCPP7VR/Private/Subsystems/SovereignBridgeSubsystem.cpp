// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

// // [J] Tactical Implementation of the 07 Handshake and Telemetry Pipeline. 2025-06-18

#include "Subsystems/SovereignBridgeSubsystem.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

void USovereignBridgeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Subsystem Initializing..."));
    LoadConfiguration();

    // Auto-initiate 07 Check-In upon world start
    Perform07CheckIn();
}

void USovereignBridgeSubsystem::Deinitialize()
{
    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Subsystem Deinitializing. Clearing %d registered entities."), RegisteredSovereignEntities.Num());
    RegisteredSovereignEntities.Empty();

    Super::Deinitialize();
}

void USovereignBridgeSubsystem::LoadConfiguration()
{
    FString ConfigPath = GetConfigPath();
    FString ConfigContent;

    if (FFileHelper::LoadFileToString(ConfigContent, *ConfigPath))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ConfigContent);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            if (JsonObject->HasField(TEXT("BridgeBaseUrl")))
            {
                BridgeBaseUrl = JsonObject->GetStringField(TEXT("BridgeBaseUrl"));
                UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Loaded URL %s from config."), *BridgeBaseUrl);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("SovereignBridge: bridge_config.json not found at %s. Using default: %s"), *ConfigPath, *BridgeBaseUrl);
    }
}

FString USovereignBridgeSubsystem::GetConfigPath() const
{
    return FPaths::ProjectSavedDir() / TEXT("Config/bridge_config.json");
}

void USovereignBridgeSubsystem::Perform07CheckIn()
{
    // // [J] The 07 Protocol ensures we boot up and 'check in' with the Lead's GTX 5090 before simulation starts.
    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Initiating 07 Protocol Check-In..."));

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->OnProcessRequestComplete().BindUObject(this, &USovereignBridgeSubsystem::OnCheckInResponse);
    Request->SetURL(BridgeBaseUrl / TEXT("v1/unreal/checkin"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    JsonObject->SetStringField(TEXT("client_name"), TEXT("Wisp_Simulation_Engine"));
    JsonObject->SetStringField(TEXT("version"), TEXT("36.4.7"));

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    Request->SetContentAsString(RequestBody);
    Request->ProcessRequest();
}

void USovereignBridgeSubsystem::ExecuteAASHandshake()
{
    // // [J] Requests a temporary +0.5 VSS authority boost from the bridge to dynamically clear 409 Conflict Gates.
    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Executing AAS Handshake..."));

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Req, FHttpResponsePtr Res, bool bWasSucc)
    {
        if (bWasSucc && Res.IsValid() && EHttpResponseCodes::IsOk(Res->GetResponseCode()))
        {
            bHandshakeActive = true;
            UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: AAS Handshake successful! Global Authority Boost Active."));
            FlushTelemetryQueue();
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("SovereignBridge: AAS Handshake failed."));
        }
    });

    Request->SetURL(BridgeBaseUrl + TEXT("/v1/aas/handshake"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->ProcessRequest();
}

void USovereignBridgeSubsystem::SendSimulationChat(const FString& ActorName, const FString& Message, const TArray<FSovereignChatMessage>& History)
{
    // // [J] Bridging the simulation's voice to the Lead's AI. 2025-06-18
    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Outgoing Chat from Simulation Actor [%s]."), *ActorName);

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->OnProcessRequestComplete().BindUObject(this, &USovereignBridgeSubsystem::OnChatResponse);
    Request->SetURL(BridgeBaseUrl + TEXT("/v1/unreal/chat"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    TSharedPtr<FJsonObject> JsonPayload = MakeShareable(new FJsonObject());
    JsonPayload->SetStringField(TEXT("actor_name"), ActorName);
    JsonPayload->SetStringField(TEXT("message"), Message);
    JsonPayload->SetBoolField(TEXT("enable_remote_history"), bEnableRemoteHistory);

    // Serialize History
    TArray<TSharedPtr<FJsonValue>> HistoryArray;
    for (const FSovereignChatMessage& Msg : History)
    {
        TSharedPtr<FJsonObject> MsgObj = MakeShareable(new FJsonObject());
        MsgObj->SetStringField(TEXT("role"), Msg.Role);
        MsgObj->SetStringField(TEXT("content"), Msg.Content);
        if (!Msg.Name.IsEmpty())
        {
            MsgObj->SetStringField(TEXT("name"), Msg.Name);
        }
        HistoryArray.Add(MakeShareable(new FJsonValueObject(MsgObj)));
    }
    JsonPayload->SetArrayField(TEXT("history"), HistoryArray);

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonPayload.ToSharedRef(), Writer);

    Request->SetContentAsString(RequestBody);
    Request->ProcessRequest();
}

void USovereignBridgeSubsystem::PushBlackBoxTelemetry(const FGuid& EntityID, float PSTAScore, const FString& BlackBoxJson)
{
    if (!bHandshakeActive)
    {
        UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Handshake pending. Queuing telemetry for Entity %s"), *EntityID.ToString());
        TelemetryQueue.Add({EntityID, PSTAScore, BlackBoxJson});
        return;
    }

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->OnProcessRequestComplete().BindUObject(this, &USovereignBridgeSubsystem::OnTelemetryResponse);
    Request->SetURL(BridgeBaseUrl / TEXT("v1/unreal/telemetry"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    // Parse the BlackBoxJson string back into an object to embed it in the payload
    TSharedPtr<FJsonObject> BlackBoxObj;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(BlackBoxJson);
    if (!FJsonSerializer::Deserialize(Reader, BlackBoxObj) || !BlackBoxObj.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("SovereignBridge: Failed to parse BlackBox JSON string."));
        return;
    }

    TSharedPtr<FJsonObject> JsonPayload = MakeShareable(new FJsonObject());
    JsonPayload->SetStringField(TEXT("entity_id"), EntityID.ToString());
    JsonPayload->SetNumberField(TEXT("psta_score"), PSTAScore);
    JsonPayload->SetObjectField(TEXT("blackbox_data"), BlackBoxObj);
    JsonPayload->SetStringField(TEXT("persona"), TEXT("Unreal_Simulation"));

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonPayload.ToSharedRef(), Writer);

    Request->SetContentAsString(RequestBody);
    Request->ProcessRequest();
}

void USovereignBridgeSubsystem::RegisterEntity(USovereignSaveableEntityComponent* Soul)
{
    if (Soul && !RegisteredSovereignEntities.Contains(Soul))
    {
        RegisteredSovereignEntities.Add(Soul);
        UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Registered Entity %s. Total: %d"), *Soul->EntityID.ToString(), RegisteredSovereignEntities.Num());
    }
}

void USovereignBridgeSubsystem::UnregisterEntity(USovereignSaveableEntityComponent* Soul)
{
    if (Soul)
    {
        RegisteredSovereignEntities.Remove(Soul);
        UE_LOG(LogTemp, Log, TEXT("SovereignBridge: Unregistered Entity %s. Total: %d"), *Soul->EntityID.ToString(), RegisteredSovereignEntities.Num());
    }
}

int32 USovereignBridgeSubsystem::GetRegisteredEntityCount() const
{
    return RegisteredSovereignEntities.Num();
}

void USovereignBridgeSubsystem::FlushTelemetryQueue()
{
    UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Flushing %d queued telemetry packets..."), TelemetryQueue.Num());

    for (const FPendingTelemetry& Pending : TelemetryQueue)
    {
        PushBlackBoxTelemetry(Pending.EntityID, Pending.PSTAScore, Pending.BlackBoxJson);
    }

    TelemetryQueue.Empty();
}

void USovereignBridgeSubsystem::OnCheckInResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid() && EHttpResponseCodes::IsOk(Response->GetResponseCode()))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            FString Status = JsonObject->GetStringField(TEXT("status"));

            if (Status == TEXT("200_OK"))
            {
                FString Message = JsonObject->GetStringField(TEXT("message"));
                float VSS = JsonObject->GetNumberField(TEXT("psta_vss"));

                bHandshakeActive = true;
                UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: 07 Check-In Successful! %s (VSS: %f)"), *Message, VSS);

                // Flush any telemetry queued during the handshake
                FlushTelemetryQueue();
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("SovereignBridge: Bridge returned non-OK status for Check-In: %s"), *Status);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("SovereignBridge: 07 Check-In FAILED. Bridge may be offline."));
    }
}

void USovereignBridgeSubsystem::OnTelemetryResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid() && EHttpResponseCodes::IsOk(Response->GetResponseCode()))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            FString Status = JsonObject->GetStringField(TEXT("status"));
            if (Status == TEXT("200_OK"))
            {
                UE_LOG(LogTemp, Log, TEXT("SovereignBridge: Telemetry successfully acknowledged by bridge."));
            }
            else if (Status == TEXT("409_CONFLICT_GATE"))
            {
                UE_LOG(LogTemp, Error, TEXT("SovereignBridge: Telemetry BLOCKED by AAS Conflict Gate."));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Telemetry response status: %s"), *Status);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("SovereignBridge: Telemetry push failed. Network error."));
    }
}

void USovereignBridgeSubsystem::OnChatResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid() && EHttpResponseCodes::IsOk(Response->GetResponseCode()))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            FSovereignChatResponse ChatResponse;
            ChatResponse.Content = JsonObject->GetStringField(TEXT("response"));

            // // [J] Parsing diagnostic tool logs returned from the Iron Officer Bridge. 2025-06-18
            const TArray<TSharedPtr<FJsonValue>>* ToolLogsArray;
            if (JsonObject->TryGetArrayField(TEXT("tool_logs"), ToolLogsArray))
            {
                for (auto& LogValue : *ToolLogsArray)
                {
                    TSharedPtr<FJsonObject> ToolLogObj = LogValue->AsObject();
                    if (ToolLogObj.IsValid())
                    {
                        FSovereignChatLog LogEntry;
                        FString OutputStr;
                        TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputStr);
                        FJsonSerializer::Serialize(ToolLogObj.ToSharedRef(), Writer);

                        LogEntry.ToolName = TEXT("Tool");
                        LogEntry.ResultSnippet = OutputStr.Left(200);
                        ChatResponse.ToolLogs.Add(LogEntry);
                    }
                }
            }

            // Cross-reference with tool_chain to resolve functional names
            const TArray<TSharedPtr<FJsonValue>>* ToolChainArray;
            if (JsonObject->TryGetArrayField(TEXT("tool_chain"), ToolChainArray))
            {
                for (int32 i = 0; i < ToolChainArray->Num() && i < ChatResponse.ToolLogs.Num(); ++i)
                {
                    TSharedPtr<FJsonObject> ToolObj = (*ToolChainArray)[i]->AsObject();
                    if (ToolObj.IsValid())
                    {
                        TSharedPtr<FJsonObject> FuncObj = ToolObj->GetObjectField(TEXT("function"));
                        if (FuncObj.IsValid())
                        {
                            FString ToolName = FuncObj->GetStringField(TEXT("name"));
                            ChatResponse.ToolLogs[i].ToolName = ToolName;
                            UE_LOG(LogTemp, Log, TEXT("SovereignBridge: AI Executed Tool: %s"), *ToolName);

                            if (ToolName == TEXT("possess_entity"))
                            {
                                TSharedPtr<FJsonObject> ArgsObj = FuncObj->GetObjectField(TEXT("arguments"));
                                if (ArgsObj.IsValid())
                                {
                                    FString EntityIdStr;
                                    if (ArgsObj->TryGetStringField(TEXT("entity_id"), EntityIdStr))
                                    {
                                        bool bPossess = true;
                                        ArgsObj->TryGetBoolField(TEXT("possess"), bPossess);

                                        FGuid TargetGuid;
                                        if (FGuid::Parse(EntityIdStr, TargetGuid))
                                        {
                                            UpdateAIPossessionState(TargetGuid, bPossess);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            UE_LOG(LogTemp, Warning, TEXT("SovereignBridge: Chat Response Received (%d tools executed)"), ChatResponse.ToolLogs.Num());
            OnChatResponseReceived.Broadcast(ChatResponse);
        }
    }
    else
    {
        FString ErrorDetail = Response.IsValid() ? FString::Printf(TEXT("Code: %d"), Response->GetResponseCode()) : TEXT("Network Error");
        UE_LOG(LogTemp, Error, TEXT("SovereignBridge: Simulation Chat FAILED. %s"), *ErrorDetail);
    }
}

void USovereignBridgeSubsystem::UpdateAIPossessionState(const FGuid& EntityID, bool bPossess)
{
    for (const TWeakObjectPtr<USovereignSaveableEntityComponent>& WeakSoul : RegisteredSovereignEntities)
    {
        if (USovereignSaveableEntityComponent* Soul = WeakSoul.Get())
        {
            if (Soul->EntityID == EntityID)
            {
                Soul->bIsBeingPossessed = bPossess;

                if (AActor* Owner = Soul->GetOwner())
                {
                    if (USovereignControllerComponent* ControlComp = Owner->FindComponentByClass<USovereignControllerComponent>())
                    {
                        ControlComp->bIsAIPossessed = bPossess;
                    }
                }

                OnAIPossessionStateChanged.Broadcast(EntityID, bPossess);

                if (bPossess)
                {
                    UE_LOG(LogTemp, Warning, TEXT("i now control id %s"), *EntityID.ToString());
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Released control of id %s"), *EntityID.ToString());
                }
                break;
            }
        }
    }
}

void USovereignBridgeSubsystem::RequestAIPossession(const FGuid& EntityID, bool bPossess)
{
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

    Request->OnProcessRequestComplete().BindLambda([this, EntityID, bPossess](FHttpRequestPtr Req, FHttpResponsePtr Res, bool bWasSucc)
    {
        if (bWasSucc && Res.IsValid() && EHttpResponseCodes::IsOk(Res->GetResponseCode()))
        {
            UpdateAIPossessionState(EntityID, bPossess);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("SovereignBridge: RequestAIPossession failed on the bridge."));
        }
    });

    Request->SetURL(BridgeBaseUrl + TEXT("/v1/unreal/possess"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    TSharedPtr<FJsonObject> JsonPayload = MakeShareable(new FJsonObject());
    JsonPayload->SetStringField(TEXT("entity_id"), EntityID.ToString());
    JsonPayload->SetBoolField(TEXT("possess"), bPossess);

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonPayload.ToSharedRef(), Writer);

    Request->SetContentAsString(RequestBody);
    Request->ProcessRequest();
}
