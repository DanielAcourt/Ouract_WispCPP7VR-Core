// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.3. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Components/SovereignBioComponent.h"
#include "Entities/SovereignBaseEntity.h"

USovereignBioComponent::USovereignBioComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Logic moved to Sovereign Heartbeat

    // Default Vitals
    Hunger = 50.0f;
    Hydration = 50.0f;
    Fatigue = 0.0f;
    Tiredness = 0.0f;
    Toxicity = 0.0f;
    WasteLevel = 0.0f;
    Entropy = 0.0f;

    Mass = 1;
    MassExperience = 1.0;

    bIsFemale = FMath::RandBool();
    ParentID = FGuid();
    MotherID = FGuid();
    FatherID = FGuid();
    OffspringCount = 0;
    LastMatingTimestamp = -100.0f;
    MatingCooldownDuration = 60.0f;
}

void USovereignBioComponent::UpdateMetabolism(float DeltaTime)
{
    // 1. ENVIRONMENTAL & AGE SCALING
    float TempCost = FMath::Abs(TemperatureShift) * 2.0f;
    float EntropyMultiplier = 1.0f + (Entropy * 0.01f);

    // Total cost of existence
    float NetDrain = (0.1f + StateDrain + TempCost) * EntropyMultiplier * DeltaTime;

    // 2. SURVIVAL HIERARCHY (The "Battery" Logic)
    if (Hunger > 0.0f)
    {
        Hunger -= NetDrain;
        Hydration -= (NetDrain * 1.2f); // Hydration typically drains faster
    }
    else if (NutrientReserves.Contains(ESovereignNutrient::Fats) && NutrientReserves[ESovereignNutrient::Fats] > 0.0f)
    {
        // Burning Fat reserves when starving
        NutrientReserves[ESovereignNutrient::Fats] -= (NetDrain * 2.0f);
        Fatigue += (NetDrain * 0.5f);
    }
    else
    {
        // Critical Starvation: Handled by AttributeComponent checking this component's Hunger
    }

    // 3. GROWTH LOOP (Cookie Clicker Prestige)
    // Only grow Mass if well-fed, hydrated, and not exhausted
    if (Hunger > 80.0f && Hydration > 80.0f && Fatigue < 20.0f)
    {
        // Tiny incremental growth toward the next "Mass" level
        double GrowthAmount = 0.00000001 * (double)DeltaTime;
        MassExperience += GrowthAmount;
        Mass = FMath::FloorToInt(MassExperience);
    }

    // 4. TOXICITY & WASTE
    if (Toxicity > 0.0f) Toxicity -= (0.01f * DeltaTime); // Passive detox
    WasteLevel += (NetDrain * 0.5f);
}

void USovereignBioComponent::HandleBiologicalTransition(float DeltaTime)
{
}

float USovereignBioComponent::GetDecompositionYield() const
{
    return 0.0f;
}


TMap<FString, FString> USovereignBioComponent::GetSaveData()
{
    TMap<FString, FString> Data;
    FString P = TEXT("BioComponent.");

    Data.Add(P + TEXT("HGR"), FString::SanitizeFloat(Hunger));
    Data.Add(P + TEXT("HYD"), FString::SanitizeFloat(Hydration));
    Data.Add(P + TEXT("FTG"), FString::SanitizeFloat(Fatigue));
    Data.Add(P + TEXT("TRD"), FString::SanitizeFloat(Tiredness));
    Data.Add(P + TEXT("ENT"), FString::SanitizeFloat(Entropy));
    Data.Add(P + TEXT("MSXP"), FString::Printf(TEXT("%f"), MassExperience));

    // --- Lineage ---
    Data.Add(P + TEXT("IsFemale"), bIsFemale ? TEXT("True") : TEXT("False"));
    Data.Add(P + TEXT("ParentID"), ParentID.ToString());
    Data.Add(P + TEXT("MotherID"), MotherID.ToString());
    Data.Add(P + TEXT("FatherID"), FatherID.ToString());
    Data.Add(P + TEXT("OffspringCount"), FString::FromInt(OffspringCount));
    Data.Add(P + TEXT("LastMating"), FString::SanitizeFloat(LastMatingTimestamp));

    FString HistoryStr;
    for (const FGuid& ID : MatingHistory)
    {
        HistoryStr += ID.ToString() + TEXT(",");
    }
    Data.Add(P + TEXT("MatingHistory"), HistoryStr);

    // Nutrient TMap Serialization
    for (uint8 i = 0; i < (uint8)ESovereignNutrient::MAX; ++i)
    {
        ESovereignNutrient Type = (ESovereignNutrient)i;
        if (NutrientReserves.Contains(Type))
        {
            Data.Add(P + FString::Printf(TEXT("Nutrient.%d"), i), FString::SanitizeFloat(NutrientReserves[Type]));
        }
    }
    return Data;
}



void USovereignBioComponent::RestoreSaveData(const TMap<FString, FString>& Data)
{
    FString P = TEXT("BioComponent.");
    auto GetFlt = [&](FString Key, float& Target) { if (Data.Contains(P + Key)) Target = FCString::Atof(*Data[P + Key]); };

    GetFlt(TEXT("HGR"), Hunger);
    GetFlt(TEXT("HYD"), Hydration);
    GetFlt(TEXT("FTG"), Fatigue);
    GetFlt(TEXT("TRD"), Tiredness);
    GetFlt(TEXT("ENT"), Entropy);

    if (Data.Contains(P + TEXT("MSXP")))
    {
        MassExperience = FCString::Atod(*Data[P + TEXT("MSXP")]);
        Mass = FMath::FloorToInt(MassExperience);
    }

    // --- Lineage Restore ---
    if (Data.Contains(P + TEXT("IsFemale"))) bIsFemale = Data[P + TEXT("IsFemale")].Equals(TEXT("True"), ESearchCase::IgnoreCase);
    if (Data.Contains(P + TEXT("ParentID"))) FGuid::Parse(Data[P + TEXT("ParentID")], ParentID);
    if (Data.Contains(P + TEXT("MotherID"))) FGuid::Parse(Data[P + TEXT("MotherID")], MotherID);
    if (Data.Contains(P + TEXT("FatherID"))) FGuid::Parse(Data[P + TEXT("FatherID")], FatherID);
    if (Data.Contains(P + TEXT("OffspringCount"))) OffspringCount = FCString::Atoi(*Data[P + TEXT("OffspringCount")]);
    GetFlt(TEXT("LastMating"), LastMatingTimestamp);

    if (Data.Contains(P + TEXT("MatingHistory")))
    {
        TArray<FString> IDStrings;
        Data[P + TEXT("MatingHistory")].ParseIntoArray(IDStrings, TEXT(","), true);
        MatingHistory.Empty();
        for (const FString& S : IDStrings)
        {
            FGuid ID;
            if (FGuid::Parse(S, ID)) MatingHistory.Add(ID);
        }
    }

    for (uint8 i = 0; i < (uint8)ESovereignNutrient::MAX; ++i)
    {
        FString Key = P + FString::Printf(TEXT("Nutrient.%d"), i);
        if (Data.Contains(Key))
            NutrientReserves.Add((ESovereignNutrient)i, FCString::Atof(*Data[Key]));
    }
}

void USovereignBioComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}