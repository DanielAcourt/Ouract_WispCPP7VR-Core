// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

/*1. The Data Structs (GardenData.h)
Class Type: "None" (Header Only)
The Data Model: This defines what a "Saved Actor" actually looks like (GUID, Transform, Tags). 
It’s the blueprint for the JSON.
Location: Public/SaveSystem/

Purpose: To define the "Language" of your save system. By putting Enums (GrowthState) and Structs (FEntitySaveData) here, you prevent circular dependencies.

Status: Do this first.*/

#pragma once

#include"CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "SovereignGameData.generated.h"

class AWispsGameModeBase; // Just type this line above the struct

USTRUCT(BlueprintType)
struct FItemDefaults : public FTableRowBase
{
    GENERATED_BODY()

    // we need this gameplay to be made or matched in some way!
    //Can be called Gameplaytag and be more genic as its not specific to a species but anything in the engine we define
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Identity")
    FGameplayTag SpeciesTag;

    // My first custom "SpeciesClass"
    // This should package things a bit nicer
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sovereign|Data")
    class USovereignSpeciesData* SpeciesVesselData;
};

UENUM(BlueprintType)
enum class EGrowthState : uint8
{
    Seed,
    Sprout,
    Mature
};

// --- 1. GLOBAL SCOPE ENUMS (This must be OUTSIDE of any class/struct) ---
UENUM(BlueprintType)
enum class EUpdateFrequency : uint8
{
    Realtime    UMETA(DisplayName = "Every Frame (Wisps/Animals)"),
    Standard    UMETA(DisplayName = "Every 1 Second (Plants/Growth)"),
    Slow        UMETA(DisplayName = "Every 10 Seconds (Geology/Rocks)"),
    Dormant     UMETA(DisplayName = "Only on Interaction (Statues/Fences)")
};

UENUM(BlueprintType)
enum class ESovereignElement : uint8
{
    None,
    // Alignment
    Light, Dark, Grey,
    // Core Natural
    Fire, Water, Earth, Nature, Air,
    // Special
    Electric, Fairy, Dragon
};

#include "Dom/JsonObject.h"

USTRUCT(BlueprintType)
struct FEntitySaveData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid MyGUID;

    /** The GUID of the entity (Wisp, Plant, or Tool) that created this object. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Lineage")
    FGuid ParentID;

    // --- Optinial i might rethink this approach as a Seperate component to "living things" DO WE ADD THESE so early on?? ---
    UPROPERTY()
    FGuid MotherID;

    UPROPERTY()
    FGuid FatherID;

    UPROPERTY()
    bool bIsFemale;

    UPROPERTY()
    int32 OffspringCount;

    UPROPERTY()
    TArray<FGuid> MatingHistory;
    // -----------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform WorldTransform;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGrowthState CurrentState;

    /** * THE SECRET SAUCE: Handles tags the system can't know in advance.
     * This is where your "Key:Value" scraper saves its data.
     */
    TSharedPtr<FJsonObject> UnknownMetaTags;


    /** * The blueprint path of the actor.
     * Essential if Player needs to respawn an object that was deleted.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
    FString ClassPath;

    // We save the frequency so the heartbeat restores correctly!
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
    EUpdateFrequency SavedFrequency;
};