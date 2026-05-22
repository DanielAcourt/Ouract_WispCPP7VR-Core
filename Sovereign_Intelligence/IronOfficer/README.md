# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 Setup Instructions (GTX 5090 Optimized)

### 1. Install Ollama (The Brain)
1.  **Download:** Go to [ollama.com](https://ollama.com/download) and download the Windows version.
2.  **Verify GPU Acceleration:**
    -   Open your terminal (PowerShell or CMD).
    -   Run: `ollama list` (This starts the background service).
    -   **Important:** To ensure it uses your 5090, check your Task Manager (Performance tab) or run `nvidia-smi` while the model is running.

### 2. Pull the Model
Run the following command to download the 70B model:
```bash
ollama pull llama3:70b
```

### 3. Setup the Python Bridge
1.  **Navigate to this directory:**
    -   **Windows Tip:** If your path has spaces (e.g., `Unreal Projects`), you **must** use double quotes.
    ```powershell
    cd "C:\Users\Danie\Unreal Projects\2027\repo\Ouract_WispCPP7VR-Core\Sovereign_Intelligence\IronOfficer"
    ```
2.  **Install Requirements:**
    ```bash
    pip install -r requirements.txt
    ```

### 4. Run the Bridge
```bash
python bridge.py
```
The bridge will start at `http://localhost:8000`.

---

## 🛠️ Troubleshooting Windows Spaces
If you encounter "File not found" or "Path not recognized" errors due to the space in `Unreal Projects`:
1.  **Quote your paths:** Always wrap the entire path in double quotes: `"C:\Path With Spaces\..."`.
2.  **Use Tab-Completion:** Type `cd "C:\Users\Danie\Unreal ` and press **Tab**; Windows will automatically wrap the path correctly for you.
3.  **Python Execution:** If calling from a batch file, use: `python "C:\Path with spaces\bridge.py"`.

## 📡 API Endpoints
-   `GET /`: Health check.
-   `POST /v1/safety/evaluate`: PSTA telemetry evaluation.
-   `POST /v1/nexus/query`: AI Nexus research query.

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions locally on the 5090, ensuring absolute data sovereignty.
