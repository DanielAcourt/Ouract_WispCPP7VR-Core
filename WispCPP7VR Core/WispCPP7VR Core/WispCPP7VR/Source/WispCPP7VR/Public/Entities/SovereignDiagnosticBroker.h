// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Entities/SovereignBrokerInterface.h"
#include "SovereignDiagnosticBroker.generated.h"

/**
 * UDiagnosticBroker: Handles the "Truth" - raw scientific, historical, and sensor data.
 */
UCLASS()
class WISPCPP7VR_API UDiagnosticBroker : public UObject, public ISovereignBrokerInterface
{
	GENERATED_BODY()

public:
	// ISovereignBrokerInterface
	virtual void OnSave(TSharedPtr<FJsonObject>& OutJson) override;
	virtual void OnLoad(const TSharedPtr<FJsonObject>& InJson) override;
	virtual void OnProcessData(const TMap<FString, FString>& Data) override;

	/** Raw Lidar / Museum Metadata storage */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Truth")
	TMap<FString, FString> TruthMetadata;

	/** Vetted Curator Sign-off */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Truth")
	FString VettedBy;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Truth")
	FString GetTruthValue(const FString& Key) const;

	UFUNCTION(BlueprintCallable, Category = "Sovereign|Truth")
	void SetTruthValue(const FString& Key, const FString& Value);
};
