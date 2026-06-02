# Sovereign Framework - Architectural Updates

This document summarizes the major architectural refactors and improvements implemented in the Sovereign Framework.

## 1. Interface-Based Possession System

**Conclusion:** The previous possession system was tightly coupled, relying on a direct `Cast` to a specific character class. This made it impossible to possess other entity types (e.g., non-character pawns, simple interactable objects) without significant code changes.

**Upgrade:**
-   The core interaction interface, `IInteractionInterface`, has been expanded with three new functions:
    -   `CanBePossessed()`: Allows an entity to declare if it can be possessed.
    -   `RequestPossession(AController*)`: The command to initiate the possession.
    -   `GetPossessionAttachmentComponent()`: Specifies which component the spirit should attach to, providing visual consistency.
-   The `ASovereignPlayerWisp` now uses this interface exclusively, removing all hard-coded class dependencies.
-   **Result:** Any actor that implements this interface can now be made possessable, fulfilling the "possess any actor" requirement and creating a truly decoupled system.

## 2. Asynchronous Asset Loading

**Conclusion:** Several systems, particularly the `Evolve` function in `ASovereignBaseEntity`, were using `LoadSynchronous` to load new `UStaticMesh` assets. This is a blocking operation that halts the game thread, causing significant frame rate drops ("hitches"), which is especially disruptive in VR.

**Upgrade:**
-   The `RefreshVisuals` function has been refactored to use the `FStreamableManager`.
-   It now calls `RequestAsyncLoad` to load the mesh in a background thread.
-   A callback function, `OnMeshLoaded`, applies the mesh to the component once it is fully loaded into memory.
-   **Result:** Entities can now evolve and change their visual representation with zero impact on the main game thread, ensuring a smooth frame rate.

## 3. Data-Driven & Asynchronous Spawning (`USovereignSpawnManager`)

**Conclusion:** Actor spawning was previously handled by a static utility library (`USovereignSpawnerUtils`). This system was not fully data-driven, as it required the calling code to provide a hard-coded `TSubclassOf<AActor>` to spawn. It was also entirely synchronous, making it unsuitable for high-velocity swarm simulations.

**Upgrade:**
-   A new **`USovereignSpawnManager`** has been implemented as a `UGameInstanceSubsystem`, providing a centralized, globally accessible manager for all entity spawning.
-   **Data-Driven:** The system now operates on `USovereignSpeciesData` assets. A `TSoftClassPtr<ASovereignBaseEntity>` was added to the data asset, allowing designers to specify the exact Blueprint class to spawn for each species directly in the editor.
-   **Asynchronous:** The manager uses an internal queue and the `FStreamableManager` to handle all spawn requests asynchronously. A call to `RequestSpawn` returns instantly, and the class loading and actor spawning occur in the background without blocking the game.

## 4. Identity Guarding (Component-First Enforcement)

**Conclusion:** v36.4.3 introduced a "Graceful Sync" for the transition from Actor-based to Component-based identity. v36.4.4 completes this by enforcing the Component-First standard.

**Upgrade:**
-   **Surgical Cleanup:** Removed `IdentitySignature` from `ASovereignBaseEntity` and `USovereignSpeciesData`.
-   **Component Authority:** The `USovereignSpawnManager` now performs an **Identity-Class Bridge Check** using the `SpeciesTag` inside the `USovereignSaveableEntityComponent` (The Soul).
-   **Decoupling:** This refactor allows for "External Soul" attachment—the ability to add a Sovereign identity to *any* actor class, which is vital for the Digital Museum and runtime API asset ingestion.
-   **Result:** The framework is now fully composition-based for identity, eliminating legacy inheritance bottlenecks.

## 5. Digital Twin Telemetry Bridge (B-001)

**Conclusion:** The framework needed a standardized way to consume real-world IoT telemetry (e.g., from a Raspberry Pi) and map it to actor properties for the Fish Tank Alpha simulation.

**Upgrade:**
-   **Standardized Namespace:** Established the `Telemetry.` namespace for all IoT-linked save data keys (e.g., `Telemetry.temp_c`, `Telemetry.ph_val`).
-   **Physical Persistence Layer:** Modified `ASovereignBaseInteractable` to implement `ISovereignSaveInterface`. This allows the actor to manage its own physical properties during the save/load pipeline.
-   **The Soul-Vessel Bridge:** Updated `USovereignSaveableEntityComponent` (The Soul) to include a "Physical Pass" that delegates state capture and restoration to the owner actor.
-   **Result:** The framework can now ingest live JSON telemetry from external hardware and automatically synchronize the simulation's physical state.
