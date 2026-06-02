// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

/*
The "Sovereign" Inheritance Chain
Think of it like a family tree where each generation adds a new capability:

AActor (Unreal Engine): Gives it a place in the world (Transform).

ASovereignBaseEntity (Your Identity Layer):
- Adds the GUID
- Adds the Saveable Component
- Registers with the Actor Registry

ASovereignBaseInteractable (Your Physical Layer):
- Adds a Static Mesh (so it exists physically)
- Implements the Interaction Interface (so it can be touched)
*/


#include "Entities/SovereignBaseInteractable.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseCharacter.h"

ASovereignBaseInteractable::ASovereignBaseInteractable()
{
    // 1. Performance: Rocks don't need to tick. 
    // If they grow, the Soul Component's timer handles it, not the Actor's tick.
    PrimaryActorTick.bCanEverTick = false;

    // 2. The Clean Pointer Logic:
    // KEY Architural NOTE DAN 25/03/2026
    // // this doubles up the logic as we have a bash mesh and an enioty mesh not good for longterm development
    // 
    // We don't create a 'BaseMesh'. We simply use the EntityMesh inherited from the parent.
    // If you need a specific name for Blueprints, use an alias, but stay in C++ reality.

    if (EntityMesh)
    {
        // 3. Collision Logic: Optimized for VR and Interaction Traces
        EntityMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

        // Block everything by default to ensure the Rock feels 'solid'
        EntityMesh->SetCollisionResponseToAllChannels(ECR_Block);

        // CRITICAL: Ensure Visibility is blocked so the Wisp's LineTrace hits it.
        EntityMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

        // 4. Visual Offset: 
        // Be careful with hardcoded offsets like -90.f. 
        // For a Rock (AActor), the root is usually at the center. 
        // Only use -90.f if this is a Character (to account for the capsule).
        if (IsA<ACharacter>())
        {
            EntityMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
        }
        else
        {
            EntityMesh->SetRelativeLocation(FVector::ZeroVector);
        }
    }

    // 5. The Soul Handshake:
    // Ensure the Soul Component is initialized. If it's not in the parent, create it here.
    if (!SaveDataComponent)
    {
        SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
    }
}

bool ASovereignBaseInteractable::CanInteract_Implementation(AActor* Interactor)
{
    return bIsInteractable && IsValid(Interactor);
}
void ASovereignBaseInteractable::OnInteract_Implementation(AActor* Interactor)
{
    // 1. Core Safety Check
    if (!CanInteract_Implementation(Interactor))
    {
        return;
    }

    // 2. The Handshake: Pass 'this' (the interactable) back to the Wisp
    if (ASovereignBaseCharacter* BaseChar = Cast<ASovereignBaseCharacter>(Interactor))
    {
        // This triggers the 'OnActorSensed' Event in your Blueprint
        BaseChar->OnActorSensed.Broadcast(this);
    }

    // 3. Feedback: Cyan for success, logging the specific names
    FString DebugMessage = FString::Printf(
        TEXT("INTERACTED: %s is now focused on %s"),
        *Interactor->GetName(),
        *GetName()
    );

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, DebugMessage);
    }

    UE_LOG(LogTemp, Log, TEXT("%s"), *DebugMessage);
}
void ASovereignBaseInteractable::OnBeginHover_Implementation()
{
    // Optional: highlight, sound cue, UI prompt
}
void ASovereignBaseInteractable::OnEndHover_Implementation()
{
    // Optional: remove highlight, stop sound
}

//Interable Name
FText ASovereignBaseInteractable::GetInteractableName_Implementation()
{
    return FText::FromString(TEXT("Interactable Object"));
}
FString ASovereignBaseInteractable::GetInteractionHint_Implementation()
{
    return TEXT("Interact");
}

void ASovereignBaseInteractable::OnSecondaryInteract_Implementation(AActor* Interactor)
{
    // Optional secondary action (long press, grip, etc.)
}

//Possession Functions
bool ASovereignBaseInteractable::CanBePossessed_Implementation()
{
    // Note: bCanBePossessed is a protected variable inherited from ASovereignBaseEntity
    return bCanBePossessed;
}

void ASovereignBaseInteractable::RequestPossession_Implementation(AController* RequestingController)
{
    if (APlayerController* PC = Cast<APlayerController>(RequestingController))
    {
        if (CanBePossessed_Implementation())
        {
            // THE BRIDGE: Instead of Possess(this), we enable input for non-pawn actors.
            this->EnableInput(PC);

            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
                    FString::Printf(TEXT("Spirit Link Established with: %s"), *GetName()));
            }

            UE_LOG(LogTemp, Warning, TEXT("Input Bridge established for non-pawn actor: %s"), *GetName());
        }
    }
}

void ASovereignBaseInteractable::RequestSoulEject_Implementation()
{
    // 1. SEVER THE INPUT BRIDGE
    // When the spirit leaves, the rock must stop listening to the player.
    this->DisableInput(GetWorld()->GetFirstPlayerController());

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange,
            FString::Printf(TEXT("Input Bridge: Severed for %s"), *GetName()));
    }

    UE_LOG(LogTemp, Log, TEXT("[%s] Input Bridge: Severed."), *GetName());
}
USceneComponent* ASovereignBaseInteractable::GetPossessionAttachmentComponent_Implementation()
{
    return BaseMesh;
}

/* =========================
   ISovereignSaveInterface
   ========================= */

TMap<FString, FString> ASovereignBaseInteractable::GetSaveData()
{
    TMap<FString, FString> Data;
    // Map internal properties to the "Telemetry." namespace for the Digital Twin
    Data.Add(TEXT("Telemetry.temp_c"), FString::SanitizeFloat(TemperatureCelsius));
    Data.Add(TEXT("Telemetry.ph_val"), FString::SanitizeFloat(PhValue));
    Data.Add(TEXT("Telemetry.water_depth_mm"), FString::SanitizeFloat(WaterDepthMM));
    return Data;
}

void ASovereignBaseInteractable::RestoreSaveData(const TMap<FString, FString>& Data)
{
    // Scrape the "suitcase" for telemetry keys and update the physical vessel
    if (const FString* Val = Data.Find(TEXT("Telemetry.temp_c")))
    {
        TemperatureCelsius = FCString::Atof(**Val);
    }

    if (const FString* Val = Data.Find(TEXT("Telemetry.ph_val")))
    {
        PhValue = FCString::Atof(**Val);
    }

    if (const FString* Val = Data.Find(TEXT("Telemetry.water_depth_mm")))
    {
        WaterDepthMM = FCString::Atof(**Val);
    }
}
