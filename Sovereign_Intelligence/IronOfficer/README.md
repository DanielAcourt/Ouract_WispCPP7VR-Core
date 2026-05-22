# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 "One-Click" Setup (Recommended)

1.  **Start the Bridge:** Double-click **`run_bridge.bat`**.
2.  **Verify the Connection:** Double-click **`verify_connection.bat`**.

---

## 🛠️ Troubleshooting

### "Python was not found" Error
If Windows tells you Python is not found or tries to open the Microsoft Store:
1.  **Check Path:** Ensure you checked "Add Python to PATH" when you installed Python.
2.  **App Execution Aliases:**
    -   Search for **"App execution aliases"** in your Windows Start menu.
    -   Find the entries for **"python.exe"** and **"python3.exe"** and **DISABLE** them. This prevents Windows from redirecting you to the Store.
3.  **Use 'py' Launcher:** Our batch files now automatically try the `py` launcher if `python` is missing.

### Windows Path Spaces
Always use the provided batch files. If running manually, wrap your path in double quotes:
`cd "C:\Users\Danie\Unreal Projects\..."`

---

## 📡 API Endpoints
-   `GET /`: Health check.
-   `POST /v1/safety/evaluate`: PSTA telemetry evaluation.
-   `POST /v1/nexus/query`: AI Nexus research query.

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions locally on the 5090, ensuring absolute data sovereignty.
