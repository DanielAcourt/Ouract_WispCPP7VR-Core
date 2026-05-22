# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Bridge (AD-001)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
"""

import os
import json
import requests
from typing import Dict, Any, List
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
OLLAMA_BASE_URL = "http://localhost:11434/api"
DEFAULT_MODEL = "llama3:70b"  # Optimized for GTX 5090
VSS_THRESHOLD_NOMINAL = 0.8

# --- Schemas ---
class PSTATelemetry(BaseModel):
    pillar: str  # P, S, T, A
    value: float
    metadata: Dict[str, Any] = {}

class VSSRequest(BaseModel):
    telemetry: List[PSTATelemetry]
    context: str = ""

# --- Core Logic ---

@app.get("/")
async def root():
    return {"status": "online", "identity": "Iron Officer", "hardware": "GTX 5090"}

@app.post("/v1/safety/evaluate")
async def evaluate_safety(request: VSSRequest):
    """
    Evaluates Vessel Safety Status (VSS) using the local LLM.
    Acts as the Administrative (A) "brain" analyzing Technical (T) and Psychological (P) telemetry.
    """

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
        response = requests.post(
            f"{OLLAMA_BASE_URL}/generate",
            json={
                "model": DEFAULT_MODEL,
                "prompt": prompt,
                "stream": False,
                "format": "json"
            }
        )
        response.raise_for_status()
        result = response.json()
        return json.loads(result['response'])

    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Ollama Error: {str(e)}")

@app.post("/v1/nexus/query")
async def query_nexus(query: str):
    """
    Queries the local AI Nexus research nodes using the 5090 for high-parameter reasoning.
    """
    # Placeholder for RAG implementation
    prompt = f"Using the Sovereign AI Nexus documentation as your source of truth, answer: {query}"

    response = requests.post(
        f"{OLLAMA_BASE_URL}/generate",
        json={
            "model": DEFAULT_MODEL,
            "prompt": prompt,
            "stream": False
        }
    )
    return {"query": query, "response": response.json()['response']}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
