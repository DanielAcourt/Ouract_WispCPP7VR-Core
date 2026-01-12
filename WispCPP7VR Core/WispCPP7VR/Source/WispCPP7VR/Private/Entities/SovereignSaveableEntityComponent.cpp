// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseEntity.h" // Essential for the Evolve() call
#include "SaveSystem/SovereignActorRegistry.h" // <--- Updated to match your Registry header

#include "JsonObjectConverter.h"
#include "GameplayTagContainer.h"

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
			if (TagString.Split(TEXT(":"), &Key, &Value))
			{
				FoundTags.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
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

	// Cleanup old tags
	for (int32 i = Owner->Tags.Num() - 1; i >= 0; --i)
	{
		if (Owner->Tags[i].ToString().Contains(TEXT(":")))
		{
			Owner->Tags.RemoveAt(i);
		}
	}

	for (auto& Elem : LoadedTags)
	{
		if (Elem.Key.Equals(TEXT("GameplayTags"), ESearchCase::IgnoreCase))
		{
			if (ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(Owner))
			{
				TArray<FString> TagStrings;
				Elem.Value.ParseIntoArray(TagStrings, TEXT(","), true);
				for (const FString& TagString : TagStrings)
				{
					MyEntity->IngestSovereignTag(TagString);
				}
			}
			continue;
		}

		if (EnumPtr)
		{
			int64 Val = EnumPtr->GetValueByNameString(Elem.Value);
			if (Val != INDEX_NONE)
			{
				if (Elem.Key.Equals(TEXT("Alignment"), ESearchCase::IgnoreCase)) AlignmentSocket = static_cast<ESovereignElement>(Val);
				else if (Elem.Key.Equals(TEXT("Body"), ESearchCase::IgnoreCase)) BodySocket = static_cast<ESovereignElement>(Val);
				else if (Elem.Key.Equals(TEXT("Magic"), ESearchCase::IgnoreCase)) MagicSocket = static_cast<ESovereignElement>(Val);
			}
		}

		FString ReconstructedTag = FString::Printf(TEXT("%s:%s"), *Elem.Key, *Elem.Value);
		Owner->Tags.Add(FName(*ReconstructedTag));
	}
}



TSharedPtr<FJsonObject> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

    // 1. SCRAPE META-TAGS (The "Isla" Unknown Tag System)
    TMap<FString, FString> MetaTags = GetUnknownMetaTags();
    for (const auto& Elem : MetaTags)
    {
        JsonObject->SetStringField(Elem.Key, Elem.Value);
    }

    // Serialize the GameplayTagContainer
    if (ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(GetOwner()))
    {
        TArray<TSharedPtr<FJsonValue>> TagArray;
        for (const FGameplayTag& Tag : MyEntity->GameplayTags)
        {
            TagArray.Add(MakeShareable(new FJsonValueString(Tag.ToString())));
        }
        JsonObject->SetArrayField(TEXT("GameplayTags"), TagArray);
    }

    // 2. SCRAPE COMPONENTS (The "Contract" System)
    TArray<UActorComponent*> InterfaceComps;
    GetOwner()->GetComponents(InterfaceComps);

    for (UActorComponent* Comp : InterfaceComps)
    {
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
        {
            TMap<FString, FString> ComponentData = SaveInterface->GetSaveData();
            for (const auto& Elem : ComponentData)
            {
                JsonObject->SetStringField(Elem.Key, Elem.Value);
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

    // Direct Deserialization for GameplayTags
    if (JsonData->HasField(TEXT("GameplayTags")))
    {
        const TArray<TSharedPtr<FJsonValue>>* TagArray;
        if (JsonData->TryGetArrayField(TEXT("GameplayTags"), TagArray))
        {
            if (ASovereignBaseEntity* MyEntity = Cast<ASovereignBaseEntity>(Owner))
            {
                MyEntity->GameplayTags.Reset();
                for (const TSharedPtr<FJsonValue>& Val : *TagArray)
                {
                    MyEntity->IngestSovereignTag(Val->AsString());
                }
            }
        }
    }

    // You can add similar logic for other keys here
    // For now, we are only concerned with GameplayTags
}

/*
void USovereignSaveableEntityComponent::CaptureEntityState()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	// 1. Capture Qi
	USovereignQiComponent* QiComp = Owner->FindComponentByClass<USovereignQiComponent>();
	if (QiComp)
	{
		// Store in a way Isla's system can read (using tags or a map)
		CapturedMetadata.AddTag(FGameplayTag::RequestGameplayTag("Data.Qi.Current"), QiComp->CurrentQi);
	}

	// 2. Capture Attributes
	USovereignAttributeComponent* AttribComp = Owner->FindComponentByClass<USovereignAttributeComponent>();
	if (AttribComp)
	{
		CapturedMetadata.AddTag(FGameplayTag::RequestGameplayTag("Data.Attr.Hunger"), AttribComp->Hunger);
	}
}
*/
#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport() { Super::PostEditImport(); EntityID = FGuid::NewGuid(); }
void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	if (!bDuplicateForPIE) { EntityID = FGuid::NewGuid(); }
}
#endif



