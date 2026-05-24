# Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Bridge (AD-001)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
"""

import os
import json
import subprocess
import requests
import argparse
from typing import Dict, Any, List, Optional
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
CONFIG_PATH = os.path.join(os.path.dirname(__file__), "config.json")
OLLAMA_HOST = "http://127.0.0.1:11434"
TARGET_MODEL = "llama3:70b"
BRIDGE_PORT = 8000

def load_config():
    global OLLAMA_HOST, TARGET_MODEL, BRIDGE_PORT
    if os.path.exists(CONFIG_PATH):
        try:
            with open(CONFIG_PATH, "r") as f:
                cfg = json.load(f)
                ollama_cfg = cfg.get("ollama", {})
                bridge_cfg = cfg.get("bridge", {})
                OLLAMA_HOST = f"http://{ollama_cfg.get('host', '127.0.0.1')}:{ollama_cfg.get('port', 11434)}"
                TARGET_MODEL = ollama_cfg.get("target_model", "llama3:70b")
                BRIDGE_PORT = bridge_cfg.get("port", 8000)
        except Exception as e:
            print(f"[07 WARNING] Failed to load config.json: {e}")

load_config()

# Global state for the 07 Salute
NEXUS_PATH = "Unknown"
DETECTED_MODELS = []
HARDWARE_ID = "GTX 5090 (Assumed)"

# --- Schemas ---
class PSTATelemetry(BaseModel):
    pillar: str  # P, S, T, A
    value: float
    metadata: Dict[str, Any] = {}

class VSSRequest(BaseModel):
    telemetry: List[PSTATelemetry]
    context: str = ""

# --- Helper Functions ---

def get_installed_models() -> List[str]:
    """Queries Ollama for installed models."""
    try:
        response = requests.get(f"{OLLAMA_HOST}/api/tags", timeout=5)
        if response.status_code == 200:
            models = response.json().get('models', [])
            return [m['name'] for m in models]
        print(f"[ERROR] Ollama returned status code: {response.status_code}")
        return []
    except Exception as e:
        print(f"[ERROR] Connection to Ollama failed: {str(e)}")
        return []

def get_best_available_model() -> str:
    """Attempts to find the target model, falls back to best available."""
    models = get_installed_models()
    if TARGET_MODEL in models:
        return TARGET_MODEL

    # Fallback logic
    llama3_variants = [m for m in models if "llama3" in m]
    if llama3_variants: return llama3_variants[0]

    qwen_variants = [m for m in models if "qwen" in m]
    if qwen_variants: return qwen_variants[0]

    return models[0] if models else TARGET_MODEL

def get_gpu_info() -> str:
    """Attempts to detect the GPU using nvidia-smi."""
    try:
        output = subprocess.check_output(["nvidia-smi", "--query-gpu=gpu_name", "--format=csv,noheader"], encoding='utf-8')
        return output.strip()
    except Exception:
        return "GPU Detection Failed (Is nvidia-smi in PATH?)"

def perform_07_handshake():
    """Outputs the 07 Protocol Salute to the terminal."""
    global DETECTED_MODELS, HARDWARE_ID
    DETECTED_MODELS = get_installed_models()
    gpu_info = get_gpu_info()

    if "5090" in gpu_info:
        HARDWARE_ID = f"GTX 5090 (Verified: {gpu_info})"
    else:
        HARDWARE_ID = f"Unknown GPU (Detected: {gpu_info})"

    print("\n" + "="*50)
    print("[07] Iron Officer Initialized.")
    print(f"[07] Persona: Structural Lead (Local)")
    print(f"[07] Nexus Path: \"{NEXUS_PATH}\"")
    print(f"[07] Detected Models: {', '.join(DETECTED_MODELS) if DETECTED_MODELS else 'None'}")
    print(f"[07] Hardware: {HARDWARE_ID}")
    print(f"[07] Ollama Host: {OLLAMA_HOST}")
    print(f"[07] Ollama Models Dir: {os.environ.get('OLLAMA_MODELS', 'Default')}")

    if os.path.exists(NEXUS_PATH):
        print("[07] Administrative Pillar: VERIFIED")
    else:
        print("[07] Administrative Pillar: WARNING (Nexus Path Not Found)")

    if DETECTED_MODELS:
        print("[07] Technical Pillar: NOMINAL")
    else:
        print("[07] Technical Pillar: CRITICAL (Ollama Empty)")

    print("[07] All Pillars Synchronized. Standing by for Commander.")
    print("="*50 + "\n")

# --- Core Logic ---

@app.get("/")
async def root():
    return {
        "status": "online",
        "identity": "Iron Officer",
        "hardware": HARDWARE_ID,
        "nexus": NEXUS_PATH,
        "models": DETECTED_MODELS
    }

@app.get("/v1/ollama/status")
async def get_ollama_status():
    try:
        response = requests.get(f"{OLLAMA_HOST}/api/tags", timeout=5)
        response.raise_for_status()
        return response.json()
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Cannot reach Ollama at {OLLAMA_HOST}/api/tags: {str(e)}")

@app.post("/v1/safety/evaluate")
async def evaluate_safety(request: VSSRequest):
    current_model = get_best_available_model()

    prompt = f"""
    [SYSTEM: Sovereign Iron Officer]
    Analyze the following PSTA telemetry for the Sovereign Framework.
    Source Nexus: {NEXUS_PATH}

    Telemetry Data:
    {json.dumps([t.model_dump() for t in request.telemetry], indent=2)}

    Context: {request.context}

    Respond in JSON format only:
    {{
        "vss": float,
        "status": "Nominal|Caution|Warning|Critical",
        "rationale": "...",
        "command": "STAY|ABORT|THROTTLE"
    }}
    """

    try:
        response = requests.post(
            f"{OLLAMA_HOST}/api/generate",
            json={"model": current_model, "prompt": prompt, "stream": False, "format": "json"}
        )
        if response.status_code != 200:
            raise HTTPException(status_code=response.status_code, detail=f"Ollama Error: {response.text}")

        result = response.json()
        return {"analysis": json.loads(result['response']), "model_used": current_model}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Internal Bridge Error: {str(e)}")

if __name__ == "__main__":
    import uvicorn
    parser = argparse.ArgumentParser()
    parser.add_argument("--nexus", help="Path to the local AI Nexus directory", default="Unknown")
    args = parser.parse_args()

    NEXUS_PATH = args.nexus

    # Run handshake on startup
    perform_07_handshake()

    try:
        uvicorn.run(app, host="0.0.0.0", port=BRIDGE_PORT)
    except Exception as e:
        print("\n" + "!"*50)
        print(f"[07 CRITICAL] Bridge crashed during startup: {e}")
        if "10048" in str(e):
            print(f"[07] SOLUTION: Port {BRIDGE_PORT} is blocked. Use 'taskkill /F /PID [PID]' to clear it.")
        print("!"*50 + "\n")
        # Keep the process alive for a moment so the user can see the error in the batch window
        import time
        time.sleep(10)
