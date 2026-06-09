// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Entities/SovereignBrokerInterface.h"
#include "SovereignCultivationBroker.generated.h"

/**
 * UCultivationBroker: Handles the "Magic" - gamified growth, Qi, and evolution.
 */
UCLASS()
class WISPCPP7VR_API UCultivationBroker : public UObject, public ISovereignBrokerInterface
{
	GENERATED_BODY()

public:
	// ISovereignBrokerInterface
	virtual void OnSave(TSharedPtr<FJsonObject>& OutJson) override;
	virtual void OnLoad(const TSharedPtr<FJsonObject>& InJson) override;
	virtual void OnProcessData(const TMap<FString, FString>& Data) override;

	/** Qi Level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Magic")
	float QiBalance = 0.0f;

	/** Cultivation Tier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Magic")
	int32 CultivationTier = 1;
};
