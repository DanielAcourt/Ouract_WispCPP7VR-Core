# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 "One-Click" Setup (Recommended)

To avoid issues with Windows path spaces and manual commands, use the provided batch files:

1.  **Start the Bridge:** Double-click **`run_bridge.bat`**.
    -   *This starts the FastAPI service at `http://localhost:8000`. Keep this window open.*
2.  **Verify the Connection:** Double-click **`verify_connection.bat`**.
    -   *This runs a test suite against the local Ollama instance and verifies the 5090 integration.*

---

## 🛠️ Manual Setup Instructions

### 1. Install Ollama (The Brain)
1.  **Download:** [ollama.com/download](https://ollama.com/download).
2.  **Pull the Model:** Open CMD and run `ollama pull llama3:70b`.

### 2. Manual Bridge Execution
If you prefer the terminal, ensure you use quotes for your path:
```powershell
cd "C:\Path\To\Your\WispRepository\Sovereign_Intelligence\IronOfficer"
pip install -r requirements.txt
python bridge.py
```

## 📡 API Endpoints
-   `GET /`: Health check.
-   `POST /v1/safety/evaluate`: PSTA telemetry evaluation.
-   `POST /v1/nexus/query`: AI Nexus research query.

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions locally on the 5090, ensuring absolute data sovereignty.
