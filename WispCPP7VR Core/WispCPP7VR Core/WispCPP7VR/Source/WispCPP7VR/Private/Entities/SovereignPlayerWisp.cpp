// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignPlayerWisp.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h" // <--- CRITICAL FOR THE TRACE
#include "Components/WidgetComponent.h" // Add this include!
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DrawDebugHelpers.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/SovereignEntityInterface.h"
#include "Entities/SovereignSaveableEntityComponent.h"


ASovereignPlayerWisp::ASovereignPlayerWisp()
{
	SpiritEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SpiritEffect"));
	SpiritEffect->SetupAttachment(RootComponent);
}

void ASovereignPlayerWisp::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the Wisp with "Spirit" stats
	if (SovereignSoul)
	{
		SovereignSoul->Health = 100.f;
		SovereignSoul->MaxHealth = 100.f;
		SovereignSoul->Qi = 500.f;
		SovereignSoul->MaxQi = 500.f;
	}
}

void ASovereignPlayerWisp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Special Wisp Drain: Being in the world costs a tiny bit of Qi every second
	if (SovereignSoul && !SovereignSoul->GameplayTags.HasTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit"))))
	{
		SovereignSoul->Qi -= QiDrainRate * DeltaTime;
	}
}

void ASovereignPlayerWisp::AttemptPossession()
{
	if (CurrentlyPossessedVessel.IsValid())
	{
		EndPossession();
		return;
	}
	// 1. Setup the Trace parameters
	FVector Start = GetActorLocation();
	FVector End = Start + (GetActorForwardVector() * InteractionDistance);
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult OutHit;

	// 2. Perform the Trace
	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(), Start, End, PossessionTraceRadius, ObjectTypes, false,
		ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true
	);

	if (bHit && OutHit.GetActor())
	{
		if (OutHit.GetActor()->Implements<USovereignEntityInterface>())
		{
			InitiatePossession(OutHit.GetActor());
		}
	}
}

void ASovereignPlayerWisp::InitiatePossession(AActor* TargetVessel)
{
	if (!TargetVessel) return;

	CurrentlyPossessedVessel = TargetVessel;

	ISovereignEntityInterface::Execute_OnPossessedByWisp(TargetVessel, GetController());

	AttachToVessel(TargetVessel);

	// Start Qi Drain
	GetWorldTimerManager().SetTimer(QiDrainTimerHandle, this, &ASovereignPlayerWisp::DrainPossessionQi, 1.0f, true);
}

void ASovereignPlayerWisp::AttachToVessel(AActor* Vessel)
{
	if (!Vessel) return;

	USceneComponent* TargetComponent = Cast<USceneComponent>(Vessel->GetRootComponent());
	if (ISovereignEntityInterface::Execute_GetPrimaryMesh(Vessel))
	{
		TargetComponent = ISovereignEntityInterface::Execute_GetPrimaryMesh(Vessel);
	}

	// Attach to the Vessel's capsule component
	AttachToComponent(TargetComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, NAME_None);

	// Hide and disable collision
	SetActorHiddenInGame(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Add the state tag
	SovereignSoul->GameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit")));
}

void ASovereignPlayerWisp::DrainPossessionQi()
{
	if (SovereignSoul && CurrentlyPossessedVessel.IsValid())
	{
		SovereignSoul->Qi -= QiDrainRate;
	}
	else
	{
		// If the vessel is invalid, stop the timer
		GetWorldTimerManager().ClearTimer(QiDrainTimerHandle);
	}
}

void ASovereignPlayerWisp::EndPossession()
{
	if (!CurrentlyPossessedVessel.IsValid()) return;

	// Tell the vessel it is no longer possessed
	ISovereignEntityInterface::Execute_OnUnpossessedByWisp(CurrentlyPossessedVessel.Get());

	// Stop the Qi Drain
	GetWorldTimerManager().ClearTimer(QiDrainTimerHandle);

	// Calculate a safe ejection point
	FVector EjectionPoint = CurrentlyPossessedVessel->GetActorLocation() + (CurrentlyPossessedVessel->GetActorForwardVector() * 150.0f);
	FHitResult HitResult;
	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		CurrentlyPossessedVessel->GetActorLocation(),
		EjectionPoint,
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(GetCapsuleComponent()->GetScaledCapsuleRadius())
	);

	if (bHit)
	{
		EjectionPoint = HitResult.ImpactPoint;
	}

	// Detach and reset wisp state
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(EjectionPoint);
	SetActorHiddenInGame(false);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SovereignSoul->GameplayTags.RemoveTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit")));

	// Re-possess the wisp
	AController* OldController = CurrentlyPossessedVessel->GetController();
	if (OldController)
	{
		OldController->Possess(this);
	}

	// Clear the reference
	CurrentlyPossessedVessel = nullptr;
}


void ASovereignPlayerWisp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind possession action
		if (PossessAction)
		{
			EIC->BindAction(PossessAction, ETriggerEvent::Triggered, this, &ASovereignPlayerWisp::AttemptPossession);
		}
	}
}

void ASovereignPlayerWisp::Interact(const FInputActionValue& Value)
{
	// 1. ARCHITECT TRUTH: Run the Parent logic first.
	// This ensures any base-level logging or variable clearing happens.
	Super::Interact(Value);

	if (!GetWorld()) return;

	// 2. CALCULATE PRECISION VECTOR
	// InteractionDistance should be defined in your header (e.g., 500.0f)
	FVector Start = GetActorLocation();
	FVector ViewDir = GetControlRotation().Vector();
	FVector End = Start + (ViewDir * InteractionDistance);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	// 3. EXECUTE LINE TRACE
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,
		Params
	);

	// 4. THE INTERFACE HANDSHAKE
	if (bHit && HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();

		// Check if the actor is a Sovereign Interactable (using the Interface)
		if (HitActor->Implements<UInteractionInterface>())
		{
			// This line is the "Spark" -> It calls OnInteract_Implementation in C++
			// which then calls the Broadcast that fires your Red Blueprint Node.
			IInteractionInterface::Execute_OnInteract(HitActor, this);

			// SUCCESS DEBUG: Draw a Green Sphere where we hit
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.f, 12, FColor::Cyan, false, 2.0f);

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan,
					FString::Printf(TEXT("Sensed: %s"), *HitActor->GetName()));
		}
		else
		{
			// Hit something, but it's not interactable (like a wall)
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.f, 8, FColor::Red, false, 1.0f);
		}
	}
	else
	{
		// Total Miss: Draw a thin red line to show where you aimed
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 1.0f);
	}
}
