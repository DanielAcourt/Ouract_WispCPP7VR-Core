// Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
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
**Model Storage:** `%USERPROFILE%\.ollama\models`

| NAME | ID | SIZE | ROLE |
|:---|:---|:---|:---|
| `llama3:70b` | 786f3184aec0 | 39 GB | Strategic Reasoning & Planning |
| `qwen3-coder:30b` | 06c1097efce0 | 18 GB | Technical Implementation & Code Review |

---

## 🍓 3. Edge Node: "Key Species Monitor"
*   **Hardware:** Raspberry Pi 4
*   **Role:** Headless safety node (PSTA) monitoring physical Key Species (Vessel: Fish Tank/Plant).
*   **Interface:** GPIO-linked physical sensors (IoT Truth).

---

## 🔭 4. Future Expansion & Principles
The Iron Officer architecture is designed to be machine-agnostic and scalable.
- **Node Discovery:** New machines (Vessels) will be registered in this manifest before being permitted into the Sovereign Cluster.
- **Decentralization:** While the 5090 is the current "Administrative Brain," the PSTA logic is distributed to the edge (Pi 4) to ensure safety even if the primary bridge is severed.
