# Research Node: PSTA Core (Provable Trust Framework)

## 🔬 1. The Philosophical "Why"
*   **Vision:** To transition the Sovereign Framework from simple **State Observation** to **Risk Mitigation**. The goal is to establish **Provable Trust**—a mathematical guarantee that the system is operating within safe, verifiable bounds across multiple dimensions of reality.
*   **Metaphor:** The **Four Pillars of the Temple**. If any one pillar (Psychological, Social, Technical, or Administrative) crumbles, the entire roof (the Mission) collapses, regardless of how strong the other three pillars remain.

---

## 📐 2. The Mathematical "How"

### 2.1 The Dimensional Choice $\{P, S, T, A\}$
The system monitors four core dimensions to determine total mission health:
*   **Psychological (P):** Internal human variables (cognitive load, stress, biometric data).
*   **Social (S):** Inter-agent dynamics (trust, cohesion, communication latency between entities like Isla and Erisis).
*   **Technical (T):** Hard constraints (hardware health, sensor drift, latency, battery voltage).
*   **Administrative (A):** Soft constraints (policy compliance, budget variance, resource stability).

### 2.2 Dimension Health ($D_i$)
The Dimension Score $D_i \in [0, 1]$ represents the overall health of a single dimension. It uses a **Self-Normalizing Weighted Average** to ensure that the arrival of new or unknown data does not skew the results.

$$D_i = \frac{1}{W_i} \sum_{j=1}^{K_i} (x_{ij} \cdot w_{ij})$$

Where:
*   $x_{ij}$ = Normalized input factor $[0, 1]$.
*   $w_{ij}$ = Importance weight of factor $j$ within dimension $i$.
*   $W_i$ = $\sum w_{ij}$ (The sum of all active weights in the dimension).

### 2.3 The Risk Index ($R_i$)
Risk is defined as the direct inversion of health. This allows the system to operate on **Safety-First** logic.

$$R_i = 1 - D_i$$

### 2.4 Provable Safety Status (PSS)
The PSS is the final holistic metric that determines if the mission is "Safe."

**Standard Aggregation:**
$$PSS = \sum_{i \in \{P,S,T,A\}} \alpha_i D_i$$

**The Bottleneck Law (Mission Critical Constraint):**
To ensure a single point of failure correctly impacts the global status, we apply a Leontief (Minimum) Constraint:
$$PSS = \min(D_i) \cdot \left( \sum \alpha_i D_i \right)$$
*Result: If any $D_i = 0$, the PSS becomes 0, proving the system is unsafe.*

---

## 🏗️ 3. The Structural Integration (The Discovery Layer)

### 3.1 Handling Unknown Tags (Meta-Tagging)
Since the system cannot know every hardware sensor or social nuance in advance, it uses a dynamic registry:
*   **Tag Registration:** New data sources ($x_{i,novel}$) must provide a metadata header defining their domain $D$ and impact weight.
*   **Residual Weight Allocation:** The system maintains a $w_{reserve}$ pool. Unknown tags siphoned weight from this pool until an RL agent or human classifies their true priority.
*   **Weight Correction:** The $\frac{1}{W_i}$ divisor in the $D_i$ formula ensures that adding unknown tags never pushes the score out of the $[0, 1]$ range.

### 3.2 Classification and Threshold Mapping
The continuous $PSS$ is mapped to discrete, actionable states:
*   **Critical ($0 \le PSS < t_{crit}$):** Immediate Shutdown.
*   **Warning ($t_{crit} \le PSS < t_{warn}$):** Human intervention required.
*   **Caution ($t_{warn} \le PSS < t_{caut}$):** Degraded performance.
*   **Nominal ($t_{caut} \le PSS \le 1$):** Standard Operations.

**Confidence-Adjusted Thresholds:** If the "Discovery Layer" detects high volumes of unknown tags, the thresholds $T$ are artificially raised, forcing the system into a "Caution" or "Warning" state until the data is verified.

---

## 🧪 4. Training Data & Scenarios

### 4.1 Definitive Terms
*   **Provable Trust:** A status derived from traceable, weighted inputs that can be audited to show exactly why a safety threshold was triggered.
*   **Asymmetric Failure:** When one dimension (e.g., Social) fails while others (e.g., Technical) are perfect.

### 4.2 Test Scenarios
*   **The Isla Stress Test:** If Isla's $x_{P,stress}$ spikes (Biometric Stress), $D_P$ drops, causing $R_P$ to rise. If $PSS$ falls below $t_{warn}$, the system autonomously reduces her workload.
*   **The Erisis Comms Silence:** If communication latency between agents increases, $D_S$ drops. Even if the hardware ($T$) is perfect, the Bottleneck Law ensures the PSS reflects the social instability.
