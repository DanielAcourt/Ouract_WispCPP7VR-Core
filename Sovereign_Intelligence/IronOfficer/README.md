# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 "One-Click" Setup (Recommended)

1.  **Start the Bridge:** Double-click **`run_bridge.bat`**.
2.  **Verify the Connection:** Double-click **`verify_connection.bat`**.

---

## 🛠️ Troubleshooting

### Autodiscovery
Our batch files automatically search for Python in `%LocalAppData%\Programs\Python` and `%ProgramFiles%\Python`. If the bridge still fails to start, proceed with the manual fixes below.

### "Python was not found" / Microsoft Store Prompt
If Windows tries to open the Microsoft Store:
1.  **Search:** Type "App execution aliases" in your Windows Start menu.
2.  **Disable:** Find the entries for `python.exe` and `python3.exe` and switch them **OFF**.
3.  **Path Fix:** Re-install Python from [python.org](https://www.python.org/) and ensure "Add Python to PATH" is checked.

### Windows Path Spaces
The provided batch files handle spaces (like `Unreal Projects`) automatically. If running manually, wrap your path in double quotes:
`cd "C:\Users\Danie\Unreal Projects\..."`

---

## 📡 API Endpoints
-   `GET /`: Health check.
-   `POST /v1/safety/evaluate`: PSTA telemetry evaluation.
-   `POST /v1/nexus/query`: AI Nexus research query.

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions locally on the 5090, ensuring absolute data sovereignty.
