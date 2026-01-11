// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignBaseCharacter.h"
#include "InputActionValue.h"
#include "SovereignPlayerWisp.generated.h"


// Add this forward declaration at the top
class UWidgetComponent;
class UNiagaraComponent;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class WISPCPP7VR_API ASovereignPlayerWisp : public ASovereignBaseCharacter
{
	GENERATED_BODY()

public:

	ASovereignPlayerWisp();

	// --- Lifecycle ---
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- Wisp Logic ---
	/** Declaring Evolve here fixes Error C2509 */
	virtual void Evolve() override;

	// --- Wisp Logic ---
	void AttemptPossession();

	/** Visuals for the Wisp - Declared ONLY ONCE now */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Vfx")
	UNiagaraComponent* SpiritEffect;

protected:
	/** * INTERACTION LOGIC
		 * This is the raycast that lets you press 'E' to evolve trees/bees Core raycast logic
		 */
	virtual void Interact(const FInputActionValue& Value) override;

	/** Enhanced Input bridge */
	void EnhancedInteract(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Input")
	float InteractionDistance = 500.0f;

private:
	/** Ghostly physics settings */
	void ConfigureSpiritPhysics();
};

