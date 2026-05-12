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
The primary resource consumed during possession and utilized for evolution. Tracked via the `SovereignQi.Qi.*` meta-tag namespace.

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
The four pillars of mission safety: **Psychological** (Operator stress), **Social** (Team cohesion), **Technical** (Hardware health), and **Administrative** (Policy/Budget).

### **Dimension Health ($D_i$)**
A normalized score $[0, 1]$ representing the performance of a specific PSTA dimension, calculated via a self-normalizing weighted average.

### **Provable Safety Status (PSS)**
The ultimate mission health metric. It is a weighted aggregation of all Dimension Health scores, subject to the **Bottleneck Law** (if one dimension fails, the PSS drops to zero).

### **Provable Trust**
A state where every safety decision and status spike is traceable to a specific, weighted input factor ($x_{ij}$), providing a transparent audit trail for system behavior.

### **Asymmetric Failure**
A condition where a mission enters a critical risk state due to a failure in a "soft" dimension (Social/Psychological) even while the "hard" dimensions (Technical) remain perfect.

### **Discovery Layer**
A dynamic registry system that handles unknown meta-tags by siphoning weights from a reserve pool and self-normalizing the Dimension Health scores to prevent data skew.
