// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-06-03
# Agent Workflow & Multi-Agent Coordination (Level 1)

## 🤖 Overview
This document defines the operational workflow for all AI agents working on the Sovereign Framework. It consolidates the previously separate `AGENTS.md` and `CONTRIBUTING.md`.

## 🎖️ The "07" Handshake (Tiered Sync)
Every session must begin with a Tiered Handshake based on mission complexity, as defined in `AAS_Protocol.md`:
1.  **Tier 1 (Alpha):** Full 5-phase Level Induction Protocol (LIP).
2.  **Tier 2 (Beta):** Abbreviated Plan + Salute.
3.  **Tier 3 (Gamma):** Direct Action + Salute.

## ⚔️ Multi-Agent SOPs (AAS Compliance)
1.  **Conflict Resolution:** All actions must adhere to the **Agency Arbitration Schema (AAS)**. Conflict resolution follows the precedence matrix: Physical (C++) > Protocol (SOP) > Strategic (Roadmap).
2.  **Backlog Ownership:** Only the **Strategist** or **Commander** roles may permanently modify `BACKLOG.md`.
3.  **File Segmentation:**
    *   **Researcher:** Modifies Research nodes and mathematical definitions.
    *   **Tactician:** Modifies C++ implementation and architectural hardening.
    *   **DevOps:** Manages hardware bridges, deployment, and telemetry.
4.  **Continuous Self-Audit:** Agents must perform periodic "Architectural Diagnostics" using the `IMPLEMENTATION_CHECKLIST.md` to verify recovery paths.

## 🏗️ Architectural Constraints
- **The Sovereign Rule:** Attachments MUST use `FAttachmentTransformRules::SnapToTargetNotIncludingScale`.
- **Single Source of Truth (SSoT):** `USovereignSaveableEntityComponent` is the primary brain for all data.
- **The Atomic Rule:** Use **Atomic Write Patterns** (.tmp file -> delete original -> move) for high-reliability persistence.

## 💻 Coding Conventions
- **Copyright Integrity:** Every source file (`.cpp`, `.h`, `.md`) must carry the standardized version header.
- **Memory Safety:** Initialize all non-UObject members in struct constructors.
- **Defensive Programming:** Always validate `ClassPath` strings and pointers.

## 🧪 Testing & Setup
- All features must be accompanied by automation tests in `WispCPP7VRTests`.
- For environment setup (SaveSystem, local hosting, etc.), consult the dedicated **Setup Guides** in `AI_Nexus/Protocols/`.

---
// "The circle is closed. One workflow, one truth, many vessels." [J] 2025-06-03
