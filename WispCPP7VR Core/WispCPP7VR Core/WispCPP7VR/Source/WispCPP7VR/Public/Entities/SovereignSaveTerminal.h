// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/SovereignEntityInterface.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "SovereignSaveTerminal.generated.h"

class USovereignSaveableEntityComponent;

/**
 * 
 */
UCLASS()
class WISPCPP7VR_API ASovereignSaveTerminal : public AActor, public ISovereignEntityInterface, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ASovereignSaveTerminal();

    /** * We "Override" the Parent's interaction.
     * This tells the compiler: "Forget the debug message in the parent, do THIS instead."
     */
    virtual void OnInteract_Implementation(AActor* Interactor);

    /** We override the name so the UI says "Chronicle Stone" instead of "Interactable" */
    virtual FText GetInteractableName_Implementation();

    // NEW: Handle the "Secondary" action (e.g., Grip + Trigger)
    virtual void OnSecondaryInteract_Implementation(AActor* Interactor);

    /** * Bakes the current world state to a file immediately.
     * This creates a button in the Editor Details panel!
     * These ideally need to be editor only or deleted later
     */
    UFUNCTION(CallInEditor, Category = "Sovereign|Debug")
    void Editor_TriggerSave();

    // NEW: The Load Button for the Editor
    UFUNCTION(CallInEditor, Category = "Sovereign|Debug")
    void Editor_TriggerLoad();

    /** * Peeks into the save file and updates the displayed count
     * without actually spawning or changing anything in the garden.
     */
    UFUNCTION(CallInEditor, Category = "Sovereign|Debug")
    void Editor_RefreshSavedCount();

	// --- ISovereignEntityInterface ---
	virtual USovereignSaveableEntityComponent* GetSovereignSoul() const override;
	virtual USceneComponent* GetPrimaryMesh() const override;
	virtual void OnPossessedByWisp(AController* WispController) override;
	virtual void OnUnpossessedByWisp() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignSaveableEntityComponent* SovereignSoul;

    /** The name of the file this stone writes to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Save")
    FString TargetSlotName = TEXT("Isla_Garden_Save");

    /** Should we use JSON for this specific stone? (Allows Isla to mod this stone's output) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Save")
    bool bOverrideToJson = true;

    /** Shows how many objects were found/processed in the last operation. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Save Status")
    int32 LastOperationEntityCount = 0;
	
};
