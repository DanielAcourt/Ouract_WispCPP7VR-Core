# Files to Create - Complete List

**Total New Files:** 6  
**Files to Modify:** 2  
**Total Time:** ~4 hours

---

## 📁 New Files to Create

### 1. Documentation Files (add to repo root)

#### `CONTRIBUTING.md`
**Location:** `/repo/CONTRIBUTING.md`  
**Size:** ~500 lines  
**Status:** Ready to copy-paste (see provided CONTRIBUTING.md)  
**Contains:** Multi-agent workflow, error handling standards, testing requirements

#### `_AGENT_CONTEXT.md`
**Location:** `/repo/_AGENT_CONTEXT.md`  
**Size:** ~400 lines  
**Status:** Ready to copy-paste  
**Contains:** Current sprint status, SaveSystem focus, communication protocol

#### `SaveSystem_Error_Audit.md`
**Location:** `/repo/SaveSystem_Error_Audit.md`  
**Size:** ~300 lines  
**Status:** Ready to copy-paste  
**Contains:** 8 issues documented, severity levels, implementation order

#### `SAVESYSTEM_SETUP_GUIDE.md`
**Location:** `/repo/SAVESYSTEM_SETUP_GUIDE.md`  
**Size:** ~400 lines  
**Status:** Ready to copy-paste  
**Contains:** Complete setup + fix walkthrough + verification checklist

#### `SAVESYSTEM_QUICK_FIX_REFERENCE.md`
**Location:** `/repo/SAVESYSTEM_QUICK_FIX_REFERENCE.md`  
**Size:** ~100 lines  
**Status:** Ready to copy-paste  
**Contains:** One-page reference for 3 critical fixes

#### `IMPLEMENTATION_CHECKLIST.md`
**Location:** `/repo/IMPLEMENTATION_CHECKLIST.md`  
**Size:** ~200 lines  
**Status:** Ready to copy-paste  
**Contains:** Phased task breakdown with time estimates

### 2. Reference Code File (add to repo root or Docs folder)

#### `SaveSystem_Hardened_Fixes.cpp`
**Location:** `/repo/SaveSystem_Hardened_Fixes.cpp` (or `/repo/Docs/`)  
**Size:** ~500 lines  
**Status:** Reference implementation (DO NOT include in compilation)  
**Note:** This is a REFERENCE file showing how to fix issues. Don't add to .Build.cs

### 3. Unit Test File (add to source)

#### `SaveSystem_Tests.cpp`
**Location:** `/Source/WispCPP7VR/Tests/SaveSystem_Tests.cpp`  
**Size:** ~400 lines  
**Status:** Ready to compile and run  
**Create Folder:** If doesn't exist: `/Source/WispCPP7VR/Tests/`  
**Compile:** Add "TestsFramework" to `WispCPP7VR.Build.cs`

---

## ✏️ Files to Modify

### 1. Project Build File

**File:** `WispCPP7VR.Build.cs`  
**Location:** `/Source/WispCPP7VR/WispCPP7VR.Build.cs`  
**Change:**