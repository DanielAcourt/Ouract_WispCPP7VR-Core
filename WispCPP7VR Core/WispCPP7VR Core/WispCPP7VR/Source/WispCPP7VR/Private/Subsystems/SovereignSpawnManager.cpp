// Fill out your copyright notice in the Description page of Project Settings.


// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.3. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

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

	TSubclassOf<AActor> ClassToSpawn = (TSubclassOf<AActor>)FallbackUnknownClass;
	TSubclassOf<AActor> LoadedClass = SpeciesData->ActorClass.Get();

	if (LoadedClass)
	{
		// Tier 1: Component-based Identity Verification [v36.4.3]
		// We check the CDO for the Sovereign Soul and verify the SpeciesTag matches.
		if (const AActor* CDO = LoadedClass->GetDefaultObject<AActor>())
		{
			if (const auto* SaveComp = CDO->FindComponentByClass<USovereignSaveableEntityComponent>())
			{
				if (SaveComp->SpeciesTag == SpeciesData->SpeciesTag || SaveComp->SpeciesTag == SpeciesData->IdentitySignature)
				{
					ClassToSpawn = LoadedClass;
				}
			}
			// Legacy Fallback: Still check the Actor's deprecated IdentitySignature
			else if (const ASovereignBaseEntity* BaseCDO = Cast<ASovereignBaseEntity>(CDO))
			{
				if (BaseCDO->IdentitySignature == SpeciesData->IdentitySignature)
				{
					ClassToSpawn = LoadedClass;
				}
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
		// 1. Core Identity Stamping [v36.4.3]
		if (auto* SaveComp = NewActor->FindComponentByClass<USovereignSaveableEntityComponent>())
		{
			SaveComp->SpeciesTag = SpeciesData->SpeciesTag;
		}

		// 2. Interface-based Initialization
		if (ASovereignBaseEntity* BaseEntity = Cast<ASovereignBaseEntity>(NewActor))
		{
			BaseEntity->PostSpawnInitialize(SpeciesData, Request->MotherID, Request->FatherID);

			if (bHasParentFailure)
			{
				FGameplayTag PenaltyTag = FGameplayTag::RequestGameplayTag(FName("State.Biological.Penalty"), false);
				if (PenaltyTag.IsValid())
				{
					BaseEntity->GameplayTags.AddTag(PenaltyTag);
				}
			}
		}
		if (ClassToSpawn == (TSubclassOf<AActor>)FallbackUnknownClass)
		{
			if (ASovereignBaseEntity* BaseEntity = Cast<ASovereignBaseEntity>(NewActor))
			{
				FGameplayTag UnknownTag = FGameplayTag::RequestGameplayTag(FName("Transient.Unknown"), false);
				if (UnknownTag.IsValid())
				{
					BaseEntity->GameplayTags.AddTag(UnknownTag);
				}
			}
		}
	}

	// Remove the request from the queue
	SpawnQueue.Remove(RequestID);
}
