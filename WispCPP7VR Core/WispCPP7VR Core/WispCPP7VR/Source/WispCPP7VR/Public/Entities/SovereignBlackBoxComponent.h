// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "SaveSystem/SovereignGameData.h"
#include "SaveSystem/SovereignPSTAConfig.h"
#include "SovereignBlackBoxComponent.generated.h"

/**
 * @class USovereignBlackBoxComponent
 * @brief An "Officer-Level" extension of the Soul.
 * Implements delta-based logging for high-fidelity data survivability.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignBlackBoxComponent : public USovereignSaveableEntityComponent
{
    GENERATED_BODY()

public:
    USovereignBlackBoxComponent();

    /**
     * Scans current telemetry and commits to the Black Box if thresholds are exceeded.
     * Called via heartbeat or manual trigger.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void RecordTruthSnapshot();

    /** Manually record a string-based event. */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void RecordEvent(const FString& EventKey, const FString& EventDescription);

    /**
     * Human-in-the-loop: Acknowledge an active alarm.
     * Reduces the weight of triggering sensors and prevents autonomous steering.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox|Alarms")
    void AcknowledgeAlarm(const FString& AlarmID);

    /** Returns true if an alarm is active but not yet acknowledged. */
    UFUNCTION(BlueprintPure, Category = "Sovereign|BlackBox|Alarms")
    bool IsAlarmActiveAndUnacknowledged(const FString& AlarmID) const;

    /**
     * TRUTH INGESTION: Replays an external Black Box entry into the local actor state.
     * Used by the "Digital Museum" to render/verify models from external telemetry.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void IngestBlackBoxEntry(const FBlackBoxEntry& Entry);

    /** PSTA Math Configuration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|BlackBox|PSTA")
    class USovereignPSTAConfig* PSTAConfig;

    /** Alarm and Threshold Configuration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|BlackBox|Alarms")
    class USovereignAlarmConfig* AlarmConfig;

    /** How often this component records snapshots. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|BlackBox")
    EUpdateFrequency UpdateFrequency = EUpdateFrequency::Standard;

protected:
    /** The sensitivity for delta-based logging. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|BlackBox")
    float LoggingThreshold = 0.2f;

    /** Internal cache for PSTA health values to track deltas. */
    TMap<EPSTADimension, float> LastDimensionHealth;
    float LastPSS = -1.0f;

    // Persistent maps to avoid heap churn in RecordTruthSnapshot
    TMap<EPSTADimension, float> DimWeightedSums;
    TMap<EPSTADimension, float> DimTotalWeights;
    TMap<EPSTADimension, bool> DimAnchorZeroed;

    /** Internal cache to track the last committed values. */
    UPROPERTY(VisibleAnywhere, Category = "Sovereign|BlackBox")
    TMap<FString, float> LastTruthValues;

    /** Set of currently active Alarms. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|BlackBox|Alarms")
    TSet<FString> ActiveAlarms;

    /** Set of Alarms that have been acknowledged by a human. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|BlackBox|Alarms")
    TSet<FString> AcknowledgedAlarms;

    /** Timestamp of when an alarm was first triggered. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|BlackBox|Alarms")
    TMap<FString, FDateTime> AlarmTriggerTimestamps;

    /** History of events since the last flush. */
    TArray<FBlackBoxEntry> PendingEntries;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    /** Helper to flush entries to the Black Box Subsystem. */
    void FlushToSubsystem();
};
