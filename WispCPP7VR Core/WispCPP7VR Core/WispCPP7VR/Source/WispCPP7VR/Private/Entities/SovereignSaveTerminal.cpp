// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignSaveTerminal.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "SaveSystem/SovereignSaveManager.h" // Needed to talk to the Save Boss
#include "Kismet/GameplayStatics.h"

ASovereignSaveTerminal::ASovereignSaveTerminal()
{
	SovereignSoul = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
}

void ASovereignSaveTerminal::OnInteract_Implementation(AActor* Interactor)
{
    // 1. Call the centralized save logic
    Editor_TriggerSave();
    // Feedback for Developer: You could trigger an Effect here in BP

    UE_LOG(LogTemp, Warning, TEXT("Sovereign: Chronicle Stone activated by %s"),
        Interactor ? *Interactor->GetName() : TEXT("Unknown"));
}

void ASovereignSaveTerminal::Editor_TriggerSave()
{
    // Subsystems require a World context
    UWorld* World = GetWorld();
    if (!World) return;

    // The Sovereign Way: Access the persistent Brain (Subsystem)
    if (USaveManager* SaveManager = World->GetGameInstance()->GetSubsystem<USaveManager>())
    {
        UE_LOG(LogTemp, Warning, TEXT("Sovereign: Chronicle Stone committing to %s (JSON: %s)"),
            *TargetSlotName, bOverrideToJson ? TEXT("True") : TEXT("False"));

        // This handles both .sav (Performance) and .json (PLayers's Modding)
        SaveManager->SaveWorldState(TargetSlotName, bOverrideToJson);

        // 2. Update our public variable so the Editor shows the count
            LastOperationEntityCount = SaveManager->GetSavedEntityCount(TargetSlotName, bOverrideToJson);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Sovereign: SaveManager Subsystem missing!"), LastOperationEntityCount);;
    }
}

FText ASovereignSaveTerminal::GetInteractableName_Implementation()
{
    // This allows the Wisp/Bee HUD to show a nice localized name
    return FText::FromString("Ancient Chronicle Stone");
}

void ASovereignSaveTerminal::Editor_TriggerLoad()
{
    UWorld* World = GetWorld();
    if (!World) return;

    // Access the SaveManager Subsystem
    if (USaveManager* SaveManager = World->GetGameInstance()->GetSubsystem<USaveManager>())
    {
        UE_LOG(LogTemp, Warning, TEXT("Sovereign: Chronicle Stone Inhaling state from [%s]"), *TargetSlotName);

        // This calls the "Reification" logic we just finished!
        SaveManager->LoadWorldState(TargetSlotName, bOverrideToJson);

        // 2. Update the variable using the NEW dedicated function
        LastOperationEntityCount = SaveManager->GetSavedEntityCount(TargetSlotName, bOverrideToJson);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Sovereign Error: SaveManager not found for Loading."));
    }
}

// FIX: Ensure this is defined if you added it to the .h!
void ASovereignSaveTerminal::OnSecondaryInteract_Implementation(AActor* Interactor)
{
    Editor_TriggerLoad();
}

void ASovereignSaveTerminal::Editor_RefreshSavedCount()
{
    UWorld* World = GetWorld();
    if (!World) return;

    if (USaveManager* SaveManager = World->GetGameInstance()->GetSubsystem<USaveManager>())
    {
        // Simply update the variable by reading the file
        LastOperationEntityCount = SaveManager->GetSavedEntityCount(TargetSlotName, bOverrideToJson);

        UE_LOG(LogTemp, Log, TEXT("Sovereign: File check complete. Found %d entities in %s"),
            LastOperationEntityCount, *TargetSlotName);
    }
}

USovereignSaveableEntityComponent* ASovereignSaveTerminal::GetSovereignSoul() const
{
	return SovereignSoul;
}

USceneComponent* ASovereignSaveTerminal::GetPrimaryMesh() const
{
	return RootComponent;
}

void ASovereignSaveTerminal::OnPossessedByWisp(AController* WispController)
{
	// This actor cannot be possessed
}

void ASovereignSaveTerminal::OnUnpossessedByWisp()
{
	// This actor cannot be possessed
}
