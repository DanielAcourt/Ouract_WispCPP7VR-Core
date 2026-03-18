// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SovereignAttributeComponent.h"
#include "Entities/SovereignBaseEntity.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "GameFramework/Actor.h"

USovereignAttributeComponent::USovereignAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Default internal values to prevent crashes before sync
	Strength = 10;
	Dexterity = 10;

	Constitution = 10;
	Intelligence = 10;

	Wisdom = 10;
	Charisma = 10;

	Luck = 10;
	ArmourClass = 10;

	CurrentHealth = 1.0f;
	
	//moved to bio component
	//CurrentStamina = 1.0f;

	//DefaultDifficalty = 1.0f
}

void USovereignAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// Automatically sync when the game starts
	SyncStatsFromEntity();

	// Start the vessel at full health/stamina based on its new stats
	CurrentHealth = GetMaxHealth();

	//CurrentStamina = GetMaxStamina();
}

void USovereignAttributeComponent::SyncStatsFromEntity()
{
	ASovereignBaseEntity* OwnerEntity = Cast<ASovereignBaseEntity>(GetOwner());
	if (!OwnerEntity) return;

	// Access the SaveDataComponent (The "Soul")
	USovereignSaveableEntityComponent* SaveComp = OwnerEntity->FindComponentByClass<USovereignSaveableEntityComponent>();

	if (SaveComp)
	{
		/** * DETERMINISTIC SCALING:
		 * Here is where you would pull from a Data Table based on SaveComp->SpeciesID.
		 * For now, we simulate the species-based logic:
		 */

		 // If we are a plant/tree, we might have high Constitution but 0 Charisma
		 // If we are Erisis, we have high Intelligence and Wisdom.

		UE_LOG(LogTemp, Log, TEXT("Sovereign: %s is syncing attributes from its Saveable Entity Component."), *GetOwner()->GetName());


		//Strength = SaveComp->GetBaseStat("Strength");
		//dev
		// etc
		
		// In a later step, we will hook these up to your Meta-Tag system!
		// Example: Strength = SaveComp->GetBaseStat("Strength");
	}
}

float USovereignAttributeComponent::GetMaxHealth() const
{
	// D&D Formula: Constitution acts as the multiplier.
	// We use 10.0f as a base, so 10 Con = 100 HP.
	return static_cast<float>(Constitution) * 10.0f;


	// Implementation of your "Version 3.0" Idea:
		// We use the floor of Constitution (the Level) plus the fractional Experience.
	//float BaseValue = 100.0f; // Every Sovereign entity starts with a 100 HP vessel
	//float GrowthScaling = 15.0f; // HP gained per point of Constitution

	//return BaseValue + (static_cast<float>(Constitution) * GrowthScaling);
}

/*
float USovereignAttributeComponent::GetMaxStamina() const
{
	// Stamina uses both Agility (Dex) and Toughness (Con)
	//float BaseValue = 50.0f;
	//return BaseValue;
	//+ (static_cast<float>(Constitution + Dexterity) * 5.0f);

	return 1;
}
*/
void USovereignAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 1. GET POSSESSION MULTIPLIER
	float PossessionBonus = 1.0f;
	ASovereignBaseEntity* OwnerEntity = Cast<ASovereignBaseEntity>(GetOwner());

	if (OwnerEntity)
	{
		// Check the Brain component we built earlier
		auto ControlComp = OwnerEntity->FindComponentByClass<USovereignControllerComponent>();
		if (ControlComp && ControlComp->bIsPlayerPossessed)
		{
			PossessionBonus = 1.5f; // 50% faster regen and slower decay while player is inside
		}
	}
}


//Moving to biocomponent
/*
	// 2. DECAY VITALS (Modified by Possession and Constitution)
	// High Constitution makes you hardy; Possession focus makes you "forget" hunger briefly
	float DecayMult = 1.0f / (PossessionBonus * (1.0f + (Constitution * 0.01f)));

	Hunger = FMath::Max(0.0f, Hunger - (0.5f * DecayMult * DeltaTime));
	Hydration = FMath::Max(0.0f, Hydration - (0.8f * DecayMult * DeltaTime));

	// Fatigue builds up faster if you are low on hydration
	float FatigueRate = (Hydration < 20.0f) ? 2.0f : 1.0f;
	Tiredness = FMath::Min(100.0f, Tiredness + (0.2f * FatigueRate * DeltaTime));

	// 3. PASSIVE REGENERATION LOGIC
	// We only regenerate if we aren't starving or dehydrated!
	bool bCanRegen = (Hunger > 10.0f && Hydration > 10.0f);

	// Wisdom is the base, Possession is the spark
	float RegenModifier = (static_cast<float>(Wisdom) * 0.05f) * PossessionBonus;

	if (bCanRegen)
	{
		// Health Regen
		if (CurrentHealth < GetMaxHealth())
		{
			CurrentHealth = FMath::Min(CurrentHealth + (RegenModifier * DeltaTime), GetMaxHealth());
		}

		// Stamina Regen (Faster than health)
		if (CurrentStamina < GetMaxStamina())
		{
			float StaminaMult = (Tiredness > 80.0f) ? 0.2f : 1.0f; // Exhaustion penalty
			CurrentStamina = FMath::Min(CurrentStamina + (RegenModifier * 2.5f * StaminaMult * DeltaTime), GetMaxStamina());
		}
	}

	// 4. APPLY CRITICAL CONSEQUENCES
	if (Hunger <= 0.0f || Hydration <= 0.0f)
	{
		// Starvation damage ignores Possession armor—it's a physical reality
		CurrentHealth -= (1.0f * DeltaTime);

		if (CurrentHealth <= 0.0f)
		{
			// Handle Death logic here or via delegate
		}
	}
}
*/


TMap<FString, FString> USovereignAttributeComponent::GetSaveData()
{
	TMap<FString, FString> Data;

	// Core Physical based Stats
	Data.Add(TEXT("STR"), FString::FromInt(Strength));
	Data.Add(TEXT("DEX"), FString::FromInt(Dexterity));
	Data.Add(TEXT("CON"), FString::FromInt(Constitution));

	//Core Magical and Ai logic level based stats
	Data.Add(TEXT("INT"), FString::FromInt(Intelligence));
	Data.Add(TEXT("WIS"), FString::FromInt(Wisdom));
	Data.Add(TEXT("CHA"), FString::FromInt(Charisma));

	//bonus stats to improve gameplay drop rate level up rolls etc
	Data.Add(TEXT("LCK"), FString::FromInt(Luck));

	//basic Armour defens// before any gear
	Data.Add(TEXT("AC"), FString::FromInt(ArmourClass));


	//Moved to bio
	/*
	// Vitals
	Data.Add(TEXT("HP"), FString::SanitizeFloat(CurrentHealth));
	Data.Add(TEXT("STM"), FString::SanitizeFloat(CurrentStamina));

	Data.Add(TEXT("HGR"), FString::SanitizeFloat(Hunger));
	Data.Add(TEXT("HYD"), FString::SanitizeFloat(Hydration));
	Data.Add(TEXT("FTG"), FString::SanitizeFloat(Fatigue));
	Data.Add(TEXT("TRD"), FString::SanitizeFloat(Tiredness));
	*/

	// Resistances
	Data.Add(TEXT("R_PHY"), FString::SanitizeFloat(PhysicalResistance));
	Data.Add(TEXT("R_MAG"), FString::SanitizeFloat(MagicalResistance));
	Data.Add(TEXT("R_MEN"), FString::SanitizeFloat(MentalResistance));

	return Data;
}

void USovereignAttributeComponent::RestoreSaveData(const TMap<FString, FString>& Data)
{
	// Local Lambda for clean extraction
	auto GetInt = [&](FString Key, int32& Target) { if (Data.Contains(Key)) Target = FCString::Atoi(*Data[Key]); };
	auto GetFlt = [&](FString Key, float& Target) { if (Data.Contains(Key)) Target = FCString::Atof(*Data[Key]); };
	

	// Use the exact strings from your JSON file
	FString P = TEXT("AttributeComponent.");

	//Core Stats
	GetInt(P + TEXT("STR"), Strength);
	GetInt(P + TEXT("DEX"), Dexterity);
	GetInt(P + TEXT("CON"), Constitution);
	GetInt(P + TEXT("INT"), Intelligence);
	GetInt(P + TEXT("WIS"), Wisdom);
	GetInt(P + TEXT("CHA"), Charisma);
	GetInt(P + TEXT("LCK"), Luck);
	GetInt(P + TEXT("AC"), ArmourClass);

	//Vitals - moving to bio component
	/*
	GetFlt(P + TEXT("HP"), CurrentHealth);
	GetFlt(P + TEXT("STM"), CurrentStamina);
	GetFlt(P + TEXT("HGR"), Hunger);
	GetFlt(P + TEXT("HYD"), Hydration);
	GetFlt(P + TEXT ("FTG"), Fatigue);
	GetFlt(P + TEXT("TRD"), Tiredness);
	*/

	//ressistances
	GetFlt(P + TEXT("PHY"), PhysicalResistance);
	GetFlt(P + TEXT("MAG"), MagicalResistance);
	GetFlt(P + TEXT("MEN"), MentalResistance);


}