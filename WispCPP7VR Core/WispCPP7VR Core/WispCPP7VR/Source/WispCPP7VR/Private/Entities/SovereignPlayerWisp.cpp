// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "Kismet/KismetSystemLibrary.h" // <--- CRITICAL FOR THE TRACE
#include "Components/WidgetComponent.h" // Add this include!

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

//DO i need these 2 in the wisp aswell?
#include "Interaction/SovereignInterfaceMain.h"
#include "Entities/SovereignSaveableEntityComponent.h"

//Visuals
#include "NiagaraComponent.h"
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

	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	// No Gravity for the Soul
	GetCharacterMovement()->GravityScale = 0.0f;
}

void ASovereignPlayerWisp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1. PERSISTENT SOUL VISUALIZATION
	// If we are attached to something, we are "Possessing" it.
	if (GetRootComponent()->GetAttachParent())
	{
		// Draw a cyan "Soul Capsule" to show where the Wisp is sitting
		DrawDebugCapsule(
			GetWorld(),
			GetActorLocation(),
			GetCapsuleComponent()->GetScaledCapsuleHalfHeight(),
			GetCapsuleComponent()->GetScaledCapsuleRadius(),
			GetActorQuat(),
			FColor::Cyan,
			false,   // Persistent? No, we draw it every frame
			-1.0f,   // LifeTime ( -1 = 1 frame)
			0,       // Depth priority
			1.5f     // Thickness
		);
	}

	// 2. METABOLISM (Existing Qi Drain)
	if (QiComponent)
	{
		float CurrentDrain = (GetRootComponent()->GetAttachParent()) ? (QiDrainRate * 0.5f) : QiDrainRate;
		QiComponent->SpendQi(CurrentDrain * DeltaTime);
	}
}

FVector ASovereignPlayerWisp::GetSpiritForwardVector() const
{
	// Priority 1: Use Control Rotation (Player's Eyes/Headset)
	if (GetController())
	{
		return GetControlRotation().Vector();
	}

	// Fallback: Use the Actor's physical forward if no controller is found
	return GetActorForwardVector();
}

void ASovereignPlayerWisp::TogglAutoSensing(bool bNewState)
{
	bIsAutoSensingEnabled = bNewState;

	if (bIsAutoSensingEnabled)
	{
		// 1.0f = The loop runs exactly once every second.
				// true = It will keep repeating.
		GetWorldTimerManager().SetTimer(SensingTimerHandle, this, &ASovereignPlayerWisp::UpdateSensingLoop, 2.0f, true);
	}
	else
	{
		// Stop the loop and the drawing
		GetWorldTimerManager().ClearTimer(SensingTimerHandle);
	}

	// Feedback for the player
	UE_LOG(LogTemp, Log, TEXT("Wisp Auto-Sensing: %s"), bNewState ? TEXT("ACTIVE") : TEXT("OFF"));
}

void ASovereignPlayerWisp::UpdateSensingLoop()
{
	if (!GetWorld()) return;

	FVector Start = GetActorLocation();
	FVector End = Start + (GetControlRotation().Vector() * InteractionDistance);
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	AActor* CurrentActor = nullptr;

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params)) //LR ECC_Camera Or ECC Pawn
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor && HitActor->Implements<UInteractionInterface>())
		{
			CurrentActor = HitActor;
		}
	}
}

/*
void ASovereignPlayerWisp::PerformAutoSensing()
{
	FVector Start = GetActorLocation();
	FVector End = Start + (GetControlRotation().Vector() * InteractionDistance);
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor && HitActor->Implements<UInteractionInterface>())
		{
			// Tell the object it is being looked at (for UI/Glow effects)
			IInteractionInterface::Execute_OnBeginHover(HitActor);

			// Draw a small "focus" point
			DrawDebugPoint(GetWorld(), Hit.ImpactPoint, 10.f, FColor::Cyan, false, 0.1f);
		}
	}
}
*/

void ASovereignPlayerWisp::AttemptPossession()
{
	// 1. Setup the Trace parameters for EVERYTHING Sovereign
	FVector Start = GetActorLocation();


	// Use our new helper function!
	FVector ViewDir = GetSpiritForwardVector();
	FVector End = Start + (ViewDir * InteractionDistance);

	//Create A List fo object we can hit
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));		  // Characters/Animals
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic)); // Rocks/Plants/Interactables

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult OutHit;

	// Perform the Trace with a 5-second debug duration
	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(),
		Start,
		End,
		PossessionTraceRadius,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration, // This will now show a clear red/green tube
		OutHit,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		5.0f
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

				// This keeps the capsule "alive" for debug drawing but prevents it from blocking movement
				GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
				GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);

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
	// 1. ARCHITECT TRUTH: Always respect the inheritance chain.
	Super::Interact(Value);

	if (!GetWorld()) return;

	// 2. PRECISION VECTOR: Trace from where the player is LOOKING.
	FVector Start = GetActorLocation();
	// Using GetControlRotation ensures VR/First Person accuracy.
	FVector ViewDir = GetControlRotation().Vector();
	FVector End = Start + (ViewDir * InteractionDistance);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Don't hit yourself!

	// 3. EXECUTE TRACE: Checking for visual blockages.
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,
		Params
	);

	// 4. THE UNIVERSAL HANDSHAKE
	if (bHit && HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();

		// Check if the target speaks the Sovereign Language
		if (HitActor->Implements<UInteractionInterface>())
		{
			// --- THE SOUL HANDSHAKE ---
			// Fetch the 'Simulated Truth' via the interface hub.
			USovereignSaveableEntityComponent* Soul = IInteractionInterface::Execute_GetSovereignSoul(HitActor);

			if (Soul)
			{
				// Isla's Logic: Access metadata even if the Wisp doesn't 'know' the tags yet.
				TMap<FString, FString> Metadata = Soul->GetUnknownMetaTags();

				// Example: Sensing the species for the UI
				if (Metadata.Contains("Identity.Species"))
				{
					UE_LOG(LogTemp, Log, TEXT("Wisp identified: %s"), *Metadata["Identity.Species"]);
				}
			}

			// --- TRIGGER ACTION ---
			// This fires the C++ Implementation AND the Blueprint 'OnInteract' event.
			IInteractionInterface::Execute_OnInteract(HitActor, this);

			// FEEDBACK: Cyan is the color of the Spirit
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 12.f, 12, FColor::Cyan, false, 2.0f);

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan,
					FString::Printf(TEXT("Sovereign Target: %s"), *HitActor->GetName()));
			}
		}
		else
		{
			// We hit a mundane object (Wall, Floor, Non-Sovereign Rock)
			DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 8.f, 8, FColor::Red, false, 1.0f);
		}
	}
	else
	{
		// Total Miss: Show the player their reach
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 0.5f);
	}
}

// Ensure your bridge function looks like this:
void ASovereignPlayerWisp::EnhancedInteract(const FInputActionValue& Value)
{
	Interact(Value); // This now links correctly to the function above
}
