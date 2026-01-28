// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SaveSystem/SovereignGameData.h"  //Lets us add to the save game Data
#include "DataTables/SovereignSpeciesData.h" // Add this if it's a separate file
#include "GameplayTagContainer.h" //Lets us read Gameplay tags
#include "GameplayTagAssetInterface.h" 
#include "SovereignBaseEntity.generated.h" //Must be last

// Forward declarations to keep compile times fast
class USovereignSaveableEntityComponent;
class USovereignSpeciesData;
class UStaticMeshComponent;


//The problem with this current approach is i start by inheriting from ACharacter,
// what we reaslly need is a base which is AActor and APawn and has this interaction.
// But not the mating and more Advance options

UCLASS()
class WISPCPP7VR_API ASovereignBaseEntity : public ACharacter, public IGameplayTagAssetInterface 
{
	GENERATED_BODY()

public:
	ASovereignBaseEntity();

	/** The Unique Identity Signature for this class. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sovereign|Identity")
	FGameplayTag IdentitySignature;

	/** The Gameplay Tags for this entity. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Identity")
	FGameplayTagContainer GameplayTags;

	/** The Gameplay Tags that this Enity is checking against. */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Tags")
	void IngestSovereignTag(FString IncomingTagString);

	// --- IGameplayTagAssetInterface Implementation ---
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	// --- Lifecycle ---
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Primary logic for moving from one growth stage to the next */
	virtual void Evolve();

	/** Returns the unique Save System ID for this specific entity */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Entity")
	FGuid GetSovereignID() const;

	/** * TRIGGER MATING: Checks compatibility and spawns a child if successful.
	 * Can be called from VR Overlap events or Interaction buttons.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Gameplay")
	virtual void AttemptMating(AActor* PotentialPartner);



	/** Optional: Check if this entity is currently able to breed */
	UFUNCTION(BlueprintPure, Category = "Sovereign|Gameplay")
	bool IsReadyForMating() const;

	/** Called by the Spawn Manager after the actor has been spawned. */
	virtual void PostSpawnInitialize(const USovereignSpeciesData* InSpeciesData, const FGuid& InMotherID, const FGuid& InFatherID);

protected:
	/** Can this entity be possessed by a Sovereign Spirit? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Possession")
	bool bCanBePossessed = false;

	// --- Components ---

	/** The physical body of the entity (The Oak Tree, the Bee, etc.) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Visuals")
	UStaticMeshComponent* EntityMesh;

	/** The Soul of the Actor: Contains the GUID and Metadata tags (Isla's unknown tags) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|SaveSystem")
	USovereignSaveableEntityComponent* SaveDataComponent;

	/** Array of 8 meshes representing the growth stages (0-7) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Visuals")
	TArray<UStaticMesh*> GrowthMeshes;

	// Add the TrustSignature back here if you want to solve that C2039 error properly
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Security")
	int32 TrustSignature = 0;

	/** 1.0 is default size. 2.0 is double size. Allows for growth without new meshes. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Growth")
	float VisualScale = 1.0f;

	/** Base health/stamina multiplier for this stage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Growth")
	float BaseConstitution = 1.0f;

	// --- Data & Evolution ---

	/** Logic to update the entity based on new Species Data */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Identity")
	virtual void InitializeFromSovereignData(USovereignSpeciesData* InData);


protected:
	void VerifySymmetryLevel();

	/** The 'Passport' for this entity's species and trust level */
/** The "Advanced" data asset defining growth stages, health, and species attributes */
	// Note: class keyword here handles the forward declaration inline
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Data", meta = (AllowPrivateAccess = "true"))
	class USovereignSpeciesData* SpeciesData;

	/** Which of the 8 growth stages are we currently in? (0 to 7) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Growth")
	int32 CurrentGrowthStage = 0;

	/** How often this entity processes logic (Realtime, Standard, Slow, Dormant) */
	UPROPERTY(EditAnywhere, Category = "Sovereign|Performance")
	EUpdateFrequency UpdateFrequency = EUpdateFrequency::Standard;

	/** Swaps the Static Mesh based on the current Growth Stage index */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Visuals")
	void RefreshVisuals();

	// --- Internal Logic ---

	/** The recurring timer handle for the heartbeat logic */
	FTimerHandle HeartbeatTimerHandle;

	/** The logic function that runs growth progress and checks for Evolution */
	void OnSovereignHeartbeat();

	/** Callback function for when a mesh has been asynchronously loaded. */
	void OnMeshLoaded(TSoftObjectPtr<UStaticMesh> LoadedMeshPtr);
};
