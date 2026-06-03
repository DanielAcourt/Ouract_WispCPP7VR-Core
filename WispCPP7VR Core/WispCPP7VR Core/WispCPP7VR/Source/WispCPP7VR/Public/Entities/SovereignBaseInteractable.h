// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignBaseEntity.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "Interaction/SovereignSaveInterface.h"
#include "SovereignBaseInteractable.generated.h"

class USovereignSaveableEntityComponent;

/**
 * ASovereignBaseInteractable
 * The base class for non-pawn interactable objects (e.g., Save Terminals, Rocks).
 * Implements telemetry-based saving and input bridging for spirits.
 */
UCLASS(Abstract)
class WISPCPP7VR_API ASovereignBaseInteractable
    : public ASovereignBaseEntity
    , public IInteractionInterface
    , public ISovereignSaveInterface
{
    GENERATED_BODY()

public:
    ASovereignBaseInteractable();

    /* =========================
       ISovereignSaveInterface
       ========================= */
    virtual TMap<FString, FString> GetSaveData() override;
    virtual void RestoreSaveData(const TMap<FString, FString>& Data) override;

protected:
    /** Master interaction gate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Interaction")
    bool bIsInteractable = true;

public:
    /** --- IoT Telemetry (Digital Twin) --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Telemetry")
    float TemperatureCelsius = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Telemetry")
    float PhValue = 7.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Telemetry")
    float WaterDepthMM = 0.0f;

public:
    /* =========================
       Interaction Interface
       ========================= */
    virtual void OnBeginHover_Implementation() override;
    virtual void OnEndHover_Implementation() override;
    virtual bool CanInteract_Implementation(AActor* Interactor) override;
    virtual void OnInteract_Implementation(AActor* Interactor) override;
    virtual FText GetInteractableName_Implementation() override;
    virtual FString GetInteractionHint_Implementation() override;
    virtual void OnSecondaryInteract_Implementation(AActor* Interactor) override;

    /* =========================
       Possession Interface
       ======================== */
    virtual bool CanBePossessed_Implementation() override;
    virtual void RequestPossession_Implementation(AController* RequestingController) override;
    virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;
    virtual void RequestSoulEject_Implementation() override;
};
