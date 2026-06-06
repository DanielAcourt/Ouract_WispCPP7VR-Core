// Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Sovereign Framework: BACKLOG

This backlog uses Fibonacci scoring to estimate task complexity. It is designed to be "KISS" compliant and easily exportable to CSV/JSON for Lead tracking.

## 🎯 Active Phase: Infrastructure & Stabilization

| ID | Task | Complexity | Status | Node | Why (Context) | What (Completion Outcome) |
|:---|:---|:---:|:---:|:---|:---|:---|
| B-001 | Actor Synchronization (Fish Tank Telemetry) | 8 | Done | DevOps | Enable Unreal to act as a Digital Twin for real-world IoT sensors. | JSON/Binary telemetry correctly maps to ASovereignBaseInteractable properties. |
| B-002 | Data Survivability (Black Box Protocol) | 5 | Done (Hardened) | Research | Ensure mission data persists even if the simulation instance collapses. | Atomic (.tmp -> move) write pattern for telemetry logs with guaranteed integrity. |
| B-003 | Lidar Intelligence (Matrix Museum Summoning) | 13 | Todo | Research | Realize the 12-year vision of summoning historical artifacts into a spatial office. | Runtime ingestion and mesh reconstruction of high-fidelity Lidar datasets. |
| B-004 | "Corpse Possession" State Persistence | 3 | Todo | DevOps | Allow the Wisp to possess and reactivate dead or inactive vessels. | Possession lifecycle correctly restores state and controls for previously "dead" actors. |
| B-005 | Qi/Maturity Evolution Milestones | 5 | Todo | DevOps | Track the gamified "Reflection" state of entities over long timeframes. | Milestone system that triggers visual/logical evolution based on persisted Qi/Time. |
| B-006 | VR Interaction Polish (Possession Lifecycle) | 5 | Todo | Protocols | Ensure the core "Possession" mechanic is comfortable and intuitive for VR. | Zero-hitch possession transitions with localized haptic and visual feedback. |
| B-007 | Performance Baseline (1000+ Entities) | 8 | Todo | DevOps | Stress-test the USovereignSaveableEntityComponent for massive swarm scenarios. | Stable 60fps in VR while tracking and saving 1000+ active Sovereign entities. |
| B-008 | PSTA C++: N-Bit Topology Matrix | 8 | Todo | DevOps | Harden the T-pillar against single-sensor hardware glitches. | FPSTACluster implemented to evaluate health based on N sensors with agreement masks. |
| B-009 | PSTA C++: Exponential Trust Recovery | 5 | Todo | DevOps | Prevent "Decision Flapping" when a sensor returns to nominal range. | Hysteresis logic that slowly regains trust (Phi) using an exponential recovery curve. |
| B-010 | PSTA C++: Risk Velocity (Vi) Detection | 5 | Todo | DevOps | Detect failure before it happens by tracking the speed of health decay. | High-frequency derivative check (dVSS/dt) that triggers Caution on rapid descent. |
| B-011 | PSTA C++: Symmetrical Guard (Severance) | 8 | Todo | DevOps | Provide an autonomous "Hard-Kill" if AI intent violates physical reality. | Kernel-level check that triggers hardware severance when Intent/Truth delta is breached. |
| B-012 | Pi Kernel: Headless Safety Node | 13 | Todo | DevOps | Deploy the PSTA safety kernel on external Raspberry Pi hardware. | C++ PSTA implementation running headlessly on Pi 4 with physical relay control. |
| B-013 | Data Bridge: Pi-Unreal Telemetry Link | 8 | Todo | DevOps | Mirror real-world hardware truth in the Unreal reflection. | UDP/TCP listener subsystem in Unreal ingesting JSON telemetry from the Pi. |
| B-014 | Simulation: "Fish Tank" Visual Mapping | 5 | Todo | DevOps | Provide a high-fidelity visual representation of Pi-linked key species. | Dynamic materials and animations in Unreal that reflect live Pi sensor data. |
| B-015 | Replay: Time-Dilation scrubbing | 8 | Todo | DevOps | Enable forensic analysis of Black Box logs at various speeds. | Standardized replay interface for scrubbing through historical PSTA sessions. |
| B-016 | Save System Performance Audit | 5 | Todo | DevOps | Investigate reported 1-second lag during EditorSave operations. | Performance report and identified bottlenecks in serialization. |
| B-017 | "Dirty Flag" Serialization Optimization | 5 | Todo | DevOps | Skip redundant serialization of unchanged entities in USovereignSaveableEntityComponent. | Implementation of bIsDirty flag to optimize save throughput. |
| B-018 | BP_Object Cleanup (0,0,0 Mesh Bug) | 3 | Todo | DevOps | BP_Object spawns a redundant mesh at world origin (0,0,0). | Redundant mesh spawning logic removed and BP_Object stabilized. |
| R-000 | PSTA Core: Unified Safety & VSS | 8 | Done | Research | Move from "Weakest Link" (PSS) to "Non-Compensatory" (VSS) safety logic. | Formalized VSS formula implemented and verified in C++ core. |
| R-001 | PSTA Math: Exponential Trust Hysteresis | 5 | Todo | Research | Define the mathematical bounds for trust recovery across all pillars. | Formalized Phi(t) equations for recovery and failure snapping. |
| R-002 | PSTA Math: Disagreement & Conflict Penalties | 8 | Todo | Research | Penalize VSS when human intent (A) and machine truth (T) diverge. | Mathematical definition of the Disagreement Penalty based on A/T vectors. |
| R-003 | PSTA Math: Residual Transparency Logging | 3 | Todo | Research | Ensure the "Why" of every safety decision is auditable. | Protocol for logging the specific dimension residuals that caused a VSS collapse. |
| R-004 | PSTA Math: Multi-Node Consensus (N > 2) | 8 | Todo | Research | Extend safety logic to clusters with more than two redundant sensors. | Generalization of the Operational Cluster Mean formula for N-bit agreement. |
| R-005 | PSTA Math: Weighted Epistemic Uncertainty | 5 | Todo | Research | Adjust caution thresholds based on how much the system "doesn't know." | Uncertainty Weight (Uw) formula that shifts safety bounds based on unknown tags. |
| R-006 | PSTA Math: Strategic vs Tactical Drift | 5 | Done | Research | Detect "Normalization of Deviance" by comparing current vs. factory baselines. | Formalized Strategic/Tactical baseline comparison logic. |
| R-007 | PSTA Math: Common-Mode Failure Signatures | 8 | Todo | Research | Identify when multiple sensors fail for the same underlying reason. | Pattern recognition logic for detecting correlated cluster failures. |
| R-008 | PSTA Math: Kernel-Level Severance Params | 5 | Todo | Research | Determine the physical bounds for autonomous AI severance. | Calculated thresholds for the Symmetrical Guard based on hardware limits. |
| L-001 | Legal: Deterministic Safety & Heritage Compliance | 13 | Todo | Admin | Ensure the framework meets international safety and heritage standards. | Whitepaper/Audit document proving the Sovereign Framework's compliance. |
| AD-001 | Iron Officer: Bridge Foundation | 13 | Done | Admin/DevOps | Establish a high-performance local AI node to handle long-term tasks. | Local LLM bridge with 07 Protocol handshake, 5090 acceleration, and Hardware Manifest. |
| AD-002 | Iron Officer: HMI (User Medium) | 5 | Done | Admin/DevOps | Provide a way for the Lead to interact with the local AI locally. | Terminal-based Chat Vessel (vessel.py) with /report functionality and 07 Persona. |
| AD-004 | Iron Officer: Sovereign Authority | 5 | Done | Admin/Protocols | Formalize root/admin permissions for the local AI node. | Symmetrical Guard kernel with tiered Safe-Zone I/O authority and KnightCommand_SOP. |
| AD-003 | Iron Officer: Session & Local Memory | 8 | In Progress | Admin/Research | Enable the local AI to ingest the AI_Nexus research directly. | Local RAG or context window management for 12 years of project data. |
| AD-005 | Iron Officer: Spatial Reflection (UE) | 13 | Todo | Admin/DevOps | Mirror the Iron Officer persona inside the Unreal simulation. | High-fidelity 3D agent manifestation responding to live PSTA telemetry. |
| W-001 | Dragon MVP: Egg & Hatching | 8 | Todo | Designer/DevOps | Implement the "Cultivation Engine" for the first player vessel. | **Definition of Done:** 1. `Species.Animal.Dragon` data asset with 8 growth stages (Egg at Index 0). 2. Dragon Egg actor inherits `ASovereignBaseEntity` and is **Possessable**. 3. `USovereignSaveableEntityComponent` updated to support `MaturityProgress` reversal and "Over-Maturity" (up to 2.5). 4. **Consolidate Spell:** Logic to reset Maturity and increment `Sovereign.Cultivation.Tier` metadata while possessed. 5. **Visual Density Scaling:** `VisualScale` inversely tied to Tier. 6. **Hatching Choice:** Manual trigger at Maturity >= 1.0 via `Interact`. 7. **Debug Input:** Keys [1-3] bound for Qi Compression, Nurture, and Consolidation. |
| W-002 | Garden: Soil Component (Fertility/Density) | 5 | Todo | Designer/DevOps | Core simulation mechanics for tile-based growth. | USovereignSoilComponent implemented with Day/Night nutrient flux. |
| W-003 | Garden: Ground Tile Actor | 3 | Todo | Designer/DevOps | Foundation for garden expansion. | ASovereignGroundTile actor integrated with SpawnManager and SaveSystem. |
| W-004 | Meta-Progression: Legacy Subsystem | 5 | Todo | Researcher/DevOps | Persistent "Bonus Stuff" tracking for Rebirth loop. | **Definition of Done:** 1. `USovereignLegacySubsystem` created. 2. `SovereignGlobalSave` class implemented for cross-session data. 3. "Bonus Stuff" currency tracked and saved. 4. Interface for deducting currency for upgrades. |
| W-005 | Rebirth: The Soul's Echo (Death Logic) | 5 | Todo | Designer/DevOps | Capture Dragon metrics upon death for currency conversion. | **Definition of Done:** 1. `OnDragonDeath` event in `SovereignBaseCharacter`. 2. Metric calculation (Tier/Age/Qi) linked to `LegacySubsystem`. 3. Clean transition to "Wisp Only" state. |
| W-006 | Rebirth: The Resonant Egg (Shop) | 5 | Todo | Designer/DevOps | Spend "Bonus Stuff" to start with better Dragon foundations. | **Definition of Done:** 1. Rebirth Shop UI/Interaction at the Door. 2. Support for spawning eggs with pre-set `CompactedPower.Tier`. 3. Modifier system for `MaturityRate` inheritance. |
| W-007 | Rebirth: The Spirit Grave | 8 | Todo | Researcher/Designer | Permanent garden improvement via Dragon death. | **Definition of Done:** 1. `ASovereignSpiritGrave` actor created. 2. Spawns at Dragon death location. 3. Periodically boosts `Fertility` of adjacent `ASovereignGroundTile` actors. 4. Visual "Soul Pulse" effect. |
| S-001 | Soul Epic: Broker Infrastructure | 13 | Todo | Researcher/DevOps | Orchestrator refactor for Diagnostic/Cultivation separation. | **Definition of Done:** 1. `ISovereignBroker` interface defined. 2. `USovereignSaveableEntityComponent` manages Broker registry. 3. Atomic delegation for save/load. |
| S-002 | Soul Epic: Dual-Mode Rendering | 8 | Todo | Designer/DevOps | Toggle between "Truth" (Raw Data) and "Magic" (Simulation) visuals. | **Definition of Done:** 1. `UDiagnosticBroker` & `UCultivationBroker` implemented. 2. Global "Truth Toggle" switch functional in-game. |
| S-003 | Soul Epic: Archival Metadata Pipeline | 13 | Todo | Admin/DevOps | Secure, vetted metadata for historical archival truth. | **Definition of Done:** 1. "Curator" signature system (vettedBy field). 2. Database API for LOD-Nanite asset streaming based on trust. |

---

## 🏛️ Strategic Alignment
- **Complexity 1-3:** "Pipe" work. Localized logic, UI tweaks, or minor hardening.
- **Complexity 5-8:** "Officer" work. Multi-system synchronization, architectural refactors, or new "Vessel" implementation.
- **Complexity 13+:** "General" work. Massive research goals, deep spatial math, or framework-shifting paradigms.
