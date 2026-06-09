// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#include "Entities/SovereignCultivationBroker.h"
#include "Dom/JsonObject.h"

void UCultivationBroker::OnSave(TSharedPtr<FJsonObject>& OutJson)
{
    if (!OutJson.IsValid()) return;

    TSharedPtr<FJsonObject> MagicObj = MakeShareable(new FJsonObject());
    MagicObj->SetNumberField(TEXT("QiBalance"), QiBalance);
    MagicObj->SetNumberField(TEXT("CultivationTier"), CultivationTier);

    OutJson->SetObjectField(TEXT("Sovereign.Magic"), MagicObj);
}

void UCultivationBroker::OnLoad(const TSharedPtr<FJsonObject>& InJson)
{
    if (!InJson.IsValid() || !InJson->HasField(TEXT("Sovereign.Magic"))) return;

    TSharedPtr<FJsonObject> MagicObj = InJson->GetObjectField(TEXT("Sovereign.Magic"));
    QiBalance = MagicObj->GetNumberField(TEXT("QiBalance"));
    CultivationTier = MagicObj->GetIntegerField(TEXT("CultivationTier"));
}

void UCultivationBroker::OnProcessData(const TMap<FString, FString>& Data)
{
    // Gamified progression logic could react to data here
}
