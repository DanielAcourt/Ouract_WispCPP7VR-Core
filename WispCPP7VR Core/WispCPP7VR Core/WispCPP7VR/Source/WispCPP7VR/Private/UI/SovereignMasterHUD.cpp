// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#include "UI/SovereignMasterHUD.h"
#include "UI/SovereignBaseWidget.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Blueprint/WidgetTree.h"
#include "Components/PanelWidget.h"
#include "Interaction/SovereignEntityInterface.h"

void USovereignMasterHUD::NativeConstruct()
{
    Super::NativeConstruct();

    // If we are owned by a Pawn that has a Soul Hub, auto-initialize
    if (AActor* OwningActor = GetOwningPlayerPawn())
    {
        InitializeMasterHUD(OwningActor);
    }
}

void USovereignMasterHUD::InitializeMasterHUD(AActor* Target)
{
    if (!Target) return;

    // Use the interface to find the Soul Hub
    if (Target->GetClass()->ImplementsInterface(USovereignEntityInterface::StaticClass()))
    {
        SoulHub = ISovereignEntityInterface::Execute_GetSovereignSoul(Target);
    }
    else
    {
        SoulHub = Target->FindComponentByClass<USovereignSaveableEntityComponent>();
    }

    if (SoulHub)
    {
        InjectSoulHubToChildren();
    }
}

void USovereignMasterHUD::InjectSoulHubToChildren()
{
    if (!SoulHub || !WidgetTree) return;

    WidgetTree->ForEachWidget([this](UWidget* Widget)
    {
        if (USovereignBaseWidget* SovereignWidget = Cast<USovereignBaseWidget>(Widget))
        {
            SovereignWidget->InitializeWidget(SoulHub);
        }
    });
}
