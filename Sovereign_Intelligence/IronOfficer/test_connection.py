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
        print("Make sure 'python bridge.py' is running in a terminal.")

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
        print("Iron Officer Analysis:")
        print(json.dumps(response.json(), indent=2))
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    test_bridge_health()
    test_vss_evaluation()
