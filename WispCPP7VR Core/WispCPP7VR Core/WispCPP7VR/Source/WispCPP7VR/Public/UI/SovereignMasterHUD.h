// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SovereignMasterHUD.generated.h"

class USovereignSaveableEntityComponent;
class USovereignBaseWidget;

/**
 * USovereignMasterHUD: The primary container for Sovereign UI.
 * Orchestrates nested widgets and automates reference injection.
 */
UCLASS(Blueprintable)
class WISPCPP7VR_API USovereignMasterHUD : public UUserWidget
{
    GENERATED_BODY()

public:
    /** The Soul Hub being observed by the entire HUD */
    UPROPERTY(BlueprintReadOnly, Category = "Sovereign|UI")
    USovereignSaveableEntityComponent* SoulHub;

    /**
     * Finds the Soul Hub on the target actor and initializes all nested Sovereign widgets.
     * @param Target The actor (e.g., Player Character) to pull data from.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|UI")
    void InitializeMasterHUD(AActor* Target);

    /**
     * Manually triggers the reference injection to all child widgets.
     * Useful if widgets are added dynamically.
     */
    UFUNCTION(BlueprintCallable, Category = "Sovereign|UI")
    void InjectSoulHubToChildren();

protected:
    virtual void NativeConstruct() override;
};
