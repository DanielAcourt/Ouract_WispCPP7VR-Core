# Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Bridge (AD-001)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
"""

import os
import json
import requests
import argparse
from typing import Dict, Any, List, Optional
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
# Use 127.0.0.1 instead of localhost for Windows stability (IPv4 preference)
OLLAMA_HOST = "http://127.0.0.1:11434"
TARGET_MODEL = "llama3:70b"

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

def perform_07_handshake():
    """Outputs the 07 Protocol Salute to the terminal."""
    global DETECTED_MODELS
    DETECTED_MODELS = get_installed_models()

    print("\n" + "="*50)
    print("[07] Iron Officer Initialized.")
    print(f"[07] Persona: Structural Lead (Local)")
    print(f"[07] Nexus Path: \"{NEXUS_PATH}\"")
    print(f"[07] Detected Models: {', '.join(DETECTED_MODELS) if DETECTED_MODELS else 'None'}")
    print(f"[07] Hardware: {HARDWARE_ID}")

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
        response = requests.get(f"{OLLAMA_HOST}/api/tags")
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
    {json.dumps([t.dict() for t in request.telemetry], indent=2)}

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

    uvicorn.run(app, host="0.0.0.0", port=8000)
