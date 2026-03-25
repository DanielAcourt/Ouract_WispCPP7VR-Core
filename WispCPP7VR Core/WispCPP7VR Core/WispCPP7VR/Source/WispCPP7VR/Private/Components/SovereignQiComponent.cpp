// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SovereignQiComponent.h"
#include "Entities/SovereignBaseEntity.h"
#include "Entities/SovereignSaveableEntityComponent.h"

//#include "Components/Sover"

#include "Kismet/KismetMathLibrary.h"

USovereignQiComponent::USovereignQiComponent()
{
	PrimaryComponentTick.bCanEverTick = false; // Driven by the BaseEntity Heartbeat/Tick

	// Default starting values
	CurrentQi = 0.0f;
	MaxQiCapacity = 100.0f;
	QiPurity = 0.1f; // Raw, unrefined Qi
	TotalQiAccumulated = 0.0f;
}

void USovereignQiComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USovereignQiComponent::AbsorbQi(float Amount, float SourcePurity)
{
	if (Amount <= 0.0f) return;

	// 1. BLEND PURITY
	// We use a weighted average: (Current Energy * Current Purity + New Energy * New Purity) / Total Energy
	float NewTotalQi = CurrentQi + Amount;

	// Ensure we don't divide by zero if starting from absolute empty
	if (NewTotalQi > 0.0f)
	{
		QiPurity = ((CurrentQi * QiPurity) + (Amount * SourcePurity)) / NewTotalQi;
	}

	// 2. UPDATE POOLS
	CurrentQi = FMath::Min(NewTotalQi, MaxQiCapacity);

	// Total accumulated is the "XP" that pushes the entity toward Evolution
	TotalQiAccumulated += Amount;

	// 3. CHECK FOR EVOLUTION
	/*
	ASovereignBaseEntity* Owner = Cast<ASovereignBaseEntity>(GetOwner());
	if (Owner)
	{
		// In a real system, the threshold would come from a data table. 
		// For testing: 1000 Qi triggers the next stage.
		if (TotalQiAccumulated >= 1000.0f)
		{
			Owner->Evolve();
		}
	}
	*/
}

bool USovereignQiComponent::SpendQi(float Amount)
{
	// EFFICIENCY CALCULATION:
	// If Purity is 1.0 (Pure), cost is standard. 
	// If Purity is 0.1 (Raw), cost is nearly double.
	float PurityEfficiency = 2.0f - QiPurity;
	float AdjustedCost = Amount * PurityEfficiency;

	if (CurrentQi >= AdjustedCost)
	{
		CurrentQi -= AdjustedCost;
		return true;
	}

	return false; // Not enough Qi
}

void USovereignQiComponent::ProcessQiFlow(float DeltaTime, int32 WisdomStat)
{
	// 1. ANCESTRAL REFINEMENT
	// Souls older than 100 Sovereign Years get a "Passive Refinement" bonus.
	// Their purity slowly creeps up toward 1.0 just by existing.
	if (QiPurity < 1.0f)
	{
		float RefinementRate = 0.00001f; // Incredibly slow, rewarding years of life
		QiPurity += RefinementRate * DeltaTime;
	}

	// 2. PASSIVE REGENERATION
	float RegenRate = (static_cast<float>(WisdomStat) * 0.1f) * QiPurity;
	if (CurrentQi < MaxQiCapacity)
	{
		CurrentQi = FMath::Min(CurrentQi + (RegenRate * DeltaTime), MaxQiCapacity);
	}
}
void USovereignQiComponent::AbsorbElementalQi(FName Element, float Amount, float SourcePurity)
{
	// 1. Blend the raw Qi first (Blends Purity and updates TotalAccumulated)
	AbsorbQi(Amount, SourcePurity);

	// 2. Update the specific Elemental Resonance
	float* CurrentResonance = ElementalResonance.Find(Element);
	if (CurrentResonance)
	{
		*CurrentResonance += (Amount * SourcePurity);
	}
	else
	{
		ElementalResonance.Add(Element, (Amount * SourcePurity));
	}

	// 3. Alignment Shift (The Light/Dark balance)
	if (Element == "Shadow" || Element == "Void") SpiritualAlignment -= 0.1f;
	if (Element == "Holy" || Element == "Light") SpiritualAlignment += 0.1f;
}

void USovereignQiComponent::ResetDensity()
{
	TotalQiAccumulated = 0.0f;
}

void USovereignQiComponent::GenerateConflictTag(FName ElementA, FName ElementB)
{
	// 1. Get the Entity
	ASovereignBaseEntity* Owner = Cast<ASovereignBaseEntity>(GetOwner());
	if (!Owner) return;

	// 2. Use the getter we put in the Entity.h
	USovereignSaveableEntityComponent* Soul = Owner->GetSaveDataComponent();

	if (Soul)
	{
		FString ConflictName = FString::Printf(TEXT("Residual.%s_%s"), *ElementA.ToString(), *ElementB.ToString());

		// 3. This now works because we included the header in step 3
		Soul->AddUnknownTag(ConflictName, TEXT("Manifested via Elemental Friction"));

		// 4. Pressure/Coal effect: Permanent density gain
		TotalQiAccumulated += 25.0f;

		UE_LOG(LogTemp, Warning, TEXT("Sovereign: %s forged a new Truth: %s"), *Owner->GetName(), *ConflictName);
	}
}

TMap<FString, FString> USovereignQiComponent::GetSaveData()
{
	// 1. Start with any data from the Base Component (Symmetry/Metadata)
	TMap<FString, FString> Data = Super::GetSaveData();

	// 2. Core Qi Stats
	Data.Add(TEXT("Qi.Current"), FString::SanitizeFloat(CurrentQi));
	Data.Add(TEXT("Qi.Max"), FString::SanitizeFloat(MaxQiCapacity));
	Data.Add(TEXT("Qi.Purity"), FString::SanitizeFloat(QiPurity));
	Data.Add(TEXT("Qi.Total"), FString::SanitizeFloat(TotalQiAccumulated));

	// 3. Spiritual Alignment (Light/Dark Truth)
	Data.Add(TEXT("Qi.Alignment"), FString::SanitizeFloat(SpiritualAlignment));

	// 4. Elemental Resonance Map
	// This allows Isla's system to handle any number of nature tags (Fire, Earth, etc.)
	for (const TPair<FName, float>& Elem : ElementalResonance)
	{
		FString Key = FString::Printf(TEXT("Qi.Elem.%s"), *Elem.Key.ToString());
		Data.Add(Key, FString::SanitizeFloat(Elem.Value));
	}

	UE_LOG(LogTemp, Log, TEXT("QiComponent %s: Ancestral Data Packed. Purity: %f"), *GetName(), QiPurity);

	return Data;
}
void USovereignQiComponent::RestoreSaveData(const TMap<FString, FString>& Data)
{
	// 1. ANCESTRAL FOUNDATION
	// Call Super to restore base component metadata (Symmetry/Trust signatures)
	Super::RestoreSaveData(Data);

	// 2. CORE SPIRITUAL STATS
	// We use Find() to get a pointer; if the save file is missing a key, we just don't update it.
	if (const FString* Val = Data.Find(TEXT("Qi.Current")))   CurrentQi = FCString::Atof(**Val);
	if (const FString* Val = Data.Find(TEXT("Qi.Max")))       MaxQiCapacity = FCString::Atof(**Val);
	if (const FString* Val = Data.Find(TEXT("Qi.Purity")))    QiPurity = FCString::Atof(**Val);
	if (const FString* Val = Data.Find(TEXT("Qi.Total")))     TotalQiAccumulated = FCString::Atof(**Val);
	if (const FString* Val = Data.Find(TEXT("Qi.Alignment"))) SpiritualAlignment = FCString::Atof(**Val);

	// 3. DYNAMIC ELEMENTAL MANIFESTATION
	// We clear the current map to ensure the saved truth is the only truth.
	ElementalResonance.Empty();

	// Loop through the entire "Suitcase" looking for our specific Elemental Prefix
	for (const TPair<FString, FString>& Pair : Data)
	{
		if (Pair.Key.StartsWith(TEXT("Qi.Elem.")))
		{
			// "Qi.Elem.Fire" -> RightChop(8) -> "Fire"
			FString ElementName = Pair.Key.RightChop(8);
			float ElementValue = FCString::Atof(*Pair.Value);

			ElementalResonance.Add(FName(*ElementName), ElementValue);

			UE_LOG(LogTemp, Verbose, TEXT("Sovereign: Restored %s resonance at %f"), *ElementName, ElementValue);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("QiComponent [%s] Restored: Purity %f, Alignment %f"),
		*GetName(), QiPurity, SpiritualAlignment);
}

