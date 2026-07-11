// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#pragma once

#include "CoreMinimal.h"
#include "Components/SovereignBaseComponent.h"
#include "Entities/SovereignBrokerInterface.h"
#include "SovereignBioComponent.generated.h"

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
 * USovereignBioComponent: Handles metabolism, growth, and reproduction.
 * Now acts as a specialized Broker for the Sovereign Soul Hub.
 */
UCLASS(ClassGroup = (Sovereign), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignBioComponent : public USovereignBaseComponent, public ISovereignBrokerInterface
{
    GENERATED_BODY()

public:
    USovereignBioComponent();

    /** --- 1. VITALS --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    TMap<ESovereignNutrient, float> NutrientReserves;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Hunger;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Hydration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Fatigue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Tiredness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float Toxicity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Vitals")
    float WasteLevel;


    /** --- 2. GROWTH & EVOLUTION --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    int32 Mass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    double MassExperience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    int32 Density;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    double DensityExperience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    float MaturityProgress = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    float MaturityRate = 0.01f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Core")
    float Entropy;


    /** --- 3. REPRODUCTION & LINEAGE --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    bool bIsFemale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    FGuid ParentID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    FGuid MotherID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    FGuid FatherID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    int32 OffspringCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    TArray<FGuid> MatingHistory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Bio Lineage")
    float LastMatingTimestamp = -100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Bio Lineage")
    float MatingCooldownDuration = 60.0f;


    /** --- 4. ENGINE FUNCTIONS --- */
    void UpdateMetabolism(float DeltaTime);
    void HandleBiologicalTransition(float DeltaTime);

    /** ISovereignBrokerInterface Implementation */
    virtual void OnSave(TSharedPtr<FJsonObject>& OutJson) override;
    virtual void OnLoad(const TSharedPtr<FJsonObject>& InJson) override;
    virtual void OnProcessData(const TMap<FString, FString>& Data) override;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
