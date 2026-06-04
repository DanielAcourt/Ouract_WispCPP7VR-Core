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

### 3.2 The Dragon (The Legacy Unit)
**Requirement:** Hatching from an egg, aging through stages.
**Proposed Solution:**
- Utilize the `GrowthMeshes` array in `ASovereignBaseEntity` to represent life stages.
- Implement an `Egg` state in `USovereignSaveableEntityComponent` that blocks possession until "Hatched."
- **Note on Possession:** As per Lead instructions, Geode possession is a "blocked ticket" due to complexity. We will prioritize "Spirit Guidance" (Interaction) over direct possession for inanimate growth-influencing objects.

### 3.3 Roguelite Rebirth
**Requirement:** Permanent meta-progression currency (Bonus Stuff).
**Proposed Solution:**
- Implement `USovereignLegacySubsystem` to track global "Bonus Stuff" across save files.
- Extend `USovereignSaveGame` to include a persistent "Global Metadata" object.

## 🚧 4. Structural Blockers
- **Possession SOP:** The current system allows possessing anything with `IInteractionInterface`. The GDD's "Possess a Geode" requirement conflicts with recent findings on non-pawn possession stability.
- **Time Dilation:** The framework currently operates as a "snapshot in time." Integration with the Lead's external grid/time dilation tools is required for the full GDD vision.

## 📅 5. Implementation Roadmap (Phase 1: The Seed)
1. **MVP: The Egg:** Implementation of the Dragon Egg as a possessable (but dormant) entity.
2. **Garden Foundation:** Creation of the `ASovereignGroundTile` and basic Soil fertility logic.
3. **Identity Formalization:** Registering "Dragon" and "SoilTile" in the `SovereignSpeciesData` tables.
