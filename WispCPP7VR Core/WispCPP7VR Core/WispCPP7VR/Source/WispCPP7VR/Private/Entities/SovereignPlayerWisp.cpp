// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"
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

ASovereignPlayerWisp::ASovereignPlayerWisp()
{
	// Force the Movement Component to link to your Capsule
	GetCharacterMovement()->SetUpdatedComponent(RootComponent);

	// 1. Setup the Visuals
	SpiritEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SpiritEffect"));
	SpiritEffect->SetupAttachment(RootComponent);

	// 2. Flying Movement (Spirit style)
	GetCharacterMovement()->DefaultLandMovementMode = MOVE_Flying;

	// Ensure we are in Flying mode immediately
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);

	// The 1% Architect values for a snappy spirit
	GetCharacterMovement()->MaxAcceleration = 10000.0f; // Extremely high to bypass friction
	GetCharacterMovement()->MaxFlySpeed = 1200.0f;
	GetCharacterMovement()->BrakingDecelerationFlying = 2000.0f;

	// Ghostly settings
	GetCharacterMovement()->bCheatFlying = true;
	GetCharacterMovement()->GravityScale = 0.0f;


	// 3. Ghostly Physics
	ConfigureSpiritPhysics();
}

void ASovereignPlayerWisp::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the Wisp with "Spirit" stats
	// We access these from the parent ASovereignBaseCharacter
	if (AttributeComponent)
	{
		AttributeComponent->Strength = 1;      // Spirit cannot lift rocks
		AttributeComponent->Constitution = 5;  // Spirit is fragile if hit by magic
		AttributeComponent->Intelligence = 25; // Spirit is pure mind

		// Wisps are eternal energy; they don't hunger for meat
		AttributeComponent->Hunger = 100.0f;
	}

	if (QiComponent)
	{
		// A Wisp is literally made of Qi
		QiComponent->MaxQiCapacity = 500.0f;
		QiComponent->CurrentQi = 500.0f;
		QiComponent->QiPurity = 0.8f; // Very pure by default
	}
}

void ASovereignPlayerWisp::ConfigureSpiritPhysics()
{
	// Don't use ECR_Ignore; use ECR_Overlap
	//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//GetCaps-uleComponent()->SetCollisionResponseToAllChannels(ECR_Overlap);

	// Block only the world so you don't fly through mountains
	//GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	// Allow the wisp to pass through most things, but stay within world bounds
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	// No Gravity for the Soul
	GetCharacterMovement()->GravityScale = 0.0f;
}

void ASovereignPlayerWisp::Tick(float DeltaTime)
{
	if (GameplayTags.HasTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit"))))
	{
		return;
	}
	Super::Tick(DeltaTime);

	// Special Wisp Drain: Being in the world costs a tiny bit of Qi every second
	if (QiComponent)
	{
		QiComponent->SpendQi(QiDrainRate * DeltaTime);
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
		ASovereignBaseCharacter* HitCharacter = Cast<ASovereignBaseCharacter>(OutHit.GetActor());
		if (HitCharacter)
		{
			InitiatePossession(HitCharacter);
		}
	}
}

void ASovereignPlayerWisp::InitiatePossession(ASovereignBaseCharacter* TargetVessel)
{
	if (!TargetVessel) return;

	CurrentlyPossessedVessel = TargetVessel;

	// Wisp-centric logic: Wisp tells the Vessel it's about to be possessed
	TargetVessel->BeginPossessionBy(this);

	AController* CurrentController = GetController();
	if (CurrentController)
	{
		CurrentController->Possess(TargetVessel);
	}

	AttachToVessel(TargetVessel);

	// Start Qi Drain
	GetWorldTimerManager().SetTimer(QiDrainTimerHandle, this, &ASovereignPlayerWisp::DrainPossessionQi, 1.0f, true);
}

void ASovereignPlayerWisp::AttachToVessel(ASovereignBaseCharacter* Vessel)
{
	if (!Vessel) return;

	// Attach to the Vessel's capsule component
	AttachToComponent(Vessel->GetCapsuleComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, NAME_None);

	// Hide and disable collision
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	// Add the state tag
	GameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit")));
}

void ASovereignPlayerWisp::DrainPossessionQi()
{
	if (QiComponent && CurrentlyPossessedVessel.IsValid())
	{
		// You can add more complex logic here based on the vessel's tags
		QiComponent->SpendQi(QiDrainRate);
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

	// Detach and reset state
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(EjectionPoint);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	GameplayTags.RemoveTag(FGameplayTag::RequestGameplayTag(FName("State.Possession.IsAttachedSpirit")));

	// Return the controller to the wisp
	AController* VesselController = CurrentlyPossessedVessel->GetController();
	if (VesselController)
	{
		VesselController->Possess(this);
	}

	// Clear the reference
	CurrentlyPossessedVessel = nullptr;
}


void ASovereignPlayerWisp::Evolve()
{
	// Call the parent Evolve first (if it has logic)
	Super::Evolve();

	// Wisp-specific evolution logic (e.g., change particle color)
	UE_LOG(LogTemp, Warning, TEXT("The Player Spirit is evolving to a higher density!"));
}

void ASovereignPlayerWisp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// 1. THIS IS THE KEY: Call the Base version first!
	// This binds Move, Look, and the Base Interact automatically.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 2. Now add Wisp-specific bindings if you have any (like AttemptPossession)
	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
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

// Ensure your bridge function looks like this:
void ASovereignPlayerWisp::EnhancedInteract(const FInputActionValue& Value)
{
	Interact(Value); // This now links correctly to the function above
}
