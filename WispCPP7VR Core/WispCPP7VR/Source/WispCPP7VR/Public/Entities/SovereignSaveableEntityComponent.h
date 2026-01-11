#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SaveSystem/SovereignGameData.h" // <--- ADD THIS LI
#include "Interaction/SovereignSaveInterface.h"
#include "SovereignSaveableEntityComponent.generated.h"

// Forward declaration to fix potential LNK issues with Evolve()
class ASovereignBaseEntity;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USovereignSaveableEntityComponent();

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Persistence")
    TMap<FString, FString> CaptureFullEntityState();

    /** --- 1. IDENTITY --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
    FGuid EntityID;

    /** --- 2. LINEAGE & BREEDING --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    bool bIsFemale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
    FGuid ParentID;

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

    /** --- 3. THE TRIPLE-AXIS SYSTEM (The Soul, Body, and Spark) --- */

    // Axis 1: Alignment (Light vs Dark)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement AlignmentSocket = ESovereignElement::Grey;

    // Axis 2: Physical Element (The Body - Fire, Water, Earth, Nature, Air)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement BodySocket = ESovereignElement::Nature;

    // Axis 3: Magic Essence (The Spark - Fairy, Dragon, Electric)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement MagicSocket = ESovereignElement::None;

    // Influence levels for each axis (0-100)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
    float AlignmentInfluence = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
    float BodyInfluence = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
    float MagicInfluence = 0.0f;

    /** --- 4. EVOLUTION & ENERGY --- */

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityProgress = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityRate = 0.1f;

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Evolution")
    void ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount);

    /** --- 5. DYNAMIC DNA (Meta Tags) --- */

    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    TMap<FString, FString> GetUnknownMetaTags() const;

    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    void ApplyMetaTags(TMap<FString, FString> LoadedTags);

protected:
    /** Calculates multipliers based on the 3-axis interaction */
    float GetElementalMultiplier(ESovereignElement IncomingType);

    UFUNCTION(BlueprintPure, Category = "Sovereign|Core")
    FGuid GetGUID() const { return EntityID; }

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
    virtual void PostEditImport() override;
    virtual void PostDuplicate(bool bDuplicateForPIE) override;
#endif
};