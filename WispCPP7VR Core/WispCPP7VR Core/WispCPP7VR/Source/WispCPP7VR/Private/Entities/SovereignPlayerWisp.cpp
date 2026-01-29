// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
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

//Default Starting Logic
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

	// This makes the Wisp an 'active listener' even when it's just an attached child
	EnableInput(GetWorld()->GetFirstPlayerController());
}

void ASovereignPlayerWisp::ConfigureSpiritPhysics()
{
	// Ensure the capsule is physically active but ghostly
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// SPIRIT RULES: Pass through characters/items, but stop at walls/floors
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	// The Soul is weightless
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->GravityScale = 0.0f;
		// Ensure flying mode is active so we don't just 'fall' slowly
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
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

//Sensing Logic
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
	// --- SOVEREIGN CHECK: THE TOGGLE LOGIC ---
	// If the Wisp already has an 'AttachParentActor', it means we are currently 
	// inhabiting a host. In this state, the button press acts as an 'Eject' command.
	if (GetRootComponent()->GetAttachParentActor())
	{
		UE_LOG(LogTemp, Log, TEXT("Wisp detected active possession. Initiating Eject."));
		EjectFromHost();
		return;
	}

	// --- STEP 1: TARGETING ---
	// We trace from the Spirit's 'Third Eye' (Control Rotation) rather than actor forward.
	FVector Start = GetActorLocation();
	FVector ViewDir = GetSpiritForwardVector();
	FVector End = Start + (ViewDir * InteractionDistance);

	// Define which object types the Soul can perceive.
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));         // Biological Vessels (Erisis/Animals)
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic)); // Material Vessels (Rocks/Plants)

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult OutHit;

	// Sphere Trace provides a 'forgiving' volume for possession compared to a thin line.
	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(), Start, End, PossessionTraceRadius, ObjectTypes, false,
		ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true,
		FLinearColor::Red, FLinearColor::Green, 2.0f
	);

	// --- STEP 2: VALIDATION ---
	if (bHit && OutHit.GetActor())
	{
		AActor* HitActor = OutHit.GetActor();

		// Check if the target speaks the Sovereign Language (Interface)
		if (HitActor->Implements<UInteractionInterface>())
		{
			// Check if the target's Soul is open for entry.
			if (IInteractionInterface::Execute_CanBePossessed(HitActor))
			{
				// Cache the controller before we start the handover.
				APlayerController* PC = Cast<APlayerController>(GetController());

				// --- STEP 3: PHYSICAL ATTACHMENT ---
				// Snap the Wisp to the designated 'Soul_Socket' on the host.
				if (USceneComponent* AttachmentComponent = IInteractionInterface::Execute_GetPossessionAttachmentComponent(HitActor))
				{
					this->AttachToComponent(AttachmentComponent,
						FAttachmentTransformRules::SnapToTargetNotIncludingScale,
						FName("Soul_Socket"));
				}

				// --- STEP 4: SOUL HANDOVER ---
				// If the host is a Pawn, the PlayerController migrates into it.
				if (PC && HitActor->IsA<APawn>())
				{
					PC->Possess(Cast<APawn>(HitActor));
					UE_LOG(LogTemp, Warning, TEXT("Soul migrated to Host: %s"), *HitActor->GetName());
				}

				// --- STEP 5: SPIRIT STATE MANAGEMENT ---
				// Hide the Wisp visual but keep Tick active for metabolism/Qi drain.
				SetActorHiddenInGame(true);

				// Disable physical collision so we don't interfere with the Host's movement,
				// but keep QueryOnly active so the Wisp remains 'Sensed' by the engine.
				GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
				GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);

				SetActorTickEnabled(true);

				// Final handshake through the interface
				IInteractionInterface::Execute_RequestPossession(HitActor, PC);
			}
		}
	}
}
//Inital thought by Dan "Need a way to unpossess if i am currently posessing something"
//We need a way to possess and control that possessed object.
//We need a way to unposess by pressing F aka the pocesskey

void ASovereignPlayerWisp::EjectFromHost()
{
	if (AActor* MyHost = GetRootComponent()->GetAttachParentActor())
	{
		// 1. IDENTIFY THE VESSEL
		APawn* HostPawn = Cast<APawn>(MyHost);

		// 2. The Great Detachment
		// KeepWorldTransform prevents the Wisp from snapping to a weird offset
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

		// 3. Restore Physicality
		SetActorHiddenInGame(false);

		// Apply your specific Spirit Physics (Weightless, Ghostly Collision)
		// Move the Player's 'Will' from the Vessel back to the Soul
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		// 4. Controller Handover
		// Move the Player's 'Will' from the Vessel back to the Soul
		if (HostPawn && HostPawn->GetController())
		{
			APlayerController* PC = Cast<APlayerController>(HostPawn->GetController());
			if (PC)
			{
				PC->Possess(this);

				// Optional: Give the Wisp a small 'Bup' upwards so it's not stuck in the host's head
				//Maybe this can be a location we difine like the face or hat extra (3rd person camera location etc)

				AddActorWorldOffset(FVector(0, 0, 50.0f));

				UE_LOG(LogTemp, Warning, TEXT("Soul has exited the vessel: %s"), *MyHost->GetName());
			}
		}

		// 5. METABOLISM
		SetActorTickEnabled(true);
	}
}

//Evolving and leveling logic
void ASovereignPlayerWisp::Evolve()
{
	// Call the parent Evolve first (if it has logic)
	Super::Evolve();

	// Wisp-specific evolution logic (e.g., change particle color)
	UE_LOG(LogTemp, Warning, TEXT("The Player Spirit is evolving to a higher density!"));
}

//make sure we have the ability to recieve input
void ASovereignPlayerWisp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// 1. ARCHITECT FOUNDATION: Call the Base version.
	// This ensures the SovereignBaseCharacter handles movement (WASD/Thumbstick) 
	// and basic interaction logic before we add Wisp-specific soul powers.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 2. CAST TO ENHANCED INPUT: 
	// We cast the generic UInputComponent to UEnhancedInputComponent to use the modern input system.
	// CastChecked will cause a crash (assertion) if the project isn't set up for Enhanced Input, 
	// which is exactly what we want for debugging.
	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// --- SOUL ABILITY: POSSESSION ---
		// Triggered: Executes as long as the button is held or the condition is met.
		// This fires the Sphere Trace to find a host like Erisis or a Rock.
		if (PossessAction)
		{
			EIC->BindAction(PossessAction, ETriggerEvent::Triggered, this, &ASovereignPlayerWisp::AttemptPossession);
		}

		// --- SOUL ABILITY: EJECT ---
		// Started: Only fires ONCE when the button is first pressed.
		// This prevents the Wisp from "glitching" out and back into the host in the same frame.
		if (EjectAction)
		{
			EIC->BindAction(EjectAction, ETriggerEvent::Started, this, &ASovereignPlayerWisp::EjectFromHost);
		}

		// Note: All bindings using 'EIC' must stay inside these brackets!
	}
}


// Interaction Logic:
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
