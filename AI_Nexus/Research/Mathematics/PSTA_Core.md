# Research Node: PSTA Core (Provable Trust Framework)

## 🔬 1. The Philosophical "Why"
*   **Vision:** To transition the Sovereign Framework from simple **State Observation** to **Risk Mitigation**. The goal is to establish **Provable Trust**—a mathematical guarantee that the system is operating within safe, verifiable bounds across multiple dimensions of reality.
*   **Metaphor:** The **Four Pillars of the Temple**. If any one pillar (Psychological, Social, Technical, or Administrative) crumbles, the entire roof (the Mission) collapses, regardless of how strong the other three pillars remain.

---

## 📐 2. The Mathematical "How"

### 2.1 The Dimensional Choice $\{P, S, T, A\}$
The system monitors four core dimensions to determine total mission health:
*   **Psychological (P):** Internal human variables (cognitive load, stress, biometric data).
*   **Social (S):** Inter-agent dynamics (trust, cohesion, communication latency).
*   **Technical (T):** Hard constraints (hardware health, sensor drift, latency).
*   **Administrative (A):** Soft constraints (policy compliance, budget variance).

### 2.2 Dimension Health ($D_i$)
The Dimension Score $D_i \in [0, 1]$ represents the overall health of a single dimension.

$$D_i = \frac{1}{W_i} \sum_{j=1}^{K_i} (x_{ij} \cdot w_{ij})$$

**Hardening - The Void Safety Rule:**
To prevent the $W_i = 0$ singularity (division by zero), the system enforces:
*   If $W_i = 0$, $D_i = 0$ (Critical Failure: Lack of Data). A dimension with zero monitoring is considered untrusted.

**Hardening - Anchor Tags (Overrides):**
To prevent critical factor dilution, certain $x_{ij}$ can be designated as **Anchor Tags**.
*   If $x_{anchor} = 0$, then $D_i = 0$ regardless of other factor weights. This ensures that a critical engine failure ($T$) or a total social breakdown ($S$) cannot be "averaged out."

### 2.3 Temporal Momentum ($V_i$)
To account for the speed of failure, we introduce the **Risk Velocity**:
$$V_i = \frac{\Delta D_i}{\Delta t}$$
*   If $|V_i| > V_{threshold}$ (e.g., a rapid drop in trust), the system applies a **Momentum Penalty** to the $PSS$, triggering a warning before the health score even hits the threshold.

### 2.4 Vessel Safety Status (VSS)
The VSS is the final holistic metric that determines if the mission is "Safe." It transitions the system from simple "Provable Safety" (PSS) to a "Non-Compensatory" Unified Safety Logic.

**The Unified Safety Formula (VSS):**
To ensure that critical failure in any single dimension cannot be "hidden" by success in others, we apply a hard step-function product:

$$VSS = \left( \prod_{i \in \{P,S,T,A\}} \text{step}(D_i - \tau_{fail, i}) \right) \cdot \sum_{i=1}^{n} \alpha_i D_i$$

*   **The Kill Switch:** The product term acts as a binary gate. If any $D_i$ falls below its dimension-specific failure threshold $\tau_{fail, i}$, the entire VSS collapses to **0.0**, proving mission failure.
*   **Non-Compensatory Logic:** Social (S) or Psychological (P) health cannot "average out" a Technical (T) failure.

---

## 🏗️ 3. The Structural Integration (The Discovery Layer)

### 3.1 Handling Unknown Tags (Epistemic Uncertainty)
*   **Tag Registration:** New data sources ($x_{i,novel}$) are ingested into the "Soul" (MetaTags).
*   **Residual Weight Allocation:** The system assigns a residual weight to unknown tags.
*   **Self-Normalization:** The $\frac{1}{W_i}$ divisor ensures $D_i$ remains bounded in $[0, 1]$ even as the number of factors ($K_i$) increases.
*   **The Unknown Tag Ratio:** The ratio of "Unknown" to "Known" tags serves as a measure of epistemic uncertainty.

### 3.2 Technical (T) Hardening via Dynamic DNA
The **Technical (T)** pillar relies on the **Sovereign Save System** to ingest truths that the simulation engine does not natively recognize.
*   **The "Sandwich" Proof:** By successfully persisting unknown tags (e.g., `Sandwhich: True`), the system demonstrates its ability to act as a **Deterministic Data Bridge**.
*   **Namespace Scoping:** Data from `AttributeComponent` (Metabolics), `QiComponent` (Energy), and `Telemetry` (Physical IoT) is namespace-scoped in the JSON. This allows the PSTA system to target specific hardware or biological subsystems for risk assessment without architectural re-compiles.

### 3.3 Automated Discovery Layer (Vision Integration)
To mitigate the "Labor of Labeling," the Sovereign Framework integrates with spatial sensors (Computer Vision/Lidar):
*   **Semantic Transcription:** Objects identified via Image Recognition (e.g., a "High-Voltage Hazard") are automatically registered as $x_{ij}$ factors in the **Administrative (A)** or **Technical (T)** dimensions.
*   **Autonomous Priority Mapping:** Known visual archetypes carry pre-defined impact weights, allowing the system to scale its risk assessment without manual human input.

### 3.3 Classification and Threshold Mapping
The system maps the continuous VSS score to a discrete operational status.

| Status | Range | Logic with "Unknown" Discovery |
| :--- | :--- | :--- |
| **Critical** | $0 \le VSS < t_{crit}$ | **Immediate Abort.** Provable failure detected. |
| **Warning** | $t_{crit} \le VSS < t_{warn}$ | **Human-in-the-loop (HITL):** Robot or human must verify. |
| **Caution** | $t_{warn} \le VSS < t_{caut}$ | **Performance throttled.** System is investigating data. |
| **Nominal** | $t_{caut} \le VSS \le 1$ | **Standard Ops.** Requires high tag-certainty. |

**The Discovery Layer Constraint (Unknown Tag Penalty):**
If the ratio of "Unknown Tags" to "Known Tags" exceeds a configured limit, the system automatically shifts $t_{caut}$ upward. This raises the "Nominal" health requirement, enforcing a safety-first posture when operating with low-confidence data.

$$t_{caut, adj} = t_{caut, base} + \gamma \cdot \left( \frac{K_{unknown}}{K_{known} + K_{unknown}} \right)$$

*   **Epistemic Skepticism ($\gamma$):** A sensitivity factor (typically $0.1$ to $0.3$) that determines how aggressively the system penalizes unknown data.
*   **Safety Margin:** By increasing $t_{caut}$, the system demands a higher Dimensional Health ($D_i$) to stay in "Nominal" status, effectively "buying" safety with stricter performance requirements.

---

## 📡 4. Truth vs. Reflection (The Sim-to-Real Bridge)

The PSTA system operates across two distinct but synchronized perspectives:

*   **The Truth (Real-World Vessel):** The physical entity (e.g., Robot, Pi-driven sensor) gathering relative truths from its environment. It generates the raw Black Box logs.
*   **The Reflection (Unreal Simulation):** A high-fidelity "movie" of the Truth. It replays the logs to reconstruct the event, using the same PSTA math to verify that the reconstruction matches the intended historical truth.

---

## 🧪 5. Training Data & Scenarios

### 4.1 Definitive Terms
*   **Anchor Tag:** A high-priority input that can autonomously zero a dimension score.
*   **Void Safety:** Fallback logic for dimensions with zero active data points.
*   **Risk Velocity:** The rate at which health is deteriorating.

### 4.2 Test Scenarios
*   **The Island Stress Test:** Isla's biometric stress spikes. $D_P$ drops. If $V_P$ (velocity) is too high, PSS enters **Warning** immediately, even if $D_P$ is still $0.7$.
*   **The Engine Anchor:** A technical sensor for fuel pressure is marked as an **Anchor**. If it hits 0, $D_T$ becomes 0 instantly, aborting the mission via the Bottleneck Law.
