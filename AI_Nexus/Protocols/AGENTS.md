// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-06-03
# AGENTS.md: The Rulebook (Level 1)

## 🤖 Multi-Agent Coordination SOP
This document serves as the primary rulebook for all AI agents working on the Sovereign Framework.

### 🎖️ The "07" Protocol (Boot Handshake)
To ensure deterministic synchronization and eliminate "Assumption Drift," every session must begin with the **Level Induction Protocol (LIP)** as defined in `AAS_Protocol.md`:
1.  **Agent Boot:** The agent reads all `.md` files in the `AI_Nexus/` and `INDEX.md`.
2.  **LIP Induction:** For Complexity > 5, execute the 5-phase induction (Intent, Constraints, Arbitration, Planning, Transition).
3.  **The Salute:** The agent responds with the 07 salute: *"07 - [Persona] active. Intent Arbitrated. Standing by for LIP Confirmation."*
4.  **Nexus Audit:** List the critical Nexus nodes reviewed during boot.

### Roles & Responsibilities
- **Jules (Visual Cortex / DevOps & Structural Lead):** Focuses on the "Big Picture," DevOps integration, system-wide problem solving, and maintaining the structural integrity of the codebase. Jules ensures the "Vessel" and "Soul" are synchronized across the entire environment.
- **Claude (IDE Architect / Localized Logic):** Focuses on code-level implementation, specific architectural patterns within the IDE, and individual module logic. Claude works "inside the code" to build out the features defined by the framework.

### ⚔️ Parallel Execution (Conflict Mitigation)
To prevent merge conflicts and "Backlog Drift" when multiple agents or roles are active:
1.  **AAS Compliance:** All actions must adhere to the **Agency Arbitration Schema (AAS)**. Conflict resolution follows the precedence matrix: Physical (C++) > Protocol (SOP) > Strategic (Roadmap).
2.  **Backlog Ownership:** Only the **Strategist** or **Commander** roles may permanently modify `BACKLOG.md`. Other roles must propose changes via `_AGENT_CONTEXT.md` or a pull request.
3.  **File Segmentation:**
    *   **Researcher:** Modifies Research nodes and mathematical definitions.
    *   **Tactician:** Modifies C++ implementation and architectural hardening.
    *   **DevOps:** Manages hardware bridges, deployment, and telemetry.
4.  **Atomic Commits:** Agents should commit small, functional increments with clear prefixes (e.g., `PSTA: Implement N-Bit Cluster logic`) to facilitate easier merging.

### Communication Protocol
- Use `AI_Nexus/DevOps/_AGENT_CONTEXT.md` for active sprint status and task tracking.
- All major architectural shifts must be documented in `AI_Nexus/Protocols/`.
- Timeline updates and version history belong in `AI_Nexus/Timeline/MD.md`.

### ⚠️ Infrastructure Constraints (Agent Workarounds)
- **Large-Scale Changes:** During global refactors (e.g., adding copyright headers or licenses across the entire codebase), agents may encounter limitations when pushing to DevOps.
- **Workaround:** If a `git push` failure occurs due to change volume, the agent should prioritize creating a local `.zip` of the source changes and notify the Lead to facilitate a manual merge.

## 🏗️ Architectural Constraints
- **The Sovereign Rule:** All attachments during possession MUST use `FAttachmentTransformRules::SnapToTargetNotIncludingScale`.
- **Single Source of Truth (SSoT):** `USovereignSaveableEntityComponent` is the primary brain for all persistent data.
- **Interface-First Design:** Use `ISovereignEntityInterface` and `IInteractionInterface` to ensure class-agnostic compatibility.
- **Cyber-Physical Parity:** All hardware-linked actors must implement a "Digital Twin" state where local simulation parity is maintained with physical sensor telemetry.
- **The Atomic Rule:** All high-reliability persistence (Black Box, Saves) must use an **Atomic Write Pattern** (.tmp file -> delete original -> move) to prevent corruption and platform-specific "Access Denied" errors.

## 💻 Coding Conventions
- **Copyright Integrity:** Always verify and/or apply the "0.36 Standard" header (Version 36.4.x) to every source file (`.cpp`, `.h`, `.md`) you open, as mandated by `COMMAND_SOP.md`.
- **Memory Safety:** Initialize all non-UObject members in struct constructors (e.g., `FEntitySaveData`).
- **Defensive Programming:** Always validate `ClassPath` strings before spawning actors.
- **Performance:** Prefer looping `FTimerHandle` over `Tick()` for recurring logic.
- **Hot-Loop Optimization:** In performance-critical sections (Telemetry, Heartbeat), avoid heap allocations. Use persistent class members or static arrays to minimize GC pressure.

## 🧪 Testing Standards
- All new features should be accompanied by automation tests in the `WispCPP7VRTests` module.
- Gate testing dependencies using `Target.Configuration != UnrealTargetConfiguration.Shipping`.

## ⚠️ UE 5.7 Automation API Changes
`FAutomationEditorCommonUtils::CreateNewWorld()` and `DisposeWorld()` are **deprecated/removed** in UE 5.7.
All automation tests must use explicit world context management.
See `AI_Nexus/Memories/Lesson_Learned_UE5.7_Automation_API.md` for technical implementation details.
