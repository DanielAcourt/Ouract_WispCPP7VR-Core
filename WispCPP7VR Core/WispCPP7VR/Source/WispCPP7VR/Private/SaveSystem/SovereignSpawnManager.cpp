// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveSystem/SovereignSpawnManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

// ADD THIS INCLUDE - It fixes the "undefined type" errors
#include "Entities/SovereignBaseEntity.h"

void USovereignSpawnManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void USovereignSpawnManager::Deinitialize()
{
	Super::Deinitialize();
}

void USovereignSpawnManager::RequestSpawn(const USovereignSpeciesData* SpeciesData, const FTransform& Transform, const FGuid& MotherID, const FGuid& FatherID)
{
    if (!SpeciesData)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnManager: SpeciesData is null!"));
        return;
    }

    int32 RequestID = NextRequestID++;
    FSpawnRequest NewRequest(RequestID, SpeciesData, Transform, MotherID, FatherID);

    // PRIORITY LOGIC: Check for the Player/Isla signature
    FGameplayTag PlayerTag = UGameplayTagsManager::Get().RequestGameplayTag(FName("Identity.Player.Isla"), false);
    if (SpeciesData->IdentitySignature == PlayerTag)
    {
        // Insert at the front of the queue
        SpawnQueue.Insert(NewRequest, 0);
    }
    else
    {
        // Add to the back of the queue
        SpawnQueue.Add(NewRequest);
    }

    FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
    StreamableManager.RequestAsyncLoad(SpeciesData->ActorClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USovereignSpawnManager::OnClassLoaded, RequestID));
}

void USovereignSpawnManager::OnClassLoaded(int32 RequestID)
{
    // 1. Locate the request in the queue
    FSpawnRequest* Request = SpawnQueue.FindByPredicate([RequestID](const FSpawnRequest& Item) { return Item.RequestID == RequestID; });
    if (!Request)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnManager: OnClassLoaded called with invalid RequestID %d!"), RequestID);
        return;
    }

    const USovereignSpeciesData* SpeciesData = Request->SpeciesData;
    if (!SpeciesData)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnManager: SpeciesData is null for RequestID %d!"), RequestID);
        return;
    }

    // 2. Identify the class to spawn (With Identity Signature Check)
    TSubclassOf<ASovereignBaseEntity> ClassToSpawn = FallbackUnknownClass;
    TSubclassOf<ASovereignBaseEntity> LoadedClass = SpeciesData->ActorClass.Get();

    if (LoadedClass)
    {
        const ASovereignBaseEntity* CDO = LoadedClass->GetDefaultObject<ASovereignBaseEntity>();
        // The Bridge Check: Ensure the blueprint matches the data asset's signature
        if (CDO && CDO->IdentitySignature == SpeciesData->IdentitySignature)
        {
            ClassToSpawn = LoadedClass;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SpawnManager: Identity mismatch for %s. Using Fallback!"), *SpeciesData->SpeciesName.ToString());
        }
    }

    if (!ClassToSpawn)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnManager: No valid class or fallback found!"));
        return;
    }

    UWorld* World = GetWorld();
    if (!World) return;

    // 3. Parent Validation (Orphan Check)
    bool bHasParentFailure = false;
    if (Request->MotherID.IsValid())
    {
        UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>();
        if (Registry && !Registry->FindActor(Request->MotherID))
        {
            bHasParentFailure = true;
        }
    }

    // 4. Physical Spawning
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    ASovereignBaseEntity* NewEntity = World->SpawnActor<ASovereignBaseEntity>(ClassToSpawn, Request->Transform, SpawnParams);

    if (NewEntity)
    {
        // Hydrate the entity with its data and parentage
        NewEntity->PostSpawnInitialize(SpeciesData, Request->MotherID, Request->FatherID);

        // 5. Apply "Orphaned" status if the parent vanished during the async load
        if (bHasParentFailure)
        {
            // CORRECTED: Plural 'UGameplayTagsManager'
            FGameplayTag OrphanedTag = UGameplayTagsManager::Get().RequestGameplayTag(FName("State.Malady.Orphaned"), false);

            if (OrphanedTag.IsValid())
            {
                // Note: Ensure GameplayTags is a public FGameplayTagContainer in SovereignBaseEntity.h
                NewEntity->GameplayTags.AddTag(OrphanedTag);
            }
        }
    }

    // 6. Cleanup the queue
    SpawnQueue.RemoveAll([RequestID](const FSpawnRequest& Item) { return Item.RequestID == RequestID; });
}