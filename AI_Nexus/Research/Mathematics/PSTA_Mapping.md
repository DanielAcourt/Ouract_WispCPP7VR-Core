# Research Node: PSTA Dimension Mapping

## 🔬 1. Purpose
This document establishes the formal link between the **Sovereign Framework's MetaTag namespaces** and the **PSTA (Psychological, Social, Technical, Administrative) Dimensions**. This mapping allows the framework to autonomously calculate **Dimension Health ($D_i$)** from raw simulation and hardware data.

---

## 📐 2. Namespace-to-Dimension Mapping

### 2.1 Technical Dimension (T)
*Focus: Hardware integrity, sensor stability, and simulation parity.*
*   **Namespace:** `Telemetry.*` (e.g., `Telemetry.TempC`, `Telemetry.PhValue`)
*   **Namespace:** `SovereignAttribute.HP` (Physical structural health)
*   **Weighting Logic:** High variance in `Telemetry.*` tags relative to simulation expectations ($|Real - Sim| > \epsilon$) triggers a **Risk Velocity ($V_T$)** spike.

### 2.2 Psychological Dimension (P)
*Focus: Operator cognitive load, stress, and biometric state.*
*   **Namespace:** `Biometric.*` (e.g., `Biometric.HeartRate`, `Biometric.StressLevel`)
*   **Namespace:** `SovereignQi.Qi.Current` (When linked to player/operator "Mental Energy")
*   **Anchor Tags:** If `Biometric.StressLevel > 0.9`, $D_P \rightarrow 0$ (Incapacitated Operator).

### 2.3 Social Dimension (S)
*Focus: Inter-agent trust, communication, and lineage integrity.*
*   **Namespace:** `Identity.Lineage.*` (e.g., MotherID/FatherID verification)
*   **Namespace:** `PPC.State.*` (Possession controller status)
*   **Event Triggers:**
    *   **Ontological Failure:** `OnClassLoaded` finds a missing parent actor $\rightarrow$ $D_S$ penalty (Lineage broken).
    *   **Handshake Latency:** Delay in possession handover $\rightarrow$ $D_S$ penalty.

### 2.4 Administrative Dimension (A)
*Focus: Policy compliance, mission bounds, and data sovereignty.*
*   **Namespace:** `Terminal.*` (User access levels and command compliance)
*   **Namespace:** `SovereignQi.Qi.Total` (Budgetary energy/resource expenditure)
*   **Anchor Tags:** Unauthorized access to `Terminal.SovereignRoot` $\rightarrow$ $D_A \rightarrow 0$.

---

## 🏗️ 3. Mathematical Integration

### 3.1 Dimension Health Calculation ($D_i$)
The health of a dimension is derived from its assigned tags:
$$D_i = \text{Normalize}\left( \sum w_{tag} \cdot \text{Health}(Tag) \right)$$

### 3.2 Automated Discovery (The Discovery Layer)
Unknown MetaTags (those not explicitly mapped) are assigned to the **Technical (T)** dimension by default with a $w_{reserve}$ weight until semantically classified via the **Discovery Layer**.

---

## 🧪 4. Implementation Scenarios

### 4.1 "Drone-Laying" Lineage Failure
1.  **Event:** `SovereignSpawnManager` detects `bHasParentFailure`.
2.  **Mapping:** This event is mapped to the **Social (S)** dimension.
3.  **Result:** $D_S$ receives an immediate penalty. If $D_S$ drops below $0.3$, $PSS$ enters **Warning** status, triggering a log entry: `PSTA: Social Dimension compromised - Ontological Failure detected for GUID [X]`.

### 4.2 Biometric Overload
1.  **Event:** `Biometric.HeartRate` exceeds $140$ BPM.
2.  **Mapping:** Psychological (P) dimension.
3.  **Result:** $V_P$ (Risk Velocity) spikes. $PSS$ drops even if current structural health is $1.0$, signaling an **Asymmetric Failure**.
