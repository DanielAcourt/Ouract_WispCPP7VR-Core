# Black Box Protocol (B-002) Technical Documentation

## 📜 Overview
The **Black Box Protocol** is a high-reliability data persistence system within the Sovereign Framework. Its purpose is to capture and survive "Critical Truth" (telemetry and state changes) independently of the primary game save system.

This protocol is essential for "Message in a Bottle" scenarios, where data must be ingested by external low-power systems (like a Raspberry Pi) for historical analysis or digital museum preservation.

---

## 🏗️ Architecture

The system is split into two primary components to ensure decoupling and reliability:

### 1. `USovereignBlackBoxComponent` (The Observer)
*   **Role:** Attached to Actors that require high-fidelity logging.
*   **Logic:**
    *   Inherits from `USovereignSaveableEntityComponent` (The Soul).
    *   Uses **Delta-Based Logging**: It scans the Actor's `ISovereignSaveInterface` data and only logs values that have changed beyond a `LoggingThreshold` (default 0.2).
    *   Caches the `LastTruthValues` to prevent redundant logging.
*   **Trigger:** `RecordTruthSnapshot()` can be called manually or via a timer/heartbeat.

### 2. `USovereignBlackBoxSubsystem` (The Recorder)
*   **Role:** A `UWorldSubsystem` that handles the heavy lifting of file I/O.
*   **Logic:**
    *   Manages the `/Saved/BlackBox/` directory.
    *   **Atomic Write Pattern:** Writes data to a `.tmp` file first, then moves it to the final destination. This prevents file corruption during system crashes or power failures.
    *   **Batching:** Appends new entries to the entity's specific JSON file (`BB_[EntityID].json`).

---

## 🛠 Usage within Unreal Engine

### Adding Black Box to an Actor
1.  Ensure your Actor implements `ISovereignSaveInterface`.
2.  Add a `USovereignBlackBoxComponent` to the Actor.
3.  In the Component details:
    *   Set the `LoggingThreshold` (e.g., 0.1 for high sensitivity).
    *   Ensure the `EntityID` is initialized (the Soul handles this).

### Triggering a Snapshot
You can trigger a snapshot from Blueprint or C++:

**Blueprint:**
*   Call `RecordTruthSnapshot` on the `SovereignBlackBox` component.

**C++:**
```cpp
BlackBoxComp->RecordTruthSnapshot();
```

---

## 📂 File Structure & Format
Logs are stored in the project directory:
`[Project]/Saved/BlackBox/BB_[GUID].json`

**Example JSON Format:**
```json
{
  "Logs": [
    {
      "Timestamp": "2026.05.13-10.15.30",
      "Key": "Telemetry.TemperatureCelsius",
      "Value": 24.5
    },
    {
      "Timestamp": "2026.05.13-10.16.45",
      "Key": "Telemetry.PhValue",
      "Value": 7.2
    }
  ]
}
```

---

## 🚀 Why Use the Subsystem?
The `USovereignBlackBoxSubsystem` provides a **Decoupled Recording Layer**. By passing data to the subsystem, the individual Actors don't need to worry about:
*   File path management.
*   JSON serialization complexities.
*   Atomic file operations.
*   Performance hits from synchronous I/O (the subsystem can be optimized for async operations in the future without changing the Actor logic).

This alignment follows the **Officer Principle**: understanding that the "Vessel" (Actor) generates the data, but the "Logistics" (Subsystem) ensures its survival.
