#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SaveSystem/SovereignGameData.h"
#include "Interaction/SovereignSaveInterface.h"
#include "GameplayTagContainer.h"
#include "SovereignSaveableEntityComponent.generated.h"

// Forward declarations
class ASovereignBaseEntity;
class FJsonObject;

UENUM(BlueprintType)
enum class EVesselState : uint8
{
	Alive,
	Dead,
	Dissolving
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEmergencyEject);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USovereignSaveableEntityComponent();

	TSharedPtr<FJsonObject> CaptureFullEntityState();

	/** --- 1. IDENTITY --- */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
	FGuid EntityID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core")
	FGameplayTagContainer GameplayTags;

	/** --- 2. ATTRIBUTES --- */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Attributes")
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Attributes")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Attributes")
	float Qi = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Attributes")
	float MaxQi = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Attributes")
	float Maturity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityProgress = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityRate = 0.1f;

	/** --- 3. STATE --- */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|State")
	EVesselState VesselState = EVesselState::Alive;

	/** --- 4. LIFECYCLE --- */
	UPROPERTY(BlueprintAssignable, Category = "Sovereign|Lifecycle")
	FOnEmergencyEject OnEmergencyEject;

	void HandleVesselDeath();

	/** --- 5. DYNAMIC DNA (Meta Tags) --- */

	UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
	TMap<FString, FString> GetUnknownMetaTags() const;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
	void ApplyMetaTags(TMap<FString, FString> LoadedTags);

	void ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData);

	/** --- 6. LINEAGE & BREEDING --- */
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

	/** --- 7. ELEMENTAL SYSTEM --- */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement AlignmentSocket = ESovereignElement::Grey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement BodySocket = ESovereignElement::Nature;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
    ESovereignElement MagicSocket = ESovereignElement::None;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Evolution")
    void ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
	virtual void PostEditImport() override;
	virtual void PostDuplicate(bool bDuplicateForPIE) override;
#endif

private:
	FTimerHandle HeartbeatTimerHandle;
	void Heartbeat();
	float GetElementalMultiplier(ESovereignElement IncomingType);
};
