// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayTagContainer.h" // <--- CRITICAL: Fixes C2061
#include "WispsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class WISPCPP7VR_API AWispsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWispsGameModeBase();

	/** Helper to find species data during spawning [v36.4.1] */
	class USovereignSpeciesData* GetSpeciesDataByTag(FGameplayTag SpeciesTag);

protected:
	/** Global reference to your Species/Item Data Table */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Data")
	class UDataTable* ItemDataTable;

};
