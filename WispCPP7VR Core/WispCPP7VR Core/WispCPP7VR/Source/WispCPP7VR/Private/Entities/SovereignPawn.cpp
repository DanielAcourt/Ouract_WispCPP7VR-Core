// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Entities/SovereignPawn.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignPlayerWisp.h"
#include "GameFramework/FloatingPawnMovementComponent.h"

ASovereignPawn::ASovereignPawn()
{
	SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

	// Add a basic movement component so pawns can move when possessed
	CreateDefaultSubobject<UFloatingPawnMovementComponent>(TEXT("MovementComponent"));

	bCanBePossessed = true;
}

void ASovereignPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ASovereignPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Bind movement for possessed pawns
	PlayerInputComponent->BindAxis("MoveForward", this, &ASovereignPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASovereignPawn::MoveRight);
}

void ASovereignPawn::MoveForward(float Value)
{
	if (Value != 0.0f) AddMovementInput(GetActorForwardVector(), Value);
}

void ASovereignPawn::MoveRight(float Value)
{
	if (Value != 0.0f) AddMovementInput(GetActorRightVector(), Value);
}

void ASovereignPawn::OnInteract_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Log, TEXT("%s interacted with Sovereign Pawn %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"), *GetName());
}

AActor* ASovereignPawn::GetInhabitingSpirit_Implementation()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors, true);
	for (AActor* Actor : AttachedActors)
	{
		if (Actor && Actor->Implements<UInteractionInterface>())
		{
			if (IInteractionInterface::Execute_IsSpiritEntity(Actor)) return Actor;
		}
	}
	return nullptr;
}

USceneComponent* ASovereignPawn::GetPossessionAttachmentComponent_Implementation()
{
	return GetRootComponent();
}

void ASovereignPawn::HandlePossessionLifecycle()
{
	AActor* Spirit = IInteractionInterface::Execute_GetInhabitingSpirit(this);
	if (Spirit)
	{
		if (ASovereignPlayerWisp* Wisp = Cast<ASovereignPlayerWisp>(Spirit))
		{
			Wisp->EjectFromHost();
		}
	}
}

void ASovereignPawn::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = FGameplayTagContainer();
	if (SaveDataComponent && SaveDataComponent->SpeciesTag.IsValid())
	{
		TagContainer.AddTag(SaveDataComponent->SpeciesTag);
	}
}
