// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataTables/SovereignSpeciesData.h"
#include "SovereignSpawnManager.generated.h"

USTRUCT(BlueprintType)
struct FSpawnRequest
{
	GENERATED_BODY()

	UPROPERTY()
	int32 RequestID;

	UPROPERTY()
	const USovereignSpeciesData* SpeciesData;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	FGuid MotherID;

	UPROPERTY()
	FGuid FatherID;

	FSpawnRequest() : RequestID(0), SpeciesData(nullptr), Transform(FTransform::Identity), MotherID(FGuid()), FatherID(FGuid()) {}

	FSpawnRequest(int32 InID, const USovereignSpeciesData* InData, const FTransform& InTransform, const FGuid& InMotherID, const FGuid& InFatherID = FGuid())
		: RequestID(InID), SpeciesData(InData), Transform(InTransform), MotherID(InMotherID), FatherID(InFatherID) {}
};

/**
 *
 */
UCLASS()
class WISPCPP7VR_API USovereignSpawnManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Spawning")
	void RequestSpawn(const USovereignSpeciesData* SpeciesData, const FTransform& Transform, const FGuid& MotherID, const FGuid& FatherID = FGuid());

private:
	UPROPERTY()
	TArray<FSpawnRequest> SpawnQueue;

	int32 NextRequestID = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Sovereign|Spawning")
	TSubclassOf<ASovereignBaseEntity> FallbackUnknownClass;

	void OnClassLoaded(int32 RequestID);
};
