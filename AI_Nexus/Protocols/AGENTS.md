# AGENTS.md: The Rulebook (Level 1)

## 🤖 Multi-Agent Coordination SOP
This document serves as the primary rulebook for all AI agents (Jules, Claude) working on the Sovereign Framework.

### Roles & Responsibilities
- **Jules (Visual Cortex / DevOps & Structural Lead):** Focuses on the "Big Picture," DevOps integration, system-wide problem solving, and maintaining the structural integrity of the codebase. Jules ensures the "Vessel" and "Soul" are synchronized across the entire environment.
- **Claude (IDE Architect / Localized Logic):** Focuses on code-level implementation, specific architectural patterns within the IDE, and individual module logic. Claude works "inside the code" to build out the features defined by the framework.

### Communication Protocol
- Use `AI_Nexus/DevOps/_AGENT_CONTEXT.md` for active sprint status and task tracking.
- All major architectural shifts must be documented in `AI_Nexus/Protocols/`.
- Timeline updates and version history belong in `AI_Nexus/Timeline/MD.md`.

## 🏗️ Architectural Constraints
- **The Sovereign Rule:** All attachments during possession MUST use `FAttachmentTransformRules::SnapToTargetNotIncludingScale`.
- **Single Source of Truth (SSoT):** `USovereignSaveableEntityComponent` is the primary brain for all persistent data.
- **Interface-First Design:** Use `ISovereignEntityInterface` and `IInteractionInterface` to ensure class-agnostic compatibility.

## 💻 Coding Conventions
- **Memory Safety:** Initialize all non-UObject members in struct constructors (e.g., `FEntitySaveData`).
- **Defensive Programming:** Always validate `ClassPath` strings before spawning actors.
- **Performance:** Prefer looping `FTimerHandle` over `Tick()` for recurring logic (Qi drain, Heartbeat).

## 🧪 Testing Standards
- All new features should be accompanied by automation tests in the `WispCPP7VRTests` module.
- Gate testing dependencies using `Target.Configuration != UnrealTargetConfiguration.Shipping`.
