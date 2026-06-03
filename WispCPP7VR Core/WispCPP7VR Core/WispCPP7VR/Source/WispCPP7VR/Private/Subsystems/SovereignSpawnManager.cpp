// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

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

	UWorld* World = GetWorld();
	if (!World || !ClassToSpawn)
	{
		return;
	}

	AActor* NewActor = World->SpawnActor<AActor>(ClassToSpawn, Request->Transform);

	if (NewActor)
	{
		USovereignSaveableEntityComponent* Soul = NewActor->FindComponentByClass<USovereignSaveableEntityComponent>();

		// 1. Direct Soul Initialization
		if (Soul)
		{
			Soul->InitializeFromSpecies(SpeciesData, Request->MotherID, Request->FatherID);
		}

		// 2. Register in Actor Registry for Persistence
		if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
		{
			if (Soul)
			{
				Registry->RegisterActor(Soul->EntityID, NewActor);
			}
		}

		// 3. Apply penalties or transient tags if needed
		if (ASovereignBaseEntity* NewEntity = Cast<ASovereignBaseEntity>(NewActor))
		{
			// Optional future logic
		}
	}

	// Remove the request from the queue
	SpawnQueue.Remove(RequestID);
}
