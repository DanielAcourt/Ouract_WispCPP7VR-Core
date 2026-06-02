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
class WISPCPP7VR_API ASovereignBaseCharacter : public ACharacter, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
    ASovereignBaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Sovereign|Senses")
	FOnEntitySensed OnActorSensed;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Soul")
	USovereignSaveableEntityComponent* GetSaveDataComponent() const { return SaveDataComponent; }

	// --- IInteractionInterface Implementation ---
	virtual class USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const override { return SaveDataComponent; }
	virtual bool CanBePossessed_Implementation() override { return bCanBePossessed; }
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual AActor* GetInhabitingSpirit_Implementation() override;
	virtual void RequestSoulEject_Implementation() override {}
	virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;

	virtual void HandlePossessionLifecycle();
	virtual void Evolve();
	virtual void Tick(float DeltaTime) override;

protected: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|SaveSystem")
	USovereignSaveableEntityComponent* SaveDataComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Possession")
	bool bCanBePossessed = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignAttributeComponent* AttributeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignQiComponent* QiComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignElementComponent* ElementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignControllerComponent* ControlComponent;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Senses")
	AActor* GetSensedActor();

	virtual void Interact(const FInputActionValue& Value);

	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	UInputAction* PossessAction;

public:
	// --- IGameplayTagAssetInterface ---
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
};

