// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "Entities/SovereignBlackBoxComponent.h"
#include "Interaction/SovereignSaveInterface.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "Subsystems/SovereignBlackBoxHeartbeat.h"
#include "SaveSystem/SovereignPSTAConfig.h"
#include "SaveSystem/SovereignAlarmConfig.h"
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

    // A mapping to track which tags contribute to which alarms for N-bit consensus
    TMap<FString, int32> AlarmAgreementCounts;

    for (auto& Elem : RawData)
    {
        if (Elem.Value.IsNumeric())
        {
            float CurrentValue = FCString::Atof(*Elem.Value);

            // 1. Alarm/Threshold Processing (N-bit Matrix Consensus)
            if (AlarmConfig)
            {
                for (const FSovereignAlarmRule& Rule : AlarmConfig->AlarmRules)
                {
                    if (Rule.TriggerTags.Contains(Elem.Key))
                    {
                        bool bExceeds = Rule.bTriggerBelowThreshold ? (CurrentValue < Rule.ThresholdValue) : (CurrentValue > Rule.ThresholdValue);
                        if (bExceeds)
                        {
                            AlarmAgreementCounts.FindOrAdd(Rule.AlarmID)++;
                        }
                    }
                }
            }

            // 2. PSTA Processing (Optimized O(1) Lookup)
            if (PSTAConfig)
            {
                if (const FPSTATagMapping* Mapping = PSTAConfig->GetMappingForTag(Elem.Key))
                {
                    float Normalized = PSTAConfig->NormalizeValue(*Mapping, CurrentValue);
                    float FinalWeight = Mapping->Weight;

                    // Apply Acknowledged Weight Multiplier if this tag is part of an acknowledged alarm
                    if (AlarmConfig)
                    {
                        for (const FString& AckAlarmID : AcknowledgedAlarms)
                        {
                            if (const FSovereignAlarmRule* Rule = AlarmConfig->GetRule(AckAlarmID))
                            {
                                if (Rule->TriggerTags.Contains(Elem.Key))
                                {
                                    FinalWeight *= Rule->AcknowledgedWeightMultiplier;
                                }
                            }
                        }
                    }

                    DimWeightedSums[Mapping->Dimension] += Normalized * FinalWeight;
                    DimTotalWeights[Mapping->Dimension] += FinalWeight;

                    if (Mapping->bIsAnchorTag && FMath::IsNearlyZero(Normalized))
                    {
                        DimAnchorZeroed[Mapping->Dimension] = true;
                    }
                }
            }

            // 3. Standard Delta Logging
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

    // 3. Process Alarms based on Consensus
    if (AlarmConfig)
    {
        for (const FSovereignAlarmRule& Rule : AlarmConfig->AlarmRules)
        {
            int32* Agreement = AlarmAgreementCounts.Find(Rule.AlarmID);
            bool bShouldBeActive = Agreement && (*Agreement >= Rule.RequiredAgreementCount);

            if (bShouldBeActive && !ActiveAlarms.Contains(Rule.AlarmID))
            {
                // Trigger Alarm
                ActiveAlarms.Add(Rule.AlarmID);
                AlarmTriggerTimestamps.Add(Rule.AlarmID, FDateTime::Now());
                RecordEvent(TEXT("Event.Alarm.Triggered"), FString::Printf(TEXT("Alarm: %s - %s"), *Rule.AlarmID, *Rule.Description));
                bHasChanges = true;
            }
            else if (!bShouldBeActive && ActiveAlarms.Contains(Rule.AlarmID))
            {
                // Clear Alarm (Auto-clear if rule allows or if threshold no longer met)
                if (!Rule.bRequiresAcknowledgment || AcknowledgedAlarms.Contains(Rule.AlarmID))
                {
                    ActiveAlarms.Remove(Rule.AlarmID);
                    AcknowledgedAlarms.Remove(Rule.AlarmID);
                    AlarmTriggerTimestamps.Remove(Rule.AlarmID);
                    RecordEvent(TEXT("Event.Alarm.Cleared"), Rule.AlarmID);
                    bHasChanges = true;
                }
            }
        }
    }

    // 4. Calculate Final PSTA Scores
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

void USovereignBlackBoxComponent::AcknowledgeAlarm(const FString& AlarmID)
{
    if (ActiveAlarms.Contains(AlarmID) && !AcknowledgedAlarms.Contains(AlarmID))
    {
        AcknowledgedAlarms.Add(AlarmID);
        RecordEvent(TEXT("Event.Alarm.Acknowledged"), AlarmID);

        // Immediate PSTA recalculation to apply weight reduction
        RecordTruthSnapshot();
    }
}

bool USovereignBlackBoxComponent::IsAlarmActiveAndUnacknowledged(const FString& AlarmID) const
{
    if (!ActiveAlarms.Contains(AlarmID)) return false;
    if (AcknowledgedAlarms.Contains(AlarmID)) return false;

    // Check Grace Period
    if (AlarmConfig)
    {
        if (const FSovereignAlarmRule* Rule = AlarmConfig->GetRule(AlarmID))
        {
            if (const FDateTime* TriggerTime = AlarmTriggerTimestamps.Find(AlarmID))
            {
                FTimespan Elapsed = FDateTime::Now() - *TriggerTime;
                if (Elapsed.GetTotalSeconds() < Rule->GracePeriodSeconds)
                {
                    return false; // Still in Grace Period, AI should not act yet
                }
            }
        }
    }

    return true; // Active, Unacknowledged, and Grace Period expired
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

    if (UWorld* World = GetWorld())
    {
        if (USovereignBlackBoxSubsystem* BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>())
        {
            BBSubsystem->RecordEntries(EntityID, PendingEntries);
            PendingEntries.Empty();
        }
    }
}
