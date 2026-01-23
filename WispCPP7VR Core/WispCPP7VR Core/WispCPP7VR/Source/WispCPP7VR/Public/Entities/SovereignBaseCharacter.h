// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h" 
#include "InputActionValue.h"
#include "Interfaces/SovereignEntityInterface.h"
#include "SovereignBaseCharacter.generated.h"


class USovereignSaveableEntityComponent;
class AController;

UCLASS()
class WISPCPP7VR_API ASovereignBaseCharacter : public ACharacter, public ISovereignEntityInterface
{
	GENERATED_BODY()
	
public:
    ASovereignBaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	// --- ISovereignEntityInterface ---
	virtual USovereignSaveableEntityComponent* GetSovereignSoul() const override;
	virtual USceneComponent* GetPrimaryMesh() const override;
	virtual void OnPossessedByWisp(AController* WispController) override;
	virtual void OnUnpossessedByWisp() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignSaveableEntityComponent* SovereignSoul;

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	class UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Input")
	class UInputAction* PossessAction;
	
};
