// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#pragma once

// // [J] The 07 Bridge Subsystem: Connecting the simulation soul to the architectural engine. 2025-06-18

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "SovereignBridgeSubsystem.generated.h"

/**
 * USovereignBridgeSubsystem: Manages communication between Unreal and the Iron Officer Bridge.
 * Implements the 07 Check-In and Telemetry protocols.
 */
UCLASS()
class WISPCPP7VR_API USovereignBridgeSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /**
     * Initiates the 07 Check-In protocol.
     * Performs a handshake and verifies bridge connectivity.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|Bridge")
    void Perform07CheckIn();

    /**
     * Pushes BlackBox data and a PSTA score to the bridge.
     * @param EntityID      The ID of the entity originating the data.
     * @param PSTAScore     The calculated PSTA viability score.
     * @param BlackBoxJson  JSON string containing metadata from the BlackBox.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|Bridge")
    void PushBlackBoxTelemetry(const FGuid& EntityID, float PSTAScore, const FString& BlackBoxJson);

private:
    /** Internal struct to buffer telemetry while handshake is pending */
    struct FPendingTelemetry
    {
        FGuid EntityID;
        float PSTAScore;
        FString BlackBoxJson;
    };

    TArray<FPendingTelemetry> TelemetryQueue;

    /** Flushes buffered telemetry to the bridge */
    void FlushTelemetryQueue();
    /** Path to bridge_config.json in Saved/Config/ */
    FString GetConfigPath() const;

    /** Loads configuration from disk */
    void LoadConfiguration();

    /** Internal HTTP response handler for Check-In */
    void OnCheckInResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    /** Internal HTTP response handler for Telemetry */
    void OnTelemetryResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    /** Bridge Base URL (e.g., http://localhost:8000) */
    UPROPERTY()
    FString BridgeBaseUrl = TEXT("http://127.0.0.1:8000");

    /** Indicates if the handshake has been established */
    UPROPERTY()
    bool bHandshakeActive = false;
};
