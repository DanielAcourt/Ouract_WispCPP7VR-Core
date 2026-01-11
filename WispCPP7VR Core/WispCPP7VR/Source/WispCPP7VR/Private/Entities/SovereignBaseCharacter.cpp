// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/SovereignBaseCharacter.h"
#include "Components/SovereignElementComponent.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "Components/SovereignQiComponent.h" // Added this include
#include "GameFramework/Character.h" // Add this include
#include "GameFramework/CharacterMovementComponent.h"//Core Unreal Character frameworks
#include "EnhancedInputComponent.h" //core unreal input libraries
#include "EnhancedInputSubsystems.h" // You'll likely need this for the Mapping Context too

ASovereignBaseCharacter::ASovereignBaseCharacter()
{
	// 1. CONSTRUCT THE HYBRID STACK
	// Naming here now matches the header exactly
	ElementComponent = CreateDefaultSubobject<USovereignElementComponent>(TEXT("ElementComponent"));
	ControlComponent = CreateDefaultSubobject<USovereignControllerComponent>(TEXT("ControlComponent"));
	AttributeComponent = CreateDefaultSubobject<USovereignAttributeComponent>(TEXT("AttributeComponent"));
	QiComponent = CreateDefaultSubobject<USovereignQiComponent>(TEXT("QiComponent"));

	// 2. CONFIGURE CHARACTER DEFAULTS
	bUseControllerRotationYaw = false;
}

void ASovereignBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ControlComponent)
	{
		ControlComponent->OnPossessed(NewController);
	}

	if (AttributeComponent && NewController && NewController->IsPlayerController())
	{
		UE_LOG(LogTemp, Log, TEXT("Sovereign: %s is now Player-Controlled."), *GetName());
	}
}

void ASovereignBaseCharacter::UnPossessed()
{
	if (ControlComponent)
	{
		ControlComponent->OnUnpossessed();
	}

	Super::UnPossessed();
}

void ASovereignBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Only run this if we are controlled by a Human (Local Player)
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
			{
				if (DefaultMappingContext)
				{
					// Clear existing to prevent double-mapping, then add
					Subsystem->RemoveMappingContext(DefaultMappingContext);
					Subsystem->AddMappingContext(DefaultMappingContext, 0);
					UE_LOG(LogTemp, Log, TEXT("Sovereign: [%s] Input Mapping Context Active."), *GetName());
				}
			}
		}
	}
}

USceneComponent* ASovereignBaseCharacter::GetPossessionAttachmentComponent_Implementation()
{
	return GetMesh();
}

void ASovereignBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 1. Move & Look (Standard)
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Move);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Look);

		// 2. Interact (THIS IS THE ONE TO CHANGE)
		EIC->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Interact);
	}
}

/* Gentic Move
void ASovereignBaseCharacter::Move(const FInputActionValue& Value)
{
	
	// 1. Architect Safety: Early exit if no controller or input
	if (!Controller) return;

	// 2. Extract and Normalize: 
	// We normalize so that holding W+D (diagonal) isn't faster than just W.
	FVector MovementVector = Value.Get<FVector>();

	if (!MovementVector.IsNearlyZero())
	{
		MovementVector.Normalize();
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Green, FString::Printf(TEXT("Input: %s"), *MovementVector.ToCompactString()));
	}
	// 3. DNA-BASED SPEED CALCULATOR
	// We update the movement component's limits based on Attribute state
	if (AttributeComponent)
	{
		// 1% Detail: Use a base speed constant so you can tune it globally later
		const float BaseSpeed = 1000.0f;

		// Boost Dexterity so the Wisp is fast!
		//AttributeComponent->Dexterity = 55550; // Higher = Faster

		// Set other spirit stats
		//AttributeComponent->Intelligence = 155500;

		float DexBonus = static_cast<float>(AttributeComponent->Dexterity) * 100.0f;

		float CalculatedSpeed = BaseSpeed + (DexBonus + 100);

		GetCharacterMovement()->MaxWalkSpeed = CalculatedSpeed;
		GetCharacterMovement()->MaxFlySpeed = CalculatedSpeed;
	}

	// Force an immediate update to movement speed
	//GetCharacterMovement()->MaxFlySpeed = 1200.0f;

	// 4. ORIENTATION LOGIC
	// We extract only the Yaw (Rotation around Z) so movement stays level with the ground
	const FRotator ControlRot = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRot.Yaw, 0.f);

	// 5. DIRECTIONAL VECTORS
	// GetUnitAxis(EAxis::X) is "Forward" relative to where the player is looking
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// 6. APPLY LATERAL MOVEMENT
	// Scale the direction by the specific axis value from our Input Action
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);

	// 7. APPLY VERTICAL MOVEMENT (Spirit/Wisp Flight)
	// If the vessel is in flight mode, allow Z-axis movement (Space/Ctrl)
	if (GetCharacterMovement()->IsFlying() && !FMath::IsNearlyZero(MovementVector.Z))
	{
		AddMovementInput(FVector::UpVector, MovementVector.Z);
	}

	// TEMP TEST: This force-moves the actor, bypassing the Movement Component
	//FVector NewLoc = GetActorLocation() + (ForwardDirection * MovementVector.Y * 10.0f);
	//SetActorLocation(NewLoc);
}
*/

/*
void ASovereignBaseCharacter::Move(const FInputActionValue& Value)
{
	// 1. Controller Safety
	if (!Controller) return;

	// 2. Extract and Normalize Input
	// This ensures that diagonal movement isn't faster than straight movement
	FVector MovementVector = Value.Get<FVector>();
	if (!MovementVector.IsNearlyZero())
	{
		MovementVector.Normalize();
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Green, FString::Printf(TEXT("Input: %s"), *MovementVector.ToCompactString()));
	}

	// 3. SET FIXED SPEED (Predictable for Level Loading)
	// We set this once; no DNA scaling here to keep it simple for now
	const float ConstantMoveSpeed = 800.0f;
	GetCharacterMovement()->MaxFlySpeed = ConstantMoveSpeed;
	GetCharacterMovement()->MaxWalkSpeed = ConstantMoveSpeed;

	// 4. ORIENTATION LOGIC
	// We only care about where the player is looking on the Horizontal (Yaw) plane
	const FRotator ControlRot = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRot.Yaw, 0.f);

	// 5. CALCULATE DIRECTIONS
	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// 6. APPLY MOVEMENT
	AddMovementInput(ForwardDir, MovementVector.Y); // W/S
	AddMovementInput(RightDir, MovementVector.X);   // A/D

	// 7. VERTICAL MOVEMENT (Optional but useful for Wisps)
	if (GetCharacterMovement()->IsFlying() && !FMath::IsNearlyZero(MovementVector.Z))
	{
		AddMovementInput(FVector::UpVector, MovementVector.Z);
	}
}
*/

/*
void ASovereignBaseCharacter::Move(const FInputActionValue& Value)
{
	// 1. ARCHITECT SAFETY: Ensure the Mind (Controller) and Body (MovementComponent) exist
	if (!Controller || !GetCharacterMovement()) return;

	// 2. EXTRACT INPUT
	FVector MovementVector = Value.Get<FVector>();

	// 3. DEBUG FEEDBACK
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Green,
			FString::Printf(TEXT("Moving: %s"), *MovementVector.ToCompactString()));
	}

	// 4. THE "FORCE MOVEMENT" SETTINGS
	// We set these here to ensure that physics friction never "wins" over your W key
	const float ConstantMoveSpeed = 1200.0f; // Slightly faster for better "feel"
	GetCharacterMovement()->MaxFlySpeed = ConstantMoveSpeed;
	GetCharacterMovement()->MaxAcceleration = 5000.0f; // Snappy start-up

	// Architect Detail: If we are moving, reduce friction to 0 so we don't get "stuck"
	GetCharacterMovement()->BrakingDecelerationFlying = MovementVector.IsNearlyZero() ? 2000.0f : 0.0f;

	// 5. ORIENTATION LOGIC
	// Get the Forward and Right vectors based ONLY on the camera's horizontal (Yaw) look
	const FRotator ControlRot = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRot.Yaw, 0.f);

	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// 6. APPLY MOVEMENT (The W/S and A/D Logic)
	// MovementVector.Y is usually Forward/Backward (W/S)
	// MovementVector.X is usually Left/Right (A/D)
	AddMovementInput(ForwardDir, MovementVector.Y);
	AddMovementInput(RightDir, MovementVector.X);

	// 7. VERTICAL MOVEMENT (Space/Shift Logic for Wisps)
	if (GetCharacterMovement()->IsFlying() && !FMath::IsNearlyZero(MovementVector.Z))
	{
		AddMovementInput(FVector::UpVector, MovementVector.Z);
	}
}
*/

void ASovereignBaseCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	// 1. Get the Raw Input (-1.0 to 1.0 for each axis)
	const FVector Input = Value.Get<FVector>();

	// 2. DEBUG FEEDBACK (The Truth Teller)
	if (GEngine)
	{
		// This prints the raw numbers from your IMC to the screen
		FString DebugMsg = FString::Printf(TEXT("Input -> Forward/Back(Y): %.2f | Right/Left(X): %.2f | Up/Down(Z): %.2f"),
			Input.Y, Input.X, Input.Z);

		GEngine->AddOnScreenDebugMessage(1, 0.1f, FColor::Yellow, DebugMsg);
	}

	// 3. Get Camera Directions
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// 4. The Movement Logic
	// Distance = speed. If 15 is too slow, bump it to 30 or 50.
	const float Distance = 15.0f;

	FVector MoveDelta = (Forward * Input.Y * Distance) +
		(Right * Input.X * Distance) +
		(FVector::UpVector * Input.Z * Distance);

	// 5. Apply Position Change
	// Sweep = true ensures you hit walls instead of going through them
	AddActorWorldOffset(MoveDelta, true);

	// 6. Kill Physics Interference
	// This prevents the character movement component from adding its own friction/drift
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->Velocity = FVector::ZeroVector;
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
}
void ASovereignBaseCharacter::Look(const FInputActionValue& Value)
{
	// 1. Extract the 2D Axis data (X = Mouse X / Yaw, Y = Mouse Y / Pitch)
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// 2. Apply the input to the Controller
		// These functions are built into APawn and automatically handle sensitivity
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);

		// 3. 1% POLISH: If you are in VR, usually the HMD handles this. 
		// For desktop/Spectator mode, this rotates the camera boom/view.
	}
}

// Update the binding in SetupPlayerInputComponent
//EIC->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ASovereignBaseCharacter::Interact);
//This doesnt work
// Update the function body

void ASovereignBaseCharacter::Interact(const FInputActionValue& Value)
{
	// 1. FORCE LOG (Visible on screen regardless of BP)
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("SYSTEM: E KEY PRESSED"));

	AActor* Target = GetSensedActor();

	if (Target)
	{
		// 2. FORCE LOG TARGET
		  if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan,
			FString::Printf(TEXT("SYSTEM: HIT ACTOR -> %s"), *Target->GetName()));

		  // 3. BROADCAST TO BLUEPRINT this sint working as intended also does it in the get sense function too
		//OnActorSensed.Broadcast(Target);
	}
}

AActor* ASovereignBaseCharacter::GetSensedActor()
{
	if (!Controller) return nullptr;

	FVector Start;
	FRotator Rot;
	Controller->GetPlayerViewPoint(Start, Rot);

	const float Range = 500.0f;
	const float Radius = 25.0f;
	FVector End = Start + (Rot.Vector() * Range);

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	// Perform the thick raycast (Sphere Trace)
	bool bHit = GetWorld()->SweepSingleByChannel(
		Hit, Start, End, FQuat::Identity,
		ECC_Visibility, FCollisionShape::MakeSphere(Radius), Params
	);

	AActor* HitActor = bHit ? Hit.GetActor() : nullptr;

	// --- NEW DEBUG & BLUEPRINT LOGIC ---
	if (HitActor)
	{
		// 1. Logs to the Output Log (Window -> Output Log)
		UE_LOG(LogTemp, Warning, TEXT("Sovereign Sense: Hit Actor [%s] at Location [%s]"),
			*HitActor->GetName(), *Hit.Location.ToString());

		// 2. Fires the Blueprint Event
		OnActorSensed.Broadcast(HitActor);
	}

#if !UE_BUILD_SHIPPING
	DrawDebugLine(GetWorld(), Start, End, bHit ? FColor::Green : FColor::Red, false, 1.0f, 0, 1.0f);

	if (bHit)
	{
		// Draw a solid sphere where the hit actually occurred
		DrawDebugSphere(GetWorld(), Hit.Location, Radius, 12, FColor::Green, false, 1.0f);
	}
#endif

	return HitActor;
}

void ASovereignBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Call this every frame so the Blueprint Event and Log fire constantly
	GetSensedActor();
}