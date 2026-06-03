// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "InputActionValue.h"
#include "SovereignBaseCharacter.generated.h"

class USovereignSaveableEntityComponent;
class USovereignAttributeComponent;
class USovereignQiComponent;
class USovereignElementComponent;
class USovereignControllerComponent;
class UInputMappingContext;
class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSensed, AActor*, SensedActor);

UCLASS()
class WISPCPP7VR_API ASovereignBaseCharacter : public ACharacter, public IGameplayTagAssetInterface, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ASovereignBaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- IInteractionInterface ---
	virtual class USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const override { return SaveDataComponent; }
	virtual bool CanBePossessed_Implementation() override { return bCanBePossessed; }
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual AActor* GetInhabitingSpirit_Implementation() override;
	virtual void RequestSoulEject_Implementation() override {}
	virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;

	virtual void HandlePossessionLifecycle();
	virtual void Evolve();

	// --- IGameplayTagAssetInterface ---
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	UPROPERTY(BlueprintAssignable, Category = "Sovereign|Senses")
	FOnActorSensed OnActorSensed;

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

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Interact(const FInputActionValue& Value);

	AActor* GetSensedActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
};
