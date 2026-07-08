// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#include "UI/SovereignBaseWidget.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"

void USovereignBaseWidget::InitializeWidget(USovereignSaveableEntityComponent* InSoulHub)
{
    if (SoulHub)
    {
        SoulHub->OnStateChanged.RemoveDynamic(this, &USovereignBaseWidget::HandleStateChanged);
    }

    SoulHub = InSoulHub;

    if (SoulHub)
    {
        SoulHub->OnStateChanged.AddDynamic(this, &USovereignBaseWidget::HandleStateChanged);
    }

    UpdateWidgetVisibility();
    HandleStateChanged(SoulHub);
}

void USovereignBaseWidget::HandleStateChanged(USovereignSaveableEntityComponent* UpdatedHub)
{
    if (UpdatedHub != SoulHub) return;

    UpdateWidgetVisibility();

    if (IsVisible() || !bAutoHideIfMissingBroker)
    {
        OnDataUpdated(GetCategoryDataAsMap());
    }
}

void USovereignBaseWidget::UpdateWidgetVisibility()
{
    if (!bAutoHideIfMissingBroker || CategoryName.IsEmpty()) return;

    if (SoulHub)
    {
        // We use GetCategoryStateJson to check if the category exists.
        // If it returns "{}" (empty object), the broker is likely missing.
        FString Json = SoulHub->GetCategoryStateJson(CategoryName);

        ESlateVisibility NewVisibility = (Json != TEXT("{}")) ? ESlateVisibility::Visible : ESlateVisibility::Collapsed;
        SetVisibility(NewVisibility);
    }
    else
    {
        SetVisibility(ESlateVisibility::Collapsed);
    }
}

TMap<FString, FString> USovereignBaseWidget::GetCategoryDataAsMap()
{
    TMap<FString, FString> DataMap;

    if (SoulHub && !CategoryName.IsEmpty())
    {
        FString JsonString = SoulHub->GetCategoryStateJson(CategoryName);
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            for (auto& Elem : JsonObject->Values)
            {
                if (Elem.Value.IsValid())
                {
                    DataMap.Add(Elem.Key, Elem.Value->AsString());
                }
            }
        }
    }

    return DataMap;
}
