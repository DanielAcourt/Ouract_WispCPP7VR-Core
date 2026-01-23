// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignSaveableEntityComponent.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "JsonObjectConverter.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Engine/World.h"
#include "TimerManager.h"

USovereignSaveableEntityComponent::USovereignSaveableEntityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USovereignSaveableEntityComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!EntityID.IsValid())
	{
		EntityID = FGuid::NewGuid();
	}

	if (UWorld* World = GetWorld())
	{
		if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
		{
			Registry->RegisterActor(EntityID, GetOwner());
		}
	}

	GetWorld()->GetTimerManager().SetTimer(HeartbeatTimerHandle, this, &USovereignSaveableEntityComponent::Heartbeat, 1.0f, true);
}

void USovereignSaveableEntityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UWorld* World = GetWorld())
	{
		if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
		{
			Registry->UnregisterActor(EntityID);
		}
	}
	Super::EndPlay(EndPlayReason);
}

void USovereignSaveableEntityComponent::Heartbeat()
{
	if (VesselState == EVesselState::Alive)
	{
		MaturityProgress += MaturityRate;
		if (MaturityProgress >= 1.0f)
		{
			MaturityProgress = 0.0f;
			if (GetOwner()->Implements<USovereignEntityInterface>())
			{
				// This is a placeholder for a more robust evolution system.
				// For now, we just log that the entity has evolved.
				UE_LOG(LogTemp, Log, TEXT("Entity %s has evolved!"), *GetOwner()->GetName());
			}
		}
	}
	else if (VesselState == EVesselState::Dead)
	{
		Qi -= 1.0f; // Bleed Qi
		if (Qi <= 0)
		{
			VesselState = EVesselState::Dissolving;
			OnEmergencyEject.Broadcast();
			GetOwner()->Destroy();
		}
	}
}

void USovereignSaveableEntityComponent::HandleVesselDeath()
{
	VesselState = EVesselState::Dead;
}

void USovereignSaveableEntityComponent::ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount)
{
	float Modifier = GetElementalMultiplier(EnergyType);
	MaturityProgress += (RawAmount * Modifier);

	UE_LOG(LogTemp, Log, TEXT("Sovereign: %s received %f %s energy. New Maturity: %f"),
		*GetOwner()->GetName(), RawAmount, *UEnum::GetValueAsString(EnergyType), MaturityProgress);
}

float USovereignSaveableEntityComponent::GetElementalMultiplier(ESovereignElement IncomingType)
{
	float Multiplier = 1.0f;

	// --- 1. SPECIAL/MAGIC (Fairy/Dragon) ---
	if (IncomingType == ESovereignElement::Fairy || IncomingType == ESovereignElement::Dragon) return 1000.0f;

	// --- 2. THE 5-WAY BATTLE CYCLE (Body) ---
	if (BodySocket == ESovereignElement::Nature) {
		if (IncomingType == ESovereignElement::Water) Multiplier = 2.0f;
		if (IncomingType == ESovereignElement::Fire)  Multiplier = 0.5f;
	}
	else if (BodySocket == ESovereignElement::Earth) {
		if (IncomingType == ESovereignElement::Nature) Multiplier = 0.5f;
		if (IncomingType == ESovereignElement::Water)  Multiplier = 2.0f;
	}
	else if (BodySocket == ESovereignElement::Water) {
		if (IncomingType == ESovereignElement::Fire)   Multiplier = 2.0f;
		if (IncomingType == ESovereignElement::Nature) Multiplier = 0.5f;
	}
	else if (BodySocket == ESovereignElement::Fire) {
		if (IncomingType == ESovereignElement::Nature) Multiplier = 2.0f;
		if (IncomingType == ESovereignElement::Water)  Multiplier = 0.5f;
	}
	else if (BodySocket == ESovereignElement::Air) {
		if (IncomingType == ESovereignElement::Fire)   Multiplier = 2.0f;
		if (IncomingType == ESovereignElement::Earth)  Multiplier = 0.5f;
	}

	// --- 3. ALIGNMENT DUALITY ---
	if ((AlignmentSocket == ESovereignElement::Light && IncomingType == ESovereignElement::Dark) ||
		(AlignmentSocket == ESovereignElement::Dark && IncomingType == ESovereignElement::Light))
	{
		Multiplier *= 0.25f;
	}

	return Multiplier;
}


TMap<FString, FString> USovereignSaveableEntityComponent::GetUnknownMetaTags() const
{
	TMap<FString, FString> FoundTags;
	if (AActor* Owner = GetOwner())
	{
		for (const FName& TagName : Owner->Tags)
		{
			FString TagString = TagName.ToString();
			FString Key, Value;

			if (TagString.Split(TEXT(":"), &Key, &Value, ESearchCase::CaseSensitive, ESearchDir::FromStart))
			{
				FoundTags.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
			}
			else
			{
				FoundTags.Add(TagString.TrimStartAndEnd(), TEXT("True"));
			}
		}
	}
	return FoundTags;
}

void USovereignSaveableEntityComponent::ApplyMetaTags(TMap<FString, FString> LoadedTags)
{
	// This function will be updated later to handle the new data-driven approach
}

TSharedPtr<FJsonObject> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return JsonObject;
	}

	JsonObject->SetStringField("Health", FString::SanitizeFloat(Health));
	JsonObject->SetStringField("MaxHealth", FString::SanitizeFloat(MaxHealth));
	JsonObject->SetStringField("Qi", FString::SanitizeFloat(Qi));
	JsonObject->SetStringField("MaxQi", FString::SanitizeFloat(MaxQi));
	JsonObject->SetStringField("Maturity", FString::SanitizeFloat(Maturity));
	JsonObject->SetStringField("MaturityProgress", FString::SanitizeFloat(MaturityProgress));
	JsonObject->SetStringField("MaturityRate", FString::SanitizeFloat(MaturityRate));


	if (IGameplayTagAssetInterface* TagInterface = Cast<IGameplayTagAssetInterface>(Owner))
	{
		FGameplayTagContainer AllTags;
		TagInterface->GetOwnedGameplayTags(AllTags);

		TArray<FGameplayTag> TagArray;
		AllTags.GetGameplayTagArray(TagArray);

		for (const FGameplayTag& Tag : TagArray)
		{
			JsonObject->SetStringField(Tag.ToString(), TEXT("True"));
		}
	}

	return JsonObject;
}

void USovereignSaveableEntityComponent::ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData)
{
	if (!JsonData.IsValid()) return;

	Health = JsonData->GetNumberField("Health");
	MaxHealth = JsonData->GetNumberField("MaxHealth");
	Qi = JsonData->GetNumberField("Qi");
	MaxQi = JsonData->GetNumberField("MaxQi");
	Maturity = JsonData->GetNumberField("Maturity");
	MaturityProgress = JsonData->GetNumberField("MaturityProgress");
	MaturityRate = JsonData->GetNumberField("MaturityRate");
}

#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport()
{
	Super::PostEditImport();
	EntityID = FGuid::NewGuid();
}

void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	if (!bDuplicateForPIE)
	{
		EntityID = FGuid::NewGuid();
	}
}
#endif
