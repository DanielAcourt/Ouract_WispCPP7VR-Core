// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseEntity.h" // Essential for the Evolve() call
#include "SaveSystem/SovereignActorRegistry.h" // <--- Updated to match your Registry header
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

void USovereignSaveableEntityComponent::ApplyMetaTags(TMap<FString, FString> LoadedTags)
{
    ASovereignBaseEntity* OwnerEntity = Cast<ASovereignBaseEntity>(GetOwner());
    if (!OwnerEntity) return;

    // ATTRIBUTES FIRST: Populate TrustSignature and Triple-Axis values before tag ingestion.
    if (LoadedTags.Contains(TEXT("TrustSignature")))
    {
        OwnerEntity->TrustSignature = FCString::Atoi(*LoadedTags[TEXT("TrustSignature")]);
    }

    UEnum* EnumPtr = StaticEnum<ESovereignElement>();
    if (EnumPtr)
    {
        if (LoadedTags.Contains(TEXT("Alignment")))
        {
            int64 Val = EnumPtr->GetValueByNameString(LoadedTags[TEXT("Alignment")]);
            if (Val != INDEX_NONE) AlignmentSocket = static_cast<ESovereignElement>(Val);
        }
        if (LoadedTags.Contains(TEXT("Body")))
        {
            int64 Val = EnumPtr->GetValueByNameString(LoadedTags[TEXT("Body")]);
            if (Val != INDEX_NONE) BodySocket = static_cast<ESovereignElement>(Val);
        }
        if (LoadedTags.Contains(TEXT("Magic")))
        {
            int64 Val = EnumPtr->GetValueByNameString(LoadedTags[TEXT("Magic")]);
            if (Val != INDEX_NONE) MagicSocket = static_cast<ESovereignElement>(Val);
        }
    }

    // TAGS SECOND: Now that attributes are loaded, ingest the Sovereign tags.
    OwnerEntity->GameplayTags.RemoveAllTags(); // Clear old tags to prevent bleeding.
    if (LoadedTags.Contains(TEXT("SovereignTags")))
    {
        TArray<FString> TagStrings;
        LoadedTags[TEXT("SovereignTags")].ParseIntoArray(TagStrings, TEXT(","), true);
        for (const FString& TagString : TagStrings)
        {
            OwnerEntity->IngestSovereignTag(TagString); // InstigatorTrust defaults to 0
        }
    }
}


TMap<FString, FString> USovereignSaveableEntityComponent::CaptureFullEntityState()
{
	TMap<FString, FString> AggregatedData;

	// 1. SCRAPE META-TAGS (The "Isla" Unknown Tag System)
	AggregatedData.Append(GetUnknownMetaTags());

	// 2. SCRAPE SOVEREIGN TAGS (LIVING SAVE BRIDGE)
	ASovereignBaseEntity* OwnerEntity = Cast<ASovereignBaseEntity>(GetOwner());
	if (OwnerEntity)
	{
		TArray<FString> TagStrings;
		for (const FGameplayTag& Tag : OwnerEntity->GameplayTags)
		{
			TagStrings.Add(Tag.ToString());
		}
		if (TagStrings.Num() > 0)
		{
			AggregatedData.Add(TEXT("SovereignTags"), FString::Join(TagStrings, TEXT(",")));
		}
	}

	// 3. SCRAPE COMPONENTS (The "Contract" System)
	TArray<UActorComponent*> InterfaceComps;
	GetOwner()->GetComponents(InterfaceComps);

	for (UActorComponent* Comp : InterfaceComps)
	{
		if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
		{
			AggregatedData.Append(SaveInterface->GetSaveData());
		}
	}

	return AggregatedData;
}
#if WITH_EDITOR
void USovereignSaveableEntityComponent::PostEditImport() { Super::PostEditImport(); EntityID = FGuid::NewGuid(); }
void USovereignSaveableEntityComponent::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);
	if (!bDuplicateForPIE) { EntityID = FGuid::NewGuid(); }
}
#endif