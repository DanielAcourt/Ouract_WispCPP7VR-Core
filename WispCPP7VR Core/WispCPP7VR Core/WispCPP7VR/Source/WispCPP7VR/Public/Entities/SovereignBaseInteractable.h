// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignBaseEntity.h"
#include "Interaction/SovereignInterfaceMain.h"

#include "SovereignBaseInteractable.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class WISPCPP7VR_API ASovereignBaseInteractable
    : public ASovereignBaseEntity
    , public IInteractionInterface
{
    GENERATED_BODY()

public:
    ASovereignBaseInteractable();


protected:

    // This is what was missing!
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
    class UStaticMeshComponent* BaseMesh;

    /** Master interaction gate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Interaction")
    bool bIsInteractable = true;

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

};
