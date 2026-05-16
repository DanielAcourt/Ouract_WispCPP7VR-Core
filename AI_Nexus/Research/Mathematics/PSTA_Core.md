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

### 2.4 Human-in-the-Loop: The Acknowledgment Handshake
To prevent "Lion Air 610" scenarios where the AI overrides human judgment based on a single sensor lie, we introduce the **Acknowledgment Factor** ($\beta$).

When an Alarm is triggered, the Captain can acknowledge it. This has two mathematical effects:
1.  **Sensor Weight Reduction:** The specific tag $x_{ij}$ that triggered the alarm has its weight $w_{ij}$ reduced by a factor $\delta$ (e.g., $w_{ij, new} = w_{ij} \cdot 0.1$). This prevents a confirmed faulty sensor from continuously dragging down the PSS.
2.  **Autonomous Inhibition:** A boolean state `bIsAcknowledged` prevents the AI from executing "Corrective Interventions" (e.g., steering) unless the total PSS collapses below a secondary **Survival Threshold** ($t_{survival}$).

### 2.5 Provable Safety Status (PSS)
The PSS is the final holistic metric that determines if the mission is "Safe."

**The Refined Bottleneck Law:**
To prevent over-punishing minor fluctuations while maintaining safety, we use a **Gated-Min** approach:
$$PSS = \sigma(\min(D_i)) \cdot \left( \sum \alpha_i D_i \right)$$
Where $\sigma$ is a scaling function that remains $\approx 1.0$ for high $D_i$, but aggressively drops to $0$ as any $D_i$ approaches a critical instability threshold (e.g., $0.3$).

---

## 🏗️ 3. The Structural Integration (The Discovery Layer)

### 3.1 The N-bit Matrix (Consensus Verification)
To harden the system against sensor failure, critical thresholds can require an **Agreement Count** ($N$).
*   An alarm is only elevated to **Active** if $N$ distinct sensors or tags within a dimension confirm the breach.
*   If $Agreement < N$, the state is logged as **Suspicious** but does not trigger autonomous intervention.

### 3.2 Handling Unknown Tags (Meta-Tagging)
*   **Tag Registration:** New data sources ($x_{i,novel}$) provide a metadata header.
*   **Residual Weight Allocation:** System siphons from $w_{reserve}$ for unknown tags.
*   **Weight Correction:** The $\frac{1}{W_i}$ divisor ensures the score stays within $[0, 1]$.

### 3.3 Automated Discovery Layer (Vision Integration)
To mitigate the "Labor of Labeling," the Sovereign Framework integrates with spatial sensors (Computer Vision/Lidar):
*   **Semantic Transcription:** Objects identified via Image Recognition (e.g., a "High-Voltage Hazard") are automatically registered as $x_{ij}$ factors in the **Administrative (A)** or **Technical (T)** dimensions.
*   **Autonomous Priority Mapping:** Known visual archetypes carry pre-defined impact weights, allowing the system to scale its risk assessment without manual human input.

### 3.4 Classification and Threshold Mapping
*   **Critical ($0 \le PSS < t_{crit}$):** Abort.
*   **Warning ($t_{crit} \le PSS < t_{warn}$):** Intervention.
*   **Caution ($t_{warn} \le PSS < t_{caut}$):** Degraded.
*   **Nominal ($t_{caut} \le PSS \le 1$):** Green.

**Confidence-Adjusted Thresholds:** High volumes of unknown tags cause the system to raise thresholds $T$ (Safety-First logic).

---

## 🧪 4. Training Data & Scenarios

### 4.1 Definitive Terms
*   **Anchor Tag:** A high-priority input that can autonomously zero a dimension score.
*   **Void Safety:** Fallback logic for dimensions with zero active data points.
*   **Risk Velocity:** The rate at which health is deteriorating.

### 4.2 Test Scenarios
*   **The Island Stress Test:** Isla's biometric stress spikes. $D_P$ drops. If $V_P$ (velocity) is too high, PSS enters **Warning** immediately, even if $D_P$ is still $0.7$.
*   **The Engine Anchor:** A technical sensor for fuel pressure is marked as an **Anchor**. If it hits 0, $D_T$ becomes 0 instantly, aborting the mission via the Bottleneck Law.
