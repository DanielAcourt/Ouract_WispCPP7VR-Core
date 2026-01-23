// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SovereignEntityInterface.generated.h"

class USovereignSaveableEntityComponent;
class USceneComponent;

UINTERFACE(MinimalAPI)
class USovereignEntityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class WISPCPP7VR_API ISovereignEntityInterface
{
	GENERATED_BODY()

public:

	virtual USovereignSaveableEntityComponent* GetSovereignSoul() const = 0;

	virtual USceneComponent* GetPrimaryMesh() const = 0;

	virtual void OnPossessedByWisp(AController* WispController) = 0;

	virtual void OnUnpossessedByWisp() = 0;
};
