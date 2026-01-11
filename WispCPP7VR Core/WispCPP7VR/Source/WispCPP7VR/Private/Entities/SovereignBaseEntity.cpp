// Fill out your copyright notice in the Description page of Project Settings.
#include "Entities/SovereignBaseEntity.h"
#include "DataTables/SovereignSpeciesData.h" // Essential for accessing GrowthStages
#include "SaveSystem/SovereignActorRegistry.h"
#include "SaveSystem/SovereignSpawnerUtils.h" 
#include "SaveSystem/SovereignGameData.h" 
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "TimerManager.h"

ASovereignBaseEntity::ASovereignBaseEntity()
{
    // 1. CHARACTER DEFAULTS
    PrimaryActorTick.bCanEverTick = true;
    bCanAffectNavigationGeneration = true;

    // 2. THE SOUL (SAVE SYSTEM)
    // This component handles the GUID and the metadata tags (Isla's unknown tags)
    SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

    // 3. PHYSICAL MESH
    // We create a StaticMeshComponent to visualize the 8 growth stages (Seed to Tree)
    EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntityMesh"));
    EntityMesh->SetupAttachment(RootComponent);
}

void ASovereignBaseEntity::BeginPlay()
{
    Super::BeginPlay();

    // Determine Heartbeat timing based on performance settings
    float Interval = 0.0f;
    switch (UpdateFrequency)
    {
    case EUpdateFrequency::Realtime: Interval = 0.0f; break;
    case EUpdateFrequency::Standard: Interval = 1.0f; break;
    case EUpdateFrequency::Slow:     Interval = 10.0f; break;
    case EUpdateFrequency::Dormant:  Interval = -1.0f; break;
    }

    if (Interval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(HeartbeatTimerHandle, this, &ASovereignBaseEntity::OnSovereignHeartbeat, Interval, true);
    }

    // Disable standard Tick if we are using a Heartbeat to save CPU (Crucial for VR performance)
    SetActorTickEnabled(UpdateFrequency == EUpdateFrequency::Realtime);

    // Initial visual setup
    RefreshVisuals();
}

void ASovereignBaseEntity::OnSovereignHeartbeat()
{
    if (SaveDataComponent)
    {
        // Increment Maturity (This is how the Oak Seed eventually becomes a Sprout)
        SaveDataComponent->MaturityProgress += (SaveDataComponent->MaturityRate);

        // Check for Evolution (Threshold met, move to next growth stage)
        if (SaveDataComponent->MaturityProgress >= 1.0f)
        {
            // Reset progress for the next stage (or keep remainder for overflow)
            SaveDataComponent->MaturityProgress = 0.0f;
            Evolve();
        }
    }
}

void ASovereignBaseEntity::Evolve()
{
    // Ensure we have a Data Asset and haven't hit the end of the 8 stages
    if (SpeciesData && CurrentGrowthStage < (SpeciesData->GrowthStages.Num() - 1))
    {
        CurrentGrowthStage++;
        RefreshVisuals();

        UE_LOG(LogTemp, Log, TEXT("Sovereign: %s evolved to stage %d"), *GetName(), CurrentGrowthStage);
    }
}

void ASovereignBaseEntity::AttemptMating(AActor* PotentialPartner)
{
    if (!PotentialPartner) return;

    ASovereignBaseEntity* PartnerActor = Cast<ASovereignBaseEntity>(PotentialPartner);

    // Logic: Ready, Compatible, and SpawnerUtils confirms the "Handshake"
    if (IsReadyForMating() && PartnerActor && PartnerActor->IsReadyForMating() &&
        USovereignSpawnerUtils::CanBreed(this, PotentialPartner))
    {
        FVector MidPoint = (GetActorLocation() + PotentialPartner->GetActorLocation()) / 2.0f;
        FTransform SpawnTransform(GetActorRotation(), MidPoint);

        AActor* Child = USovereignSpawnerUtils::SpawnHybridEntity(
            GetWorld(),
            this->GetClass(),
            SpawnTransform,
            this,
            PotentialPartner
        );

        if (Child)
        {
            float CurrentTime = GetWorld()->GetTimeSeconds();
            this->SaveDataComponent->LastMatingTimestamp = CurrentTime;
            PartnerActor->SaveDataComponent->LastMatingTimestamp = CurrentTime;

            UE_LOG(LogTemp, Log, TEXT("Sovereign: Hybrid born between %s and %s!"), *GetName(), *PotentialPartner->GetName());
        }
    }
}

bool ASovereignBaseEntity::IsReadyForMating() const
{
    if (!SaveDataComponent || !GetWorld()) return false;

    float CurrentTime = GetWorld()->GetTimeSeconds();
    float TimeSinceLastMating = CurrentTime - SaveDataComponent->LastMatingTimestamp;

    return TimeSinceLastMating >= SaveDataComponent->MatingCooldownDuration;
}

FGuid ASovereignBaseEntity::GetSovereignID() const
{
    return SaveDataComponent ? SaveDataComponent->EntityID : FGuid();
}

void ASovereignBaseEntity::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASovereignBaseEntity::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>();
        if (Registry && SaveDataComponent)
        {
            Registry->UnregisterActor(SaveDataComponent->EntityID);
        }
    }
    Super::EndPlay(EndPlayReason);
}



void ASovereignBaseEntity::InitializeFromSovereignData(USovereignSpeciesData* InData)
{
    // 1. Safety Check: Stop the crash if data is missing
    if (!InData)
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s] InitializeFromSovereignData: No Data Asset provided."), *GetName());
        return;
    }

    // 2. Assign the Pointer
    SpeciesData = InData;

    // 3. Update Visuals
    // This ensures the Mesh matches the Data Asset right away
    RefreshVisuals();

    // 4. Log Success (Simplified)
    UE_LOG(LogTemp, Log, TEXT("[%s] Sovereign Entity Initialized successfully."), *GetName());
}


void ASovereignBaseEntity::RefreshVisuals()
{
    // 1. Fast Exit: Basic safety checks
    if (!EntityMesh || !SpeciesData) return;

    // 2. Index Validation
    if (!SpeciesData->GrowthStages.IsValidIndex(CurrentGrowthStage))
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s] Invalid Growth Stage: %d"), *GetName(), CurrentGrowthStage);
        return;
    }

    // 3. Get the Soft Pointer to the mesh
    TSoftObjectPtr<UStaticMesh> NewMeshPtr = SpeciesData->GrowthStages[CurrentGrowthStage].StageMesh;

    // 4. Optimization: Check if the mesh is already loaded and set
    // This prevents redundant logic if Evolve() is called multiple times
    if (NewMeshPtr.Get() == EntityMesh->GetStaticMesh() && !NewMeshPtr.IsNull())
    {
        return;
    }

    // 5. The "Sovereign" Load Strategy: Asynchronous Loading
    if (NewMeshPtr.IsPending())
    {
        FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
        StreamableManager.RequestAsyncLoad(NewMeshPtr.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ASovereignBaseEntity::OnMeshLoaded, NewMeshPtr));
    }
    else
    {
        // Mesh is already loaded, so just apply it.
        OnMeshLoaded(NewMeshPtr);
    }
}

void ASovereignBaseEntity::OnMeshLoaded(TSoftObjectPtr<UStaticMesh> LoadedMeshPtr)
{
    if (LoadedMeshPtr.IsValid())
    {
        EntityMesh->SetStaticMesh(LoadedMeshPtr.Get());

        // 6. Scale/Physical Logic (The "Symmetry" adjustment)
        // Adjust the scale based on the growth stage defined in the data asset
        float StageScale = SpeciesData->GrowthStages[CurrentGrowthStage].VisualScale;
        EntityMesh->SetWorldScale3D(FVector(StageScale));

        UE_LOG(LogTemp, Log, TEXT("[%s] Visuals synced to Stage %d"), *GetName(), CurrentGrowthStage);
    }
}