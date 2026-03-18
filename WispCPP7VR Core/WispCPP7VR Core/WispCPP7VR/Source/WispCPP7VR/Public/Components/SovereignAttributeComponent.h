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

	// --- 1. CORE ATTRIBUTES (Infinite Accumulator Logic) ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Strength; // The Prestige Level

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double StrengthExperience; // The Scientific Accumulator

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Dexterity;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double DexterityExperience; // Fixed typo and duplicate

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Constitution;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double ConstitutionExperience;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Intelligence;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double IntelligenceExperience;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Wisdom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double WisdomExperience;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Charisma;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double CharismaExperience;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 Luck;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	double LuckExperience;

	/** Derived from Dexterity and Equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Core Attributes")
	int32 ArmourClass;

	// --- 2. USABLE RESOURCES (Real-time Bars) ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Realtime Attributes")
	float CurrentHealth;

	/* Moving to Bio Bio runs here and now Attributes handles longterm
	/** Physical exhaustion. Separate from Qi (Soul Energy). */
	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Realtime Attributes")
	float CurrentStamina;
	*/
	// These act as the 'Clamps' for the bars
	float MaxHealth;
	float MaxStamina;


	// --- 3. RESISTANCES (Innate Vessel Defense) ---
	// Kept here as base values before gear modifications.


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

	/*
	// --- SURVIVAL VITALS (0.0 to 100.0) ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Hunger; // 0 = Starving, 100 = Full

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Hydration; // 0 = Dehydrated if 0 starts taking damage and slowing down Health regen
	//Health regen is qi to the tick for every update tick they get their, hunger, thirst, current health and eith A. regen health. Or if 0 begin to loose health. not just always loosing health

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Fatigue; // 100 = Exhausted (affects movement speed//attack speed etc all manner of movement)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float Tiredness; // 100 = Needs sleep (affects Qi regeneration)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Vitals")
	float StateDrain; // 0 no drain. +x gain stamina other stats etc, gain hunger over time so create a living loop = Needs sleep (affects Qi regeneration)
	*/
	// --- 4. LOGIC & DATA SYNC ---

	/** * Pulls base stats from the Owner's SaveDataComponent.
	 * Essential for ensuring Humans, Plants, and Dragons have different starting potential.
	 */

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Attributes")
	void SyncStatsFromEntity();

	/** Incremental training function for scientific growth */
	void TrainAttribute(double& TargetXP, int32& TargetLevel, double Amount, float Difficulty);

	/** Helper to get Max Health based on Constitution and Maturity */
	UFUNCTION(BlueprintPure, Category = "Sovereign|Calculations")
	float GetMaxHealth() const;

	/** Helper to get Max Stamina based on Constitution/Strength */
	/*
	UFUNCTION(BlueprintPure, Category = "Sovereign|Calculations")
	float GetMaxStamina() const;
	*/

	//Version 3.2 Version Mapping ATtributes
	// Mapping the Attribute Type to its scientific progress (Double)
	//UPROPERTY(VisibleAnywhere, Category = "Sovereign|Attributes")
	//TMap<ESovereignAttribute, double> AttributeExperience;

	// Mapping the Attribute Type to its Prestige Level (Int32)
	/* vERSION 3.2 TRYING TO MAP ENUMS
	UPROPERTY(VisibleAnywhere, Category = "Sovereign|Attributes")
	TMap<ESovereignAttribute, int32> AttributeLevels;
	*/
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
