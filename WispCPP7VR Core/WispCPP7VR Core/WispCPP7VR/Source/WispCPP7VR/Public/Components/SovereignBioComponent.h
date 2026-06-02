// Fill out your copyright notice in the Description page of Project Settings.

// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.3. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "Components/SovereignBaseComponent.h"
#include "SovereignBioComponent.generated.h"

// --- GLOBAL SCOPE: Defined for engine-wide visibility ---
UENUM(BlueprintType)
enum class ESovereignNutrient : uint8
{
    Carbs       UMETA(DisplayName = "Carbohydrates"),
    Proteins    UMETA(DisplayName = "Proteins"),
    Fats        UMETA(DisplayName = "Fats"),
    Minerals    UMETA(DisplayName = "Minerals"),
    QiEssence   UMETA(DisplayName = "Qi Essence"),
    MAX         UMETA(Hidden)
};

/**
 * The Biological Engine of the Sovereign Soul.
 * Handles metabolism, growth (Mass/Density), and survival vitals.
 */
UCLASS(ClassGroup = (Sovereign), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignBioComponent : public USovereignBaseComponent
{
    GENERATED_BODY()

public:
    USovereignBioComponent();

    //Timestamp of creation


    // --- NUTRITION SYSTEM ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    TMap<ESovereignNutrient, float> NutrientReserves;

    // --- BIOLOGICAL ATTRIBUTES (The Growth Loop) ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    int32 Mass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    double MassExperience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    int32 Density;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    double DensityExperience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    int32 CurrentStaminaRegen;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    double CurrentStaminaRegenExperience;

    // --- SURVIVAL VITALS (0.0 to 100.0) ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Hunger; //Take Nutrients from soil, Animals or plants. It consumes dead or dying mass basically.

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Hydration; // Takes liquids not just water

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Fatigue; //Physical drain higher levels means more wearin, idling brings this to 0

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Tiredness; // sleeping reduces this

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Toxicity; // Damge over time
    //Needs  a way to wear down the posien over time with healing, rest anitdotes. Version 3.5

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float WasteLevel; // Reduces this by pooing or peeing. Can be magical and boost fetility of plants and soil, Posiibly even work in a way to fossil carbon to make diamonds

    // --- METABOLIC MODIFIERS ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float StateDrain; // 0 = Idle, >0 = Action-based burn

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float TemperatureShift; // -1 (Freezing) to 1 (Burning)

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Nature Cycle")
    float Entropy; // Biological age

    /** --- 1. LINEAGE & BREEDING --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    bool bIsFemale;

    //Base idea , Important acts as a seed root to a class
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid ParentID;

    //Optional if we want to store its mother code compared to its fathers so we can do pokemon like upgrading/breeding
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid MotherID;

    //Core now, We can combine the 2 stats in the near future when maing a baby
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid FatherID;

    // Can be useful as if they hit a limit they can break if item or just store a known log for Parents
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    int32 OffspringCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    TArray<FGuid> MatingHistory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Biology")
    float LastMatingTimestamp = -100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    float MatingCooldownDuration = 60.0f;

    // --- ENGINE FUNCTIONS ---
    void UpdateMetabolism(float DeltaTime);

    void HandleBiologicalTransition(float DeltaTime);

    float GetDecompositionYield() const;

    // --- SAVE SYSTEM INTERFACE ---
    virtual TMap<FString, FString> GetSaveData() override;
    virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};