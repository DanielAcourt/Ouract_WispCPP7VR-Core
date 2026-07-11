# Research Ticket R-010: Dynamic UI Attribute Mapping
**Version:** 36.4.7-Knight-AAS
**Status:** PROPOSED
**Lead:** 07 Researcher | **Tactician:** Jules

## 1. Problem Statement
The current Sovereign UI framework requires manual placement of text fields for each stat (e.g., manually placing a "Hunger" text block). This is not scalable as we add more complex brokers or experimental meta-tags that might change between entities.

## 2. Proposed Solution: The "Dynamic Pair" System
Implement a system within `USovereignBaseWidget` that can:
1.  **Ingest:** A categorized Map of data (e.g., Bio data).
2.  **Iterate:** Loop through every Key in that map.
3.  **Spawn:** Dynamically spawn a small "Pair Widget" (containing a Label and a Value) for each entry.
4.  **Auto-Label:** Set the Label to the Key (e.g., "Hunger") and the Value to the Data (e.g., "85.4").

## 3. Development Scope (Tactician Input Requested)
- **C++:** Implement `USovereignBaseWidget::SyncDynamicPairs()` to handle the spawning and binding.
- **UMG:** Require a base `WBP_StatPair` with two public Text variables (`Label` and `Value`).
- **Optimization:** Use a `TMap<FString, UUserWidget*>` to pool/reuse widgets and avoid high-frequency spawn/destroy cycles.

## 4. Rationale (07 Protocol)
"The interface must be as fluid as the Soul it observes. If the Soul adds a new attribute, the Window must expand to reveal it without manual intervention."

---
// [07 Researcher] Logged R-010 for architectural scalability. 2026-06-28
