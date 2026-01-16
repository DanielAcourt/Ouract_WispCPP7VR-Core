// Copyright Wisp Games, Inc. All Rights Reserved.

#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseEntity.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "JsonObjectConverter.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Engine/World.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECTION 1: STANDARD COMPONENT LIFECYCLE
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

USovereignSaveableEntityComponent::USovereignSaveableEntityComponent()
{
	// This component does not need to tick. It acts as a data container and manager.
	PrimaryComponentTick.bCanEverTick = false;
}

void USovereignSaveableEntityComponent::BeginPlay()
{
	Super::BeginPlay();

	// Ensure this entity has a valid GUID. If not, generate a new one.
	// This is critical for new instances placed in the world.
	if (!EntityID.IsValid())
	{
		EntityID = FGuid::NewGuid();
	}

	// Register this actor with the world's ActorRegistry. This subsystem keeps track of all
	// saveable entities, allowing the save/load system to find them by their GUID.
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
	// Unregister this actor from the ActorRegistry when it is destroyed.
	// This prevents dangling references in the save system.
	if (UWorld* World = GetWorld())
	{
		if (UActorRegistry* Registry = World->GetSubsystem<UActorRegistry>())
		{
			Registry->UnregisterActor(EntityID);
		}
	}
	Super::EndPlay(EndPlayReason);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECTION 2: CORE SERIALIZATION API
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TSharedPtr<FJsonObject> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
	// Use TSharedPtr for memory safety. The pointer will be automatically managed,
	// preventing memory leaks during the potentially complex serialization process.
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return JsonObject;
	}

	// --- PASS A: THE ID CARD (TAGS) ---
	// This pass captures all forms of tags, which define the entity's identity and state.

	// Part 1: Tier 4 - Unknown Meta Tags (The Pass-Through Buffer)
	// Scrape the AActor::Tags array. This captures all loose key-value pairs and simple boolean tags.
	// This is the "polite" part of the system; it saves data it doesn't understand.
	TMap<FString, FString> UnknownTags = GetUnknownMetaTags();
	for (const auto& Elem : UnknownTags)
	{
		JsonObject->SetStringField(Elem.Key, Elem.Value);
	}

	// Part 2: Tier 2 - Gameplay Tags
	// If the actor uses the GameplayTag system, capture all of its owned tags.
	// These are formal, hierarchical tags (e.g., "State.Burning", "Identity.Player").
	if (IGameplayTagAssetInterface* TagInterface = Cast<IGameplayTagAssetInterface>(Owner))
	{
		FGameplayTagContainer AllTags;
		TagInterface->GetOwnedGameplayTags(AllTags);
		for (const FGameplayTag& Tag : AllTags)
		{
			JsonObject->SetStringField(Tag.ToString(), TEXT("True"));
		}
	}

	// --- PASS B: THE DNA (COMPONENT DATA) ---
	// This pass captures the detailed, strongly-typed data from other components.

	// Part 1: Tier 1 - Component Data
	// Find all components on the actor that implement our save interface.
	TArray<UActorComponent*> InterfaceComps;
	Owner->GetComponents(InterfaceComps);

	for (UActorComponent* Comp : InterfaceComps)
	{
		// Skip self to prevent recursion.
		if (Comp == this) continue;

		if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
		{
			// Ask the component for its save data.
			TMap<FString, FString> ComponentData = SaveInterface->GetSaveData();
			FString ComponentName = Comp->GetName();

			// Prefix each key with the component's name (e.g., "QiComponent.CurrentQi")
			// to prevent key collisions in the final JSON object.
			for (const auto& Elem : ComponentData)
			{
				FString PrefixedKey = FString::Printf(TEXT("%s.%s"), *ComponentName, *Elem.Key);
				JsonObject->SetStringField(PrefixedKey, Elem.Value);
			}
		}
	}

	return JsonObject;
}

void USovereignSaveableEntityComponent::ApplyStateFromJsonObject(const TSharedPtr<FJsonObject>& JsonData)
{
	if (!JsonData.IsValid()) return;

	AActor* Owner = GetOwner();
	if (!Owner) return;

	// Step 1: Create the "Suitcase"
	// Convert the entire JSON object into a single, flat TMap of strings. This universal container
	// holds all the data and can be passed around easily to any system that needs to restore its state.
	TMap<FString, FString> AllData;
	for (const auto& Elem : JsonData->Values)
	{
		if (Elem.Value.IsValid() && Elem.Value->Type == EJson::String)
		{
			AllData.Add(Elem.Key, Elem.Value->AsString());
		}
	}

	if (AllData.Num() == 0) return;

	// Step 2: Apply Identity (ID Card & Soul)
	// This single function call processes Tiers 2, 3, and 4 of the Hierarchy of Truth.
	// It ingests GameplayTags, sets the elemental sockets, and restores all unknown meta tags.
	ApplyMetaTags(AllData);

	// Step 3: Apply Component Data (DNA)
	// Distribute the "Suitcase" of data to all components that can be saved.
	TArray<UActorComponent*> InterfaceComps;
	Owner->GetComponents(InterfaceComps);

	for (UActorComponent* Comp : InterfaceComps)
	{
		if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
		{
			// Each component is responsible for finding its own data within the map
			// (e.g., looking for the "AttributeComponent." prefix) and restoring its state.
			SaveInterface->RestoreSaveData(AllData);
		}
	}
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECTION 3: META TAG HANDLING & HIERARCHY OF TRUTH
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void USovereignSaveableEntityComponent::ApplyMetaTags(TMap<FString, FString> LoadedTags)
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	UEnum* EnumPtr = StaticEnum<ESovereignElement>();
	ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(Owner);

	// First, clean up the existing AActor::Tags array. This prevents duplication of data
	// from a previous state. We only remove tags that contain a colon, as these are the
	// ones this system specifically manages.
	for (int32 i = Owner->Tags.Num() - 1; i >= 0; --i)
	{
		if (Owner->Tags[i].ToString().Contains(TEXT(":")))
		{
			Owner->Tags.RemoveAt(i);
		}
	}

	// Now, iterate through all loaded tags and apply them according to the Hierarchy of Truth.
	for (auto& Elem : LoadedTags)
	{
		// --- HIERARCHY TIER 1: Component Data ---
		// If a key contains "Component.", we know it belongs to another component.
		// We skip it here because the DNA pass in ApplyStateFromJsonObject handles it.
		if (Elem.Key.Contains(TEXT("Component.")))
		{
			continue;
		}

		// --- HIERARCHY TIER 2: Gameplay Tags ---
		// If the key contains a dot, it's treated as a formal Gameplay Tag.
		// These are ingested into the entity's GameplayTagContainer for system-wide logic.
		if (MyEntity && Elem.Key.Contains(TEXT(".")))
		{
			MyEntity->IngestSovereignTag(Elem.Key);
			continue;
		}

		// --- HIERARCHY TIER 3: Mapped Properties (The Soul) ---
		// Check if the key matches one of our core elemental sockets.
		if (EnumPtr)
		{
			int64 Val = EnumPtr->GetValueByNameString(Elem.Value);
			if (Val != INDEX_NONE)
			{
				if (Elem.Key.Equals(TEXT("Alignment"), ESearchCase::IgnoreCase)) { AlignmentSocket = static_cast<ESovereignElement>(Val); continue; }
				if (Elem.Key.Equals(TEXT("Body"), ESearchCase::IgnoreCase))      { BodySocket = static_cast<ESovereignElement>(Val); continue; }
				if (Elem.Key.Equals(TEXT("Magic"), ESearchCase::IgnoreCase))      { MagicSocket = static_cast<ESovereignElement>(Val); continue; }
			}
		}

		// --- HIERARCHY TIER 4: Unknown Meta Tags (Non-Destructive Pass-Through Buffer) ---
		// If a tag has not been "claimed" by any of the higher tiers, it falls through to here.
		// We restore it to the `AActor::Tags` array, ensuring no data is lost.
		// Using FName is efficient here due to Unreal's string interning.
		if (Elem.Value.Equals(TEXT("True"), ESearchCase::IgnoreCase))
		{
			// It's a simple boolean tag (e.g., "IsOnFire").
			Owner->Tags.Add(FName(*Elem.Key));
		}
		else
		{
			// It's a key-value pair (e.g., "DoorCode:1234").
			FString ReconstructedTag = FString::Printf(TEXT("%s:%s"), *Elem.Key, *Elem.Value);
			Owner->Tags.Add(FName(*ReconstructedTag));
		}
	}
}

TMap<FString, FString> USovereignSaveableEntityComponent::GetUnknownMetaTags() const
{
	TMap<FString, FString> FoundTags;
	if (AActor* Owner = GetOwner())
	{
		// Using FName for the Tags array is memory efficient, as Unreal Engine will reuse
		// memory for duplicate strings (string interning).
		for (const FName& TagName : Owner->Tags)
		{
			FString TagString = TagName.ToString();
			FString Key, Value;

			// Split only on the first colon. This allows values to contain their own colons
			// (e.g., "Timestamp:12:30:00").
			if (TagString.Split(TEXT(":"), &Key, &Value, ESearchCase::CaseSensitive, ESearchDir::FromStart))
			{
				FoundTags.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
			}
			else // If no colon, it's a simple boolean tag like "IsOnFire".
			{
				FoundTags.Add(TagString.TrimStartAndEnd(), TEXT("True"));
			}
		}
	}
	return FoundTags;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECTION 4: GAMEPLAY LOGIC (EVOLUTION & ENERGY)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void USovereignSaveableEntityComponent::ReceiveElementalEnergy(ESovereignElement EnergyType, float RawAmount)
{
	// Logic for shifting elemental alignment and influence based on energy received.
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

	// Calculate the final growth amount based on elemental strengths/weaknesses.
	float Modifier = GetElementalMultiplier(EnergyType);
	MaturityProgress += (RawAmount * Modifier);

	// Check if the entity has gained enough maturity to evolve.
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

	if (IncomingType == ESovereignElement::Fairy || IncomingType == ESovereignElement::Dragon) return 1000.0f;

	// The 5-way battle cycle for physical elements.
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

	// Alignment duality rules.
	if ((AlignmentSocket == ESovereignElement::Light && IncomingType == ESovereignElement::Dark) ||
		(AlignmentSocket == ESovereignElement::Dark && IncomingType == ESovereignElement::Light))
	{
		Multiplier *= 0.25f;
	}

	return Multiplier;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// SECTION 5: EDITOR-SPECIFIC LOGIC
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport()
{
	Super::PostEditImport();
	// Always generate a new ID on import to prevent duplicates.
	EntityID = FGuid::NewGuid();
}

void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	// Generate a new ID when duplicating in the editor, but not for Play-In-Editor instances.
	if (!bDuplicateForPIE)
	{
		EntityID = FGuid::NewGuid();
	}
}
#endif