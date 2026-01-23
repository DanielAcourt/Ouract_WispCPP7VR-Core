// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/SovereignEntityInterface.h"
#include "SovereignPawn.generated.h"

class USovereignSaveableEntityComponent;

UCLASS()
class WISPCPP7VR_API ASovereignPawn : public APawn, public ISovereignEntityInterface
{
	GENERATED_BODY()

public:
	ASovereignPawn();

	virtual USovereignSaveableEntityComponent* GetSovereignSoul() const override;
	virtual USceneComponent* GetPrimaryMesh() const override;
	virtual void OnPossessedByWisp(AController* WispController) override;
	virtual void OnUnpossessedByWisp() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	USovereignSaveableEntityComponent* SovereignSoul;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Components")
	class UFloatingPawnMovement* MovementComponent;
};
