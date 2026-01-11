// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveSystem/SovereignSpawnerUtils.h"
#include "SaveSystem/SovereignActorRegistry.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h" 


// --- 1. PHYSICAL BIRTH ---
AActor * USovereignSpawnerUtils::SpawnEarnedEntity(UObject * WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform SpawnTransform, FGuid ParentID)
{
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    UActorRegistry* Registry = World ? World->GetSubsystem<UActorRegistry>() : nullptr;

    if (!World || !ActorClass || !Registry) return nullptr;

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AActor* NewEntity = World->SpawnActor<AActor>(ActorClass, SpawnTransform, SpawnParams);

    if (NewEntity)
    {
        if (auto* SaveComp = NewEntity->FindComponentByClass<USovereignSaveableEntityComponent>())
        {
            // Assign a brand new, unique 128-bit Identity
            SaveComp->EntityID = FGuid::NewGuid();

            // Assign the Parent ID (Lineage tracking)
            SaveComp->ParentID = ParentID;

            // Registration with the Global System
            Registry->RegisterActor(SaveComp->EntityID, NewEntity);

            UE_LOG(LogTemp, Log, TEXT("Sovereign: New Entity Born! ID: %s | Parent: %s"),
                *SaveComp->EntityID.ToString(), *ParentID.ToString());
        }
    }
    return NewEntity;
}

// --- 2. CLONE BIRTH (Single Parent) ---
AActor* USovereignSpawnerUtils::SpawnEarnedEntityInherited(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform SpawnTransform, AActor* ParentActor)
{
    if (!ParentActor) return nullptr;
    auto* ParentComp = ParentActor->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (!ParentComp) return nullptr;

    // Apply genetic drift (10% chance) to the parent's tags for the clone
    TMap<FString, FString> MutatedDNA = GenerateMutatedTags(ParentComp->GetUnknownMetaTags(), 0.1f);

    // Call physical birth
    AActor* Child = SpawnEarnedEntity(WorldContextObject, ActorClass, SpawnTransform, ParentComp->EntityID);

    if (Child)
    {
        if (auto* ChildComp = Child->FindComponentByClass<USovereignSaveableEntityComponent>())
        {
            // Apply the mutated traits
            ChildComp->ApplyMetaTags(MutatedDNA);
        }
    }
    return Child;
}

// --- 3. HYBRID BIRTH (Dual Parent) ---
AActor* USovereignSpawnerUtils::SpawnHybridEntity(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform SpawnTransform, AActor* Mother, AActor* Father)
{
    if (!Mother || !Father) return nullptr;

    auto* MomComp = Mother->FindComponentByClass<USovereignSaveableEntityComponent>();
    auto* DadComp = Father->FindComponentByClass<USovereignSaveableEntityComponent>();
    if (!MomComp || !DadComp) return nullptr;

    // 1. Record the union in their histories
    MomComp->MatingHistory.AddUnique(DadComp->EntityID);
    DadComp->MatingHistory.AddUnique(MomComp->EntityID);
    MomComp->OffspringCount++;
    DadComp->OffspringCount++;

    // 2. Recombine DNA (Handling unknown tags for Isla's dynamic system)
    TMap<FString, FString> ChildDNA = RecombineDNA(MomComp->GetUnknownMetaTags(), DadComp->GetUnknownMetaTags(), 0.05f);

    // 3. Physical Birth (Using Mother as primary ParentID for the registry)
    AActor* Child = SpawnEarnedEntity(WorldContextObject, ActorClass, SpawnTransform, MomComp->EntityID);

    if (Child)
    {
        if (auto* ChildComp = Child->FindComponentByClass<USovereignSaveableEntityComponent>())
        {
            ChildComp->MotherID = MomComp->EntityID;
            ChildComp->FatherID = DadComp->EntityID;
            ChildComp->ApplyMetaTags(ChildDNA);
        }
    }
    return Child;
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
