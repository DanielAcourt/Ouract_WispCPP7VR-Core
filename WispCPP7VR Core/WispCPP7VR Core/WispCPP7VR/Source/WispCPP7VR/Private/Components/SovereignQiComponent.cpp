// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SovereignQiComponent.h"
#include "Entities/SovereignBaseEntity.h"
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
	// PASSIVE REGENERATION
	// This represents the soul "breathing" the weave.
	// Wisdom determines the rate, Purity determines the quality of that rate.
	float RegenRate = (static_cast<float>(WisdomStat) * 0.1f) * QiPurity;

	if (CurrentQi < MaxQiCapacity)
	{
		CurrentQi = FMath::Min(CurrentQi + (RegenRate * DeltaTime), MaxQiCapacity);
	}
}

void USovereignQiComponent::ResetDensity()
{
	TotalQiAccumulated = 0.0f;
}



TMap<FString, FString> USovereignQiComponent::GetSaveData()
{
	TMap<FString, FString> Data;
	// Change Proposal 2 = Refactored to provide raw, unprefixed variable names. The SovereignSaveableEntityComponent is now responsible for prefixing these keys to prevent naming collisions.
	Data.Add(TEXT("CurrentQi"), FString::SanitizeFloat(CurrentQi));
	Data.Add(TEXT("MaxQiCapacity"), FString::SanitizeFloat(MaxQiCapacity));
	Data.Add(TEXT("QiPurity"), FString::SanitizeFloat(QiPurity));
	Data.Add(TEXT("TotalQiAccumulated"), FString::SanitizeFloat(TotalQiAccumulated));

	UE_LOG(LogTemp, Log, TEXT("QiComponent %s: GetSaveData called. CurrentQi: %f"), *GetName(), CurrentQi);

	return Data;
}

void USovereignQiComponent::RestoreSaveData(const TMap<FString, FString>& Data)
{
	// Change Proposal 3 = Refactored to parse the entire actor "Suitcase" map. It now looks for keys prefixed with its own component name, making it compliant with the "polite persistence" model.
	const FString ComponentPrefix = GetName() + TEXT(".");
	int32 FoundKeys = 0;

	for (const auto& Elem : Data)
	{
		if (Elem.Key.StartsWith(ComponentPrefix))
		{
			const FString VariableName = Elem.Key.RightChop(ComponentPrefix.Len());
			if (VariableName.Equals(TEXT("CurrentQi")))
			{
				CurrentQi = FCString::Atof(*Elem.Value);
				FoundKeys++;
			}
			else if (VariableName.Equals(TEXT("MaxQiCapacity")))
			{
				MaxQiCapacity = FCString::Atof(*Elem.Value);
				FoundKeys++;
			}
			else if (VariableName.Equals(TEXT("QiPurity")))
			{
				QiPurity = FCString::Atof(*Elem.Value);
				FoundKeys++;
			}
			else if (VariableName.Equals(TEXT("TotalQiAccumulated")))
			{
				TotalQiAccumulated = FCString::Atof(*Elem.Value);
				FoundKeys++;
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("QiComponent %s: RestoreSaveData called. Found %d matching keys. CurrentQi is now: %f"), *GetName(), FoundKeys, CurrentQi);
}

