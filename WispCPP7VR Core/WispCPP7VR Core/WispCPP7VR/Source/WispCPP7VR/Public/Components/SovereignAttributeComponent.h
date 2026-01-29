// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SovereignBaseComponent.h"
#include "SovereignAttributeComponent.generated.h"

/**
 * USovereignAttributeComponent
 * Handles the D&D-style physical and mental vessel stats.
 * Values are synced from the SaveDataComponent to allow dynamic species scaling.
 */


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WISPCPP7VR_API USovereignAttributeComponent : public USovereignBaseComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USovereignAttributeComponent();

	// --- 1. CORE ATTRIBUTES HOMEBREW DND with a twist (Vessel Hardware) ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Strength;// Represents the physical strength of an object

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Dexterity;

	/** Determines Max Health and physical toughness */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Constitution;

	/** Knowledge and raw spell scaling */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Intelligence;

	/** Affects Qi regeneration and application of knowledge */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Wisdom;

	/** Social interaction, barter, and NPC manipulation */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Charisma;

	/** Affects RNG rolls and minor environmental chances */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Luck; // Represents its ability to affect luckiy things in this game

	/** Derived from Dexterity and Equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 ArmourClass;

	// --- 2. USABLE RESOURCES (Real-time Bars) ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Resources")
	float CurrentHealth;

	/** Physical exhaustion. Separate from Qi (Soul Energy). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Resources")
	float CurrentStamina;


	// --- 3. RESISTANCES (Defense Layers) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Resistances")
	float PhysicalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Resistances")
	float MagicalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Resistances")
	float MentalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Resistances")
	float PoisonResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Resistances")
	float SlowResistance;

	// --- SURVIVAL VITALS (0.0 to 100.0) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Hunger; // 0 = Starving, 100 = Full

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Hydration; // 0 = Dehydrated if 0 starts taking damage and slowing down Health regen
	//Health regen is qi to the tick for every update tick they get their, hunger, thirst, current health and eith A. regen health. Or if 0 begin to loose health. not just always loosing health

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Fatigue; // 100 = Exhausted (affects movement speed)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Tiredness; // 100 = Needs sleep (affects Qi regeneration)

	// --- 4. LOGIC & DATA SYNC ---

	/** * Pulls base stats from the Owner's SaveDataComponent.
	 * Essential for ensuring Humans, Plants, and Dragons have different starting potential.
	 */
	UFUNCTION(BlueprintCallable, Category = "Sovereign|Attributes")
	void SyncStatsFromEntity();

	/** Helper to get Max Health based on Constitution and Maturity */
	UFUNCTION(BlueprintPure, Category = "Sovereign|Calculations")
	float GetMaxHealth() const;

	/** Helper to get Max Stamina based on Constitution/Strength */
	UFUNCTION(BlueprintPure, Category = "Sovereign|Calculations")
	float GetMaxStamina() const;

	// Sovereign Save Interface Overrides (triggers the saving of data on this componet really important but i though tit inherited this fromt he parent class,)
	virtual TMap<FString, FString> GetSaveData() override;
	virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
