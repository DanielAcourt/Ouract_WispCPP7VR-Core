// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28

#include "UI/SovereignBaseWidget.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"
#include "Components/PanelWidget.h"

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
        TMap<FString, FString> DataMap = GetCategoryDataAsMap();
        OnDataUpdated(DataMap);

        if (StatPairWidgetClass && PairContainer)
        {
            SyncDynamicPairs();
        }
    }
}

void USovereignBaseWidget::SyncDynamicPairs()
{
    if (!StatPairWidgetClass || !PairContainer) return;

    TMap<FString, FString> DataMap = GetCategoryDataAsMap();

    // 1. Remove widgets for keys that no longer exist
    TArray<FString> KeysToRemove;
    for (auto& Elem : CachedPairWidgets)
    {
        if (!DataMap.Contains(Elem.Key))
        {
            PairContainer->RemoveChild(Elem.Value);
            KeysToRemove.Add(Elem.Key);
        }
    }
    for (const FString& Key : KeysToRemove) { CachedPairWidgets.Remove(Key); }

    // 2. Add or Update widgets for current keys
    for (auto& Elem : DataMap)
    {
        UUserWidget* PairWidget = nullptr;

        if (CachedPairWidgets.Contains(Elem.Key))
        {
            PairWidget = CachedPairWidgets[Elem.Key];
        }
        else
        {
            PairWidget = CreateWidget<UUserWidget>(this, StatPairWidgetClass);
            if (PairWidget)
            {
                PairContainer->AddChild(PairWidget);
                CachedPairWidgets.Add(Elem.Key, PairWidget);
            }
        }

        if (PairWidget)
        {
            // We use a "Late Binding" approach:
            // We look for "SetStatData" or similar Blueprint functions if they exist,
            // but the most KISS way is to just call a specific function we expect.
            UFunction* Func = PairWidget->FindFunction(FName("SetStatData"));
            if (Func)
            {
                struct { FString Label; FString Value; } Params;
                Params.Label = Elem.Key;
                Params.Value = Elem.Value;
                PairWidget->ProcessEvent(Func, &Params);
            }
        }
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
                    FString ValueStr;
                    if (Elem.Value->Type == EJson::Number)
                    {
                        ValueStr = FString::SanitizeFloat(Elem.Value->AsNumber());
                    }
                    else if (Elem.Value->Type == EJson::Boolean)
                    {
                        ValueStr = Elem.Value->AsBool() ? TEXT("True") : TEXT("False");
                    }
                    else
                    {
                        ValueStr = Elem.Value->AsString();
                    }
                    DataMap.Add(Elem.Key, ValueStr);
                }
            }
        }
    }

    return DataMap;
}
