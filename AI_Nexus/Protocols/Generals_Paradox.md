# Protocol: The General's Paradox (Intent & Common Language)

## ⚔️ Purpose
To solve the paradox of the "Lead's Burden." This document acts as the definitive dictionary of **Intent**. Once a technical pattern or naming convention is "Stabilized" here, agents have a standing order to "Go Crazy"—executing that pattern autonomously to reduce the Lead's cognitive load.

---

## 🏗️ 1. Naming & Structural Intent

### 1.1 The "Sovereign" Prefix
*   **Intent:** All core framework classes MUST start with the `Sovereign` prefix (e.g., `USovereignSaveableEntityComponent`).
*   **Status:** **STABILIZED**. Agents are authorized to rename legacy "Wisp" classes to "Sovereign" when encountered.

### 1.2 Telemetry Namespace
*   **Intent:** Data keys for physical sensor data must use the `Telemetry.` prefix (e.g., `Telemetry.Temp_C`).
*   **Status:** **STABILIZED**. Autonomous correction of non-conforming keys is permitted.

---

## 🧬 2. Architectural Patterns

### 2.1 Interface-First Possession
*   **Intent:** Never `Cast` to a specific Character. Always use `IInteractionInterface` and `RequestPossession()`.
*   **Status:** **STABILIZED**. Agents should refactor any hard-casted possession logic on sight.

### 2.2 Async Asset Loading
*   **Intent:** No blocking `LoadSynchronous` on the game thread. Use `FStreamableManager` and `RequestAsyncLoad`.
*   **Status:** **STABILIZED**. Agents should replace synchronous loads with async patterns autonomously.

---

## 🧪 3. Formatting & Repository Standards

### 3.1 EditorConfig Compliance
*   **Intent:** Maintain Unreal Engine standards (Tabs, CRLF, 120-char limit) via root `.editorconfig`.
*   **Status:** **STABILIZED**. Agents are authorized to reformat non-conforming code.

### 3.2 Global Contributing Visibility
*   **Intent:** Ensure all agents and humans see the `CONTRIBUTING.md` at the root.
*   **Status:** **STABILIZED**.

---

## 🧪 4. Verification & Compliance

### 4.1 UE 5.7 World Context
*   **Intent:** Use explicit world context management in automation tests to avoid `GEngine` null-pointer crashes.
*   **Status:** **STABILIZED**. Agents are authorized to update all legacy tests to the 5.7 pattern.

---

## 🔄 5. Proposing New Stabilizations
To add to this document, the agent must:
1.  Identify a recurring pattern that causes "The General's Burden."
2.  Propose the "Stabilized Intent" to the Lead.
3.  Once approved, move the pattern to this list.

**Current Proposals:**
*   *Proposal A:* Standardizing the `FEntitySaveData` constructor to always include default values for all members.
*   *Proposal B:* Automatically adding `FSovereignBlackBoxEntry` triggers to all setter functions in `ASovereignBaseInteractable`.
