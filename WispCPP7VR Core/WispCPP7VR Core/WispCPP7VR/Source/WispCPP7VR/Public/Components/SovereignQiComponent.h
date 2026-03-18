// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SovereignBaseComponent.h"
#include "SovereignQiComponent.generated.h"


/**
 * USovereignQiComponent
 * Handles the "Spiritual" energy of the entity.
 * Manages Qi levels, Purity (quality), and Density (experience/evolution).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignQiComponent : public USovereignBaseComponent
{
	GENERATED_BODY()
public:
	USovereignQiComponent();

	// --- 1. CORE ENERGY STATS ---

	/** Current usable Qi in the pool */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Qi")
	float CurrentQi;

	/** Maximum amount of Qi this vessel can hold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Qi")
	float MaxQiCapacity;

	/** * Qi Purity (0.0 to 1.0).
	 * Higher purity reduces the cost of spells and increases evolution speed.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Qi")
	float QiPurity;

	/** * Qi Density / Accumulated Qi.
	 * This is your "XP". When this hits a threshold, the owner Evolves.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Qi")
	float TotalQiAccumulated;


	/** Periodic check for elemental friction and density refinement */
	void SymmetryCheck(float DeltaTime);



	//qi Affinity pointing to light or dark. This needs to acts as a default affintiy
	//also which element.
	//Needs to be stored in an array with amounts for each Fire, Earth, Water, Wind, 
	//0 is there default everything by its nature will have a dfark/light and a nature.

	//Elemental Affinty
	/** The spiritual alignment. Positive = Light, Negative = Dark. 0 = Neutral/Primal. */
/** Spiritual Alignment: Positive = Light, Negative = Dark. 0 = Primal/Neutral. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Qi")
	float SpiritualAlignment = 0.0f;

	/** * Elemental Resonance.
	 * Keys: "Fire", "Earth", "Water", "Wind"
	 * Values: Resonance levels.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Qi")
	TMap<FName, float> ElementalResonance;

	/** New function to handle specific elemental absorption */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Qi")
	void AbsorbElementalQi(FName Element, float Amount, float SourcePurity);


	/** Helper to initialize the default elements */
	void InitializeElements();

	// --- 2. LOGIC FUNCTIONS ---

	/** * Adds Qi to the pool. Mixing different purities will shift the overall QiPurity.
	 * @param Amount The amount of Qi to add.
	 * @param SourcePurity The purity of the Qi being absorbed.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Qi")
	void AbsorbQi(float Amount, float SourcePurity);

	/** * Spends Qi for actions.
	 * @param Amount The raw cost. Purity will be applied to reduce this cost.
	 * @return True if the entity had enough Qi to perform the action.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Qi")
	bool SpendQi(float Amount);

	/** Resets the accumulated density (usually called after an Evolution) */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Qi")
	void ResetDensity();



protected:
	virtual void BeginPlay() override;

	/** Internal: Creates a "Residual" tag when two elements clash violently */
	void GenerateConflictTag(FName ElementA, FName ElementB);

public:
	/** * Override the ability to save the component data to the save slot or json file
	 */
	virtual TMap<FString, FString> GetSaveData() override;
	virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;


	/** * Internal tick called by the Character's Heartbeat.
 * @param DeltaTime Time since last tick.
 * @param WisdomStat The Wisdom attribute from the physical body to boost regen.
 */
	void ProcessQiFlow(float DeltaTime, int32 WisdomStat);

};

