// Copyright Wisp Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SaveSystem/SovereignGameData.h"
#include "Interaction/SovereignSaveInterface.h"
#include "SovereignSaveableEntityComponent.generated.h"

// Forward declarations
class ASovereignBaseEntity;
class FJsonObject;

/**
 * @class USovereignSaveableEntityComponent
 * @brief The central data bridge for entity persistence in the Sovereign Framework.
 *
 * This component is responsible for serializing and deserializing an entity's state to and from a JSON format.
 * It operates on a "Hierarchy of Truth" to ensure data integrity for both known, strongly-typed properties
 * and unknown, dynamic metadata. This design allows the system to save and load any entity without losing
 * data, even for properties it doesn't explicitly understand.
 *
 * The Hierarchy of Truth is processed in the following order:
 * 1.  **Tier 1: Component Data (The DNA)** - Data from other components implementing the ISovereignSaveInterface.
 *     This is considered the most specific and highest priority data (e.g., "AttributeComponent.Strength").
 * 2.  **Tier 2: Gameplay Tags (The ID Card)** - Formal, hierarchical tags (e.g., "Identity.Species.Wisp")
 *     managed by Unreal's GameplayTag system.
 * 3.  **Tier 3: Mapped Properties (The Soul)** - A small, fixed set of keys (e.g., "Alignment", "Body") that
 *     map directly to core UPROPERTYs on this component.
 * 4.  **Tier 4: Unknown Meta Tags (The Pass-Through Buffer)** - Any other key-value pair. These are stored
 *     in the owning Actor's `Tags` array (`AActor::Tags`). This component is "polite"; it does not
 *     discard metadata it doesn't recognize, ensuring a non-destructive save/load cycle.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USovereignSaveableEntityComponent();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// SECTION 1: NATIVE MANAGED PROPERTIES
	// These properties are part of the entity's core state but are managed by higher-level
	// systems or standard Unreal Engine serialization. They are not directly handled by the
	// JSON serialization functions (CaptureFullEntityState/ApplyStateFromJsonObject).
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	/** The unique identifier for this entity across all game sessions. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
	FGuid EntityID;

	/** Biological sex of the entity, used for breeding mechanics. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	bool bIsFemale;

	/** The GUID of the entity that spawned this one. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	FGuid ParentID;

	/** The GUID of the biological mother. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	FGuid MotherID;

	/** The GUID of the biological father. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	FGuid FatherID;

	/** A count of all offspring this entity has produced. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	int32 OffspringCount = 0;

	/** A record of GUIDs for all entities this one has successfully mated with. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	TArray<FGuid> MatingHistory;

	/** The timestamp of the last successful mating event. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Biology")
	float LastMatingTimestamp = -100.0f;

	/** The duration in seconds this entity must wait before mating again. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Biology")
	float MatingCooldownDuration = 60.0f;

    /** Current progress towards the next evolution stage (0.0 to 1.0). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityProgress = 0.0f;

    /** The base rate at which maturity increases. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Evolution")
    float MaturityRate = 0.1f;


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// SECTION 2: DYNAMIC JSON METADATA (THE SOUL, BODY, AND SPARK)
	// These properties are core to the entity's identity and are directly manipulated by the
	// JSON save/load process. They represent Tier 3 in the "Hierarchy of Truth".
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	/** Axis 1: The entity's spiritual alignment (Light vs. Dark). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
	ESovereignElement AlignmentSocket = ESovereignElement::Grey;

	/** Axis 2: The entity's physical elemental type. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
	ESovereignElement BodySocket = ESovereignElement::Nature;

	/** Axis 3: The entity's magical essence or affinity. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics")
	ESovereignElement MagicSocket = ESovereignElement::None;

	/** Influence level (0-100) for the Alignment axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
	float AlignmentInfluence = 100.0f;

	/** Influence level (0-100) for the Body axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
	float BodyInfluence = 100.0f;

	/** Influence level (0-100) for the Magic axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Genetics", meta = (ClampMin = "0", ClampMax = "100"))
	float MagicInfluence = 0.0f;


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// SECTION 3: CORE SERIALIZATION API
	// The primary functions for capturing and applying entity state.
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	/**
	 * @brief Captures the entire state of the owning entity into a JSON object.
	 * This function orchestrates the data gathering process based on the Hierarchy of Truth.
	 * @return A TSharedPtr to a FJsonObject containing the full entity state.
	 * @note Memory safe due to TSharedPtr, which prevents leaks during the serialization handshake.
	 */
	TSharedPtr<FJsonObject> CaptureFullEntityState();

	/**
	 * @brief Deserializes entity state from a JSON object.
	 * This is the main entry point for loading data. It unpacks the JSON into a flat map
	 * and then delegates the application of that data to other components and functions.
	 * @param JsonData A TSharedPtr to the FJsonObject containing the saved state.
	 */
	void ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData);


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// SECTION 4: UTILITY AND LEGACY FUNCTIONS
	// Helper functions for interacting with the entity's data.
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	/**
	 * @brief Scans the owning Actor's `Tags` array for any key-value pairs.
	 * This function serves as the primary mechanism for reading Tier 4 "Unknown Meta Tags".
	 * @return A map of all key-value string pairs found in the actor's tags.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
	TMap<FString, FString> GetUnknownMetaTags() const;

	/**
	 * @brief Applies a map of tags to the entity, filtering them through the Hierarchy of Truth.
	 * @param LoadedTags A map of string keys and values to apply.
	 * @note This is now the primary function for applying loaded data, handling everything from
	 * Gameplay Tags to the pass-through buffer. It is also used for DNA cloning/hybrid logic.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|SaveSystem")
	void ApplyMetaTags(TMap<FString, FString> LoadedTags);

    /**
     * @brief Processes incoming elemental energy to drive evolution and alignment shifts.
     * @param EnergyType The type of element being received.
     * @param RawAmount The amount of energy.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|Evolution")
    void ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount);

protected:
	/**
	 * @brief Calculates the elemental interaction multiplier for received energy.
	 * Implements the 5-way battle cycle and alignment duality rules.
	 * @param IncomingType The type of element to check against the entity's BodySocket.
	 * @return A float multiplier for the incoming energy.
	 */
	float GetElementalMultiplier(ESovereignElement IncomingType);

	/** Blueprint-accessible getter for the entity's unique ID. */
	UFUNCTION(BlueprintPure, Category = "Sovereign|Core")
	FGuid GetGUID() const { return EntityID; }

	// Standard ActorComponent overrides
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
	// Ensures a new GUID is generated on duplication or import to prevent ID collisions.
	virtual void PostEditImport() override;
	virtual void PostDuplicate(bool bDuplicateForPIE) override;
#endif
};