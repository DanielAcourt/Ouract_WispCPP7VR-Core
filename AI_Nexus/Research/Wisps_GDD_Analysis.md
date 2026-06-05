# Technical Research Report: Wisps GDD Analysis
**Persona:** Jules: The Designer (The Architect of Experience)
**Status:** Initial Assessment (v36.4.6)
**Date:** 2024-06-03

## 🌌 1. Executive Summary
This report analyzes the "Wisps" Game Design Document (GDD) against the current capabilities of the Sovereign Framework (WispCPP7VR). The framework provides a strong foundation for the "Garden Realm" through its data-driven spawning and "Soul" (USovereignSaveableEntityComponent) architecture. However, significant structural additions are required for the Dragon's lifecycle and Soil Mechanics.

## 🔍 2. Technical Mapping (GDD vs. Framework)

| GDD Feature | Existing Component/Logic | Match Level | Technical Notes |
|:---|:---|:---:|:---|
| **The Wisp (Possession)** | `ASovereignPlayerWisp` | **High** | Core possession lifecycle (Attach/Eject) is robust. Uses `IInteractionInterface`. |
| **Garden Realm (Persistence)** | `USovereignSaveManager` / `UActorRegistry` | **High** | JSON-based persistence of entity state is fully implemented. |
| **Plants & Animals (Ecology)** | `SovereignBioComponent` / `SovereignBaseEntity` | **Medium** | Metabolism, Hunger, and Growth (Mass/Density) are built but need "Garden" tuning. |
| **Dragon Lifecycle** | `SovereignSaveableEntityComponent` | **Low** | Requires "Egg/Hatch" state and specific age-based stat scaling. |
| **Soil Mechanics (Fertility)** | *Missing* | **None** | Needs a `USovereignSoilComponent` or Tile-based data structure. |
| **The Door (Dungeon)** | `ASovereignBaseInteractable` | **Low** | Placeholder interface exists; logic for party transition is missing. |

## 🛠️ 3. Gap Analysis & Proposed Solutions

### 3.1 Soil Mechanics (The Foundation)
**Requirement:** Ground Tiles with Fertility and Density.
**Proposed Solution:**
- Implement `ASovereignGroundTile` (AActor) inheriting from `ASovereignBaseEntity`.
- Add `USovereignSoilComponent` to handle the Fertility/Density ebb and flow.
- Link `SovereignBioComponent::UpdateMetabolism` to interact with the `SoilComponent` of the tile the entity is standing on.

### 3.2 The Dragon & The Cultivation Loop
**Requirement:** Hatching from an egg, aging through stages, and "Stalling" growth for power.
**Proposed Solution: The Cultivation Engine**
- **Possessable Egg:** The Dragon Egg is a "Living Vessel (Dormant)." The Wisp can possess it to enter a **Meditation State**.
- **Maturity & Over-Maturity (Compacted Power):**
    - `MaturityProgress` (0.0 -> 1.0): The biological path to hatching.
    - **Cultivation Zone** (1.0 -> 2.5+): Reaching "Over-Maturity" allows the Wisp to feed the egg beyond its natural limits.
- **The Stalling Mechanic (Maturity Reversal):** While possessing the egg, the player can actively "Compress Qi."
    - *Effect:* Consumes Wisp Qi to **subtract** from `MaturityProgress`. This allows for infinite stalling of the hatching process to maximize stat gains.
- **The "Consolidate" Spell (Possession Only):** A high-cost Wisp ability that can *only* be cast while possessing the egg in an Over-Mature state (Maturity >= 1.0).
    - *Effect:* Resets `MaturityProgress` (e.g., back to 0.2) and increases the **Compacted Power Tier** (e.g., Iron -> Steel).
- **Input & Control (The Meditation Map):** Since the Egg has no default UI, we will utilize a "Debug Action Map" for prototyping.
    - **Key [1]:** *Compress Qi* (Subtracts Maturity, increases Potential).
    - **Key [2]:** *Nurture* (Speeds up Maturity).
    - **Key [3]:** *Consolidate* (Reset Maturity + Tier Up - Requires Maturity >= 1.0).
    - **Key [4-9]:** Reserved for future Elemental Infusion spells.
- **Tier Impact (Sovereign Framework Integration):**
    - **Stat Multipliers:** Each Tier applies a permanent multiplier to `BaseConstitution` and `Strength`.
    - **Training Efficiency:** Increases `ClassDifficulty`, making subsequent growth slower but higher quality (Steel is harder to forge than Iron).
- **Visuals (Compacted Power):** Higher Tiers utilize a "Density Scale" (e.g., `VisualScale = 1.0 / Tier`). A Tier 3 Dragon Egg is physically smaller and has a higher visual "Density" (material shimmer/glow) than a Tier 1 Egg.
- **Hatching Choice:** Hatching is a deliberate Player Choice (Interact) once `MaturityProgress >= 1.0`. The player can choose to hatch a "Low-Tier Iron Dragon" quickly or stall for a "High-Tier Steel Dragon."

**Note on Possession:** Geode/Inanimate possession remains blocked. The Dragon Egg is treated as a "Living Vessel (Dormant)" to allow the Possession Handshake.

### 3.3 The Broker Integration (Truth Engine Alignment)
To align with the **Sovereign Soul Epic (S-001)**, the Wisps simulation will be encapsulated within the **Cultivation Broker**:
- **Diagnostic Broker:** Tracks raw bio-telemetry (Heartrate, Age in Seconds, Nutrient Absorption).
- **Cultivation Broker:** Translates raw telemetry into gamified stats (Qi Purity, Potential, Compacted Power Tier).
- **Benefit:** This allows the "Wisps" layer to be toggled off for a "Scientific View" of the Garden ecosystem.

### 3.4 Roguelite Rebirth (The Cycle of Legacy)
**Requirement:** Permanent meta-progression currency (Bonus Stuff) and cyclical evolution.
**Proposed Solution: The Soul's Echo**
- **The Soul's Echo (Death Metrics):** Upon Dragon death, the system scrapes metrics (`Tier`, `Age`, `QiSpent`) and converts them into **Bonus Stuff** (Permanent Currency).
- **The Resonant Egg (Shop):** Bonus Stuff can be spent at **The Door** to purchase "Resonant Eggs."
    - *Resonant Traits:* Start at a higher `CompactedPower.Tier`, or inherit improved `MaturityRate` multipliers.
- **The Spirit Grave (Garden Legacy):** When a Dragon dies, a `ASovereignSpiritGrave` actor is spawned at the death location.
    - *Effect:* The grave acts as a "Fertility Beacon," permanently increasing the `Fertility` of adjacent soil tiles. This turns failure into a literal foundation for future garden growth.
- **Persistence:** All legacy data is managed by the `USovereignLegacySubsystem`, which writes to a `SovereignGlobalSave` file, ensuring progress survives individual Dragon resets.

## 📐 4. Sovereign Framework Extension (Metadata Contract)
To ensure the "Cultivation Engine" remains deterministic and save-safe, the following metadata keys are now reserved within the `USovereignSaveableEntityComponent` "UnknownMetaTags" suitcase:

| Key | Type | Description |
|:---|:---:|:---|
| `Sovereign.Cultivation.Tier` | `int32` | The Compacted Power level (1: Iron, 2: Steel, 3: Obsidian). |
| `Sovereign.Cultivation.MaturityDelta` | `float` | Cumulative maturity subtracted via "Compress Qi". |
| `Sovereign.Cultivation.CycleCount` | `int32` | Total number of Consolidation resets performed. |
| `Sovereign.Cultivation.Potential` | `float` | Hidden multiplier for future stat training efficiency. |

### 4.1 Rationale: Identity vs. Engine
Cultivation markers (Tier, Potential) are stored in the **Soul's Suitcase (Metadata)** rather than the `QiComponent` to ensure:
1.  **Identity Persistence:** Tier is a marker of *who* the entity is, not just its current energy level. It must survive even if the Qi engine is modified or severed.
2.  **Interface Agility:** Metadata is accessible to the `SpawnManager` and `BioComponent` without requiring hard-links to the `QiComponent`, adhering to the "Modularity over Inheritance" directive.
3.  **Experimental Flexibility:** Allows for rapid iteration of the "Iron to Steel" logic without recompilation of core C++ component structures.

## 🚧 5. Structural Blockers
- **Possession SOP:** The current system allows possessing anything with `IInteractionInterface`. The GDD's "Possess a Geode" requirement conflicts with recent findings on non-pawn possession stability.
- **Time Dilation:** The framework currently operates as a "snapshot in time." Integration with the Lead's external grid/time dilation tools is required for the full GDD vision.

## 📅 5. Implementation Roadmap (Phase 1: The Seed)
1. **MVP: The Egg:** Implementation of the Dragon Egg as a possessable (but dormant) entity.
2. **Garden Foundation:** Creation of the `ASovereignGroundTile` and basic Soil fertility logic.
3. **Identity Formalization:** Registering "Dragon" and "SoilTile" in the `SovereignSpeciesData` tables.
