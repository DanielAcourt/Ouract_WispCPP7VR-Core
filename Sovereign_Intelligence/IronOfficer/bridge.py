# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
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

# --- Configuration & State ---
OLLAMA_BASE_URL = "http://localhost:11434/api"
CONFIG_FILE = "config.json"

NEXUS_PATH = "Unknown"
DETECTED_MODELS = []
HARDWARE_ID = "GTX 5090"

def load_config():
    if os.path.exists(CONFIG_FILE):
        with open(CONFIG_FILE, 'r') as f:
            return json.load(f)
    return {"Settings": {"ActiveModel": "llama3:70b", "FallbackModel": "llama3"}}

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
    try:
        response = requests.get(f"http://localhost:11434/api/tags")
        if response.status_code == 200:
            return [m['name'] for m in response.json().get('models', [])]
        return []
    except:
        return []

def get_best_available_model() -> str:
    config = load_config()
    target = config["Settings"].get("ActiveModel", "llama3:70b")
    fallback = config["Settings"].get("FallbackModel", "llama3")

    models = get_installed_models()
    if target in models:
        return target
    if fallback in models:
        return fallback

    # Tier-based discovery
    for tier in ["Commander", "Officer", "Instinct"]:
        for model_name in config.get("AvailableTiers", {}).get(tier, []):
            if any(model_name in m for m in models):
                return [m for m in models if model_name in m][0]

    return models[0] if models else target

def perform_07_handshake():
    global DETECTED_MODELS
    DETECTED_MODELS = get_installed_models()
    current_model = get_best_available_model()

    print("\n" + "="*50)
    print("[07] Iron Officer Initialized.")
    print(f"[07] Active Model: {current_model}")
    print(f"[07] Nexus Path: \"{NEXUS_PATH}\"")
    print(f"[07] Hardware: {HARDWARE_ID}")

    if os.path.exists(NEXUS_PATH):
        print("[07] Administrative Pillar: VERIFIED")
    else:
        print("[07] Administrative Pillar: WARNING (Nexus Path Missing)")

    print(f"[07] Technical Pillar: {len(DETECTED_MODELS)} Models Loaded")
    print("[07] All Pillars Nominal. Standing by for Commander.")
    print("="*50 + "\n")

# --- Core Logic ---

@app.get("/")
async def root():
    return {
        "status": "online",
        "identity": "Iron Officer",
        "hardware": HARDWARE_ID,
        "nexus": NEXUS_PATH,
        "active_model": get_best_available_model(),
        "installed_models": DETECTED_MODELS
    }

@app.get("/v1/ollama/status")
async def get_ollama_status():
    try:
        response = requests.get(f"http://localhost:11434/api/tags")
        response.raise_for_status()
        return response.json()
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Cannot reach Ollama: {str(e)}")

@app.post("/v1/safety/evaluate")
async def evaluate_safety(request: VSSRequest):
    current_model = get_best_available_model()

    prompt = f"""
    [SYSTEM: Sovereign Iron Officer]
    Analyze the following PSTA telemetry for the Sovereign Framework.
    Source Nexus: {NEXUS_PATH}

    Telemetry Data:
    {json.dumps([t.dict() for t in request.telemetry], indent=2)}

    Respond in JSON format:
    {{
        "vss": float,
        "status": "Nominal|Caution|Warning|Critical",
        "rationale": "...",
        "command": "STAY|ABORT|THROTTLE"
    }}
    """

    try:
        response = requests.post(
            f"{OLLAMA_BASE_URL}/generate",
            json={"model": current_model, "prompt": prompt, "stream": False, "format": "json"}
        )
        response.raise_for_status()
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

    perform_07_handshake()
    uvicorn.run(app, host="0.0.0.0", port=8000)
