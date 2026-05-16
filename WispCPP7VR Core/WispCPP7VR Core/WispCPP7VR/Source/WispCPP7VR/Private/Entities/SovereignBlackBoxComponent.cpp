// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "Entities/SovereignBlackBoxComponent.h"
#include "Interaction/SovereignSaveInterface.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "Subsystems/SovereignBlackBoxHeartbeat.h"
#include "SaveSystem/SovereignPSTAConfig.h"
#include "Engine/World.h"

USovereignBlackBoxComponent::USovereignBlackBoxComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USovereignBlackBoxComponent::BeginPlay()
{
    Super::BeginPlay();

    if (UWorld* World = GetWorld())
    {
        if (USovereignBlackBoxHeartbeat* Heartbeat = World->GetSubsystem<USovereignBlackBoxHeartbeat>())
        {
            Heartbeat->RegisterComponent(this, UpdateFrequency);
        }
    }
}

void USovereignBlackBoxComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        if (USovereignBlackBoxHeartbeat* Heartbeat = World->GetSubsystem<USovereignBlackBoxHeartbeat>())
        {
            Heartbeat->UnregisterComponent(this);
        }
    }

    Super::EndPlay(EndPlayReason);
}

void USovereignBlackBoxComponent::RecordTruthSnapshot()
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    // 1. Gather all data from the Vessel (Actor) and its Components
    TMap<FString, FString> RawData;

    // A. Actor Data
    if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Owner))
    {
        RawData.Append(SaveInterface->GetSaveData());
    }

    // B. Component Data
    TArray<UActorComponent*> Comps;
    Owner->GetComponents(Comps);
    for (UActorComponent* Comp : Comps)
    {
        if (Comp == this) continue;
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
        {
            TMap<FString, FString> CompData = SaveInterface->GetSaveData();
            FString Prefix = Comp->GetName() + TEXT(".");
            for (auto& Elem : CompData)
            {
                RawData.Add(Prefix + Elem.Key, Elem.Value);
            }
        }
    }

    // 2. Process deltas and calculate PSTA
    bool bHasChanges = false;

    // Initialize dimensions (using persistent members to avoid heap churn)
    TArray<EPSTADimension> Dimensions = { EPSTADimension::Psychological, EPSTADimension::Social, EPSTADimension::Technical, EPSTADimension::Administrative };
    for (EPSTADimension Dim : Dimensions)
    {
        DimWeightedSums.Add(Dim, 0.0f);
        DimTotalWeights.Add(Dim, 0.0f);
        DimAnchorZeroed.Add(Dim, false);
    }

    for (auto& Elem : RawData)
    {
        if (Elem.Value.IsNumeric())
        {
            float CurrentValue = FCString::Atof(*Elem.Value);

            // PSTA Processing (Optimized O(1) Lookup)
            if (PSTAConfig)
            {
                if (const FPSTATagMapping* Mapping = PSTAConfig->GetMappingForTag(Elem.Key))
                {
                    float Normalized = PSTAConfig->NormalizeValue(*Mapping, CurrentValue);
                    DimWeightedSums[Mapping->Dimension] += Normalized * Mapping->Weight;
                    DimTotalWeights[Mapping->Dimension] += Mapping->Weight;

                    if (Mapping->bIsAnchorTag && FMath::IsNearlyZero(Normalized))
                    {
                        DimAnchorZeroed[Mapping->Dimension] = true;
                    }
                }
            }

            // Standard Delta Logging
            float* LastValuePtr = LastTruthValues.Find(Elem.Key);
            bool bShouldLog = !LastValuePtr || (FMath::Abs(CurrentValue - *LastValuePtr) >= LoggingThreshold);

            if (bShouldLog)
            {
                PendingEntries.Add(FBlackBoxEntry(Elem.Key, CurrentValue));
                LastTruthValues.Add(Elem.Key, CurrentValue);
                bHasChanges = true;
            }
        }
    }

    // 3. Calculate Final PSTA Scores
    if (PSTAConfig)
    {
        float PSS = 0.0f;
        float MinDi = 1.0f;

        for (EPSTADimension Dim : Dimensions)
        {
            float Di = 0.0f;
            if (DimAnchorZeroed[Dim])
            {
                Di = 0.0f;
            }
            else if (DimTotalWeights[Dim] > 0.0f)
            {
                Di = DimWeightedSums[Dim] / DimTotalWeights[Dim];
            }
            // else Di = 0.0f (Void Safety)

            MinDi = FMath::Min(MinDi, Di);

            // Record Di if changed
            float* LastDi = LastDimensionHealth.Find(Dim);
            if (!LastDi || FMath::Abs(Di - *LastDi) >= 0.01f)
            {
                FString Key = FString::Printf(TEXT("PSTA.Di.%d"), (uint8)Dim);
                PendingEntries.Add(FBlackBoxEntry(Key, Di));
                LastDimensionHealth.Add(Dim, Di);
                bHasChanges = true;
            }

            float Alpha = PSTAConfig->DimensionWeights.Contains(Dim) ? PSTAConfig->DimensionWeights[Dim] : 0.0f;
            PSS += Alpha * Di;
        }

        // Apply Bottleneck Law Scaling
        float Scaling = (MinDi < PSTAConfig->CriticalInstabilityThreshold) ? (MinDi / PSTAConfig->CriticalInstabilityThreshold) : 1.0f;
        PSS *= Scaling;

        if (FMath::Abs(PSS - LastPSS) >= 0.01f)
        {
            PendingEntries.Add(FBlackBoxEntry(TEXT("PSTA.PSS"), PSS));
            LastPSS = PSS;
            bHasChanges = true;
        }
    }

    // 4. Flush if we have data
    if (bHasChanges)
    {
        FlushToSubsystem();
    }
}

void USovereignBlackBoxComponent::RecordEvent(const FString& EventKey, const FString& EventDescription)
{
    PendingEntries.Add(FBlackBoxEntry(EventKey, 0.0f, EventDescription));
    FlushToSubsystem();
}

void USovereignBlackBoxComponent::IngestBlackBoxEntry(const FBlackBoxEntry& Entry)
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    // 1. Update the Vessel (Actor) via Save Interface if it's numeric telemetry
    if (!Entry.Key.IsEmpty())
    {
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Owner))
        {
            TMap<FString, FString> Data;
            Data.Add(Entry.Key, FString::SanitizeFloat(Entry.Value));
            SaveInterface->RestoreSaveData(Data);
        }
    }

    // 2. Trigger a PSTA recalculation based on the new truth
    // We don't want to record a NEW snapshot during ingestion (to avoid infinite loops)
    // but we do want to update the internal PSTA health cache.
    RecordTruthSnapshot();
}

void USovereignBlackBoxComponent::FlushToSubsystem()
{
    if (PendingEntries.Num() == 0) return;

    if (bEnableFilePersistence)
    {
        if (UWorld* World = GetWorld())
        {
            if (USovereignBlackBoxSubsystem* BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>())
            {
                BBSubsystem->RecordEntries(EntityID, PendingEntries);
            }
        }
    }

    // Always clear entries after flushing (or discarding) to prevent memory growth
    PendingEntries.Empty();
}
