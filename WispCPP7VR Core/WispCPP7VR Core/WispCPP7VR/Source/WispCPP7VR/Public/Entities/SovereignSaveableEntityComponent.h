#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SaveSystem/SovereignGameData.h" // <--- ADD THIS LI

#include "Interaction/SovereignSaveInterface.h"

#include "SovereignSaveableEntityComponent.generated.h"

// Forward declarations
class ASovereignBaseEntity;
class FJsonObject;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USovereignSaveableEntityComponent();

    TSharedPtr<FJsonObject> CaptureFullEntityState();

    /** The Central Hub initialization */
    void InitializeSoul();

    /** --- 1. IDENTITY --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
    FGuid EntityID;

    /** The exact moment this Soul was manifested in the world */
    UPROPERTY(BlueprintReadOnly, Category = "Sovereign|Core")
    FDateTime BirthTimestamp;

    /** ANCESTRAL OVERRIDE: Use a custom date instead of the current time? */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Identity")
    bool bUseManualBirthDate = false;

    /** Custom Date. Format: "2017.03.23-16.00.00" */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Identity", meta = (EditCondition = "bUseManualBirthDate"))
    FString ManualBirthDateStr = "2017.03.23-16.00.00";

    /*Add these constants to your logic for a balanced simulation:Sovereign Hour: 1 Real Minute Sovereign Day: 24 Real Minutes Sovereign Week: 2.8 Real Hours Sovereign Month: 11.2 Real Hours Sovereign Year: 5.6 Real Days */

    /** --- 2. LINEAGE & BREEDING --- */
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
    //Ideally we need this maturity progress and current state to determine an object age deterministically
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityProgress = 0.0f;

    //How quickly it ages based on a tick
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityRate = 0.01f;

    UFUNCTION(BlueprintCallable, Category = "Sovereign|Evolution")
    void ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount);

    /** --- 5. DYNAMIC DNA (Meta Tags) --- */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    TMap<FString, FString> GetUnknownMetaTags() const;

    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    void ApplyMetaTags(TMap<FString, FString> LoadedTags);

    //Not sure if worth making a blueprint callable fucntions
    //UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    void ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData);

    //Version 3.0 Added
    void TrainAttribute(float& Attribute, float GainAmount, float ClassDifficulty);


    //Version 3.3 Added
    /** The Hub's way of handling data it doesn't recognize yet (Isla's unknown tags) */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
    void AddUnknownTag(FString Key, FString Value) { UnknownMetaTags.Add(Key, Value); }
protected:
    /** Calculates multipliers based on the 3-axis interaction */
    float GetElementalMultiplier(ESovereignElement IncomingType);

    /** The storage for all manifested truths and elemental residuals */
    UPROPERTY(VisibleAnywhere, Category = "Sovereign|SaveSystem")
    TMap<FString, FString> UnknownMetaTags;

    UFUNCTION(BlueprintPure, Category = "Sovereign|Core")
    FGuid GetGUID() const { return EntityID; }

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
    virtual void PostEditImport() override;
    virtual void PostDuplicate(bool bDuplicateForPIE) override;
#endif
};