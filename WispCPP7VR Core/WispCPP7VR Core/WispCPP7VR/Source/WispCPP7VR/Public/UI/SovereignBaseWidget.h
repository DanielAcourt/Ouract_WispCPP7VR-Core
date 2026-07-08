// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SovereignBaseWidget.generated.h"

class USovereignSaveableEntityComponent;

/**
 * USovereignBaseWidget: The foundation for nested UI modules.
 * Handles automatic visibility based on Broker presence and provides simplified data access.
 */
UCLASS(Abstract, Blueprintable)
class WISPCPP7VR_API USovereignBaseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    /** The Soul Hub this widget is currently observing */
    UPROPERTY(BlueprintReadOnly, Category = "Sovereign|UI", meta = (ExposeOnSpawn = "true"))
    USovereignSaveableEntityComponent* SoulHub;

    /** The category this widget represents (e.g., "Bio", "Qi", "Attributes") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|UI")
    FString CategoryName;

    /** If true, the widget will automatically hide itself if the SoulHub does not have this category */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|UI")
    bool bAutoHideIfMissingBroker = true;

    /** Manual initialization if not handled by a Master HUD */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|UI")
    virtual void InitializeWidget(USovereignSaveableEntityComponent* InSoulHub);

    /** Helper to get current category data as a simple map for Blueprints */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|UI")
    TMap<FString, FString> GetCategoryDataAsMap();

protected:
    /** Called when the SoulHub state changes (e.g., brokers added/removed or data updated) */
    UFUNCTION()
    virtual void HandleStateChanged(USovereignSaveableEntityComponent* UpdatedHub);

    /** Internal check to update visibility */
    virtual void UpdateWidgetVisibility();

    /** Hook for Blueprints to respond to data updates without manual JSON parsing */
    UFUNCTION(BlueprintImplementableEvent, Category = "Sovereign|UI")
    void OnDataUpdated(const TMap<FString, FString>& CategoryData);
};
