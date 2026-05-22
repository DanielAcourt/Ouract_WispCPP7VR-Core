# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Iron Officer: Local Sovereign Bridge (GTX 5090)

This is the Python-based bridge for the **Iron Officer** (AD-001). It connects the local Unreal simulation and Raspberry Pi hardware to a high-parameter LLM (Llama 3 70B) running on the GTX 5090.

## 🚀 Setup Instructions

1.  **Prerequisites:**
    -   Python 3.10+
    -   [Ollama](https://ollama.com/) installed and running on your host machine.
    -   GTX 5090 drivers and CUDA configured.

2.  **Install Dependencies:**
    ```bash
    pip install -r requirements.txt
    ```

3.  **Pull the Model:**
    ```bash
    ollama pull llama3:70b
    ```

4.  **Run the Bridge:**
    ```bash
    python bridge.py
    ```
    The bridge will start at `http://localhost:8000`.

## 📡 API Endpoints

-   `GET /`: Health check.
-   `POST /v1/safety/evaluate`: Sends PSTA telemetry for LLM-based VSS risk assessment.
-   `POST /v1/nexus/query`: Queries the AI Nexus documentation using the local model.

## 🏛️ Strategic Role
The Iron Officer acts as the **Administrative (A)** brain. It interprets **Technical (T)** truth and provides "Command" decisions. This bypasses the need for cloud-based agents during live simulation sessions, ensuring absolute data sovereignty and low-latency safety responses.
