// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

#include "Entities/SovereignBaseCharacter.h"
#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"
#include "Components/SovereignElementComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "Entities/SovereignSaveableEntityComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASovereignBaseCharacter::ASovereignBaseCharacter()
{
	// 2. THE SOUL (SAVE SYSTEM)
	SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

	// 3. PHYSICAL MESH
	EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntityMesh"));
	if (GetMesh())
	{
		EntityMesh->SetupAttachment(GetMesh());
	}

	bCanBePossessed = true;
	EntityMesh->SetCollisionProfileName(TEXT("BlockAll"));

	AttributeComponent = CreateDefaultSubobject<USovereignAttributeComponent>(TEXT("AttributeComponent"));
	QiComponent = CreateDefaultSubobject<USovereignQiComponent>(TEXT("QiComponent"));
	ElementComponent = CreateDefaultSubobject<USovereignElementComponent>(TEXT("ElementComponent"));
	ControlComponent = CreateDefaultSubobject<USovereignControllerComponent>(TEXT("ControlComponent"));
}

void ASovereignBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (SaveDataComponent)
	{
		SaveDataComponent->InitializeSoul();
	}
}

void ASovereignBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetSensedActor();
}

void ASovereignBaseCharacter::Evolve()
{
	Super::Evolve();
	UE_LOG(LogTemp, Log, TEXT("Base Character Evolving..."));
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
	const float Distance = 5.0f;
	FVector MoveDelta = (Forward * Input.Y * Distance) + (Right * Input.X * Distance) + (FVector::UpVector * Input.Z * Distance);
	AddActorWorldOffset(MoveDelta, true);
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->Velocity = FVector::ZeroVector;
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
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

void ASovereignBaseCharacter::Interact(const FInputActionValue& Value)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("VESSEL: INTERACT TRIGGERED"));
	AActor* Target = GetSensedActor();
	if (Target)
	{
		OnActorSensed.Broadcast(Target);
		if (Target->Implements<UInteractionInterface>())
		{
			IInteractionInterface::Execute_OnInteract(Target, this);
		}
	}
}

void ASovereignBaseCharacter::HandlePossessionLifecycle()
{
	AActor* Spirit = IInteractionInterface::Execute_GetInhabitingSpirit(this);
	if (Spirit)
	{
		ASovereignPlayerWisp* Wisp = Cast<ASovereignPlayerWisp>(Spirit);
		if (Wisp)
		{
			UE_LOG(LogTemp, Warning, TEXT("Sovereign: Soul Eject initiated by vessel %s"), *GetName());
			Wisp->EjectFromHost();
			return;
		}
	}
}

AActor* ASovereignBaseCharacter::GetSensedActor()
{
	if (!Controller) return nullptr;
	FVector Start; FRotator Rot;
	Controller->GetPlayerViewPoint(Start, Rot);
	const float Range = 500.0f; const float Radius = 25.0f;
	FVector End = Start + (Rot.Vector() * Range);
	FHitResult Hit; FCollisionQueryParams Params; Params.AddIgnoredActor(this);
	bool bHit = GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(Radius), Params);
	AActor* HitActor = bHit ? Hit.GetActor() : nullptr;
	if (HitActor) { OnActorSensed.Broadcast(HitActor); }
	return HitActor;
}

void ASovereignBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (ControlComponent) { ControlComponent->OnPossessed(NewController); }
	if (APlayerController* PC = Cast<APlayerController>(NewController))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			if (DefaultMappingContext) { Subsystem->AddMappingContext(DefaultMappingContext, 0); }
		}
	}
}

void ASovereignBaseCharacter::UnPossessed()
{
	if (ControlComponent) { ControlComponent->OnUnpossessed(); }
	Super::UnPossessed();
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
			if (IInteractionInterface::Execute_IsSpiritEntity(Actor)) { return Actor; }
		}
	}
	for (AActor* Actor : AttachedActors)
	{
		if (Actor && Actor->IsA(ASovereignPlayerWisp::StaticClass())) { return Actor; }
	}
	return nullptr;
}

void ASovereignBaseCharacter::OnInteract_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Log, TEXT("%s interacted with Sovereign Character %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"), *GetName());
}

void ASovereignBaseCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = FGameplayTagContainer(); // Initialize
	if (SaveDataComponent && SaveDataComponent->SpeciesTag.IsValid())
	{
		TagContainer.AddTag(SaveDataComponent->SpeciesTag);
	}
}
