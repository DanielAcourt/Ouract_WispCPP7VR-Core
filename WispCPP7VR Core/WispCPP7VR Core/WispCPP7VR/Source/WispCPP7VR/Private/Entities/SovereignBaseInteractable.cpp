// Fill out your copyright notice in the Description page of Project Settings.
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

bool ASovereignBaseInteractable::CanBePossessed_Implementation()
{
    // Note: bCanBePossessed is a protected variable inherited from ASovereignBaseEntity
    return bCanBePossessed;
}

void ASovereignBaseInteractable::RequestPossession_Implementation(AController* RequestingController)
{
    // 1. Cast the controller to a PlayerController
    if (APlayerController* PC = Cast<APlayerController>(RequestingController))
    {
        if (CanBePossessed_Implementation())
        {
            // 2. THE BRIDGE: Instead of Possess(this), we enable input.
            // This allows the player to "drive" the rock/actor.
            this->EnableInput(PC);

            // 3. UI/Feedback Handshake
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
                    FString::Printf(TEXT("Spirit Link Established with: %s"), *GetName()));
            }

            UE_LOG(LogTemp, Warning, TEXT("Input Bridge established for non-pawn actor: %s"), *GetName());
        }
    }
}

USceneComponent* ASovereignBaseInteractable::GetPossessionAttachmentComponent_Implementation()
{
    return BaseMesh;
}
