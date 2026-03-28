# Sovereign Soul - Bridge Documentation (Visual Cortex)

## 1. Actor Synchronization (Real-to-Sim)

The `ASovereignBaseInteractable` (Fish Tank) Actor will serve as the physical representation of the real-world hardware in the Unreal Engine 'Living Library.'

### Telemetry Mapping
Incoming hardware telemetry from `Sovereign_DevOps/telemetry.json` will be mapped as follows:

-   **`temp_c` (Temperature)**:
    -   Maps to `USovereignBioComponent::TemperatureShift`.
    -   Calculation: `(temp_c - IdealTemp) / TempRangeScale`.
    -   Visual Effect: Driven by the `Entropy` and `StateDrain` parameters to reflect thermal stress.

-   **`ph_val` (pH Level)**:
    -   Maps to `USovereignBioComponent::Toxicity`.
    -   Calculation: Deviations from the neutral pH (7.0) will increase the `Toxicity` level over time.
    -   Visual Effect: Drives a color shift in the water volume mesh/material to reflect acidity or alkalinity.

-   **`water_depth_mm` (Water Level)**:
    -   Maps to `USovereignBioComponent::Hydration`.
    -   Calculation: `(water_depth_mm / MaxDepth) * 100.0`.
    -   Visual Effect: Directly drives the Z-scale or position of the Water Surface mesh within the Fish Tank actor.

## 2. Sim2Real Feedback (Sim-to-Real)

The Unreal 'Living Library' serves as a predictive engine for environmental decay.

### Predictive Logic (Simulator Output)
The simulator will output to `Sovereign_DevOps/sim_feedback.json` with the following parameters:

-   **Evaporation Prediction**: Based on current `temp_c` and simulator physics (e.g., surface area and simulated ambient temperature), predicts the rate of water level drop.
-   **Algae Density (BHA Growth)**: Simulates biological growth based on simulated light exposure and `ph_val` drift.
-   **Survival Risk Level**: A value between `0.0` (Safe) and `1.0` (Critical failure imminent).

### Sim_Warning Protocol
If `Survival Risk Level` > `0.5`, a `Sim_Warning` payload is generated. This is an early-warning system for the Hardware-Level Jules's Safety Kernel.

## 3. DevOps & Agent Alignment
-   **SSoT Integrity**: All synchronization logic is defined in `identity.json`.
-   **Auditing**: The `USovereignSaveableEntityComponent` (the Soul) logs all telemetry-to-actor updates as "Truth Transitions" to ensure auditable states.
-   **Student/Collaborator Interface**: All scripts and tools within `Sovereign_DevOps/` are documented for the human student to understand the hardware/software interface.

---
*Sync Level: 1.0 - Bridge Architecture Finalized*
