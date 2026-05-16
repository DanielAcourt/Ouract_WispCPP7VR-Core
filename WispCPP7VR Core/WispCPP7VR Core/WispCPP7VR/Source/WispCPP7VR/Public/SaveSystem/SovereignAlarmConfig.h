// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SovereignAlarmConfig.generated.h"

/**
 * @struct FSovereignAlarmRule
 * @brief Defines the criteria for a "Safety Sentinel" alarm.
 */
USTRUCT(BlueprintType)
struct FSovereignAlarmRule
{
    GENERATED_BODY()

    /** Unique identifier for this alarm (e.g., "Iceberg_Detected"). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AlarmID;

    /** Friendly description for the user/UI. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    /**
     * The list of Meta-Tags that can trigger this alarm.
     * Used for the N-bit matrix consensus.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TriggerTags;

    /** The threshold value (normalized 0-1 if PSTA tag, or raw if telemetry). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ThresholdValue = 0.5f;

    /** If true, triggers when value < Threshold. If false, triggers when value > Threshold. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTriggerBelowThreshold = true;

    /** How many sensors from TriggerTags must agree to activate the alarm. (N-bit Matrix) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1"))
    int32 RequiredAgreementCount = 1;

    /** Time in seconds the human has to acknowledge before AI autonomy is permitted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0"))
    float GracePeriodSeconds = 10.0f;

    /** If true, the alarm remains active until manually cleared by the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRequiresAcknowledgment = true;

    /**
     * If acknowledged, the weights of the TriggerTags in the PSTA calculation
     * are multiplied by this factor to prevent "Lion Air" style persistent drag.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float AcknowledgedWeightMultiplier = 0.1f;

    FSovereignAlarmRule() {}
};

/**
 * @class USovereignAlarmConfig
 * @brief Configuration for the Sovereign Framework's Safety Sentinel.
 */
UCLASS(BlueprintType)
class WISPCPP7VR_API USovereignAlarmConfig : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Alarms")
    TArray<FSovereignAlarmRule> AlarmRules;

    /** Returns the rule for a specific AlarmID, or nullptr if not found. */
    const FSovereignAlarmRule* GetRule(const FString& AlarmID) const;
};
