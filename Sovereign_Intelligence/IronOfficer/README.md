# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 Setup Instructions (GTX 5090 Optimized)

### 1. Install Ollama (The Brain)
1.  **Download:** Go to [ollama.com](https://ollama.com/download) and download the Windows or Linux version.
2.  **Verify GPU Acceleration:**
    -   Open your terminal (PowerShell or Bash).
    -   Run: `ollama list` (This starts the background service).
    -   **Important:** To ensure it uses your 5090, check your Task Manager (Performance tab) or run `nvidia-smi` while the model is running to see VRAM usage on the GPU.

### 2. Pull the Model
Run the following command to download the 70B model (Optimized for the 5090's large VRAM):
```bash
ollama pull llama3:70b
```
*Note: If you want a faster, lighter version for testing, use `ollama pull llama3`.*

### 3. Setup the Python Bridge
1.  **Navigate to this directory:**
    ```bash
    cd Sovereign_Intelligence/IronOfficer/
    ```
2.  **Install Requirements:**
    ```bash
    pip install -r requirements.txt
    ```

### 4. Run the Bridge
```bash
python bridge.py
```
The bridge will start at `http://localhost:8000`. It acts as a middleman, taking telemetry from Unreal and converting it into JSON prompts for Ollama.

---

## 📡 API Endpoints

-   `GET /`: Health check (Returns identity as "Iron Officer").
-   `POST /v1/safety/evaluate`: Sends PSTA telemetry for LLM-based VSS risk assessment.
-   `POST /v1/nexus/query`: Queries the AI Nexus documentation using the local model.

## 🏗️ Technical Architecture
-   **Host:** Local Machine (Lead's Desktop).
-   **Hardware:** NVIDIA GeForce RTX 5090.
-   **Inference Engine:** Ollama (serving Llama 3).
-   **Bridge:** FastAPI (Async Python 3.10).

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions. This bypasses the need for cloud-based agents during live simulation sessions, ensuring absolute data sovereignty and low-latency safety responses.
