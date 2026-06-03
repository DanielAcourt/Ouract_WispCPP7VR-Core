// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseEntity.h"
#include "DataTables/SovereignSpeciesData.h"
#include "CoreModules/WispsGameModeBase.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Dom/JsonObject.h"

USovereignSaveableEntityComponent::USovereignSaveableEntityComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    EntityID = FGuid::NewGuid();
}

void USovereignSaveableEntityComponent::BeginPlay()
{
    Super::BeginPlay();
}

void USovereignSaveableEntityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    StopHeartbeat();
    Super::EndPlay(EndPlayReason);
}

void USovereignSaveableEntityComponent::InitializeSoul()
{
    if (!EntityID.IsValid())
    {
        EntityID = FGuid::NewGuid();
    }
    BirthTimestamp = FDateTime::Now();

    StartHeartbeat();
}

void USovereignSaveableEntityComponent::InitializeFromSpecies(const USovereignSpeciesData* InSpeciesData, const FGuid& InMotherID, const FGuid& InFatherID)
{
    if (!InSpeciesData) return;

    SpeciesData = const_cast<USovereignSpeciesData*>(InSpeciesData);
    SpeciesTag = InSpeciesData->SpeciesTag;
    MotherID = InMotherID;
    FatherID = InFatherID;

    InitializeSoul();
    RefreshVisuals();
}

void USovereignSaveableEntityComponent::StartHeartbeat()
{
    if (UpdateFrequency == EUpdateFrequency::Dormant) return;

    GetWorld()->GetTimerManager().SetTimer(HeartbeatTimerHandle, this, &USovereignSaveableEntityComponent::OnHeartbeat, GetHeartbeatInterval(), true);
}

void USovereignSaveableEntityComponent::StopHeartbeat()
{
    GetWorld()->GetTimerManager().ClearTimer(HeartbeatTimerHandle);
}

void USovereignSaveableEntityComponent::OnHeartbeat()
{
    if (!SpeciesData) return;

    MaturityProgress += MaturityRate;
    CheckForEvolution();
}

float USovereignSaveableEntityComponent::GetHeartbeatInterval() const
{
    switch (UpdateFrequency)
    {
        case EUpdateFrequency::Faster:   return 0.016f;
        case EUpdateFrequency::Realtime: return 0.1f;
        case EUpdateFrequency::Standard: return 1.0f;
        case EUpdateFrequency::Slow:     return 10.0f;
        case EUpdateFrequency::Slower:   return 30.0f;
        case EUpdateFrequency::Slowest:  return 60.0f;
        case EUpdateFrequency::Glacier:  return 360.0f;
        default:                         return 1.0f;
    }
}

void USovereignSaveableEntityComponent::CheckForEvolution()
{
    if (MaturityProgress >= 1.0f)
    {
        MaturityProgress = 0.0f;
        GrowthStageIndex++;

        if (SpeciesData && GrowthStageIndex < SpeciesData->GrowthStages.Num())
        {
            RefreshVisuals();
        }

        if (AActor* Owner = GetOwner())
        {
            if (ASovereignBaseEntity* Entity = Cast<ASovereignBaseEntity>(Owner))
            {
                Entity->Evolve();
            }
        }
    }
}

void USovereignSaveableEntityComponent::RefreshVisuals()
{
    if (!SpeciesData || !SpeciesData->GrowthStages.IsValidIndex(GrowthStageIndex)) return;

    AActor* Owner = GetOwner();
    if (!Owner) return;

    UStaticMeshComponent* MeshComp = Owner->FindComponentByClass<UStaticMeshComponent>();
    if (MeshComp)
    {
        TSoftObjectPtr<UStaticMesh> StageMesh = SpeciesData->GrowthStages[GrowthStageIndex].StageMesh;
        if (UStaticMesh* LoadedMesh = StageMesh.LoadSynchronous())
        {
            MeshComp->SetStaticMesh(LoadedMesh);
            float Scale = SpeciesData->GrowthStages[GrowthStageIndex].VisualScale;
            Owner->SetActorScale3D(FVector(Scale));
        }
    }
}

void USovereignSaveableEntityComponent::ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount)
{
    float Modifier = GetElementalMultiplier(EnergyType);
    MaturityProgress += (RawAmount * Modifier);
    CheckForEvolution();
}

float USovereignSaveableEntityComponent::GetElementalMultiplier(ESovereignElement IncomingType)
{
    return 1.0f;
}

void USovereignSaveableEntityComponent::AttemptMating(AActor* PotentialPartner)
{
    if (!IsReadyForMating() || !PotentialPartner) return;

    USovereignSaveableEntityComponent* OtherSoul = PotentialPartner->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (OtherSoul && OtherSoul->IsReadyForMating())
    {
        UE_LOG(LogTemp, Log, TEXT("Sovereign: Mating successful between %s and %s"), *GetOwner()->GetName(), *PotentialPartner->GetName());
    }
}

bool USovereignSaveableEntityComponent::IsReadyForMating() const
{
    return (int32)CurrentGrowthStage >= (int32)ESovereignGrowthStage::Adult;
}

TMap<FString, FString> USovereignSaveableEntityComponent::GetUnknownMetaTags() const
{
    TMap<FString, FString> FoundTags;
    if (AActor* Owner = GetOwner())
    {
        for (const FName& TagName : Owner->Tags)
        {
            FString TagString = TagName.ToString();
            FString Key, Value;
            if (TagString.Split(TEXT(":"), &Key, &Value, ESearchCase::CaseSensitive, ESearchDir::FromStart))
            {
                FoundTags.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
            }
            else
            {
                FoundTags.Add(TagString.TrimStartAndEnd(), TEXT("True"));
            }
        }
    }
    return FoundTags;
}

void USovereignSaveableEntityComponent::ApplyMetaTags(TMap<FString, FString> LoadedTags)
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    for (int32 i = Owner->Tags.Num() - 1; i >= 0; --i)
    {
        if (Owner->Tags[i].ToString().Contains(TEXT(":")))
        {
            Owner->Tags.RemoveAt(i);
        }
    }

    for (auto& Elem : LoadedTags)
    {
        if (Elem.Value.Equals(TEXT("True"), ESearchCase::IgnoreCase))
        {
            Owner->Tags.Add(FName(*Elem.Key));
        }
        else
        {
            FString ReconstructedTag = FString::Printf(TEXT("%s:%s"), *Elem.Key, *Elem.Value);
            Owner->Tags.Add(FName(*ReconstructedTag));
        }
    }
}

TSharedPtr<FJsonObject> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    AActor* Owner = GetOwner();
    if (!Owner) return JsonObject;

    // 1. Identity & Tags
    JsonObject->SetStringField(TEXT("EntityID"), EntityID.ToString());
    JsonObject->SetStringField(TEXT("SpeciesTag"), SpeciesTag.ToString());
    JsonObject->SetNumberField(TEXT("GrowthStageIndex"), GrowthStageIndex);
    JsonObject->SetNumberField(TEXT("MaturityProgress"), MaturityProgress);

    TMap<FString, FString> LegacyTags = GetUnknownMetaTags();
    for (const auto& Elem : LegacyTags)
    {
        JsonObject->SetStringField(Elem.Key, Elem.Value);
    }

    // 2. Physical & Component Scrape
    if (ISovereignSaveInterface* ActorInterface = Cast<ISovereignSaveInterface>(Owner))
    {
        TMap<FString, FString> ActorData = ActorInterface->GetSaveData();
        for (const auto& Elem : ActorData) JsonObject->SetStringField(Elem.Key, Elem.Value);
    }

    TArray<UActorComponent*> InterfaceComps;
    Owner->GetComponents(InterfaceComps);
    for (UActorComponent* Comp : InterfaceComps)
    {
        if (Comp == this) continue;
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
        {
            TMap<FString, FString> ComponentData = SaveInterface->GetSaveData();
            FString ComponentName = Comp->GetName();
            for (const auto& Elem : ComponentData)
            {
                FString PrefixedKey = FString::Printf(TEXT("%s.%s"), *ComponentName, *Elem.Key);
                JsonObject->SetStringField(PrefixedKey, Elem.Value);
            }
        }
    }

    return JsonObject;
}

void USovereignSaveableEntityComponent::ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData)
{
    if (!JsonData.IsValid()) return;
    AActor* Owner = GetOwner();
    if (!Owner) return;

    TMap<FString, FString> AllData;
    for (const auto& Elem : JsonData->Values)
    {
        if (Elem.Value.IsValid() && Elem.Value->Type == EJson::String)
        {
            AllData.Add(Elem.Key, Elem.Value->AsString());
        }
    }

    if (JsonData->HasField(TEXT("EntityID"))) FGuid::Parse(JsonData->GetStringField(TEXT("EntityID")), EntityID);
    if (JsonData->HasField(TEXT("SpeciesTag"))) SpeciesTag = FGameplayTag::RequestGameplayTag(FName(*JsonData->GetStringField(TEXT("SpeciesTag"))));
    if (JsonData->HasField(TEXT("GrowthStageIndex"))) GrowthStageIndex = JsonData->GetIntegerField(TEXT("GrowthStageIndex"));
    if (JsonData->HasField(TEXT("MaturityProgress"))) MaturityProgress = JsonData->GetNumberField(TEXT("MaturityProgress"));

    ApplyMetaTags(AllData);

    if (ISovereignSaveInterface* ActorInterface = Cast<ISovereignSaveInterface>(Owner))
    {
        ActorInterface->RestoreSaveData(AllData);
    }

    TArray<UActorComponent*> InterfaceComps;
    Owner->GetComponents(InterfaceComps);
    for (UActorComponent* Comp : InterfaceComps)
    {
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
        {
            SaveInterface->RestoreSaveData(AllData);
        }
    }

    RefreshVisuals();
}

#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport() { Super::PostEditImport(); EntityID = FGuid::NewGuid(); }
void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
    Super::PostDuplicate(bDuplicateForPIE);
    if (!bDuplicateForPIE) { EntityID = FGuid::NewGuid(); }
}
#endif
