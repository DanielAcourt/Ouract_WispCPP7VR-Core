// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Entities/SovereignBaseCharacter.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"
#include "Components/SovereignElementComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASovereignBaseCharacter::ASovereignBaseCharacter()
{
	SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

	AttributeComponent = CreateDefaultSubobject<USovereignAttributeComponent>(TEXT("AttributeComponent"));
	QiComponent = CreateDefaultSubobject<USovereignQiComponent>(TEXT("QiComponent"));
	ElementComponent = CreateDefaultSubobject<USovereignElementComponent>(TEXT("ElementComponent"));
	ControlComponent = CreateDefaultSubobject<USovereignControllerComponent>(TEXT("ControlComponent"));

	bCanBePossessed = true;
}

void ASovereignBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASovereignBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (AActor* Target = GetSensedActor())
	{
		OnActorSensed.Broadcast(Target);
	}
}

void ASovereignBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction) EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Move);
		if (LookAction) EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Look);
		if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &ASovereignBaseCharacter::Interact);
		if (PossessAction) EIC->BindAction(PossessAction, ETriggerEvent::Started, this, &ASovereignBaseCharacter::HandlePossessionLifecycle);
	}
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
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void ASovereignBaseCharacter::Interact(const FInputActionValue& Value)
{
	AActor* Target = GetSensedActor();
	if (Target && Target->Implements<UInteractionInterface>())
	{
		IInteractionInterface::Execute_OnInteract(Target, this);
	}
}

AActor* ASovereignBaseCharacter::GetSensedActor()
{
	if (!Controller) return nullptr;
	FVector Start; FRotator Rot;
	Controller->GetPlayerViewPoint(Start, Rot);
	FHitResult Hit;
	GetWorld()->SweepSingleByChannel(Hit, Start, Start + Rot.Vector() * 500.0f, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(25.0f), FCollisionQueryParams::DefaultQueryParam);
	return Hit.GetActor();
}

void ASovereignBaseCharacter::HandlePossessionLifecycle()
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

void ASovereignBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (ControlComponent) ControlComponent->OnPossessed(NewController);
	if (APlayerController* PC = Cast<APlayerController>(NewController))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			if (DefaultMappingContext) Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ASovereignBaseCharacter::UnPossessed()
{
	if (ControlComponent) ControlComponent->OnUnpossessed();
	Super::UnPossessed();
}

void ASovereignBaseCharacter::Evolve()
{
	UE_LOG(LogTemp, Log, TEXT("Base Character Evolving..."));
}

USceneComponent* ASovereignBaseCharacter::GetPossessionAttachmentComponent_Implementation()
{
	return GetMesh();
}

AActor* ASovereignBaseCharacter::GetInhabitingSpirit_Implementation()
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

void ASovereignBaseCharacter::OnInteract_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Log, TEXT("%s interacted with Sovereign Character %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"), *GetName());
}

void ASovereignBaseCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = FGameplayTagContainer();
	if (SaveDataComponent && SaveDataComponent->SpeciesTag.IsValid())
	{
		TagContainer.AddTag(SaveDataComponent->SpeciesTag);
	}
}
