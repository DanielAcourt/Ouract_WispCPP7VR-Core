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
	//GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Overlap);

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
	Super::Tick(DeltaTime);

	// Special Wisp Drain: Being in the world costs a tiny bit of Qi every second
	if (QiComponent)
	{
		QiComponent->SpendQi(QiDrainRate * DeltaTime);
	}
}

void ASovereignPlayerWisp::AttemptPossession()
{
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
		AActor* HitActor = OutHit.GetActor();
		if (HitActor->Implements<UInteractionInterface>())
		{
			if (IInteractionInterface::Execute_CanBePossessed(HitActor))
			{
				IInteractionInterface::Execute_RequestPossession(HitActor, GetController());

				// 2. Physical Snap
				// We attach to the "Soul_Socket". If it doesn't exist, it defaults to the root.
				if (USceneComponent* AttachmentComponent = IInteractionInterface::Execute_GetPossessionAttachmentComponent(HitActor))
				{
					this->AttachToComponent(AttachmentComponent,
						FAttachmentTransformRules::SnapToTargetNotIncludingScale,
						FName("Soul_Socket"));
				}

				// 3. Spirit State
				SetActorHiddenInGame(true);
				GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

				// Disable Wisp Tick while inside to save performance, 
				// OR leave it on if you want the "Wisp Drain" to stay active.
				SetActorTickEnabled(true);

				UE_LOG(LogTemp, Warning, TEXT("Spirit bound to Soul Socket of %s"), *HitActor->GetName());;
			}
		}
	}
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
