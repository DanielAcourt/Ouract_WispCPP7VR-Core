// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h" 
#include "Interaction/SovereignInterfaceMain.h"
#include "Entities/SovereignBaseInteractable.h"


//This means i need a Input SetupPlayerInputComponent
#include "InputActionValue.h" // For FInputActionValue
#include "SovereignBaseCharacter.generated.h"


// 1. FORWARD DECLARATIONS (Tells the compiler: These classes exist, we'll define them later)
class USovereignElementComponent;
class USovereignControllerComponent;
class USovereignAttributeComponent;
class ASovereignPlayerWisp;
class USovereignQiComponent; // Added this
class AController ; // <--- MUST ADD THIS FOR POSSESSION

// This creates a custom event node for your Blueprints
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSensed, AActor*, SensedActor);

/**
 * ASovereignBaseCharacter
 * The 'Master Vessel' for everything from Erisis to Dragons.
 */
UCLASS()
class WISPCPP7VR_API ASovereignBaseCharacter : public ASovereignBaseEntity
{
	GENERATED_BODY()
	
public:
    ASovereignBaseCharacter();

	/** Use the inherited versions but keep the stats logic */
	virtual void Evolve() override;
	virtual void Tick(float DeltaTime) override;

protected: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignAttributeComponent* AttributeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignQiComponent* QiComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignElementComponent* ElementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignControllerComponent* ControlComponent;

	virtual void BeginPlay() override;
	
};

