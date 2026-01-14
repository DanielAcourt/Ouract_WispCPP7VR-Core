# Architectural Analysis: Sovereign Framework Data Persistence

This document details the current data flow and interaction between the key components of the Sovereign Framework's save system.

### 1. `SovereignSaveGame.h`: The Data Container

- **Struct:** `FSovereignActorData`
- **Key Property:** `TMap<FString, FString> MetaTags`

**Architectural Role:**
The `FSovereignActorData` struct is the fundamental unit of persistence in this framework. It acts as a "suitcase" for a single actor's state that is written to and read from the save file.

The most critical property for dynamic data is `MetaTags`. This `TMap` is a flexible, string-based key-value store. It serves as a universal container for any piece of data that isn't rigidly defined in the struct itself (like `Transform` or `EntityID`). It can store anything from `GrowthStage:5` to `PlayerName:Isla`. This design is highly adaptable but relies on the save/load logic to correctly interpret the string keys.

---

### 2. `SovereignBaseEntity.h/.cpp`: The Tag Provider

- **Interface:** `IGameplayTagAssetInterface`
- **Function:** `GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const`

**Architectural Role:**
`ASovereignBaseEntity` is the source for an entity's core identity tags. By implementing `IGameplayTagAssetInterface`, it hooks into Unreal's native gameplay tag system.

The `GetOwnedGameplayTags` function is the primary data source for this. It collects all `FGameplayTag` objects stored in the entity's `GameplayTags` container and its `IdentitySignature`.

**Interaction with Persistence:**
Crucially, the data from `GetOwnedGameplayTags` is **not directly saved as `FGameplayTag` objects**. Instead, the save system (specifically the `CaptureFullEntityState` function in `USovereignSaveableEntityComponent`) is responsible for:
1.  Calling `GetOwnedGameplayTags`.
2.  Converting each `FGameplayTag` into a string.
3.  Storing that string inside the `MetaTags` map of the `FSovereignActorData` struct.

This creates a one-way data flow: `FGameplayTag` -> `String` -> `TMap` -> `Save File`. The reverse process happens on load.

---

### 3. `SovereignSaveableEntityComponent.h`: The Data Hub & "Nbit Matrix" Insertion Point

- **Class:** `USovereignSaveableEntityComponent`

**Architectural Role:**
This component is the central hub for all of an entity's saveable data. It holds the entity's core identity (`EntityID`), its lineage (`ParentID`, `MotherID`), its biological state, and its evolutionary progress. It is also responsible for the master "scrape" function, `CaptureFullEntityState`, which gathers data from all other components and the base actor.

**Proposed Insertion Point for the "Nbit Matrix":**
To ensure the `uint64` status bitmask is saved and loaded correctly, it must be a `UPROPERTY` within this component. This hooks it into Unreal's reflection system, making it automatically discoverable by serialization processes.

The ideal location to add the property is within the "IDENTITY" or a new "STATUS" section of the component's header file.

```cpp
// SovereignSaveableEntityComponent.h

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WISPCPP7VR_API USovereignSaveableEntityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USovereignSaveableEntityComponent();

    // ... other functions

    /** --- 1. IDENTITY --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Core")
    FGuid EntityID;

    /** --- PROPOSED NEW SECTION --- */
    /** --- 1.5. STATUS FLAGS (The "Nbit Matrix") --- */
    UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Status")
    uint64 StatusBitmask;
    /** --- END PROPOSED SECTION --- */


    /** --- 2. LINEAGE & BREEDING --- */
    // ... other properties
};
```

**Interaction and Final Data Flow:**
By adding the `StatusBitmask` here, the `CaptureFullEntityState` function would be modified to read this `uint64` value, convert it to a string (e.g., `"Status:12345"`), and insert it into the `MetaTags` map of the `FSovereignActorData` struct, just like it does with gameplay tags. This ensures that this new, highly efficient status tracking system integrates seamlessly into the existing, flexible persistence architecture.
