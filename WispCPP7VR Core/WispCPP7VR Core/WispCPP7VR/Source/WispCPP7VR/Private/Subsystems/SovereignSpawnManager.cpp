// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/SovereignSpawnManager.h"
#include "Entities/SovereignBaseEntity.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "GameplayTagContainer.h"

void USovereignSpawnManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("Sovereign Spawn Manager Online: PSTAS Logic Engaged"));
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
	SpawnQueue.Add(RequestID, NewRequest);

	FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
	StreamableManager.RequestAsyncLoad(SpeciesData->ActorClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USovereignSpawnManager::OnClassLoaded, RequestID));
}

void USovereignSpawnManager::OnClassLoaded(int32 RequestID)
{
	FSpawnRequest* Request = SpawnQueue.Find(RequestID);
	if (!Request)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnManager: OnClassLoaded called with invalid RequestID!"));
		return;
	}

	const USovereignSpeciesData* SpeciesData = Request->SpeciesData;
	if (!SpeciesData)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnManager: OnClassLoaded called with null SpeciesData!"));
		return;
	}

	TSubclassOf<AActor> ClassToSpawn = FallbackUnknownClass;
	TSubclassOf<AActor> LoadedClass = SpeciesData->ActorClass.Get();

	if (LoadedClass)
	{
		const AActor* CDO = LoadedClass->GetDefaultObject<AActor>();
		if (CDO)
		{
			// RELAXED VALIDATION [v36.4.4]:
			// We only verify that the class HAS a "Soul" (SaveDataComponent).
			// We no longer require the CDO's tag to match the Data Asset.
			// This allows one generic Blueprint vessel to be used for multiple Species.
			if (CDO->FindComponentByClass<USovereignSaveableEntityComponent>())
			{
				ClassToSpawn = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("SpawnManager: Class %s has no SaveableEntityComponent!"), *LoadedClass->GetName());
			}
		}
	}

	if (!ClassToSpawn)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnManager: ClassToSpawn is null and no fallback is set!"));
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// "Drone-Laying Penalty" (Ontological Parent Check)
	// If the parent ID is valid but the parent actor is not found in the registry,
	// it is considered an ontological failure (e.g. the parent has died or been culled).
	bool bHasParentFailure = false;
	if (Request->MotherID.IsValid())
	{
		UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>();
		if (Registry && !Registry->FindActor(Request->MotherID))
		{
			bHasParentFailure = true;
		}
	}

	AActor* NewActor = World->SpawnActor<AActor>(ClassToSpawn, Request->Transform);

	if (NewActor)
	{
		// 1. Initialize the entity if it supports the Sovereign system
		if (ASovereignBaseEntity* NewEntity = Cast<ASovereignBaseEntity>(NewActor))
		{
			NewEntity->PostSpawnInitialize(SpeciesData, Request->MotherID, Request->FatherID);
		}
		else if (USovereignSaveableEntityComponent* Soul = NewActor->FindComponentByClass<USovereignSaveableEntityComponent>())
		{
			// For generic actors carrying the Soul component, we still perform basic initialization
			Soul->SpeciesTag = SpeciesData->SpeciesTag;
			Soul->EntityID = FGuid::NewGuid();
			Soul->MotherID = Request->MotherID;
			Soul->FatherID = Request->FatherID;
		}

		// 2. Apply penalties if applicable
		if (bHasParentFailure)
		{
			FGameplayTag PenaltyTag = FGameplayTag::RequestGameplayTag(FName("State.Biological.Penalty"), false);
			if (PenaltyTag.IsValid())
			{
				if (ASovereignBaseEntity* NewEntity = Cast<ASovereignBaseEntity>(NewActor))
				{
					NewEntity->GameplayTags.AddTag(PenaltyTag);
				}
			}
		}

		// 3. Flag unknown fallback entities
		if (ClassToSpawn == FallbackUnknownClass)
		{
			FGameplayTag UnknownTag = FGameplayTag::RequestGameplayTag(FName("Transient.Unknown"), false);
			if (UnknownTag.IsValid())
			{
				if (ASovereignBaseEntity* NewEntity = Cast<ASovereignBaseEntity>(NewActor))
				{
					NewEntity->GameplayTags.AddTag(UnknownTag);
				}
			}
		}
	}

	// Remove the request from the queue
	SpawnQueue.Remove(RequestID);
}
