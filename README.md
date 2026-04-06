# Sovereign Framework: WispCPP7VR

## 🌌 Overview
The **Sovereign Framework** (WispCPP7VR) is a high-performance, modular C++ architecture for Unreal Engine, designed for immersive VR experiences. It provides a robust foundation for entity possession, data-driven simulations, and real-time environmental telemetry. The framework blends rigorous technical standards with a spiritual, meditative theme centered around "Wisps," "Souls," and "Possession."

---

## 🏛️ Sovereign Intelligence Hierarchy (SSoT)
The project adheres to a strict **Single Source of Truth (SSoT)** hierarchy to ensure alignment between high-level intent and low-level implementation.

*   **Level 0 (MD.md):** The Timeline and Evolution. Tracks the project's historical context and long-term vision.
*   **Level 1 (AGENTS.md):** The Rulebook. Standard operating procedures, coding conventions, and architectural constraints.
*   **Level 2 (Identity):** The Internal Logic. `identity.json` and `USovereignSaveableEntityComponent` (The Soul) define the "Current Truth" for every actor in the world.

---

## 👻 The "Soul" Architecture (`USovereignSaveableEntityComponent`)
The core of every entity in the Sovereign Framework is the **Soul**. This actor component serves as the **Primary Brain** and central data container.

*   **Identity Persistence:** Ensures that an entity's identity, attributes, and state persist across serialization (JSON/Binary) and possession cycles.
*   **Single Point of Truth:** All systems (Possession, Growth, Save/Load) interact with the Soul component rather than the Actor directly, ensuring class-agnostic compatibility.

---

## 🛸 Possession Lifecycle & SOP
Possession is a critical mechanic governed by a strict **Standard Operating Procedure (SOP)** to prevent actor-state corruption and ensure visual consistency in VR. The lifecycle is managed by `HandlePossessionLifecycle()`, which toggles between entering and exiting a host.

### The "Sovereign Rule" for Transforms
All attachments during the possession lifecycle **must** use:
`FAttachmentTransformRules::SnapToTargetNotIncludingScale`
This ensures the possessing Spirit does not inherit the scale of its host Vessel, maintaining visual integrity.

### Technical Implementation Sequence:

#### 1. Entering a Host (`AttemptPossession`)
*   **Targeting:** Performs a `SphereTraceSingleForObjects` to find a valid Vessel.
*   **Validation:** Checks `CanBePossessed()` via the `IInteractionInterface`.
*   **Attachment:** Uses the "Sovereign Rule" to attach to the target's `GetPossessionAttachmentComponent()`.
*   **Control Handover:** The Player Controller `Possess()`es the target Pawn.
*   **Spirit State:** The Spirit actor is hidden, and collision is set to `QueryOnly` to avoid physical interference while inhabiting the host.

#### 2. Exiting a Host (`EjectFromHost`)
*   **Unhide & Physics:** Restores the Spirit's visibility and `QueryAndPhysics` collision.
*   **Detachment:** Calls `DetachFromActor(FDetachmentTransformRules::KeepWorldTransform)`.
*   **Safe Offset:** Applies a safe world offset (e.g., `Z + 80.0f`) to prevent the Spirit from spawning inside the host's collision.
*   **Re-possession:** Control is handed back to the Spirit actor via `PC->Possess(this)`.

---

## 🐟 Digital Twin & Fish Tank Alpha (FTA)
The Sovereign Framework features advanced "Digital Twin" capabilities, allowing it to consume real-world IoT data.

**Fish Tank Alpha (FTA)** is the flagship implementation of this system, mapping live environmental telemetry from `DansOfficeTank_0` to Unreal Actor properties:
*   `temp_c`: Water temperature (Celsius).
*   `ph_val`: pH level.
*   `water_depth_mm`: Water depth in millimeters.

---

## 🎮 Input Conventions
The framework enforces a standardized input model to ensure a consistent user experience:
*   **[F] Key:** Possession lifecycle (Initiate Possession / Unpossess / Eject). Bound to `HandlePossessionLifecycle`.
*   **[E] Key:** Contextual Interaction (Harvesting, Activating, Conversing). Bound to `Interact`.

---

## 🛠️ Technical Features
*   **Interface-Based Possession:** Decoupled `IInteractionInterface` allows any Actor to become a possessable Vessel.
*   **Asynchronous Asset Loading:** Uses `FStreamableManager` for zero-hitch mesh updates and entity evolution.
*   **Data-Driven Spawning:** `USovereignSpawnManager` utilizes `USovereignSpeciesData` for class-agnostic, async actor instantiation.
*   **Identity Guarding:** A "Logic Gate" check ensures the physical Actor class matches its logical Identity Signature before spawning.

---

## 📜 Development Guidelines
*   **Sovereign_DevOps/:** The "Neutral Zone" for shared data (telemetry.json, sim_feedback.json) and documentation.
*   **Polite Persistence:** Saveable components extract only their relevant keys from the "Suitcase" (`TMap<FString, FString>`), ensuring clean data management.
