// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE).

#include "Entities/SovereignDiagnosticBroker.h"
#include "Dom/JsonObject.h"

void UDiagnosticBroker::OnSave(TSharedPtr<FJsonObject>& OutJson)
{
    if (!OutJson.IsValid()) return;

    TSharedPtr<FJsonObject> TruthObj = MakeShareable(new FJsonObject());

    for (auto& Elem : TruthMetadata)
    {
        TruthObj->SetStringField(Elem.Key, Elem.Value);
    }

    TruthObj->SetStringField(TEXT("VettedBy"), VettedBy);

    OutJson->SetObjectField(TEXT("Sovereign.Truth"), TruthObj);
}

void UDiagnosticBroker::OnLoad(const TSharedPtr<FJsonObject>& InJson)
{
    if (!InJson.IsValid() || !InJson->HasField(TEXT("Sovereign.Truth"))) return;

    TSharedPtr<FJsonObject> TruthObj = InJson->GetObjectField(TEXT("Sovereign.Truth"));

    TruthMetadata.Empty();
    for (auto& Elem : TruthObj->Values)
    {
        if (Elem.Key == TEXT("VettedBy"))
        {
            VettedBy = Elem.Value->AsString();
        }
        else
        {
            TruthMetadata.Add(Elem.Key, Elem.Value->AsString());
        }
    }
}

void UDiagnosticBroker::OnProcessData(const TMap<FString, FString>& Data)
{
    // Ingest Lidar Manifest / Museum Data
    for (auto& Elem : Data)
    {
        TruthMetadata.Add(Elem.Key, Elem.Value);
    }
}
