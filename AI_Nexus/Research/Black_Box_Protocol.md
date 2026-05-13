# Research Node: Black Box Protocol (Phase II)

## 🔬 1. The Philosophical "Why"
*   **Vision:** To ensure **Data Survivability** in extreme, detached, or high-risk environments. The mission must be able to reconstruct its "Soul" even if the primary "Vessel" (the main hardware or ship) is totally destroyed.
*   **Metaphor:** **The Message in a Bottle.** A small, hardened, and self-contained repository that drifts safely through the digital ocean after a shipwreck, carrying the critical truth of the mission.

---

## 📐 2. Theoretical Requirements

### 2.1 Decoupled Persistence
The Black Box logic must operate independently of the main simulation tick. It requires a dedicated, low-power logging sub-cycle that persists state to non-volatile memory (NVM) with minimal overhead.

### 2.2 Critical Truth Selection
The system cannot save everything. It must use the **PSTA Framework** to identify "Critical Truths":
*   **Anchor Tags:** Any tag marked as an Anchor must be logged with high frequency.
*   **Dimensional Snapshots:** Periodic $D_i$ scores and $PSS$ logs to reconstruct the failure timeline.
*   **Identity Lineage:** The GUID and ParentID to maintain the chain of sovereignty.

### 2.3 Hardened Serialization
*   **Binary Compaction:** Moving away from human-readable JSON to high-density binary formats for storage efficiency.
*   **Checksum Verification:** Every "bottle" (data packet) must have a cyclic redundancy check (CRC) to ensure truth integrity upon recovery.

---

## 🏗️ 3. Structural Integration (The Pipes)

### 3.1 The "Shipwreck" Trigger
Detection of critical $PSS$ failure (e.g., total power loss or $D_T = 0$) triggers an immediate "Final Breath" save—a prioritized dump of all critical buffers to the Black Box.

### 3.2 Recovery Lifecycle
1.  **Discovery:** External hardware/agent finds the Black Box.
2.  **Handshake:** Verification of the `TrustSignature`.
3.  **Ingestion:** The `USovereignSaveManager` ingests the binary data, spawning "Ghost" entities or reconstructing the final state for audit.

---

## 🧪 4. Test Scenarios

### 4.1 "Dead Ship" Audit
A simulation is force-crashed. The Black Box must contain the last 60 seconds of telemetry and the specific $PSS$ value that preceded the failure.

### 4.2 Low-Power Endurance
The system must demonstrate the ability to maintain the "Black Box Heartbeat" (minimal logging) for extended periods on reserve power without corrupting the lineage data.
