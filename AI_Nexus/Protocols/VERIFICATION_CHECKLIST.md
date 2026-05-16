# Protocol: Knowledge Verification Checklist

## 🛡️ Purpose
To ensure that the "Soul" (documented lessons in `AI_Nexus/Memories/`) is correctly reflected in the "Vessel" (the C++ codebase). This prevents knowledge degradation and ensures that architectural "lessons learned" are enforced over time.

---

## 📋 Audit Checklist

### 1. UE 5.7 Automation API
*   **Lesson:** `FAutomationEditorCommonUtils::CreateNewWorld()` is deprecated.
*   **Verification:**
    - [ ] Check `Source/WispCPP7VRTests/` for legacy API calls.
    - [ ] Verify explicit world context management in `SovereignBlackBoxTests.cpp`.
*   **Status:** Active Audit Required.

### 2. Black Box Atomic Writes
*   **Lesson:** Use `.tmp` files and explicit `MoveFile` to prevent "Access Denied" errors on Windows.
*   **Verification:**
    - [ ] Audit `USovereignBlackBoxSubsystem::SaveToFile`.
    - [ ] Confirm `IPlatformFile::DeleteFile` is called before move.
*   **Status:** **VERIFIED (May 2026)**.

### 3. SaveSystem Identity Guarding
*   **Lesson:** Always validate `ClassPath` strings before spawning actors from save data.
*   **Verification:**
    - [ ] Audit `USovereignSaveManager::SpawnEntityFromData`.
    - [ ] Confirm defensive null-checks and fallback spawning logic.
*   **Status:** **VERIFIED (May 2026)**.

### 4. Telemetry Standardisation
*   **Lesson:** Use the `Telemetry.` namespace for IoT-linked data.
*   **Verification:**
    - [ ] Audit `ASovereignBaseInteractable` for hard-coded key strings.
    - [ ] Check `FSovereignTelemetryMappingTest.cpp`.
*   **Status:** **VERIFIED (May 2026)**.

---

## 🔄 Verification SOP
1.  **New Memory Creation:** Whenever a new file is added to `AI_Nexus/Memories/`, a corresponding entry must be added to this checklist.
2.  **Officer Audit:** Jules or Claude must run this checklist at the start of every new task that touches these modules.
3.  **CI/CD Alignment:** (Future Goal) Integrate these checks into automated pre-commit scripts.
