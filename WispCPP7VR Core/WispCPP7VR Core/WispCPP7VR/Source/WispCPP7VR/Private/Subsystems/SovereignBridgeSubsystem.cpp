// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#include "Subsystems/SovereignBridgeSubsystem.h"
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

    LoadConfiguration();

    // Auto-initiate 07 Check-In upon world start
    Perform07CheckIn();
}

void USovereignBridgeSubsystem::Deinitialize()
{
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
