// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignBaseEntity.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "Interaction/SovereignSaveInterface.h"
#include "SovereignBaseInteractable.generated.h"

class USovereignSaveableEntityComponent;

// 1. Setup the Trace for EVERYTHING Sovereign



/**
 * 
 */
UCLASS(Abstract)
class WISPCPP7VR_API ASovereignBaseInteractable
    : public ASovereignBaseEntity
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

    // This is what was missing!
    UPROPERTY(BlueprintReadOnly, Category = "Sovereign|Components")
    class UStaticMeshComponent* BaseMesh;
    // this needs testing this might not be the smartest way to do this as the default pawn come with a standard base mesh.

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

    // there is not controller?

public:
    /* =========================
       Interaction Interface
       ========================= */

       /** Hover start (UI highlight, sound cue, etc.) */
    virtual void OnBeginHover_Implementation() override;

    /** Hover end */
    virtual void OnEndHover_Implementation() override;

    /**
     * Global interaction check.
     * Called BEFORE OnInteract.
     */
    virtual bool CanInteract_Implementation(AActor* Interactor) override;

    /**
     * Primary interaction.
     * Children override this for behavior.
     */
    virtual void OnInteract_Implementation(AActor* Interactor) override;

    /** Display name for UI */
    virtual FText GetInteractableName_Implementation() override;

    /** Short hint (e.g. "Save", "Pick Up", "Talk") */
    virtual FString GetInteractionHint_Implementation() override;

    /** Optional secondary interaction */
    virtual void OnSecondaryInteract_Implementation(AActor* Interactor) override;

    /* =========================
       Possession Interface
       ========================= */

    /** Can this entity be possessed? */
    virtual bool CanBePossessed_Implementation() override;

    /** Possess this entity */
    virtual void RequestPossession_Implementation(AController* RequestingController) override;

    /** Get the component to attach to */
    virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;

    /** Cleanup when a soul leaves the vessel */
    virtual void RequestSoulEject_Implementation() override;

};
