// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SaveSystem/SovereignGameData.h"
#include "SovereignBlackBoxHeartbeat.generated.h"

class USovereignBlackBoxComponent;

/**
 * @struct FBlackBoxHeartbeatEntry
 * @brief Internal entry for tracking a component's pulse.
 */
struct FBlackBoxHeartbeatEntry
{
    TWeakObjectPtr<USovereignBlackBoxComponent> Component;
    float TimeSinceLastSnapshot = 0.0f;

    FBlackBoxHeartbeatEntry() : Component(nullptr) {}
    FBlackBoxHeartbeatEntry(USovereignBlackBoxComponent* InComp) : Component(InComp) {}
};

/**
 * @class USovereignBlackBoxHeartbeat
 * @brief Centralized "Sovereign Pulse" for Black Box telemetry.
 * Inherits from UTickableWorldSubsystem to provide high-performance scheduled snapshots.
 */
UCLASS()
class WISPCPP7VR_API USovereignBlackBoxHeartbeat : public UTickableWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // FTickableGameObject Interface
    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;

    /** Registers a component for the heartbeat. */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void RegisterComponent(USovereignBlackBoxComponent* Component, EUpdateFrequency Frequency);

    /** Unregisters a component. */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void UnregisterComponent(USovereignBlackBoxComponent* Component);

    /** Forces all registered components to record a snapshot immediately. */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|BlackBox")
    void ForceHeartbeat();

private:
    /** Components grouped by their pulse frequency for O(N) tick performance. */
    TMap<EUpdateFrequency, TArray<FBlackBoxHeartbeatEntry>> PulseGroups;

    /** Pre-defined intervals for each frequency. */
    TMap<EUpdateFrequency, float> Intervals;

    void InitializeIntervals();
    void CleanupDeadComponents();

    float LastCleanupTime = 0.0f;
};
