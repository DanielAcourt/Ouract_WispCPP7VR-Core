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
		QiComponent->SpendQi(0.1f * DeltaTime);
	}
}

void ASovereignPlayerWisp::AttemptPossession()
{
	// 1. Setup the Trace parameters
	FVector Start = GetActorLocation();
	FVector End = Start + (GetActorForwardVector() * 500.0f); // 5 meters range
	float Radius = 50.0f;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult OutHit;

	// 2. Perform the Trace
	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(), Start, End, Radius, ObjectTypes, false,
		ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true
	);

	if (bHit && OutHit.GetActor())
	{
		ASovereignBaseCharacter* TargetVessel = Cast<ASovereignBaseCharacter>(OutHit.GetActor());
		if (TargetVessel)
		{
			AController* PC = GetController();
			if (PC)
			{
				// 1. Logic Swap
					PC->UnPossess();
				PC->Possess(TargetVessel);

				// 2. Physical Snap
				// We attach to the "Soul_Socket". If it doesn't exist, it defaults to the root.
				this->AttachToComponent(TargetVessel->GetMesh(),
					FAttachmentTransformRules::SnapToTargetNotIncludingScale,
					FName("Soul_Socket"));

				// 3. Spirit State
				SetActorHiddenInGame(true);
				GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

				// Disable Wisp Tick while inside to save performance, 
				// OR leave it on if you want the "Wisp Drain" to stay active.
				SetActorTickEnabled(true);

				UE_LOG(LogTemp, Warning, TEXT("Spirit bound to Soul Socket of %s"), *TargetVessel->GetName());;
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
		// Example: Bind 'Q' or 'Right Click' to AttemptPossession
		// EIC->BindAction(PossessAction, ETriggerEvent::Triggered, this, &ASovereignPlayerWisp::AttemptPossession);
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

	// 3. EXECUTE SPHERE TRACE
	float TraceRadius = 25.0f;
	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(TraceRadius),
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
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, TraceRadius, 12, FColor::Cyan, false, 2.0f);

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

/*
// THE MISSING LINK: This is the function the Linker couldn't find
void ASovereignPlayerWisp::Interact()
{
	if (!GetWorld()) return;

	// 1. Calculate the Raycast (Line Trace)
	// We trace from the Wisp's center forward
	FVector Start = GetActorLocation();
	FVector End = Start + (GetActorForwardVector() * InteractionDistance);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Don't hit yourself

	// 2. Execute Trace
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);

	// 3. DEBUG: Draw a red line in-game so you can see your "reach"
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 2.0f);

	if (bHit && HitResult.GetActor())
	{
		// 4. Try to find a Sovereign Entity (Tree, Bee, etc.)
		// We cast to the BaseEntity which holds the Growth/Evolve logic
		ASovereignBaseEntity* Target = Cast<ASovereignBaseEntity>(HitResult.GetActor());

		if (Target)
		{
			UE_LOG(LogTemp, Warning, TEXT("Sovereign: Wisp interacted with %s"), *Target->GetName());

			// Trigger the 8-stage growth logic!
			Target->Evolve();
		}
	}
}
*/
// Ensure your bridge function looks like this:
void ASovereignPlayerWisp::EnhancedInteract(const FInputActionValue& Value)
{
	Interact(Value); // This now links correctly to the function above
}

/*
void ASovereignPlayerWisp::ReturnToWispForm()
{
	// 1. Get the current controller (which is currently inside a Vessel)
	AController* PC = GetController();
	if (!PC) return;

	// 2. Unhide the Wisp and Detach from the Vessel
	SetActorHiddenInGame(false);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	// 3. Move the Wisp slightly away from the body so they don't get stuck
	SetActorLocation(GetActorLocation() + (GetActorUpVector() * 100.0f));

	// 4. Swap control back to the Wisp
	PC->Possess(this);

	UE_LOG(LogTemp, Log, TEXT("Spirit has manifested from the vessel."));
}
*/

/*
ASovereignPlayerWisp::ASovereignPlayerWisp()
{
	// ... existing constructor logic (SpiritEffect, Movement) ...

	// Setup the Wrist UI
	WristDisplay = CreateDefaultSubobject<UWidgetComponent>(TEXT("WristDisplay"));
	WristDisplay->SetupAttachment(RootComponent);

	// Position it where a "watch" would be
	WristDisplay->SetRelativeLocation(FVector(20.0f, -15.0f, 10.0f));
	WristDisplay->SetWidgetSpace(EWidgetSpace::World); // Makes it feel "physical"
	WristDisplay->SetDrawSize(FVector2D(250.0f, 250.0f));
}
*/