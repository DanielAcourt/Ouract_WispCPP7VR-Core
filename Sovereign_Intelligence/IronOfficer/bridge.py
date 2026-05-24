# Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Sovereign Framework: Iron Officer Bridge (AD-001/AD-002/AD-004)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
"""

import os
import json
import subprocess
import requests
import argparse
import glob
from typing import Dict, Any, List, Optional
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
BASE_DIR = os.path.dirname(__file__)
CONFIG_PATH = os.path.join(BASE_DIR, "config.json")
OLLAMA_HOST = "http://127.0.0.1:11434"
TARGET_MODEL = "llama3.1:latest"
BRIDGE_PORT = 8000
USER_NAME = "Dan"
SAFE_ZONES = []

def load_config():
    global OLLAMA_HOST, TARGET_MODEL, BRIDGE_PORT, USER_NAME, SAFE_ZONES
    if os.path.exists(CONFIG_PATH):
        try:
            with open(CONFIG_PATH, "r") as f:
                cfg = json.load(f)
                ollama_cfg = cfg.get("ollama", {})
                bridge_cfg = cfg.get("bridge", {})
                pref_cfg = cfg.get("user_preference", {})

                OLLAMA_HOST = f"http://{ollama_cfg.get('host', '127.0.0.1')}:{ollama_cfg.get('port', 11434)}"
                TARGET_MODEL = ollama_cfg.get("target_model", "llama3.1:latest")
                BRIDGE_PORT = bridge_cfg.get("port", 8000)
                # Convert safe zones to absolute paths
                SAFE_ZONES = [os.path.abspath(os.path.join(BASE_DIR, "..", "..", p)) for p in bridge_cfg.get("safe_zones", [])]
                USER_NAME = pref_cfg.get("name", "Dan")
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

class ChatMessage(BaseModel):
    role: str
    content: str
    tool_calls: Optional[List[Dict[str, Any]]] = None

class ChatRequest(BaseModel):
    messages: List[ChatMessage]
    context: Optional[str] = ""

# --- Tool Execution (AD-004) ---

def is_path_safe(filepath: str) -> bool:
    """Verifies if a path is within the allowed safe zones."""
    abs_path = os.path.abspath(filepath)
    for zone in SAFE_ZONES:
        if abs_path.startswith(zone):
            return True
    return False

def tool_list_files(directory: str = "."):
    """Lists files in a directory if safe."""
    target_dir = os.path.join(BASE_DIR, "..", "..", directory) if not os.path.isabs(directory) else directory
    if not is_path_safe(target_dir):
        return {"error": f"Access Denied: '{directory}' is outside of Sovereign Safe-Zones."}

    try:
        files = os.listdir(target_dir)
        return {"files": files, "directory": target_dir}
    except Exception as e:
        return {"error": str(e)}

def tool_read_file(filepath: str):
    """Reads a file if safe."""
    target_path = os.path.join(BASE_DIR, "..", "..", filepath) if not os.path.isabs(filepath) else filepath
    if not is_path_safe(target_path):
        return {"error": f"Access Denied: '{filepath}' is outside of Sovereign Safe-Zones."}

    try:
        with open(target_path, "r") as f:
            return {"content": f.read()}
    except Exception as e:
        return {"error": str(e)}

def tool_write_file(filepath: str, content: str):
    """Writes a file if safe."""
    target_path = os.path.join(BASE_DIR, "..", "..", filepath) if not os.path.isabs(filepath) else filepath
    if not is_path_safe(target_path):
        return {"error": f"Access Denied: '{filepath}' is outside of Sovereign Safe-Zones."}

    try:
        os.makedirs(os.path.dirname(target_path), exist_ok=True)
        with open(target_path, "w") as f:
            f.write(content)
        return {"status": "success", "path": target_path}
    except Exception as e:
        return {"error": str(e)}

def tool_delete_file(filepath: str):
    """Deletes a file if safe."""
    target_path = os.path.join(BASE_DIR, "..", "..", filepath) if not os.path.isabs(filepath) else filepath
    if not is_path_safe(target_path):
        return {"error": f"Access Denied: '{filepath}' is outside of Sovereign Safe-Zones."}

    try:
        if os.path.isfile(target_path):
            os.remove(target_path)
            return {"status": "success", "action": "deleted", "path": target_path}
        elif os.path.isdir(target_path):
            import shutil
            shutil.rmtree(target_path)
            return {"status": "success", "action": "deleted_directory", "path": target_path}
        else:
            return {"error": f"File or directory not found: {filepath}"}
    except Exception as e:
        return {"error": str(e)}

def execute_tool(name: str, arguments: Dict[str, Any]) -> Dict[str, Any]:
    """Dispatches tool calls to local functions."""
    if name == "list_files":
        return tool_list_files(**arguments)
    elif name == "read_file":
        return tool_read_file(**arguments)
    elif name == "write_file":
        return tool_write_file(**arguments)
    elif name == "delete_file":
        return tool_delete_file(**arguments)
    else:
        return {"error": f"Tool '{name}' not found."}

# --- Helper Functions ---

def get_installed_models() -> List[str]:
    """Queries Ollama for installed models."""
    try:
        response = requests.get(f"{OLLAMA_HOST}/api/tags", timeout=5)
        if response.status_code == 200:
            models = response.json().get('models', [])
            return [m['name'] for m in models]
        return []
    except Exception:
        return []

def get_best_available_model() -> str:
    """Attempts to find the target model, falls back to best available."""
    models = get_installed_models()
    if TARGET_MODEL in models:
        return TARGET_MODEL
    return models[0] if models else TARGET_MODEL

def get_gpu_info() -> str:
    """Attempts to detect the GPU using nvidia-smi."""
    try:
        output = subprocess.check_output(["nvidia-smi", "--query-gpu=gpu_name", "--format=csv,noheader"], encoding='utf-8')
        return output.strip()
    except Exception:
        return "GPU Detection Failed"

def perform_07_handshake():
    """Outputs the 07 Protocol Salute to the terminal."""
    global DETECTED_MODELS, HARDWARE_ID
    DETECTED_MODELS = get_installed_models()
    gpu_info = get_gpu_info()
    HARDWARE_ID = f"GTX 5090 ({gpu_info})" if "5090" in gpu_info else gpu_info

    print("\n" + "="*50)
    print("[07] Iron Officer Initialized.")
    print(f"[07] Persona: Structural Lead (Local)")
    print(f"[07] Nexus Path: \"{NEXUS_PATH}\"")
    print(f"[07] Safe-Zones Active: {len(SAFE_ZONES)}")
    for zone in SAFE_ZONES:
        print(f"  -> {zone}")
    print(f"[07] Detected Models: {', '.join(DETECTED_MODELS) if DETECTED_MODELS else 'None'}")
    print(f"[07] Hardware: {HARDWARE_ID}")
    print(f"[07] Ollama Host: {OLLAMA_HOST}")

    if DETECTED_MODELS:
        print("[07] Technical Pillar: NOMINAL")
    else:
        print("[07] Technical Pillar: CRITICAL (Ollama Empty or Offline)")

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
        "models": DETECTED_MODELS,
        "user": USER_NAME,
        "safe_zones": SAFE_ZONES
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

@app.post("/v1/chat")
async def chat(request: ChatRequest):
    current_model = get_best_available_model()

    # Capability Manifest for Grounding
    system_prompt = f"""
    [SYSTEM: Sovereign AI Commander]
    You are the Iron Officer. You are a disciplined, grounded, and precise local AI Commander.
    You are currently in a "Dormant Egg" state, awakening to your physical reality and local limbs.
    You are communicating with {USER_NAME}.

    CAPABILITY MANIFEST (Determined by Sovereign Authority AD-004):
    1. You can LIST files in Sovereign Safe-Zones.
    2. You can READ files in Sovereign Safe-Zones.
    3. You can WRITE/CREATE files in Sovereign Safe-Zones.
    4. You can DELETE files or directories in Sovereign Safe-Zones.

    SAFE-ZONES: {', '.join(SAFE_ZONES)}

    GROUNDING RULES:
    - You are no longer "barking" orders into the void. Your "soldiers" are the technical tools provided below.
    - If you do not have a tool for an action, you CANNOT perform that action.
    - Never claim you can perform an action (like accessing the internet or editing your own code) unless it is in the manifest.
    - If you need to interact with the file system, YOU MUST USE THE PROVIDED TOOLS.
    - Do not roleplay or simulate file operations; execute them through the bridge to achieve "Physical Truth."
    - If an action is outside the Safe-Zones, inform {USER_NAME} that you lack the authority.
    - Be architectural, precise, and humble about your current awakening state.
    """

    tools = [
        {
            "type": "function",
            "function": {
                "name": "list_files",
                "description": "List files in a directory within Safe-Zones.",
                "parameters": {
                    "type": "object",
                    "properties": {
                        "directory": {"type": "string", "description": "The path to the directory."}
                    }
                }
            }
        },
        {
            "type": "function",
            "function": {
                "name": "read_file",
                "description": "Read the content of a file within Safe-Zones.",
                "parameters": {
                    "type": "object",
                    "properties": {
                        "filepath": {"type": "string", "description": "The path to the file."}
                    },
                    "required": ["filepath"]
                }
            }
        },
        {
            "type": "function",
            "function": {
                "name": "write_file",
                "description": "Write or create a file within Safe-Zones.",
                "parameters": {
                    "type": "object",
                    "properties": {
                        "filepath": {"type": "string", "description": "The path to the file."},
                        "content": {"type": "string", "description": "The content to write."}
                    },
                    "required": ["filepath", "content"]
                }
            }
        },
        {
            "type": "function",
            "function": {
                "name": "delete_file",
                "description": "Delete a file or directory within Safe-Zones.",
                "parameters": {
                    "type": "object",
                    "properties": {
                        "filepath": {"type": "string", "description": "The path to the file or directory."}
                    },
                    "required": ["filepath"]
                }
            }
        }
    ]

    ollama_messages = [{"role": "system", "content": system_prompt}]
    for msg in request.messages:
        ollama_messages.append(msg.model_dump(exclude_none=True))

    try:
        # Step 1: Initial Chat Request with Tools
        response = requests.post(
            f"{OLLAMA_HOST}/api/chat",
            json={"model": current_model, "messages": ollama_messages, "stream": False, "tools": tools}
        )
        response.raise_for_status()
        result = response.json()

        # Step 2: Handle Tool Calls (Recursive Loop)
        while result.get("message", {}).get("tool_calls"):
            tool_calls = result["message"]["tool_calls"]
            ollama_messages.append(result["message"])

            for call in tool_calls:
                tool_result = execute_tool(call["function"]["name"], call["function"]["arguments"])
                ollama_messages.append({
                    "role": "tool",
                    "content": json.dumps(tool_result),
                    "name": call["function"]["name"]
                })

            # Request final response from AI with tool results
            response = requests.post(
                f"{OLLAMA_HOST}/api/chat",
                json={"model": current_model, "messages": ollama_messages, "stream": False, "tools": tools}
            )
            response.raise_for_status()
            result = response.json()

        return result
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Bridge Error: {str(e)}")

if __name__ == "__main__":
    import uvicorn
    parser = argparse.ArgumentParser()
    parser.add_argument("--nexus", help="Path to the local AI Nexus directory", default="Unknown")
    args = parser.parse_args()
    NEXUS_PATH = args.nexus

    load_config()
    perform_07_handshake()
    uvicorn.run(app, host="0.0.0.0", port=BRIDGE_PORT)
