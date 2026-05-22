# Sovereign Framework Glossary: Single Source of Truth

This glossary defines the core technical and thematic terminology of the Sovereign Framework. Adherence to these definitions ensures consistency across code, documentation, and agent communication.

---

## 🏗️ Core Entities

### **The Soul (USovereignSaveableEntityComponent)**
The primary data hub and Single Source of Truth for an entity. It persists across possession cycles and manages the entity's GUID, state, and identity.

### **The Vessel (Actor/Pawn/Character)**
The physical or digital body that houses a Soul. Vessels can be possessed by the Spirit (Wisp) or operate autonomously.

### **The Spirit (ASovereignPlayerWisp)**
The player-controlled entity capable of possessing and unpossessing different Vessels. It carries the player's consciousness through the simulation.

---

## ⚡ Energy & State

### **Qi (Elemental Energy)**
A **Simulated/Gamified State** variable used for evolution and possession mechanics. It represents a fantasy result of user interaction and time, distinct from real-world telemetry truth. Tracked via the `SovereignQi.Qi.*` namespace.

### **Maturity / Growth Stage**
A measure of a Soul's evolution. Progression is triggered by elemental input, eventually leading to a physical/visual "Evolve" event.

---

## 🌐 Systems & Protocols

### **Digital Twin**
A high-fidelity digital representation of a physical object or volume (e.g., the Fish Tank). Parity is maintained via real-time JSON/Binary telemetry.

### **Black Box Protocol**
A system design focused on data survivability in detached, low-power, or high-risk environments.

### **Sovereign Rule**
A fundamental architectural constraint: All attachments during possession MUST use `FAttachmentTransformRules::SnapToTargetNotIncludingScale` to maintain scale integrity.

### **Cyber-Physical Systems (CPS)**
Systems where software logic directly governs or synchronizes with physical hardware (Robotics/Sensors).

---

## 📐 PSTA (Provable Trust Framework)

### **PSTA Dimensions**
The **Four Pillars of Mission Integrity**: **Psychological** (Operator stress), **Social** (Team cohesion), **Technical** (Hardware health), and **Administrative** (Policy/Budget).

### **Dimension Health ($D_i$)**
A normalized score $[0, 1]$ representing the performance of a specific PSTA dimension, calculated via a self-normalizing weighted average.

### **Provable Safety Status (PSS)**
(Legacy) A weighted aggregation of Dimension Health scores subject to the Bottleneck Law. Replaced by the **Vessel Safety Status (VSS)** in the Unified Safety Formula.

### **Vessel Safety Status (VSS)**
The ultimate mission health metric. It utilizes the **Unified Safety Formula** to ensure absolute integrity. If any dimension fails its $\tau_{fail}$ threshold, or if the **Conflict Penalty** between Administrative and Technical pillars becomes too high, the VSS collapses to zero.

### **Coherence Coefficient ($\Phi$)**
A mathematical measure of agreement within an $N$-bit sensor cluster. In a healthy state, $\Phi=1.0$. A breach of the $\Delta_{fault}$ threshold snaps $\Phi$ to $0.0$, triggering degraded single-channel operation and Exponential Trust Recovery.

### **Severance Event**
A hardware-level "Hard-Kill" command triggered by the **Symmetrical Guard** when AI Intent and Physical Truth diverge beyond a kernel-level threshold. It bypasses all software "opinion" to ensure safety.

### **Symmetrical Guard (The Safety Kernel)**
A deterministic, non-neural monitoring process that calculates the **Symmetry Delta** ($Δ_{sym}$) between what the system *intends* to do and what the physical environment *allows*.

### **Provable Trust**
A state where every safety decision and status spike is traceable to a specific, weighted input factor ($x_{ij}$), providing a transparent audit trail for system behavior.

### **Asymmetric Failure**
A condition where a mission enters a critical risk state due to a failure in a "soft" dimension (Social/Psychological) even while the "hard" dimensions (Technical) remain perfect.

### **Discovery Layer**
A dynamic registry system that handles unknown meta-tags and degraded $N$-bit sensor clusters. It self-normalizes Dimension Health scores and adjusts the system's Caution threshold based on total Uncertainty Weight ($U_W$).

### **$N$-Bit Topology**
A sensor redundancy architecture where factors are grouped into clusters (e.g., $N=2$ for stereo). A **Topology Mask** ($\mathbf{b}_{ij}$) tracks the operational state of each sensor, allowing the system to isolate hardware malfunctions from true environmental data.

### **Anchor Tag**
A critical input factor ($x_{ij}$) that possesses "Override Authority." If an Anchor Tag's value hits zero, the entire Dimension Health ($D_i$) is forced to zero, regardless of other weights.

### **Void Safety**
A deterministic fallback protocol for dimensions with zero active monitoring ($W_i = 0$). In the Sovereign Framework, a "Void" dimension is treated as a critical failure ($D_i = 0$) because untracked reality is untrusted reality.

### **Risk Velocity ($V_i$)**
The rate of change of Dimension Health over time. High Risk Velocity triggers safety warnings even if absolute health is still above nominal thresholds, allowing for proactive intervention.
