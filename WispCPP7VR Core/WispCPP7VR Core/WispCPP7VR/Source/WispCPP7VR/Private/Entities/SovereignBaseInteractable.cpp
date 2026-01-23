// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignBaseInteractable.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

ASovereignBaseInteractable::ASovereignBaseInteractable()
{
	SovereignSoul = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

USovereignSaveableEntityComponent* ASovereignBaseInteractable::GetSovereignSoul() const
{
	return SovereignSoul;
}

USceneComponent* ASovereignBaseInteractable::GetPrimaryMesh() const
{
	return MeshComponent;
}

void ASovereignBaseInteractable::OnPossessedByWisp(AController* WispController)
{
	PossessingController = WispController;

	MovementComponent = NewObject<UFloatingPawnMovement>(this, TEXT("MovementComponent"));
	MovementComponent->RegisterComponent();

	EnableInput(WispController->GetLocalPlayer());
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (MoveAction)
		{
			EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASovereignBaseInteractable::Move);
		}
	}
}

void ASovereignBaseInteractable::OnUnpossessedByWisp()
{
	if (MovementComponent.IsValid())
	{
		MovementComponent->DestroyComponent();
	}
	DisableInput(PossessingController->GetLocalPlayer());
	PossessingController = nullptr;
}

void ASovereignBaseInteractable::Move(const FInputActionValue& Value)
{
	if (MovementComponent.IsValid())
	{
		const FVector Input = Value.Get<FVector>();
		MovementComponent->AddInputVector(GetActorForwardVector() * Input.Y);
		MovementComponent->AddInputVector(GetActorRightVector() * Input.X);
	}
}
