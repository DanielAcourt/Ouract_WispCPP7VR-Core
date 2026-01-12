// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveSystem/SovereignSpawnManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "GameplayTagContainer.h"
#include "GameplayTags/Classes/GameplayTagManager.h"

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
	SpawnQueue.Add(NewRequest);

	FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
	StreamableManager.RequestAsyncLoad(SpeciesData->ActorClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USovereignSpawnManager::OnClassLoaded, RequestID));
}

void USovereignSpawnManager::OnClassLoaded(int32 RequestID)
{
	FSpawnRequest* Request = SpawnQueue.FindByPredicate([RequestID](const FSpawnRequest& Item) { return Item.RequestID == RequestID; });
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

	TSubclassOf<ASovereignBaseEntity> ClassToSpawn = FallbackUnknownClass;
	TSubclassOf<ASovereignBaseEntity> LoadedClass = SpeciesData->ActorClass.Get();

	if (LoadedClass)
	{
		const ASovereignBaseEntity* CDO = LoadedClass->GetDefaultObject<ASovereignBaseEntity>();
		if (CDO && CDO->IdentitySignature == SpeciesData->IdentitySignature)
		{
			ClassToSpawn = LoadedClass;
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

	bool bHasParentFailure = false;
	if (Request->MotherID.IsValid())
	{
		UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>();
		if (Registry && !Registry->FindActor(Request->MotherID))
		{
			bHasParentFailure = true;
		}
	}

	ASovereignBaseEntity* NewEntity = World->SpawnActor<ASovereignBaseEntity>(ClassToSpawn, Request->Transform);

	if (NewEntity)
	{
		NewEntity->PostSpawnInitialize(SpeciesData, Request->MotherID, Request->FatherID);
		if (bHasParentFailure)
		{
			FGameplayTag OrphanedTag = UGameplayTagManager::Get().RequestGameplayTag(FName("State.Malady.Orphaned"), false);
			if (OrphanedTag.IsValid())
			{
				NewEntity->GameplayTags.AddTag(OrphanedTag);
			}
		}
	}

	// Remove the request from the queue
	SpawnQueue.RemoveAll([RequestID](const FSpawnRequest& Item) { return Item.RequestID == RequestID; });
}
