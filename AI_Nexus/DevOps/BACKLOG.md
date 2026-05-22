# Sovereign Framework: BACKLOG

This backlog uses Fibonacci scoring to estimate task complexity.

## 🎯 Active Phase: Infrastructure & Stabilization

| ID | Task | Complexity | Status | Node |
|:---|:---|:---:|:---:|:---|
| B-001 | Actor Synchronization (Fish Tank Telemetry) | 8 | Done | DevOps |
| B-002 | Data Survivability (Black Box Protocol) | 5 | Done (Hardened) | Research |
| B-003 | Lidar Intelligence (Matrix Museum Summoning) | 13 | Todo | Research |
| B-004 | "Corpse Possession" State Persistence | 3 | Todo | DevOps |
| B-005 | Qi/Maturity Evolution Milestones | 5 | Todo | DevOps |
| B-006 | VR Interaction Polish (Possession Lifecycle) | 5 | Todo | Protocols |
| B-007 | Performance Baseline (1000+ Entities) | 8 | Todo | DevOps |
| B-008 | PSTA C++: N-Bit Topology Matrix | 8 | Todo | DevOps |
| B-009 | PSTA C++: Exponential Trust Recovery | 5 | Todo | DevOps |
| B-010 | PSTA C++: Risk Velocity (Vi) Detection | 5 | Todo | DevOps |
| B-011 | PSTA C++: Symmetrical Guard (Severance) | 8 | Todo | DevOps |
| B-012 | Pi Kernel: Headless Safety Node | 13 | Todo | DevOps |
| B-013 | Data Bridge: Pi-Unreal Telemetry Link | 8 | Todo | DevOps |
| B-014 | Simulation: "Fish Tank" Visual Mapping | 5 | Todo | DevOps |
| B-015 | Replay: Time-Dilation scrubbing | 8 | Todo | DevOps |
| R-000 | PSTA Core: Unified Safety & VSS | 8 | Done | Research |
| R-001 | PSTA Math: Exponential Trust Hysteresis | 5 | Todo | Research |
| R-002 | PSTA Math: Disagreement & Conflict Penalties | 8 | Todo | Research |
| R-003 | PSTA Math: Residual Transparency Logging | 3 | Todo | Research |
| R-004 | PSTA Math: Multi-Node Consensus (N > 2) | 8 | Todo | Research |
| R-005 | PSTA Math: Weighted Epistemic Uncertainty | 5 | Todo | Research |
| R-006 | PSTA Math: Strategic vs Tactical Drift | 5 | Done | Research |
| R-007 | PSTA Math: Common-Mode Failure Signatures | 8 | Todo | Research |
| R-008 | PSTA Math: Kernel-Level Severance Params | 5 | Todo | Research |
| L-001 | Legal: Deterministic Safety & Heritage Compliance | 13 | Todo | Admin |

---

## 🏛️ Strategic Alignment
- **Complexity 1-3:** "Pipe" work. Localized logic, UI tweaks, or minor hardening.
- **Complexity 5-8:** "Officer" work. Multi-system synchronization, architectural refactors, or new "Vessel" implementation.
- **Complexity 13+:** "General" work. Massive research goals, deep spatial math, or framework-shifting paradigms.

## 📝 Next Priority

**B-008: PSTA C++: N-Bit Topology Matrix (Complexity 8)**
- **Why:** To transition from single-sensor mapping to robust cluster-based safety, preventing hardware glitches from collapsing mission health.
- **What:** Implement `FPSTACluster` and update `USovereignBlackBoxComponent` to evaluate health based on $N$ sensors with topology masks.
- **How:** Refactor the PSTA mapping logic to support multi-tag clusters.

**B-013: Data Bridge: Pi-Unreal Telemetry Link (Complexity 8)**
- **Why:** To enable the "Fish Tank" simulation to act as a real-time reflection of the Raspberry Pi hardware truth.
- **What:** Establish a socket-based (UDP or TCP) listener in an Unreal Subsystem to ingest JSON telemetry from the Pi.
- **How:** Create `USovereignPiBridgeSubsystem` to handle networking and entity possession via telemetry.

**B-015: Replay: Time-Dilation scrubbing (Complexity 8)**
- **Why:** To fulfill the vision of Unreal as a tool for replaying and analyzing historical Black Box data at various speeds.
- **What:** Extend `USovereignBlackBoxReplaySubsystem` to support variable playback rates and index-based scrubbing.
- **How:** Implement a normalized time-scrubbing interface for the Black Box logs.
