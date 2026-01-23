// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/SovereignPawn.h"
#include "InputActionValue.h"
#include "Engine/TimerManager.h"
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
class WISPCPP7VR_API ASovereignPlayerWisp : public ASovereignPawn
{
	GENERATED_BODY()

public:

	ASovereignPlayerWisp();

	// --- Lifecycle ---
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- Possession ---
	void InitiatePossession(AActor* TargetVessel);
	void EndPossession();

	/** Visuals for the Wisp - Declared ONLY ONCE now */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Vfx")
	UNiagaraComponent* SpiritEffect;

protected:
	/** * INTERACTION LOGIC
		 * This is the raycast that lets you press 'E' to evolve trees/bees Core raycast logic
		 */
	virtual void Interact(const FInputActionValue& Value);

	/** Enhanced Input bridge */
	void EnhancedInteract(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Input")
	float InteractionDistance = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Possession")
	float PossessionTraceRadius = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
	float QiDrainRate = 0.1f;

private:
	/** Wisp Logic */
	void AttemptPossession();

	// --- Possession State ---
	TWeakObjectPtr<AActor> CurrentlyPossessedVessel;
	FTimerHandle QiDrainTimerHandle;

	void AttachToVessel(AActor* Vessel);
	void DrainPossessionQi();
};
