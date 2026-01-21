// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseEntity.h" // Essential for the Evolve() call
#include "SaveSystem/SovereignActorRegistry.h" // <--- Updated to match your Registry header

#include "JsonObjectConverter.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"

#include "Engine/World.h"

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

// --- ENERGY & EVOLUTION ---
void USovereignSaveableEntityComponent::ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount)
{
	// 1. AXIS LOGIC: Shift the correct influence (0-100)

	// Check if this is Alignment Energy (Light/Dark)
	if (EnergyType == ESovereignElement::Light || EnergyType == ESovereignElement::Dark)
	{
		if (EnergyType == AlignmentSocket)
		{
			AlignmentInfluence = FMath::Clamp(AlignmentInfluence + (RawAmount * 5.0f), 0.0f, 100.0f);
		}
		else
		{
			AlignmentInfluence -= (RawAmount * 2.0f);
			if (AlignmentInfluence <= 0.0f)
			{
				AlignmentSocket = EnergyType;
				AlignmentInfluence = 1.0f;
			}
		}
	}
	// Check if this is Body Energy (Nature/Fire/Water/Earth/Air)
	else if (EnergyType != ESovereignElement::Grey && EnergyType != ESovereignElement::Fairy && EnergyType != ESovereignElement::Dragon)
	{
		if (EnergyType == BodySocket)
		{
			BodyInfluence = FMath::Clamp(BodyInfluence + (RawAmount * 5.0f), 0.0f, 100.0f);
		}
		else
		{
			BodyInfluence -= (RawAmount * 2.0f);
			if (BodyInfluence <= 0.0f)
			{
				BodySocket = EnergyType;
				BodyInfluence = 1.0f;
			}
		}
	}

	// 2. YIELD LOGIC: Calculate growth using the 5-way cycle
	float Modifier = GetElementalMultiplier(EnergyType);
	MaturityProgress += (RawAmount * Modifier);

	UE_LOG(LogTemp, Log, TEXT("Sovereign: %s received %f %s energy. New Maturity: %f"),
		*GetOwner()->GetName(), RawAmount, *UEnum::GetValueAsString(EnergyType), MaturityProgress);

	// 3. EVOLUTION CHECK
	if (MaturityProgress >= 1.0f)
	{
		if (ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(GetOwner()))
		{
			MyEntity->Evolve();
		}
	}
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

// --- META TAG HANDLING ---
TMap<FString, FString> USovereignSaveableEntityComponent::GetUnknownMetaTags() const
{
	TMap<FString, FString> FoundTags;
	if (AActor* Owner = GetOwner())
	{
		for (const FName& TagName : Owner->Tags)
		{
			FString TagString = TagName.ToString();
			FString Key, Value;

			// Split only on the first colon to support values with colons
			if (TagString.Split(TEXT(":"), &Key, &Value, ESearchCase::CaseSensitive, ESearchDir::FromStart))
			{
				FoundTags.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
			}
			else // If no colon is found, treat the whole tag as a key with a value of "True"
			{
				FoundTags.Add(TagString.TrimStartAndEnd(), TEXT("True"));
			}
		}
	}
	return FoundTags;
}

// Note: This function is now primarily used for the hybrid/clone spawning logic.
// For loading from save files, see ApplyStateFromJsonObject.
void USovereignSaveableEntityComponent::ApplyMetaTags(TMap<FString, FString> LoadedTags)
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	UEnum* EnumPtr = StaticEnum<ESovereignElement>();
	ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(Owner);

	// 1. CLEANUP: Only remove old "Legacy" colon-tags.
	for (int32 i = Owner->Tags.Num() - 1; i >= 0; --i)
	{
		if (Owner->Tags[i].ToString().Contains(TEXT(":")))
		{
			Owner->Tags.RemoveAt(i);
		}
	}

	for (auto& Elem : LoadedTags)
	{
		// 2. DNA FILTER: If the key contains "Component.", it is physical data.
		// We skip it here because ApplyStateFromJsonObject handles this via the ISovereignSaveInterface.
		if (Elem.Key.Contains(TEXT("Component.")))
		{
			continue;
		}

		// 3. ID CARD (Gameplay Tags): If it uses dot-notation (e.g., "Identity.Species.Wisp")
		// We ingest it into the formal GameplayTagContainer for system-wide logic.
		if (MyEntity && Elem.Key.Contains(TEXT(".")))
		{
			MyEntity->IngestSovereignTag(Elem.Key);
			continue;
		}

		// 4. ELEMENTAL SOCKETS (The Soul's Alignment)
		if (EnumPtr)
		{
			int64 Val = EnumPtr->GetValueByNameString(Elem.Value);
			if (Val != INDEX_NONE)
			{
				if (Elem.Key.Equals(TEXT("Alignment"), ESearchCase::IgnoreCase)) AlignmentSocket = static_cast<ESovereignElement>(Val);
				else if (Elem.Key.Equals(TEXT("Body"), ESearchCase::IgnoreCase)) BodySocket = static_cast<ESovereignElement>(Val);
				else if (Elem.Key.Equals(TEXT("Magic"), ESearchCase::IgnoreCase)) MagicSocket = static_cast<ESovereignElement>(Val);
				continue;
			}
		}

		// 5. LEGACY/STRING FALLBACK: Add to standard AActor::Tags array
		if (Elem.Value.Equals(TEXT("True"), ESearchCase::IgnoreCase))
		{
			// Simple boolean tag (e.g., "Terminal.Active")
			Owner->Tags.Add(FName(*Elem.Key));
		}
		else
		{
			// Key:Value pair tag (e.g., "Door.Code:1234")
			FString ReconstructedTag = FString::Printf(TEXT("%s:%s"), *Elem.Key, *Elem.Value);
			Owner->Tags.Add(FName(*ReconstructedTag));
		}
	}
}



TSharedPtr<FJsonObject> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return JsonObject;
	}

	// --- PASS A (ID CARD) ---

	// Part 1: Scrape AActor::Tags (e.g., "Terminal.Active:True") via helper function
// Part 1: Standard Actor Tags (e.g., "Terminal.Active")
	TMap<FString, FString> LegacyTags = GetUnknownMetaTags();
	for (const auto& Elem : LegacyTags)
	{
		JsonObject->SetStringField(Elem.Key, Elem.Value);
	}

	// Part 2: Upgraded Gameplay Tag Scraper (Interface-based)
		// This finds ALL hierarchical tags set in Blueprints
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

	// --- PASS B (DNA) ---
	// Scrape Component Data (e.g., "QiComponent.CurrentQi", "AttributeComponent.Strength")
	TArray<UActorComponent*> InterfaceComps;
	Owner->GetComponents(InterfaceComps);

	for (UActorComponent* Comp : InterfaceComps)
	{
		if (Comp == this) continue;

		if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
		{
			TMap<FString, FString> ComponentData = SaveInterface->GetSaveData();
			FString ComponentName = Comp->GetName();

			// Change Proposal 4 = Added diagnostic logging to trace the serialization process.
			if (ComponentData.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("SaveableEntityComponent: Capturing %d keys from component %s"), ComponentData.Num(), *ComponentName);
			}

			for (const auto& Elem : ComponentData)
			{
				// Prefix component data to prevent key collisions, e.g., "Qi.Current"
				FString PrefixedKey = FString::Printf(TEXT("%s.%s"), *ComponentName, *Elem.Key);
				JsonObject->SetStringField(PrefixedKey, Elem.Value);
			}
		}
	}

	return JsonObject;
}
//new feature add qi components and attribute components to the save file
// i need to implment this as it acts as tyhe framework to save all the data from attached compoents. I need to think as 
//this was a time sink attaching everything in blueprints

// we need to finish implementing this to the desired solution so all components and their data get written
// to the save file reglardless of the meta tags so i dont have to make loads of loops in blkueprints./
void USovereignSaveableEntityComponent::ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData)
{
	if (!JsonData.IsValid()) return;

	AActor* Owner = GetOwner();
	if (!Owner) return;

	// 1. Convert the entire JsonObject into a flat string map.
	// This "Suitcase" now contains everything: Tags, Stats, and Enums.
	TMap<FString, FString> AllData;
	for (const auto& Elem : JsonData->Values)
	{
		// We process everything as strings to maintain the Flat JSON standard
		if (Elem.Value.IsValid() && Elem.Value->Type == EJson::String)
		{
			AllData.Add(Elem.Key, Elem.Value->AsString());
		}
	}

	// If there's nothing to restore, exit early
	if (AllData.Num() == 0) return;

	// 2. APPLY IDENTITY (The ID Card Pass)
	// This processes Sockets (Alignment/Body), Ingests Gameplay Tags, 
	// and handles standard Actor Tags.
	ApplyMetaTags(AllData);

	// 3. APPLY COMPONENT DATA (The DNA Pass)
	// Find all components that implement the Save Interface (Qi, Attributes, etc.)
	TArray<UActorComponent*> InterfaceComps;
	Owner->GetComponents(InterfaceComps);

	for (UActorComponent* Comp : InterfaceComps)
	{
		if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
		{
			// The component scans AllData for keys starting with its name 
			// (e.g., "AttributeComponent.STR") and restores itself.
			// Change Proposal 5 = Added diagnostic logging to trace the deserialization process.
			UE_LOG(LogTemp, Warning, TEXT("SaveableEntityComponent: Passing entire %d-key suitcase to %s for restore."), AllData.Num(), *Comp->GetName());
			SaveInterface->RestoreSaveData(AllData);
		}
	}
}

/*
void USovereignSaveableEntityComponent::CaptureEntityState()

*/


#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport() { Super::PostEditImport(); EntityID = FGuid::NewGuid(); }
void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	if (!bDuplicateForPIE) { EntityID = FGuid::NewGuid(); }
}
#endif



