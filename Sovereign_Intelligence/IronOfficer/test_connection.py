# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Verification Script
Run this to test the connection between the Bridge, Ollama, and your GTX 5090.
"""

import requests
import json

BRIDGE_URL = "http://localhost:8000"

def test_bridge_health():
    print("--- Testing Bridge Health ---")
    try:
        response = requests.get(BRIDGE_URL)
        print(f"Status: {response.status_code}")
        print(f"Response: {response.json()}")
    except Exception as e:
        print(f"Error connecting to Bridge: {e}")
        print("Make sure 'run_bridge.bat' is running in another window.")

def check_ollama_models():
    print("\n--- Checking Ollama Models ---")
    try:
        response = requests.get(f"{BRIDGE_URL}/v1/ollama/status")
        if response.status_code == 200:
            models = response.json().get('models', [])
            model_names = [m['name'] for m in models]
            print(f"Found Models: {model_names}")
            if "llama3:70b" not in model_names:
                print("[WARNING] 'llama3:70b' not found in Ollama. Evaluation might fail.")
                print("Run: 'ollama pull llama3:70b' in a CMD window.")
        else:
            print(f"Error: {response.json()}")
    except Exception as e:
        print(f"Error: {e}")

def test_vss_evaluation():
    print("\n--- Testing VSS Evaluation (Ollama + 5090) ---")
    telemetry = [
        {"pillar": "T", "value": 0.9, "metadata": {"temp": "nominal"}},
        {"pillar": "P", "value": 0.4, "metadata": {"stress": "high"}}
    ]
    payload = {
        "telemetry": telemetry,
        "context": "Simulated stress test on the Lead's machine."
    }

    try:
        response = requests.post(f"{BRIDGE_URL}/v1/safety/evaluate", json=payload)
        print(f"Status: {response.status_code}")
        if response.status_code == 200:
            print("Iron Officer Analysis:")
            print(json.dumps(response.json(), indent=2))
        else:
            print("Error Details:")
            print(json.dumps(response.json(), indent=2))
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    test_bridge_health()
    check_ollama_models()
    test_vss_evaluation()
