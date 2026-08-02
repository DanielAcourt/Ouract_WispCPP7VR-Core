// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-08-01
# Research Proposal: Hardware-Agnostic Telemetry (T-Pillar) Implementation Spec

**Date:** 2026-08-01
**Agent:** Jules (Researcher / Systems Alchemist)
**Version:** 36.4.7-Knight-AAS-RAG
**Status:** 07 - Research Proposal Complete

---

## 🏛️ 1. Philosophical Grounding & Problem Definition

The **Sovereign Framework's Technical (T) Pillar** serves as our diagnostic window into local machine state, anchoring the Agent's decision-making in hard physical truth. In version 36.4.7, the T-pillar calculation is coupled directly with the `nvidia-smi` command-line utility.

This introduces a severe architectural fragility:
1.  **Hardware Dependency:** If the local sandbox executes on non-NVIDIA GPUs (e.g., AMD Radeon on student machines, Intel Iris on laptops, or Apple Silicon), `nvidia-smi` fails.
2.  **Telemetry Snap-Failure:** Any failure querying hardware throws an unhandled exception or returns an empty payload.
3.  **Coherence (Phi) Collapse:** Without valid telemetry status, the system's Coherence Coefficient ($\Phi$) snaps instantly to **`0.0`** (unusable status).
4.  **Operational Stasis:** A zero-coherence state lowers the **Viability Safety Score (VSS)** below the mutation gate, blocking all write operations and locking the local environment.

To realize a fully sovereign, resilient, and developer-friendly infrastructure, we must design an abstract, **hardware-agnostic telemetry subsystem** that dynamically accommodates NVIDIA, AMD, Intel, and CPU-only topologies without hardcoding card-specific paths.

---

## 📐 2. The Strategy Design Pattern Abstraction

Rather than hardcoding conditional queries for specific GPU card models, the standard convention is to separate telemetry interfaces from vendor-specific driver implementations.

```text
                  +--------------------------+
                  |  SovereignTelemetry      |  <--- Generic Contract Interface
                  +--------------------------+
                               |
       +-----------------------+-----------------------+
       |                       |                       |
+------v-------+        +------v-------+        +------v-------+
|  NvidiaNVML  |        |  AMDRadeon   |        | CPUFallback  |  <--- Concrete Providers
+--------------+        +--------------+        +--------------+
```

### A. The Base Telemetry Provider
We define an abstract base contract class `SovereignTelemetryProvider` which each physical hardware driver module must implement:

```python
class SovereignTelemetryProvider:
    def initialize(self) -> bool:
        """
        Attempts to bind to the physical drivers.
        Returns True if successful, False if hardware is missing.
        """
        raise NotImplementedError

    def get_temperature(self) -> int:
        """Returns GPU core temperature in Celsius."""
        raise NotImplementedError

    def get_utilization(self) -> int:
        """Returns GPU core utilization as an integer percentage [0-100]."""
        raise NotImplementedError

    def get_vram_usage(self) -> dict:
        """Returns dict containing {'used': int, 'total': int} in MB."""
        raise NotImplementedError

    def get_status(self) -> str:
        """Returns standard status string: 'NOMINAL', 'WARNING', or 'CRITICAL'."""
        raise NotImplementedError
```

### B. Vendor-Specific Implementation Strategies

#### 1. NVIDIA Strategy (NVML)
- **Primary Mechanism:** Binds directly to the compiled **NVML (NVIDIA Management Library)** shared library (`nvml.dll` on Windows / `libnvidia-ml.so` on Linux) using python ctypes or `py3nvml`.
- **Secondary Fallback:** Executes the `nvidia-smi` command-line utility.
- **Initialization Check:** Succeeds if the library can load and find at least one NVIDIA device.

#### 2. AMD Radeon Strategy (ROCm & ADL)
- **Linux Environment:** Queries the standard open-source **`rocm-smi`** utility or reads sysfs attributes directly.
- **Windows Environment:** Interacts with the **ADL (AMD Display Library)** API via ctypes.
- **Initialization Check:** Succeeds if AMD drivers are detected.

#### 3. CPU-Resident Fallback Strategy
- **Mechanism:** Monitors CPU cores and system RAM using the cross-platform **`psutil`** library (which compiles natively on all major architectures).
- **Metric Mapping:**
  - CPU Core Utilization maps to "Utilization".
  - Host RAM usage maps to "VRAM Usage".
  - Motherboard/CPU sensors map to "Temperature".
- **Status:** Evaluated as a virtualized nominal environment, returning a status of **`NOMINAL (EMULATED)`** and ensuring the $\Phi$ coefficient remains at **`1.0`**.

---

## 💻 3. OS-Level Native Query APIs (Zero-Dependency Fallbacks)

If external vendor binaries are missing, the bridge should bypass third-party tools and query the host operating system directly.

### A. Windows: WMI (Windows Management Instrumentation)
Windows abstracts all installed graphic components through standard WMI classes. We can run standard SQL-style queries natively in Python to retrieve VRAM and device status:

```python
import win32com.client

def query_windows_wmi():
    wmi = win32com.client.GetObject("winmgmts:")
    controllers = wmi.InstancesOf("Win32_VideoController")
    for controller in controllers:
        name = controller.Properties_("Name").Value
        ram = controller.Properties_("AdapterRAM").Value
        status = controller.Properties_("Status").Value
        print(f"Device: {name} | VRAM: {ram} bytes | OS Status: {status}")
```

### B. Linux: Sysfs (`/sys`) & hwmon Interface
On Linux, all hardware telemetry is exposed as read-only virtual files. We can monitor thermals and power draw with simple file operations, completely bypassing vendor SDKs:

```python
import os

def read_linux_sysfs_sensors() -> int:
    # Locate core temperature sensors
    hwmon_base = "/sys/class/hwmon/"
    if os.path.exists(hwmon_base):
        for hwmon in os.listdir(hwmon_base):
            name_file = os.path.join(hwmon_base, hwmon, "name")
            if os.path.exists(name_file):
                with open(name_file, "r") as f:
                    if "amdgpu" in f.read():
                        temp_file = os.path.join(hwmon_base, hwmon, "temp1_input")
                        if os.path.exists(temp_file):
                            with open(temp_file, "r") as tf:
                                return int(tf.read().strip()) // 1000 # Convert millidegrees to C
    return 0
```

---

## 🛠️ 4. Dynamic Provider Discovery Engine

At bridge startup, we instantiate and queue all available telemetry strategies. The first provider that successfully initializes is bound as the active telemetry driver.

```python
class TelemetryOrchestrator:
    def __init__(self):
        self.providers = [
            NvidiaNVMLProvider(),
            AMDRadeonProvider(),
            CPUFallbackProvider()  # Guaranteed to return True on initialize
        ]
        self.active_provider = None

    def discover_hardware(self):
        for provider in self.providers:
            try:
                if provider.initialize():
                    self.active_provider = provider
                    logger.info(f"07 TELEMETRY: Successfully bound to hardware provider: {provider.__class__.__name__}")
                    return
            except Exception as e:
                logger.debug(f"Telemetry provider {provider.__class__.__name__} failed initialization: {e}")

        # Fallback security layer
        self.active_provider = CPUFallbackProvider()
        self.active_provider.initialize()
```

---

## 🎯 5. Definition of Done (DoD)

To close out the proposed **B-031 (Hardware-Agnostic Telemetry Fallback)** implementation ticket in future iterations, the following criteria must be met and verified:

1.  **Driver Safety:** No unhandled exceptions are raised during `get_psta_telemetry()` calls, regardless of whether NVIDIA drivers are installed on the local system.
2.  **Telemetry Delivery:** Querying `GET /v1/psta/salute` on non-NVIDIA machines returns valid JSON with `T` fields (Temperature, Utilization, and VRAM) successfully populated.
3.  **Coherence Preservation:** The system's Coherence Coefficient ($\Phi$) retains a score of `1.0` on non-NVIDIA laptops, avoiding local `409_CONFLICT_GATE` stasis.
4.  **Unit Test Integration:** The regression suite (`test_rag_and_psta.py`) mock-tests the fallback engine by verifying that disabling NVIDIA mock-adapters successfully routes calls to the CPU-resident monitor.

---
// Copyright (c) 2013-2026 Daniel Acourt. Licensed under GPLv3.
