// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "Entities/SovereignBlackBoxComponent.h"
#include "Interaction/SovereignSaveInterface.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "Engine/World.h"

USovereignBlackBoxComponent::USovereignBlackBoxComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USovereignBlackBoxComponent::BeginPlay()
{
    Super::BeginPlay();
}

void USovereignBlackBoxComponent::RecordTruthSnapshot()
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    // 1. Gather all data from the Vessel (Actor) and its Components
    TMap<FString, FString> RawData;

    // A. Actor Data
    if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Owner))
    {
        RawData.Append(SaveInterface->GetSaveData());
    }

    // B. Component Data
    TArray<UActorComponent*> Comps;
    Owner->GetComponents(Comps);
    for (UActorComponent* Comp : Comps)
    {
        if (Comp == this) continue;
        if (ISovereignSaveInterface* SaveInterface = Cast<ISovereignSaveInterface>(Comp))
        {
            TMap<FString, FString> CompData = SaveInterface->GetSaveData();
            FString Prefix = Comp->GetName() + TEXT(".");
            for (auto& Elem : CompData)
            {
                RawData.Add(Prefix + Elem.Key, Elem.Value);
            }
        }
    }

    // 2. Process deltas
    bool bHasChanges = false;
    for (auto& Elem : RawData)
    {
        // We only care about numeric telemetry for now (the "Truth")
        if (Elem.Value.IsNumeric())
        {
            float CurrentValue = FCString::Atof(*Elem.Value);
            float* LastValuePtr = LastTruthValues.Find(Elem.Key);

            bool bShouldLog = false;
            if (!LastValuePtr)
            {
                // First time seeing this key
                bShouldLog = true;
            }
            else if (FMath::Abs(CurrentValue - *LastValuePtr) >= LoggingThreshold)
            {
                // Delta exceeded
                bShouldLog = true;
            }

            if (bShouldLog)
            {
                PendingEntries.Add(FBlackBoxEntry(Elem.Key, CurrentValue));
                LastTruthValues.Add(Elem.Key, CurrentValue);
                bHasChanges = true;

                UE_LOG(LogTemp, Log, TEXT("BlackBox [%s]: Change detected for %s: %f (Delta: %f)"),
                    *EntityID.ToString(), *Elem.Key, CurrentValue, LastValuePtr ? FMath::Abs(CurrentValue - *LastValuePtr) : 0.0f);
            }
        }
    }

    // 3. Flush if we have data
    if (bHasChanges)
    {
        FlushToSubsystem();
    }
}

void USovereignBlackBoxComponent::FlushToSubsystem()
{
    if (PendingEntries.Num() == 0) return;

    if (UWorld* World = GetWorld())
    {
        if (USovereignBlackBoxSubsystem* BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>())
        {
            BBSubsystem->RecordEntries(EntityID, PendingEntries);
            PendingEntries.Empty();
        }
    }
}
