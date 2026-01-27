// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/SovereignSpawnManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "GameplayTagContainer.h"
#include "Interfaces/SovereignEntityInterface.h"
#include "Entities/SovereignSaveableEntityComponent.h"

void USovereignSpawnManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("Sovereign Spawn Manager Online: PSTAS Logic Engaged"));
}

void USovereignSpawnManager::Deinitialize()
{
	Super::Deinitialize();
}

void USovereignSpawnManager::RequestSpawn(const USovereignSpeciesData* SpeciesData, const FTransform& Transform, const FGuid& ParentID)
{
	if (!SpeciesData)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnManager: SpeciesData is null!"));
		return;
	}

	int32 RequestID = NextRequestID++;
	FSpawnRequest NewRequest(RequestID, SpeciesData, Transform, ParentID);
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
		ClassToSpawn = LoadedClass;
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
		if (NewActor->Implements<USovereignEntityInterface>())
		{
			USovereignSaveableEntityComponent* Soul = ISovereignEntityInterface::Execute_GetSovereignSoul(NewActor);
			if (Soul)
			{
				Soul->ParentID = Request->MotherID;
				if (bHasParentFailure)
				{
					FGameplayTag PenaltyTag = FGameplayTag::RequestGameplayTag(FName("State.Biological.Penalty"), false);
					if (PenaltyTag.IsValid())
					{
						Soul->GameplayTags.AddTag(PenaltyTag);
					}
				}
				if (ClassToSpawn == FallbackUnknownClass)
				{
					FGameplayTag UnknownTag = FGameplayTag::RequestGameplayTag(FName("Transient.Unknown"), false);
					if (UnknownTag.IsValid())
					{
						Soul->GameplayTags.AddTag(UnknownTag);
					}
				}
			}
		}
	}

	// Remove the request from the queue
	SpawnQueue.Remove(RequestID);
}
