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
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseCharacter.h"

// The constructor
ASovereignBaseInteractable::ASovereignBaseInteractable()
{
    PrimaryActorTick.bCanEverTick = false;

    // --- THE FIX ---
    // Instead of creating a new mesh, we just point to the one the parent made.
    // EntityMesh is inherited from ASovereignBaseEntity.
    BaseMesh = EntityMesh;

    // Now, anything we do to BaseMesh is actually happening to EntityMesh!
    if (BaseMesh)
    {
        // No need for SetupAttachment here because the Parent 
        // constructor already attached EntityMesh to the Root!

        BaseMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        BaseMesh->SetCollisionResponseToAllChannels(ECR_Block);
        BaseMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
        BaseMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);

        // Use the same location offset as the parent
        BaseMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
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
    if (RequestingController && CanBePossessed_Implementation())
    {
        // Unpossess the current pawn
        if (APawn* CurrentPawn = RequestingController->GetPawn())
        {
            RequestingController->UnPossess();
        }

        // Possess this entity
        RequestingController->Possess(this);
    }
}

USceneComponent* ASovereignBaseInteractable::GetPossessionAttachmentComponent_Implementation()
{
    return BaseMesh;
}
