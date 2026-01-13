# Sovereign Architecture: Source of Truth

## 1. Project Vitals & Build Status

*   **Compilation Check:**
    *   **Status:** `Unknown`.
    *   **Details:** The Unreal Build Tool could not be located in the provided environment, preventing a compilation attempt. No build errors can be reported.

*   **Version Tracking:**
    *   **Git Commit Hash:** `3cf3955514318db5ade8a2556fb656aa33bd17de`
    *   **Config Version:** No project version is specified in `Config/DefaultGame.ini`.

*   **Include Order Check:**
    *   **Status:** `Not Found`.
    *   **Details:** The `EngineIncludeOrderVersion` setting is not explicitly defined in any of the project's build or target files. The project likely defaults to a backward-compatible version.

## 2. Entity & Component Mapping

*   **The Inheritance Tree:**
    *   The core inheritance hierarchy originating from `ASovereignBaseEntity` is as follows:
        ```
        ACharacter
        └── ASovereignBaseEntity (Implements IGameplayTagAssetInterface)
            └── ASovereignBaseInteractable
                ├── ASovereignBaseCharacter
                │   └── ASovereignPlayerWisp (Isla)
                └── ASovereignSaveTerminal
        ```
    *   No C++ classes for "Human" or "Elf" subclasses were found inheriting from this tree.

*   **Interface Audit:**
    *   **`IGameplayTagAssetInterface`:** The only class implementing this interface is `ASovereignBaseEntity`.
    *   **`GetOwnedGameplayTags`:** The override is correctly implemented in `SovereignBaseEntity.cpp`.

*   **Component Sync (C++ & Blueprint Analysis):**
    *   **Blueprint Analysis Limitation:** As a file-system-based agent, I cannot directly parse the binary `.uasset` format of Unreal Engine Blueprints. Therefore, the component list for `BP_PlayerWisp` and `BP_Human` cannot be directly audited. The following is an analysis of the foundational C++ parent classes.
    *   **C++ Parent Class Analysis:**
        *   **`ASovereignBaseEntity`:**
            *   `UStaticMeshComponent* EntityMesh`
            *   `USovereignSaveableEntityComponent* SaveDataComponent`
    *   **`ASovereignBaseCharacter` (inherits from above):**
        *   `USovereignAttributeComponent* AttributeComponent`
        *   `USovereignQiComponent* QiComponent`
        *   `USovereignElementComponent* ElementComponent`
        *   `USovereignControllerComponent* ControlComponent`
    *   **`ASovereignPlayerWisp` (inherits from above):**
        *   `UNiagaraComponent* SpiritEffect`

## 3. Search for the "Nbit Matrix"

*   **Code Search:**
    *   **Status:** `Not Found`.
    *   **Details:** A recursive search for "Nbit" and "Matrix" confirmed that no such data structure is currently implemented in the C++ source.

*   **Contextual Analysis & Proposed Location:**
    *   **Analysis:** The concept of an "Nbit Matrix" implies a need to track binary status flags (e.g., "IsPoisoned," "IsBlessed"), which does not fit within the numerical focus of the `USovereignAttributeComponent`.
    *   **Recommendation:** The best approach is to create a new `USTRUCT` (e.g., `FEntityStatusFlags`) containing a `uint64` bitmask. This new struct should be added as a property to the **`USovereignSaveableEntityComponent`** to ensure it is part of the entity's core, saveable state.

## 4. Tag & Data Structure Analysis

*   **Gameplay Tags (`DefaultGameplayTags.ini`):**
    *   The `PPC.` (Project Player Character) hierarchy is well-defined with several sub-tags.
    *   **`PPC.` Tags Found:**
        ```ini
        PPC
        PPC.Animal
        PPC.Animal.Birds
        PPC.Animal.Fish
        PPC.Animal.Mammal
        PPC.Animal.Mammal.Antelope
        PPC.Animal.Repitle
        PPC.Humanoid
        PPC.Humanoid.Elf
        PPC.Humanoid.HalfElf
        PPC.Humanoid.Human
        PPC.Humanoid.Orc
        PPC.State
        PPC.State.Awake
        PPC.State.Dormant
        ```
    *   The `Activity.` tag hierarchy was **not found** in the file.

*   **Save Structure:**
    *   **Primary Save Struct:** The core data structure for saving actor state is `FSovereignActorData`, located in `SovereignSaveGame.h`.
    *   **`MetaTags` Type:** The `MetaTags` property is explicitly defined as `TMap<FString, FString>`.
        ```cpp
        USTRUCT(BlueprintType)
        struct FSovereignActorData
        {
            GENERATED_BODY()

            UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
            FGuid EntityID;

            UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
            FString ClassPath;

            UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
            TMap<FString, FString> MetaTags;

            UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign")
            FTransform Transform;
        };
        ```
    *   **Unreadable Files:** `SovereignGameData.h` and `SovereignGameData.cpp` were found to be unreadable binary files, but the definition in `SovereignSaveGame.h` provides the required "Source of Truth."

## 5. Dead Code & Partially Implemented Subroutines

*   **`SovereignSaveManager.cpp`:**
    *   **Status:** `Clean`.
    *   **Details:** The file contains no `TODO` markers, empty function bodies, or large commented-out blocks.

*   **`SovereignJsonUtils.cpp`:**
    *   **Status:** `Contains Abandoned Code`.
    *   **Details:** A large commented-out block was found containing the functions `MapToJsonObject` and `JsonObjectToMap`. This suggests an abandoned implementation for `TMap` to JSON conversion, which has been superseded by the more direct serialization methods in the `SovereignSaveManager`.
