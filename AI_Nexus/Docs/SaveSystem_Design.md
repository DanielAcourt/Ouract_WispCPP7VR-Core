# Architecture: The Sovereign Save System

## 🏛️ 1. Philosophical Overview
The Sovereign Save System is designed around the principle of **Vessel-independent Persistence**. It ensures that an entity's "Soul" (its identity, history, and state) can survive the destruction, replacement, or evolution of its "Vessel" (its physical Actor representation).

---

## 🏗️ 2. Core Components

### 2.1 The Soul (`USovereignSaveableEntityComponent`)
*   **Role:** The Single Source of Truth (SSoT) for an entity.
*   **Responsibilities:**
    *   Maintaining a unique `FGuid` (EntityID).
    *   Tracking lineage (ParentID, MotherID, FatherID).
    *   Managing MetaTags (TMap of manifested truths).
    *   Handling serialization to and from JSON.

### 2.2 The Vessel (`AActor` with `ISovereignSaveInterface`)
*   **Role:** The physical manifestation of the Soul in the simulation.
*   **Responsibilities:**
    *   Implementing `ISovereignSaveInterface` to provide/consume state data.
    *   Executing physical logic based on Soul data (e.g., Applying a `Telemetry.TempC` value to a material parameter).

### 2.3 The Manager (`USovereignSaveManager`)
*   **Role:** The orchestrator of the persistence lifecycle.
*   **Responsibilities:**
    *   Capturing the state of all tracked entities in the world.
    *   Writing the "Suitcase" (SaveGame) to disk as JSON/Binary.
    *   Managing the registry of active GUIDs to prevent identity collisions.

---

## 📐 3. Data Flow: The Capture/Restore Loop

### 3.1 Capture Phase
1.  `SaveManager` iterates through the `UActorRegistry`.
2.  For each Actor, it finds the `USovereignSaveableEntityComponent`.
3.  The component calls `CaptureFullEntityState()`:
    *   It scrapes internal variables (Lineage, Alignment).
    *   It queries its owner via `ISovereignSaveInterface::GetSovereignSaveData()`.
    *   It scrapes all other Save-ready components (Qi, Attributes).
4.  The combined data is flattened into a `FEntitySaveData` struct and added to the JSON "Suitcase."

### 3.2 Restore Phase
1.  `SaveManager` reads the JSON file and parses entities.
2.  `SpawnManager` requests a spawn based on the `ClassPath`.
3.  Upon spawning, the new Actor's Soul component is initialized.
4.  `ApplyStateFromJsonObject()` is called:
    *   Identity and Lineage are restored.
    *   MetaTags are applied to components.
    *   Owner Actor is notified via `ISovereignSaveInterface::OnSovereignStateRestored()`.

---

## 🛡️ 4. Hardening & Safety

### 4.1 Void Safety
If a Soul component is initialized without a saved state, it generates a new GUID and defaults to "Nominal" values. Untracked entities are treated as "Transient" until their first successful save cycle.

### 4.2 Deterministic Spawning
The system uses `TSoftClassPtr` within `USovereignSpeciesData` to ensure that actor classes are loaded from data assets, eliminating hardcoded class references and allowing for runtime model swapping (The Matrix Museum).

### 4.3 Cyber-Physical Parity
The Save System supports real-time telemetry mapping. By treating incoming IoT data as a "Restoration Event," the system maintains parity between the physical device and its digital twin using the same pipeline as a standard game save.
