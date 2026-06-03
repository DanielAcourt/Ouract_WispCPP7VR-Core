// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SaveSystem/SovereignGameData.h"
#include "Interaction/SovereignSaveInterface.h"
#include "GameplayTagContainer.h"
#include "SovereignSaveableEntityComponent.generated.h"

class ASovereignBaseEntity;
class USovereignSpeciesData;
class FJsonObject;

/**
 * USovereignSaveableEntityComponent (The Soul)
 * The central repository for an entity's identity, simulation state, and persistence.
 * As of v36.4.4, simulation logic (growth, mating, heartbeats) has been moved here
 * to support the "Component-First" architectural mandate.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USovereignSaveableEntityComponent();

    // --- 1. IDENTITY ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
    FGuid EntityID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Identity")
    FGameplayTag SpeciesTag;

    UPROPERTY(BlueprintReadOnly, Category = "Sovereign|Core")
    FDateTime BirthTimestamp;

    // --- 2. SIMULATION STATE ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Simulation")
    EUpdateFrequency UpdateFrequency = EUpdateFrequency::Standard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Simulation")
    ESovereignGrowthStage CurrentGrowthStage = ESovereignGrowthStage::Inception;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Simulation")
    int32 GrowthStageIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Simulation")
    float MaturityProgress = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Simulation")
    float MaturityRate = 0.01f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Data")
    USovereignSpeciesData* SpeciesData;

    // --- 3. BIOLOGY & LINEAGE ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    bool bIsFemale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid MotherID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid FatherID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    int32 OffspringCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    TArray<FGuid> MatingHistory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Biology")
    float LastMatingTimestamp = -100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    float MatingCooldownDuration = 60.0f;

    // --- 4. TRIPLE-AXIS GENETICS ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement AlignmentSocket = ESovereignElement::Grey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement BodySocket = ESovereignElement::Nature;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement MagicSocket = ESovereignElement::None;

    // --- 5. LOGIC & SIMULATION ---
    UFUNCTION(BlueprintCallable, Category = "Sovereign|Simulation")
    void StartHeartbeat();

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Simulation")
    void StopHeartbeat();

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Simulation")
    void ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount);

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Simulation")
    void AttemptMating(AActor* PotentialPartner);

    UFUNCTION(BlueprintPure, Category = "Sovereign|Simulation")
    bool IsReadyForMating() const;

    /** Manual initialization for non-spawned or manually placed actors */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|Core")
    void InitializeSoul();

    /** Direct initialization from Spawn Manager */
    void InitializeFromSpecies(const USovereignSpeciesData* InSpeciesData, const FGuid& InMotherID, const FGuid& InFatherID);

    // --- 6. PERSISTENCE ---
    TSharedPtr<FJsonObject> CaptureFullEntityState();
    void ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData);

    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    TMap<FString, FString> GetUnknownMetaTags() const;

    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    void ApplyMetaTags(TMap<FString, FString> LoadedTags);

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    void OnHeartbeat();
    float GetHeartbeatInterval() const;
    void CheckForEvolution();
    void RefreshVisuals();
    float GetElementalMultiplier(ESovereignElement IncomingType);

    FTimerHandle HeartbeatTimerHandle;

    UPROPERTY(VisibleAnywhere, Category = "Sovereign|SaveSystem")
    TMap<FString, FString> UnknownMetaTags;

#if WITH_EDITOR
    virtual void PostEditImport() override;
    virtual void PostDuplicate(bool bDuplicateForPIE) override;
#endif
};
