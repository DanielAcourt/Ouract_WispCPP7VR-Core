//SovereignBaseEntity.ccp

#include "Entities/SovereignBaseEntity.h"
#include "DataTables/SovereignSpeciesData.h" // Essential for accessing GrowthStages
#include "SaveSystem/SovereignActorRegistry.h"
#include "SaveSystem/SovereignSpawnerUtils.h" 
#include "SaveSystem/SovereignGameData.h" 
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Components/CapsuleComponent.h" // Add this include!
#include "Components/StaticMeshComponent.h"
#include "GameplayTagsManager.h"
#include "Engine/World.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "TimerManager.h"

ASovereignBaseEntity::ASovereignBaseEntity()
{
    // 0. CHARACTER DEFAULTS
    PrimaryActorTick.bCanEverTick = true;
    //bCanAffectNavigationGeneration = true;

    /*
    // 1. CONFIGURE THE BUILT-IN CAPSULE
        // We don't use CreateDefaultSubobject here because ACharacter already did it!
    if (UCapsuleComponent* MyCapsule = GetCapsuleComponent())
    {
        MyCapsule->InitCapsuleSize(40.f, 90.f);
        MyCapsule->SetCollisionProfileName(TEXT("Pawn"));
    }
    */
    // 2. THE SOUL (SAVE SYSTEM)
    // This component handles the GUID and the metadata tags (Isla's unknown tags)
    SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

    // 3. PHYSICAL MESH
    // We create a StaticMeshComponent to visualize the 8 growth stages (Seed to Tree)
    // Create the "Master" mesh slot
    EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntityMesh"));

    // Since we are an AActor now, the Mesh is our Physical Root
    RootComponent = EntityMesh;

    // 3. Setup Default Collision for your Wisp's LineTrace
    EntityMesh->SetCollisionProfileName(TEXT("BlockAll"));

    /*
    if (RootComponent)
    {
        EntityMesh->SetupAttachment(RootComponent);
    }
    */
    // Optional: Move the mesh down so it sits at the bottom of the capsule
    //EntityMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
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

        USovereignSpawnerUtils::SpawnHybridEntity(
            GetWorld(),
            SpeciesData,
            SpawnTransform,
            this,
            PotentialPartner
        );

        // Since spawning is now async, we can't get a return value.
        // The timestamp logic should be moved to the PostSpawnInitialize function if needed.
        // For now, we will just assume success.
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

// Implementation of the IGameplayTagAssetInterface
void ASovereignBaseEntity::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
    TagContainer = GameplayTags;

    // Optional: If you want the IdentitySignature to always be included in the save
    if (IdentitySignature.IsValid())
    {
        TagContainer.AddTag(IdentitySignature);
    }
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
        EntityMesh->SetRelativeScale3D(FVector(StageScale));

        UE_LOG(LogTemp, Log, TEXT("[%s] Visuals synced to Stage %d"), *GetName(), CurrentGrowthStage);
    }
}

void ASovereignBaseEntity::PostSpawnInitialize(const USovereignSpeciesData* InSpeciesData, const FGuid& InMotherID, const FGuid& InFatherID)
{
	if (InSpeciesData)
	{
		InitializeFromSovereignData(const_cast<USovereignSpeciesData*>(InSpeciesData));
	}

	if (SaveDataComponent)
	{
		SaveDataComponent->EntityID = FGuid::NewGuid();
		SaveDataComponent->MotherID = InMotherID;
		SaveDataComponent->FatherID = InFatherID;

		if (UWorld* World = GetWorld())
		{
			if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
			{
				Registry->RegisterActor(SaveDataComponent->EntityID, this);
			}
		}

		if (InFatherID.IsValid())
		{
			// This is a hybrid, so we need to recombine DNA
			if (UWorld* World = GetWorld())
			{
				if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
				{
					AActor* Mother = Registry->FindActor(InMotherID);
					AActor* Father = Registry->FindActor(InFatherID);
					if (Mother && Father)
					{
						auto* MomComp = Mother->FindComponentByClass<USovereignSaveableEntityComponent>();
						auto* DadComp = Father->FindComponentByClass<USovereignSaveableEntityComponent>();
						if (MomComp && DadComp)
						{
							TMap<FString, FString> ChildDNA = USovereignSpawnerUtils::RecombineDNA(MomComp->GetUnknownMetaTags(), DadComp->GetUnknownMetaTags(), 0.05f);
							SaveDataComponent->ApplyMetaTags(ChildDNA);

							float CurrentTime = World->GetTimeSeconds();
							MomComp->LastMatingTimestamp = CurrentTime;
							DadComp->LastMatingTimestamp = CurrentTime;

							UE_LOG(LogTemp, Log, TEXT("Sovereign: Hybrid born between %s and %s!"), *Mother->GetName(), *Father->GetName());
						}
					}
				}
			}
		}
		else if (InMotherID.IsValid())
		{
			// This is a clone, so we need to mutate DNA
			if (UWorld* World = GetWorld())
			{
				if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
				{
					AActor* Mother = Registry->FindActor(InMotherID);
					if (Mother)
					{
						auto* MomComp = Mother->FindComponentByClass<USovereignSaveableEntityComponent>();
						if (MomComp)
						{
							TMap<FString, FString> MutatedDNA = USovereignSpawnerUtils::GenerateMutatedTags(MomComp->GetUnknownMetaTags(), 0.1f);
							SaveDataComponent->ApplyMetaTags(MutatedDNA);
						}
					}
				}
			}
		}
	}
}

void ASovereignBaseEntity::IngestSovereignTag(FString IncomingTagString)
{
    if (IncomingTagString.IsEmpty()) return;

    // Use the native FGameplayTag request - no Manager include needed!
    FGameplayTag NewTag = FGameplayTag::RequestGameplayTag(FName(*IncomingTagString), false);

    if (NewTag.IsValid())
    {
        GameplayTags.AddTag(NewTag);
        UE_LOG(LogTemp, Log, TEXT("Sovereign: Ingested Tag %s"), *IncomingTagString);
    }
}

void ASovereignBaseEntity::VerifySymmetryLevel()
{
	// Placeholder for Symmetry Kernel Check
	// This is where you would grant permissions based on the TrustSignature,
	// and attributes like Luck or Charisma.
	// For example:
	// if (TrustSignature > 1000 && GetAttributeComponent()->Luck > 50)
	// {
	//		// Grant special permission
	// }
}

/*
USovereignSaveableEntityComponent* ASovereignBaseEntity::GetSovereignSoul_Implementation() const
{
    // Simply return the component we already have!
    return SaveDataComponent;
}
*/
