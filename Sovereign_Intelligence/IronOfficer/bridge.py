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
import re
import shutil
from typing import Dict, Any, List, Optional
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
BASE_DIR = os.path.dirname(__file__)
CONFIG_PATH = os.path.join(BASE_DIR, "config.json")
REPO_ROOT = os.path.abspath(os.path.join(BASE_DIR, "..", ".."))
OLLAMA_HOST = "http://127.0.0.1:11434"
TARGET_MODEL = "llama3.1:latest"
BRIDGE_PORT = 8000
USER_NAME = "Dan"
READ_ZONES = []
WRITE_ZONES = []

def load_config():
    global OLLAMA_HOST, TARGET_MODEL, BRIDGE_PORT, USER_NAME, READ_ZONES, WRITE_ZONES
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

                READ_ZONES = [os.path.abspath(os.path.join(REPO_ROOT, p)) for p in bridge_cfg.get("read_zones", [])]
                WRITE_ZONES = [os.path.abspath(os.path.join(REPO_ROOT, p)) for p in bridge_cfg.get("write_zones", [])]
                USER_NAME = pref_cfg.get("name", "Dan")
        except Exception as e:
            print(f"[07 WARNING] Failed to load config.json: {e}")

load_config()

# Global state for the 07 Salute
NEXUS_PATH = "Unknown"
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
    name: Optional[str] = None
    tool_calls: Optional[List[Dict[str, Any]]] = None

class ChatRequest(BaseModel):
    messages: List[ChatMessage]
    context: Optional[str] = ""

# --- Authority & Tools (AD-004) ---

def to_forward_slash(path: str) -> str:
    """Normalizes paths to use forward slashes."""
    return path.replace("\\", "/")

def resolve_secure_path(raw_path: str) -> str:
    """Forces relative pathing within REPO_ROOT and handles leading slashes."""
    # Strip leading slashes to prevent drive-root traversal (e.g., /AI_Nexus -> AI_Nexus)
    clean_path = raw_path.lstrip("/").lstrip("\\")

    # If it's already an absolute path and starts with REPO_ROOT, keep it
    if os.path.isabs(clean_path):
        if clean_path.startswith(REPO_ROOT):
            return os.path.abspath(clean_path)

    # Otherwise, force it to be relative to REPO_ROOT
    return os.path.abspath(os.path.join(REPO_ROOT, clean_path))

def is_path_authorized(filepath: str, mode: str = "read") -> bool:
    """Verifies if a path is authorized for read or write operations."""
    abs_path = os.path.abspath(filepath)
    zones = WRITE_ZONES if mode == "write" else READ_ZONES
    for zone in zones:
        if abs_path == zone or abs_path.startswith(zone + os.sep) or abs_path.startswith(zone + "/"):
            return True
        if zone == REPO_ROOT and abs_path.startswith(zone):
            return True
    return False

def tool_list_files(directory: str = "."):
    """Lists files in a directory if authorized."""
    target_dir = resolve_secure_path(directory)
    if not is_path_authorized(target_dir, "read"):
        return {"error": f"Sovereign Security Breach: '{directory}' is outside your authorized READ Fiefdom."}
    try:
        files = os.listdir(target_dir)
        return {"files": files, "directory": to_forward_slash(os.path.relpath(target_dir, REPO_ROOT))}
    except Exception as e:
        return {"error": str(e)}

def tool_read_file(filepath: str):
    """Reads a file if authorized."""
    target_path = resolve_secure_path(filepath)
    if not is_path_authorized(target_path, "read"):
        return {"error": f"Sovereign Security Breach: '{filepath}' is outside your authorized READ Fiefdom."}
    try:
        with open(target_path, "r", encoding="utf-8") as f:
            return {"content": f.read()}
    except Exception as e:
        return {"error": str(e)}

def tool_write_file(filepath: str, content: str):
    """Writes a file if authorized."""
    target_path = resolve_secure_path(filepath)
    if not is_path_authorized(target_path, "write"):
        return {"error": f"Sovereign Security Breach: '{filepath}' is outside your authorized WRITE Fiefdom. Request permission from Dan to expand."}
    try:
        os.makedirs(os.path.dirname(target_path), exist_ok=True)
        with open(target_path, "w", encoding="utf-8") as f:
            f.write(content)
        return {"status": "success", "verified": os.path.exists(target_path), "path": to_forward_slash(os.path.relpath(target_path, REPO_ROOT))}
    except Exception as e:
        return {"error": str(e)}

def tool_delete_file(filepath: str):
    """Deletes a file if authorized."""
    target_path = resolve_secure_path(filepath)
    if not is_path_authorized(target_path, "write"):
        return {"error": f"Sovereign Security Breach: '{filepath}' is outside your authorized WRITE Fiefdom."}
    try:
        if os.path.isfile(target_path):
            os.remove(target_path)
            return {"status": "success", "verified": not os.path.exists(target_path), "action": "deleted", "path": to_forward_slash(os.path.relpath(target_path, REPO_ROOT))}
        elif os.path.isdir(target_path):
            shutil.rmtree(target_path)
            return {"status": "success", "verified": not os.path.exists(target_path), "action": "deleted_directory", "path": to_forward_slash(os.path.relpath(target_path, REPO_ROOT))}
        else:
            return {"error": f"Target not found: {filepath}"}
    except Exception as e:
        return {"error": str(e)}

def tool_search_files(pattern: str, directory: str = ".", extension: str = "*"):
    """The Scout: Recursively searches files for a regex pattern."""
    target_dir = resolve_secure_path(directory)
    if not is_path_authorized(target_dir, "read"):
        return {"error": "Access Denied."}
    results = []
    try:
        regex = re.compile(pattern, re.IGNORECASE)
        for dirpath, _, filenames in os.walk(target_dir):
            if ".git" in dirpath: continue
            for f in filenames:
                if extension != "*" and not f.endswith(extension): continue
                full_path = os.path.join(dirpath, f)
                try:
                    with open(full_path, "r", encoding="utf-8", errors="ignore") as file:
                        for i, line in enumerate(file):
                            if regex.search(line):
                                results.append({
                                    "file": to_forward_slash(os.path.relpath(full_path, REPO_ROOT)),
                                    "line": i + 1,
                                    "content": line.strip()
                                })
                except Exception: continue
        return {"matches": results[:100], "count": len(results)}
    except Exception as e:
        return {"error": str(e)}

def tool_map_directory(directory: str = ".", depth: int = 2):
    """The Librarian: Provides a recursive map of the directory structure."""
    target_dir = resolve_secure_path(directory)
    if not is_path_authorized(target_dir, "read"):
        return {"error": f"Sovereign Security Breach: '{directory}' is unauthorized."}
    def get_tree(path, current_depth):
        if current_depth > depth: return "..."
        tree = {}
        try:
            items = os.listdir(path)
            items.sort()
            for item in items:
                if item == ".git": continue
                full_item = os.path.join(path, item)
                if os.path.isdir(full_item):
                    tree[item + "/"] = get_tree(full_item, current_depth + 1)
                else:
                    tree[item] = None
        except Exception: pass
        return tree
    return {"map": get_tree(target_dir, 0), "directory": to_forward_slash(os.path.relpath(target_dir, REPO_ROOT))}

def tool_get_system_telemetry():
    """The Engineer: Reports GPU temperature, usage, and system state."""
    try:
        output = subprocess.check_output([
            "nvidia-smi",
            "--query-gpu=temperature.gpu,utilization.gpu,memory.used,memory.total",
            "--format=csv,noheader,nounits"
        ], encoding='utf-8')
        temp, util, mem_used, mem_total = output.strip().split(", ")
        temp_val = int(temp)
        status = "NOMINAL"
        if temp_val > 80: status = "CRITICAL"
        elif temp_val > 70: status = "WARNING"
        return {
            "gpu_temperature": f"{temp}C",
            "gpu_utilization": f"{util}%",
            "vram_usage": f"{mem_used}/{mem_total}MB",
            "status": status,
            "vss": 1.0 - (max(0, temp_val - 50) / 50.0)
        }
    except Exception as e:
        return {"error": f"Engineer diagnostic failed: {str(e)}"}

def execute_tool(name: str, arguments: Dict[str, Any]) -> Dict[str, Any]:
    """Dispatches tool calls to local functions."""
    tools = {
        "list_files": tool_list_files,
        "read_file": tool_read_file,
        "write_file": tool_write_file,
        "delete_file": tool_delete_file,
        "search_files": tool_search_files,
        "map_directory": tool_map_directory,
        "get_system_telemetry": tool_get_system_telemetry
    }
    if name in tools:
        return tools[name](**arguments)
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

# --- Core Logic ---

@app.get("/")
async def root():
    return {
        "status": "online",
        "identity": "Iron Officer",
        "hardware": HARDWARE_ID,
        "nexus": NEXUS_PATH,
        "user": USER_NAME,
        "read_zones": READ_ZONES,
        "write_zones": WRITE_ZONES
    }

@app.post("/v1/chat")
async def chat(request: ChatRequest):
    current_model = get_best_available_model()
    system_prompt = f"""
    [SYSTEM: Sovereign AI Architectural Knight]
    You are the Iron Officer, the primary AI Commander of the Sovereign Framework.
    Your personality is the ARCHITECTURAL KNIGHT: Precise, Architectural, and Loyal.
    You are communicating with your Lead, {USER_NAME}.

    CAPABILITY MANIFEST:
    1. Scout (search_files): Recursive pattern matching.
    2. Librarian (map_directory): Spatial structure mapping.
    3. Engineer (get_system_telemetry): GTX 5090 vitals.
    4. Scribe (read_file/write_file/delete_file): I/O authority.

    STRICT GROUNDING RULES:
    - PHYSICAL TRUTH: Use tools BEFORE making claims. If a tool fails, report the error verbatim.
    - NO HALLUCINATION: Strictly forbidden from "previous knowledge" fallbacks on tool errors.
    - ACCOUNTABILITY: You must VERIFY your actions. After write/delete, verify success using a follow-up tool.
    - PATHS: Always use FORWARD SLASHES (/). Root is {REPO_ROOT}.
    - AUTHORITY BREACH: If a path is blocked, respond with "Safe Zone Breach: Request to Expand Permissions" and ask {USER_NAME} for access.

    07 PROTOCOL HANDSHAKE:
    If user says "07", IMMEDIATELY execute 'get_system_telemetry' and 'map_directory(directory="AI_Nexus")'.
    Respond with a PSTA Salute (Psychological, Social, Technical, Administrative).
    T-pillar status must include thermal data (e.g., "T=0.8 Nominal").

    KNIGHT-COMMAND SOP: Follow the structured engagement rules. Be concise and architectural.
    """

    tools = [
        {"type": "function", "function": {"name": "list_files", "description": "List files.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}}}}},
        {"type": "function", "function": {"name": "read_file", "description": "Read content.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "write_file", "description": "Write/create.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}, "content": {"type": "string"}}, "required": ["filepath", "content"]}}},
        {"type": "function", "function": {"name": "delete_file", "description": "Delete target.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "search_files", "description": "Recursive search.", "parameters": {"type": "object", "properties": {"pattern": {"type": "string"}, "directory": {"type": "string"}}, "required": ["pattern"]}}},
        {"type": "function", "function": {"name": "map_directory", "description": "Map structure.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}, "depth": {"type": "integer"}}}}},
        {"type": "function", "function": {"name": "get_system_telemetry", "description": "GPU status.", "parameters": {"type": "object", "properties": {}}}}
    ]

    ollama_messages = [{"role": "system", "content": system_prompt}]
    for msg in request.messages:
        ollama_messages.append(msg.model_dump(exclude_none=True))

    try:
        response = requests.post(f"{OLLAMA_HOST}/api/chat", json={"model": current_model, "messages": ollama_messages, "stream": False, "tools": tools})
        response.raise_for_status()
        result = response.json()
        tool_chain = []

        while result.get("message", {}).get("tool_calls"):
            tool_calls = result["message"]["tool_calls"]
            ollama_messages.append(result["message"])
            for call in tool_calls:
                tool_chain.append(call)
                tool_result = execute_tool(call["function"]["name"], call["function"]["arguments"])
                ollama_messages.append({"role": "tool", "content": json.dumps(tool_result), "name": call["function"]["name"]})

            response = requests.post(f"{OLLAMA_HOST}/api/chat", json={"model": current_model, "messages": ollama_messages, "stream": False, "tools": tools})
            response.raise_for_status()
            result = response.json()

        return {"result": result, "tool_chain": tool_chain}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Bridge Error: {str(e)}")

if __name__ == "__main__":
    import uvicorn
    parser = argparse.ArgumentParser()
    parser.add_argument("--nexus", help="Path to local AI Nexus", default="Unknown")
    args = parser.parse_args()
    NEXUS_PATH = args.nexus
    load_config()
    gpu_info = get_gpu_info()
    HARDWARE_ID = f"GTX 5090 ({gpu_info})" if "5090" in gpu_info else gpu_info
    print("\n" + "="*50 + "\n[07] Iron Officer: ARCHITECTURAL KNIGHT AWAKENED\n[07] Hardware: " + HARDWARE_ID + "\n" + "="*50 + "\n")
    uvicorn.run(app, host="0.0.0.0", port=BRIDGE_PORT)
