// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28
# Sovereign UI Integration Guide: The Nested Interface

**Version:** 36.4.7-Knight-AAS
**Status:** ACTIVE
**Lead:** Dan | **Tactician:** Jules

## 1. Overview
The v36.4.7 update introduces a **Nested UI Architecture**. Instead of manually passing references and parsing JSON in every widget, the system now uses a **Master HUD** that automatically discovers and initializes specialized sub-widgets.

## 2. The Core Classes
- **`USovereignMasterHUD`**: The container. Place this on your screen. It finds the `SoulHub` on the player and injects it into all children.
- **`USovereignBaseWidget`**: The base for every small module (e.g., a Health Bar, a Mana Meter). It handles visibility and data mapping automatically.

---

## 3. Blueprint Implementation Guide (Step-by-Step)

### Step 1: Create a Sub-Widget (e.g., `WBP_BioVitals`)
1. Create a new Widget Blueprint.
2. **Reparent** the widget to `SovereignBaseWidget` (Class Settings -> Parent Class).
3. In the **Details** panel, set the **Category Name** to match a Broker (e.g., `Bio`, `Qi`, `Identity`).
4. **Visibility:** The widget will now automatically hide itself if the player doesn't have that Broker.

### Step 2: Display Data (The KISS Method)
You don't need to parse JSON. Use the `OnDataUpdated` event:
1. In the Event Graph, add the `Event OnDataUpdated`.
2. This event gives you a `CategoryData` Map (String to String).
3. Use `Find` on the Map with keys like "Hunger" or "Hydration".
4. Update your Progress Bars or Text blocks using these values.

### Step 3: Create the Master HUD (`WBP_MainHUD`)
1. Create a new Widget Blueprint and reparent it to `SovereignMasterHUD`.
2. Open the Designer.
3. **Drag and Drop** your sub-widgets (like `WBP_BioVitals`) into the Canvas or a Vertical Box.
4. That's it. The Master HUD will automatically find them and send them the data they need.

---

## 4. Advanced: The "Enum Switch" Pattern
If you want to dynamically spawn widgets based on what the entity actually has (instead of pre-placing them), you can use the Discovery helper:

1. In your HUD, call `SoulHub -> GetRegisteredCategories`.
2. Use a **ForEach Loop** on the resulting array.
3. Use a **Switch on String** (or a Map of Strings to Widget Classes) to decide which widget to spawn.
4. After spawning, call `InitializeWidget(SoulHub)` on the new widget.

## 5. Summary of Benefits
- **Zero Configuration:** Sub-widgets find their own data.
- **Dynamic Visibility:** If a "Rock" doesn't have "Bio", the Hunger bar simply vanishes.
- **Simplified Logic:** No `JsonUtilities` nodes required in Blueprints—just use the `CategoryData` map.

**07 - The Interface is the Window to the Soul.**

---
// [J] Finalized the UI Integration Guide to reflect the automated Nested UI workflow. 2026-06-28
