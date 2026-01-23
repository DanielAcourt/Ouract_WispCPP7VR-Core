// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignPawn.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

ASovereignPawn::ASovereignPawn()
{
	SovereignSoul = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
}

USovereignSaveableEntityComponent* ASovereignPawn::GetSovereignSoul() const
{
	return SovereignSoul;
}

USceneComponent* ASovereignPawn::GetPrimaryMesh() const
{
	return RootComponent;
}

void ASovereignPawn::OnPossessedByWisp(AController* WispController)
{
	// A Pawn can be possessed directly
	WispController->Possess(this);
}

void ASovereignPawn::OnUnpossessedByWisp()
{
	// Nothing to do here
}
