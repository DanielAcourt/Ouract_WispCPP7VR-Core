// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignBaseCharacter.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASovereignBaseCharacter::ASovereignBaseCharacter()
{
	SovereignSoul = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
	bUseControllerRotationYaw = false;
}

void ASovereignBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
			{
				if (DefaultMappingContext)
				{
					Subsystem->RemoveMappingContext(DefaultMappingContext);
					Subsystem->AddMappingContext(DefaultMappingContext, 0);
				}
			}
		}
	}
}

void ASovereignBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Move);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Look);
	}
}

void ASovereignBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USovereignSaveableEntityComponent* ASovereignBaseCharacter::GetSovereignSoul() const
{
	return SovereignSoul;
}

USceneComponent* ASovereignBaseCharacter::GetPrimaryMesh() const
{
	return GetMesh();
}

void ASovereignBaseCharacter::OnPossessedByWisp(AController* WispController)
{
	WispController->Possess(this);
}

void ASovereignBaseCharacter::OnUnpossessedByWisp()
{
	// Nothing to do here
}

void ASovereignBaseCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	const FVector Input = Value.Get<FVector>();
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(Forward, Input.Y);
	AddMovementInput(Right, Input.X);
}

void ASovereignBaseCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
