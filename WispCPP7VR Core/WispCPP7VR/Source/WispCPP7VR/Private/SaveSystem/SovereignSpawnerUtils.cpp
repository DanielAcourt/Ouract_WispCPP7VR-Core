// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveSystem/SovereignSpawnerUtils.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "SaveSystem/SovereignSpawnManager.h"


// --- 1. PHYSICAL BIRTH ---
void USovereignSpawnerUtils::SpawnEarnedEntity(UObject* WorldContextObject, const USovereignSpeciesData* SpeciesData, FTransform SpawnTransform, FGuid ParentID)
{
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return;

    if (USovereignSpawnManager* SpawnManager = World->GetGameInstance()->GetSubsystem<USovereignSpawnManager>())
    {
        SpawnManager->RequestSpawn(SpeciesData, SpawnTransform, ParentID);
    }
}

// --- 2. CLONE BIRTH (Single Parent) ---
void USovereignSpawnerUtils::SpawnEarnedEntityInherited(UObject* WorldContextObject, const USovereignSpeciesData* SpeciesData, FTransform SpawnTransform, AActor* ParentActor)
{
    if (!ParentActor) return;
    auto* ParentComp = ParentActor->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (!ParentComp) return;

    SpawnEarnedEntity(WorldContextObject, SpeciesData, SpawnTransform, ParentComp->EntityID);
}

// --- 3. HYBRID BIRTH (Dual Parent) ---
void USovereignSpawnerUtils::SpawnHybridEntity(UObject* WorldContextObject, const USovereignSpeciesData* SpeciesData, FTransform SpawnTransform, AActor* Mother, AActor* Father)
{
    if (!Mother || !Father) return;

    auto* MomComp = Mother->FindComponentByClass<USovereignSaveableEntityComponent>();
    auto* DadComp = Father->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (!MomComp || !DadComp) return;

    // 1. Record the union in their histories
    MomComp->MatingHistory.AddUnique(DadComp->EntityID);
    DadComp->MatingHistory.AddUnique(MomComp->EntityID);
    MomComp->OffspringCount++;
    DadComp->OffspringCount++;

    // TODO: The ChildDNA logic needs to be moved to the PostSpawnInitialize function
    // TMap<FString, FString> ChildDNA = RecombineDNA(MomComp->GetUnknownMetaTags(), DadComp->GetUnknownMetaTags(), 0.05f);

    // 3. Physical Birth (Using Mother as primary ParentID for the registry)
    SpawnEarnedEntity(WorldContextObject, SpeciesData, SpawnTransform, MomComp->EntityID);
}

// --- 4. GENETIC ENGINE ---
TMap<FString, FString> USovereignSpawnerUtils::RecombineDNA(const TMap<FString, FString>& MotherDNA, const TMap<FString, FString>& FatherDNA, float MutationChance)
{
    TMap<FString, FString> ChildDNA;
    TArray<FString> AllKeys;
    MotherDNA.GetKeys(AllKeys);
    for (auto& Elem : FatherDNA) { AllKeys.AddUnique(Elem.Key); }

    for (const FString& Key : AllKeys)
    {
        // Default to 10.0 if a parent is missing a specific trait
        float ValM = MotherDNA.Contains(Key) ? FCString::Atof(*MotherDNA[Key]) : 10.0f;
        float ValF = FatherDNA.Contains(Key) ? FCString::Atof(*FatherDNA[Key]) : 10.0f;

        // Crossover: 50/50 chance to take Mom or Dad's trait
        float ResultVal = FMath::RandBool() ? ValM : ValF;

        // Mutation: Apply the jitter
        if (FMath::FRand() < MutationChance)
        {
            ResultVal += FMath::FRandRange(-1.0f, 1.5f);
        }
        ChildDNA.Add(Key, FString::SanitizeFloat(FMath::Max(1.0f, ResultVal)));
    }
    return ChildDNA;
}

// --- 5. MUTATOR ---
TMap<FString, FString> USovereignSpawnerUtils::GenerateMutatedTags(TMap<FString, FString> SourceTags, float MutationChance)
{
    TMap<FString, FString> MutatedTags = SourceTags;
    for (auto& Elem : MutatedTags)
    {
        if (FMath::FRand() > MutationChance) continue;

        if (Elem.Value.IsNumeric())
        {
            float CurrentValue = FCString::Atof(*Elem.Value);
            // Jitter the value by +/- 10%
            float Jitter = FMath::FRandRange(0.9f, 1.1f);
            Elem.Value = FString::SanitizeFloat(CurrentValue * Jitter);
        }
    }
    return MutatedTags;
}

// --- 6. DEBUGGER ---
FString USovereignSpawnerUtils::GetEntityAncestry(AActor* TargetActor)
{
    if (!TargetActor) return "Invalid";
    UWorld* World = TargetActor->GetWorld();
    UActorRegistry* Registry = World ? World->GetSubsystem<UActorRegistry>() : nullptr;
    auto* SaveComp = TargetActor->FindComponentByClass<USovereignSaveableEntityComponent>();

    if (!SaveComp || !Registry) return "No Data";

    FString Tree = TargetActor->GetName();
    FGuid CurrentID = SaveComp->ParentID;

    // Max 5 levels to prevent loops or excessive recursion
    for (int32 i = 0; i < 5; ++i)
    {
        if (!CurrentID.IsValid()) break;
        AActor* P = Registry->FindActor(CurrentID);
        if (P)
        {
            Tree += " -> " + P->GetName();
            if (auto* Next = P->FindComponentByClass<USovereignSaveableEntityComponent>())
                CurrentID = Next->ParentID;
            else break;
        }
        else
        {
            Tree += " -> [Unknown Parent]";
            break;
        }
    }
    return Tree;
}

// --- 7. SCANNER ---
TArray<FString> USovereignSpawnerUtils::ScanForMutations(AActor* ChildActor, AActor* ParentActor)
{
    TArray<FString> Log;
    if (!ChildActor || !ParentActor) return { "Invalid" };
    auto* C = ChildActor->FindComponentByClass<USovereignSaveableEntityComponent>();
    auto* P = ParentActor->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (!C || !P) return { "Missing Component" };

    TMap<FString, FString> CTags = C->GetUnknownMetaTags();
    TMap<FString, FString> PTags = P->GetUnknownMetaTags();

    for (auto& E : CTags)
    {
        if (!PTags.Contains(E.Key))
        {
            Log.Add("NEW TRAIT: " + E.Key);
        }
        else if (PTags[E.Key] != E.Value)
        {
            Log.Add("MUTATED: " + E.Key + " (" + PTags[E.Key] + " -> " + E.Value + ")");
        }
    }
    return Log;
}

bool USovereignSpawnerUtils::CanBreed(AActor* ParentA, AActor* ParentB)
{
    if (!ParentA || !ParentB || (ParentA == ParentB)) return false;

    auto* CompA = ParentA->FindComponentByClass<USovereignSaveableEntityComponent>();
    auto* CompB = ParentB->FindComponentByClass<USovereignSaveableEntityComponent>();

    if (CompA && CompB)
    {
        // 1. Maturity Check (Flowers must bloom, Bees must be adults)
        if (CompA->MaturityProgress < 1.0f || CompB->MaturityProgress < 1.0f) return false;

        // 2. Class Match (Bees mate with Bees, Flowers with Flowers)
        if (ParentA->GetClass() != ParentB->GetClass()) return false;

        // 3. Gender Check (Still applies to biologicals)
        return CompA->bIsFemale != CompB->bIsFemale;
    }
    return false;
}
