// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Research Node: Local AI Model Tiers

## 🔬 1. The Philosophical "Why"
To ensure the Sovereign Framework utilizes the correct "Cognitive Vessel" for the task. Running a 70B model for simple sensor thresholding is inefficient, while running a 3B model for strategic roadmap synthesis results in "hallucinatory drift."

---

## 📐 2. Tier Definitions

### 2.1 Tier 0: The "Instinct" Layer (1B - 8B Parameters)
*   **Persona:** Tactician (The Clockwork) / Secondary Sensors.
*   **Role:** High-frequency PSTA VSS calculation, JSON parsing, and real-time anomaly detection.
*   **Target Models:** `llama3:8b`, `phi3:mini`.
*   **Hardware Goal:** Sub-50ms inference.

### 2.2 Tier 1: The "Officer" Layer (14B - 34B Parameters)
*   **Persona:** Researcher (The Alchemist).
*   **Role:** Technical reasoning, C++ code review, and metadata transcription from Lidar logs.
*   **Target Models:** `qwen3-coder:30b`, `codellama:34b`.
*   **Hardware Goal:** Sub-200ms inference.

### 2.3 Tier 2: The "Commander" Layer (70B+ Parameters)
*   **Persona:** Strategist (The Commander).
*   **Role:** Large-scale research synthesis, roadmap evolution, and cross-repo architectural alignment.
*   **Target Models:** `llama3:70b`, `mixtral:8x7b`.
*   **Hardware Goal:** Sustained high-fidelity reasoning on the GTX 5090.

---

## 🛰️ 3. Sovereign Deployment Rule
All models must be hosted within the same local directory via **Ollama** or **vLLM** to ensure the Iron Officer Bridge can perform high-speed context switching without external network latency.
