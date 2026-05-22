# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Bridge (AD-001)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
"""

import os
import json
import requests
from typing import Dict, Any, List, Optional
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
OLLAMA_BASE_URL = "http://localhost:11434/api"
TARGET_MODEL = "llama3:70b"  # The ideal mission model

# --- Schemas ---
class PSTATelemetry(BaseModel):
    pillar: str  # P, S, T, A
    value: float
    metadata: Dict[str, Any] = {}

class VSSRequest(BaseModel):
    telemetry: List[PSTATelemetry]
    context: str = ""

# --- Helper Functions ---

def get_best_available_model() -> str:
    """Attempts to find the target model, falls back to any available llama3."""
    try:
        response = requests.get(f"{OLLAMA_BASE_URL}/tags")
        if response.status_code == 200:
            models = [m['name'] for m in response.json().get('models', [])]

            if TARGET_MODEL in models:
                return TARGET_MODEL

            # Look for any llama3 variants
            llama3_variants = [m for m in models if "llama3" in m]
            if llama3_variants:
                return llama3_variants[0]

            # Last resort: just use the first available model
            if models:
                return models[0]

        return TARGET_MODEL # Try anyway
    except:
        return TARGET_MODEL

# --- Core Logic ---

@app.get("/")
async def root():
    return {"status": "online", "identity": "Iron Officer", "hardware": "GTX 5090"}

@app.get("/v1/ollama/status")
async def get_ollama_status():
    """Checks if Ollama is reachable and lists available models."""
    try:
        response = requests.get(f"{OLLAMA_BASE_URL}/tags")
        response.raise_for_status()
        return response.json()
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Cannot reach Ollama: {str(e)}")

@app.post("/v1/safety/evaluate")
async def evaluate_safety(request: VSSRequest):
    """
    Evaluates Vessel Safety Status (VSS) using the best available local LLM.
    """

    current_model = get_best_available_model()

    prompt = f"""
    [SYSTEM: Sovereign Iron Officer]
    Analyze the following PSTA telemetry for the Sovereign Framework.

    Telemetry Data:
    {json.dumps([t.dict() for t in request.telemetry], indent=2)}

    Context: {request.context}

    Task:
    1. Calculate the VSS (Vessel Safety Status).
    2. Identify if any pillar (P, S, T, A) is below failure thresholds.
    3. Provide a 'Sovereign Command' if an immediate abort is required.

    Respond in JSON format only:
    {{
        "vss": float,
        "status": "Nominal|Caution|Warning|Critical",
        "rationale": "...",
        "command": "STAY|ABORT|THROTTLE"
    }}
    """

    try:
        payload = {
            "model": current_model,
            "prompt": prompt,
            "stream": False,
            "format": "json"
        }

        response = requests.post(f"{OLLAMA_BASE_URL}/generate", json=payload)

        if response.status_code != 200:
            error_body = response.text
            raise HTTPException(status_code=response.status_code, detail=f"Ollama Error ({response.status_code}): {error_body}")

        result = response.json()
        return {
            "analysis": json.loads(result['response']),
            "model_used": current_model
        }

    except requests.exceptions.RequestException as e:
        raise HTTPException(status_code=500, detail=f"Network error talking to Ollama: {str(e)}")
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Internal Bridge Error: {str(e)}")

@app.post("/v1/nexus/query")
async def query_nexus(query: str):
    """
    Queries the local AI Nexus research nodes using the 5090.
    """
    current_model = get_best_available_model()
    prompt = f"Using the Sovereign AI Nexus documentation as your source of truth, answer: {query}"

    try:
        response = requests.post(
            f"{OLLAMA_BASE_URL}/generate",
            json={
                "model": current_model,
                "prompt": prompt,
                "stream": False
            }
        )
        response.raise_for_status()
        return {
            "query": query,
            "response": response.json()['response'],
            "model_used": current_model
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Ollama Error: {str(e)}")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
