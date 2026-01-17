// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SovereignBaseComponent.h"
#include "Interaction/SovereignSaveInterface.h"
#include "SovereignQiComponent.generated.h"


/**
 * USovereignQiComponent
 * Handles the "Spiritual" energy of the entity.
 * Manages Qi levels, Purity (quality), and Density (experience/evolution).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignQiComponent : public USovereignBaseComponent, public ISovereignSaveInterface
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

public:
	/** * Internal tick called by the Character's Heartbeat.
	 * @param DeltaTime Time since last tick.
	 * @param WisdomStat The Wisdom attribute from the physical body to boost regen.
	 */
	virtual TMap<FString, FString> GetSaveData() override;
	virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;

	void ProcessQiFlow(float DeltaTime, int32 WisdomStat);

};

