// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28
# Sovereign UI Integration Guide: The Modular Interface

**Version:** 36.4.7-Knight-AAS
**Status:** DRAFT / PROPOSAL
**Lead:** Dan | **Tactician:** Jules

## 1. Overview
With the transition to the **Modular Soul Hub** (`USovereignSaveableEntityComponent`), UI widgets no longer need to scrape raw data from multiple scattered components. The Hub acts as the **Mediator**, providing a unified gateway for all simulation data.

## 2. Core Communication Patterns

### A. Push: The Event-Driven UI (`OnStateChanged`)
For performance-critical UI (e.g., Vitals bars), widgets should **Subscribe** to the Hub's delegate.
- **When to use:** Health bars, Qi levels, real-time feedback.
- **Blueprint Logic:**
  1. `Event Construct`: Get the Actor's `USovereignSaveableEntityComponent`.
  2. `Bind Event to OnStateChanged`: Create a custom event to refresh the UI.
  3. `Refresh UI`: Pull the specific data needed (see below).

### B. Pull: The Categorized Query (`GetCategoryStateJson`)
The Hub provides a helper to get specific module data as a JSON string.
- **When to use:** Character sheets, detailed attribute menus, resonance charts.
- **Blueprint Logic:**
  1. Call `GetCategoryStateJson(CategoryName)` (e.g., "Bio", "Qi", "Attributes").
  2. Use Unreal's `Json Utilities` to parse the string into a Blueprint Struct or Map.

---

## 3. Recommended Widget Architecture

To maintain the modularity of the system, we recommend a **Nested Widget** approach:

### Level 1: The Master Sovereign HUD
A global container that finds the currently possessed or targeted entity. It doesn't know *how* to display Bio or Qi; it just holds the references.

### Level 2: Specialized Module Widgets
Small, reusable widgets designed for specific categories:
- `WBP_BioVitals`: Listens for `OnStateChanged`, pulls "Bio" category, updates Hunger/Hydration bars.
- `WBP_AttributeSheet`: Pulls "Attributes" JSON on-demand when the player opens the menu.
- `WBP_QiResonance`: Visualizes the `Resonance` map found within the "Qi" category.

---

## 4. Playability Features (Proposals)

### 1. The "Stability Meter" (Paradox Density)
Visualize the `ParadoxDensity` (Ξ) as a glitch effect or a status bar.
- **High Ξ:** Distorted UI, shifting colors, "Unknown" labels on certain stats.
- **Implementation:** Bind to `OnStateChanged` and read `1.0 - GetSystemConfidence()`.

### 2. Live Attribute "Training" Feedback
Since attributes now accumulate experience, the UI should show "XP Progress" for stats like Strength or Wisdom.
- **Implementation:** Pull the "Attributes" category and display the decimal part of the experience as a progress bar.

### 3. Soul Identity Card
A "flavor" widget that shows the `BirthTimestamp` and `EntityID`, translated into "Sovereign Years" using the logic already in the Hub.

### 4. Direct Bridge Interaction (Chat)
Use the `SendSimulationChat` function in the `USovereignBridgeSubsystem` to feed the ChatWindow. The Hub's `bIsBeingPossessed` flag can be used to toggle the UI style between "Observer" and "Pilot" modes.

---

## 5. Best Practices for Nested Widgets (UMG Implementation)

To make a truly flexible and playable experience, you should use **Composition**. Instead of one giant widget, build small modules and nest them.

### A. The "Reference Injection" Pattern
The biggest challenge with nested widgets is making sure every sub-widget has the correct Soul Hub reference.

1.  **Expose on Spawn:** In your sub-widgets (e.g., `WBP_BioBar`), create a variable `SoulHub` of type `USovereignSaveableEntityComponent`. Mark it as **Instance Editable** and **Expose on Spawn**.
2.  **The Parent Handshake:** In the Master HUD's `Construct` or `OnPossession` event:
    - Get the `SoulHub` from the player.
    - Set the `SoulHub` variable on all child widgets.
    - Call a "Initialize" function on the children to trigger their internal binding logic.

### B. Dynamic Module Loading (The "Module Slot" Pattern)
If you want the UI to change based on what components the entity actually has:

1.  **Named Slots:** In your Master HUD, use **Named Slots** instead of hardcoded widgets.
2.  **Component Discovery:**
    - On BeginPlay, the Master HUD asks the `SoulHub` for its `RegisteredBrokers`.
    - For each Broker (Bio, Qi, etc.), the HUD spawns the corresponding Widget and drops it into a Vertical/Horizontal Box.
    - This way, a "Rock" (which has no Bio) won't show a Hunger bar, but a "Bird" will.

### C. UI Polling vs. Events
- **Events (Efficient):** Use the `OnStateChanged` delegate for bars that change frequently.
- **Polling (Playable):** For text fields (like "Level" or "Name"), simply use a **Widget Binding** or a slow timer (0.1s) to pull data. This is often "good enough" for simulation-style UIs and easier to debug.

---

## 6. Blueprint Example: Refreshing Bio Vitals
```blueprint
// Inside WBP_BioVitals
Event RefreshVitals(USovereignSaveableEntityComponent* SoulHub)
{
    FString BioJson = SoulHub->GetCategoryStateJson("Bio");
    // Parse JSON...
    float CurrentHunger = JsonData.GetNumberField("Hunger");
    ProgressBar_Hunger->SetPercent(CurrentHunger / 100.0f);
}
```

**07 - The Interface is the Window to the Soul.**

---
// [J] Drafted the UI Integration Guide to enable the transition from structural code to a playable experience. 2026-06-28
