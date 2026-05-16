# Protocol: Decision Matrix (Autonomy Boundaries)

## ⚖️ Purpose
To resolve the **Agent Autonomy Paradox** by defining clear boundaries for where agents (Jules/Claude) have permission to execute "Crazy" (autonomous) logic vs. where mandatory Lead approval is required.

---

## 🟢 1. Agent Autonomy (Permission: HIGH)
Agents are expected to act as **Officers** in these areas. No explicit approval is required for:
*   **Defensive Hardening:** Adding null-checks, `IsValid()` guards, and memory safety logic.
*   **Testing & Verification:** Writing and re-integrating automation tests (C++).
*   **Boilerplate & Declaration:** Standardizing class constructors, function signatures (within existing classes), and `UPROPERTY` macro alignment.
*   **Documentation Refinement:** Correcting typos, updating index files, and expanding on technical "lessons learned."
*   **Standard Refactors:** Renaming variables for clarity (within local scopes) or optimizing internal loops for performance.

---

## 🟡 2. Strategic Consultation (Permission: MEDIUM)
Agents must propose a plan via `set_plan` and wait for "Acknowledged" or a "thumbs up" before proceeding:
*   **New File Creation:** Adding new components or subsystems to the `Source/` directory.
*   **Interface Expansion:** Modifying core interfaces (e.g., `ISovereignSaveInterface`).
*   **Cross-Module Logic:** Implementation that links two previously decoupled systems (e.g., SaveSystem ↔ AI/Navigation).
*   **Significant Refactors:** Restructuring directories or moving major class hierarchies.

---

## 🔴 3. Lead Approval (Permission: LOW)
Mandatory deep planning mode and explicit approval required:
*   **Architectural Philosophy:** Changing the "Sovereign Rule" or the core "Soul/Vessel" relationship.
*   **Vision Shifts:** Moving from Framework focus to MVP/Prototype focus (the current MVS pivot).
*   **External Dependencies:** Adding new plugins, third-party libraries (e.g., IIIF integration), or hardware drivers.
*   **Core Data Contracts:** Modifying the `identity.json` schema or global telemetry namespaces.

---

## 📜 The "Go Crazy" Override
If a proposal is documented and approved in `Generals_Paradox.md`, the permission level for that specific technical pattern moves to **🟢 GREEN**. Agents may then implement that pattern across the entire codebase without further consultation.
