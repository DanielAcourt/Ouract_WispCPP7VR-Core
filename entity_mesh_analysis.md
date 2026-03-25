# Sovereign Entity and Mesh Architecture Report

## 1. Architectural Overview

The Sovereign system has been refactored into a component-centric, interface-driven architecture where the **Sovereign Soul** (`USovereignSaveableEntityComponent`) acts as the single source of truth for an entity's identity, state, and growth.

### Core Hierarchy
*   **ASovereignBaseEntity (APawn)**: The base for non-skeletal or simple mobile entities (Trees, Items).
*   **ASovereignBaseCharacter (ACharacter)**: The base for complex skeletal entities (Erisis, Animals).
*   **ASovereignBaseInteractable**: A lean layer for interactive objects, now stripped of redundant mesh components.

Both hierarchies are now unified through the **ISovereignEntityInterface** and **IInteractionInterface**.

## 2. Mesh and "Basemesh" Resolution

### Polymorphic Mesh Access
The "Basemesh" is no longer a specific variable name to be used for components. Instead, the system uses a polymorphic `GetPrimaryMesh()` function defined in the interface.
*   In `ASovereignBaseEntity`, it returns the `EntityMesh` (Static).
*   In `ASovereignBaseCharacter`, it returns the native `Mesh` (Skeletal).
*   This allows systems (like the Wisp or VFX) to interact with "The Mesh" without knowing the underlying class.

### Unified Growth System
The "Basemesh" concept now lives within the **FSovereignGrowthStage** data record.
*   **Data Record**: `FSovereignGrowthStage` now uses `TSoftObjectPtr<UStreamableRenderAsset>`, supporting both `UStaticMesh` and `USkeletalMesh`.
*   **Soul-Led Refresh**: The Soul component triggers the `Evolve()` command via the interface. The Actor then calls `RefreshVisuals()`, which handles the asynchronous loading and application of the correct mesh type (Static or Skeletal) to the `PrimaryMesh`.

## 3. Interface and Interaction Flow

### Consolidated Interfaces
*   **ISovereignEntityInterface**: Handles identity and internal data access (`GetSovereignSoul`, `GetPrimaryMesh`).
*   **IInteractionInterface**: Handles external actions ([E] for Interact, [F] for Possess).

### Input Standardization
The system is now prepared for a "Push" model:
*   **Interact [E]**: Triggers `Execute_OnInteract`.
*   **Possess [F]**: Triggers `Execute_RequestPossession`.
*   The **Wisp** (or Player Controller) performs the trace and calls these interface functions, keeping the Actors lean and focused only on their specific reactions to these triggers.

## 4. Possession Handshake

The possession logic has been unified:
*   **Pawns**: Use the standard `Controller->Possess()` flow.
*   **Non-Pawns**: Use a "Spirit Link" state where the Wisp attaches to the `PrimaryMesh` and manages the input bridge/state without requiring the target to be a Pawn.
*   **Ejection**: A standardized `RequestSoulEject` command ensures the Wisp can exit any host (Pawn or Actor) and return to its free-roaming state.

## 5. Summary of Key Changes
| Feature | Implementation | Owner |
| :--- | :--- | :--- |
| **Primary Mesh** | `GetPrimaryMesh()` -> `UMeshComponent*` | Actor (via Interface) |
| **Growth Logic** | Supports Static & Skeletal | Sovereign Soul -> Actor Refresh |
| **Input [E]** | Interaction (Eat, Open, Talk) | IInteractionInterface |
| **Input [F]** | Possession (Wisp Enter/Exit) | IInteractionInterface |
| **BaseMesh** | **DELETED** | N/A (Uses EntityMesh) |
