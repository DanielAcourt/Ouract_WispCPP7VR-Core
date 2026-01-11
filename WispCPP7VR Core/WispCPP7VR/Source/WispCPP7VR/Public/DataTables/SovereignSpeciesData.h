// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h" // <--- CRITICAL: Fixes FGameplayTag errors
#include "SovereignSpeciesData.generated.h"

/** * The Unique Tag for this species (e.g., Species.Plant.Oak).
     * This is what the Save System looks for to know which asset to load.
     */
USTRUCT(BlueprintType)
struct FSovereignGrowthStage
{
    GENERATED_BODY()

    /** The 3D model for this specific stage */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Growth")
    TSoftObjectPtr<UStaticMesh> StageMesh;

    /** NEW: Scaling factor for this stage (1.0 = Default) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Growth")
    float VisualScale = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Security")
    int32 TrustSignature = 0;

    // PHYSICAL ATTRIBUTES (The 'Advanced' data)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float BaseStrength = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float BaseConstitution = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float BaseAgility = 5.0f;

    // How much food/water/energy this stage consumes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float MetabolicRate = 1.0f;


};

/** * USovereignSpeciesData
 * The 'Template' for an entire species.
 */
UCLASS(BlueprintType)
class WISPCPP7VR_API USovereignSpeciesData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
    FText SpeciesName;

    /** * The Unique Tag for this species (e.g., Species.Plant.Oak).
     * This is the bridge to Isla's Save System [2025-12-20].
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identity")
    FGameplayTag SpeciesTag;

    /** The 8 growth stages (or however many you need) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Evolution")
    TArray<FSovereignGrowthStage> GrowthStages;

    /** Default movement mode (Flying for Bees, Stationary for Oak) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
    bool bCanFly = false;
};
