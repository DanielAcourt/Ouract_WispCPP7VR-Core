// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28
# Sovereign UI Integration: The Nested Observer Framework

**Version:** 36.4.7-Knight-AAS
**Status:** ACTIVE
**Lead:** Dan | **Tactician:** Jules

## 1. Executive Summary
The Sovereign UI Framework (v36.4.7) moves away from monolithic, hard-coded HUDs toward a **Nested Observer Pattern**. In this architecture, the UI is treated as a dynamic "Lens" that can be pointed at any entity in the simulation—be it the Player, an NPC, or a Sensed Actor—automatically adapting its display based on the "Soul" (Brokers) it discovers.

## 2. Core Architectural Components

### A. The Mediator: `USovereignSaveableEntityComponent` (The Soul)
This is the **Source of Truth**. It holds all the data brokers (Bio, Qi, Attributes). The UI does not talk to the brokers directly; it talks to this Hub.

### B. The Orchestrator: `USovereignMasterHUD` (The Lens)
This is your main UI container (Canvas). Its sole job is to:
1.  Establish a connection to a **Target Actor**.
2.  Locate the Soul Hub on that Target.
3.  Inject that Soul Hub reference into every child widget automatically.

### C. The Module: `USovereignBaseWidget` (The Filter)
These are your small, reusable "Sub-Widgets" (e.g., `WBP_BioBar`, `WBP_QiMeter`). Each one is configured to look for a specific **Category Name**.
- **Auto-Logic:** If the Target Actor has a matching Broker (e.g., "Bio"), the widget stays visible. If the Broker is missing (e.g., a Ghost has no Bio), the widget automatically **Collapses**.

---

## 3. Implementation Workflow

### I. Creating a Specialized Module
1.  **Create Widget:** Create a new Widget Blueprint (e.g., `WBP_AttributeSheet`).
2.  **Reparent:** Set the Parent Class to `SovereignBaseWidget`.
3.  **Configure Category:** In the **Details** panel, set the **Category Name** to match the Broker you want to observe:
    - `"Bio"` (Metabolism, Hunger, Hydration)
    - `"Qi"` (Spirit Energy, Alignment)
    - `"Attributes"` (Core Stats, XP)
    - `"Identity"` (GUID, Birth Timestamp)
4.  **Handle Data:** In the Event Graph, use **`Event OnDataUpdated`**. This event fires whenever the Soul Hub changes.
    - Use the provided **`CategoryData`** Map (String -> String) to update your text blocks or progress bars.

### II. Creating the HUD Container
1.  **Create HUD:** Create a new Widget Blueprint (e.g., `WBP_TargetScanner`).
2.  **Reparent:** Set the Parent Class to `SovereignMasterHUD`.
3.  **Design:** Drag and drop multiple sub-widgets (from Step I) into your design.
    - *Tip: Use Horizontal/Vertical boxes. The "AutoHide" feature will automatically shift the layout when modules vanish.*

### III. Pointing the Lens (The Handshake)
The UI is agnostic; it doesn't care who it's watching until you tell it.

#### Case A: The Player HUD
In your PlayerController or Character Blueprint, when you create the widget:
```blueprint
// On BeginPlay or Possession
WBP_PlayerHUD -> InitializeMasterHUD(Self);
```

#### Case B: The Sensing/Questioning HUD
When you hit an actor with a line trace, or a sensor detects an entity:
```blueprint
// When an actor is sensed/targeted
WBP_TargetScanner -> InitializeMasterHUD(SensedActor);
WBP_TargetScanner -> SetVisibility(Visible);

// When the target is lost
WBP_TargetScanner -> InitializeMasterHUD(nullptr);
WBP_TargetScanner -> SetVisibility(Collapsed);
```

---

## 4. Key Advantages for Simulation Playability
1.  **Target-Agnostic Design:** One single `WBP_BioBar` can be used for the Player, a Rabbit, or a Boss.
2.  **Dynamic Intelligence:** The UI "knows" what the target is. It won't show a Hunger bar for a Stone or a Magic bar for a non-magical entity.
3.  **Zero-Node Initialization:** Because `SovereignMasterHUD` iterates through its own `WidgetTree`, you never have to manually "Set Soul Hub" on 20 different sub-widgets.

## 5. R-010: Advanced Dynamic Attribute Mapping
If you want your UI to automatically scale as we add new stats to components (e.g., adding a new nutrient to Bio), use the **Dynamic Pair** system:

1.  **Create a Stat Pair Widget:** Create a simple widget (`WBP_StatPair`) with two text blocks.
2.  **Add a "SetStatData" Function:** In `WBP_StatPair`, create a function called **`SetStatData`** with two String inputs: `Label` and `Value`. Have this function update your two text blocks.
3.  **Configure the Module:** In your main module (e.g., `WBP_BioVitals`):
    - Add a **Vertical Box** and name it `PairContainer`. In the Variables list, check **"Is Variable"**.
    - In the Class Defaults, set the **Stat Pair Widget Class** to your `WBP_StatPair`.
4.  **Result:** Every time the data updates, the module will automatically spawn one `WBP_StatPair` for every piece of data in the category (Hunger, Hydration, etc.) and fill in the text for you.

**07 - The Interface is the Window to the Soul. If the Soul changes, the Window must follow.**

---
// [J] Rewrote the Integration Guide to emphasize the "Observer" nature of the UI and provide specific sensing use-cases. 2026-06-28
