# Sovereign Soul Project Backlog - Fish Tank Alpha (FTA)

## [IN PROGRESS]

### TICKET-001: Actor Synchronization (Real-to-Sim Bridge)
- **Complexity (Fibonacci)**: 8
- **Priority**: CRITICAL
- **Description**: Map the incoming hardware telemetry from `Sovereign_DevOps/telemetry.json` (temp_c, ph_val, water_depth_mm) to the `ASovereignBaseInteractable` Actor properties in Unreal. This requires the `USovereignSaveableEntityComponent` to ingest the JSON data at a 1Hz frequency and update the `USovereignBioComponent` vitals (TemperatureShift, Toxicity, Hydration).
- **Acceptance Criteria**:
    - [ ] Unreal can parse `telemetry.json` without crashing.
    - [ ] `ASovereignBaseInteractable` (Fish Tank) properties update in real-time based on file changes.
    - [ ] "Truth Transitions" are logged in the Actor's soul component for auditing.

---

## [TO DO]

### TICKET-002: Sim2Real Feedback (Predictive Safety)
- **Complexity (Fibonacci)**: 5
- **Priority**: HIGH
- **Description**: Implement the `Sim_Warning` protocol. The simulator must calculate environment decay (Evaporation/BHA Growth) based on physics models and output a `risk_factor` (0.0 to 1.0) to `Sovereign_DevOps/sim_feedback.json`.
- **Acceptance Criteria**:
    - [ ] Simulator generates `evaporation_prediction` and `algae_density`.
    - [ ] `Sim_Warning` is triggered when `risk_factor` > 0.5.
    - [ ] Payload is written to `sim_feedback.json` for the Hardware Safety Kernel.

### TICKET-003: Living Library Dashboard (Visual Filter)
- **Complexity (Fibonacci)**: 3
- **Priority**: MEDIUM
- **Description**: Create a high-signal VR UI/Dashboard that distills complex simulator telemetry into a simple "Survival Status" display to save Dan's administrative time.
- **Acceptance Criteria**:
    - [ ] Dashboard displays "Healthy", "Warning", or "Critical" status.
    - [ ] VR-interactable interface allows viewing raw telemetry data.

### TICKET-004: Identity-Class Bridge Integrity
- **Complexity (Fibonacci)**: 2
- **Priority**: MEDIUM
- **Description**: Audit the `IdentitySignature` and `TrustSignature` on the Fish Tank actor to ensure it correctly matches the `SovereignSpeciesData` for the tank.
- **Acceptance Criteria**:
    - [ ] `identity.json` mapping is validated during Actor `BeginPlay`.

---

## [DONE]

### TICKET-000: SSoT Bridge Initialization
- **Complexity (Fibonacci)**: 3
- **Completed**: 2025-03-28
- **Description**: Created `MD.md`, `AGENTS.md`, `identity.json`, and `Sovereign_DevOps/` structure.
