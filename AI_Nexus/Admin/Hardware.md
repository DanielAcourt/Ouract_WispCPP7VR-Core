// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Hardware Source of Truth (Inventory)

## 👑 1. Primary Authority
All hardware listed herein is owned and operated by the **Technical Lead (Admin)**: **Daniel Acourt**.
- **Admin Privileges:** Full root/sudo access to all local nodes.
- **Role:** Primary User and Sovereign Authority.

---

## 🖥️ 2. Primary Compute Node: "Iron Officer"
*   **Host System:** High-performance Windows Workstation
*   **GPU:** NVIDIA GeForce RTX 5090
*   **Role:** Local Sovereign Bridge, high-parameter LLM inference, and AI Nexus repository host.
*   **OS:** Microsoft Windows [Version 10.0.26200.8457]

### 📡 Ollama Inventory (Verified Modules)
These modules are confirmed installed on the 5090 and accessible via the Iron Officer bridge.

**Installation Root:** `C:\Users\Danie\AppData\Local\Programs\Ollama`
**Model Storage:** `C:\Users\Danie\.ollama\models`
**Technical Config:** `Sovereign_Intelligence/IronOfficer/config.json`

| NAME | ID | SIZE | MANIFEST PATH | ROLE |
|:---|:---|:---|:---|:---|
| `llama3:70b` | 786f3184aec0 | 39 GB | `...\manifests\registry.ollama.ai\library\llama3\70b` | Strategic Reasoning |
| `llama3.1:latest` | - | - | - | Local Evaluation (Verified) |
| `qwen3-coder:30b` | 06c1097efce0 | 18 GB | `...\manifests\registry.ollama.ai\library\qwen3-coder\30b` | Code Review |

---

## 🛠️ "Iron Officer" Self-Healing Features
- **GPU Verification:** The bridge now uses `nvidia-smi` to confirm hardware truth (GTX 5090) on startup.
- **Port Autodiscovery:** The launcher detects port blockers and offers to terminate them automatically.
- **Environment Parity:** The `config.json` synchronizes `OLLAMA_MODELS` paths with the Windows host.

---

## 🛠️ Troubleshooting & Technical (T) Pillar Recovery
If the 07 Handshake fails or Ollama is "Refusing Connection":
1. **Ollama Service:** Ensure the Ollama icon is visible in the Windows System Tray.
2. **Port Conflict (10048):** The Bridge requires Port 8000. If blocked, find and kill the process: `netstat -ano | findstr :8000`.
3. **IPv4 Binding:** Ensure the bridge is bound to `127.0.0.1`. Windows often fails to resolve `localhost` in restricted environments.
4. **Empty Model List:** If Ollama is running but no models are detected:
    - Open a CMD window and run `ollama list`.
    - If `ollama list` shows models but the Bridge does not, it means the **Ollama.app.exe** process is unaware of your custom model path.
    - **Permanent Fix:** Add a System Environment Variable named `OLLAMA_MODELS` pointing to your path.
    - **Session Fix:** Fully exit Ollama from the Windows System Tray, then launch it via `run_bridge.bat` which injects the variable.
5. **Nvidia-SMI Not Found:** If GPU detection fails, ensure the Nvidia Drivers are installed and `C:\Program Files\NVIDIA Corporation\NVSMI` is in your System PATH.

---

## 🖥️ 3. Advanced Compute Optimization (KV Cache)
To maximize the 32GB VRAM of the **RTX 5090** and the **64GB System RAM** reservoir during Deep Ingestion:

### 3.1 KV Cache Quantization
- **Goal:** Double the context window for repository-wide ingestion.
- **Implementation:** Compressing the KV Cache to **FP8** or **INT4**. Cuts the memory footprint in half without significant accuracy loss.
- **Vessel Logic:** Allows for ~64k context support on the 5090.

### 3.2 Dynamic RAM Offloading
- **Goal:** Utilize the 64GB System RAM for overflow parking lot.
- **Mechanism:** Large models (70B+) can offload their KV cache layers to system RAM over the high-speed interconnect.
- **Trade-off:** Decelerates the "decode" phase but prevents OOM errors during `/read all`.

### 3.3 Smart Prefix Caching (PagedAttention)
- **Goal:** Instant responses for repeated codebase queries.
- **Mechanism:** The engine hashes and locks file structures into VRAM. Subsequent turns skip recalculation if files are unchanged.

### 3.4 Allocation Pool Management
- **num_ctx:** Explicitly set to `32768` in `config.json` to pre-allocate context blocks.
- **num_gpu:** If context window is insufficient, lower the GPU layer count (e.g., to 72 layers) to force model weights into system RAM, freeing VRAM exclusively for the tracking cache.

---

## 🍓 4. Edge Node: "Key Species Monitor"
*   **Hardware:** Raspberry Pi 4
*   **Role:** Headless safety node (PSTA) monitoring physical Key Species (Vessel: Fish Tank/Plant).
*   **Interface:** GPIO-linked physical sensors (IoT Truth).

---

## 🔭 5. Future Expansion & Principles
The Iron Officer architecture is designed to be machine-agnostic and scalable.
- **Node Discovery:** New machines (Vessels) will be registered in this manifest before being permitted into the Sovereign Cluster.
- **Decentralization:** While the 5090 is the current "Administrative Brain," the PSTA logic is distributed to the edge (Pi 4) to ensure safety even if the primary bridge is severed.
