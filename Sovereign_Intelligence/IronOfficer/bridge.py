# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
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
import time
from typing import Dict, Any, List, Optional, Set
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
VERSION = "0.37.1-Knight"
BASE_DIR = os.path.dirname(__file__)
CONFIG_PATH = os.path.join(BASE_DIR, "config.json")
REPO_ROOT = os.path.abspath(os.path.join(BASE_DIR, "..", ".."))
REPO_NAME = os.path.basename(REPO_ROOT)
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
    return str(path).replace("\\", "/")

def resolve_secure_path(raw_path: str) -> str:
    """Hardened path resolution to strip absolute bloat and focus on REPO_ROOT."""
    path_str = to_forward_slash(str(raw_path))
    if REPO_NAME in path_str:
        path_str = path_str.split(REPO_NAME, 1)[-1]
    clean_path = path_str.lstrip("/").lstrip("\\")
    if ":" in clean_path:
        clean_path = clean_path.split(":", 1)[-1].lstrip("/").lstrip("\\")
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
        return {"error": f"Security Breach: '{directory}' is unauthorized."}
    try:
        files = os.listdir(target_dir)
        return {"files": files, "directory": to_forward_slash(os.path.relpath(target_dir, REPO_ROOT))}
    except Exception as e:
        return {"error": str(e)}

def tool_read_file(filepath: str):
    """Reads a file if authorized."""
    target_path = resolve_secure_path(filepath)
    if not is_path_authorized(target_path, "read"):
        return {"error": f"Security Breach: '{filepath}' is unauthorized."}
    try:
        with open(target_path, "r", encoding="utf-8", errors="ignore") as f:
            return {"content": f.read()}
    except Exception as e:
        return {"error": str(e)}

def tool_write_file(filepath: str, content: str):
    """Writes a file if authorized."""
    target_path = resolve_secure_path(filepath)
    if not is_path_authorized(target_path, "write"):
        return {"error": f"Security Breach: '{filepath}' is outside WRITE zones."}
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
        return {"error": f"Security Breach: '{filepath}' is outside WRITE zones."}
    try:
        if os.path.isfile(target_path):
            os.remove(target_path)
            return {"status": "success", "verified": not os.path.exists(target_path)}
        elif os.path.isdir(target_path):
            shutil.rmtree(target_path)
            return {"status": "success", "verified": not os.path.exists(target_path)}
        else:
            return {"error": "Target not found."}
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
            if ".git" in dirpath or "__pycache__" in dirpath: continue
            for f in filenames:
                if extension != "*" and not f.endswith(extension): continue
                full_path = os.path.join(dirpath, f)
                try:
                    with open(full_path, "r", encoding="utf-8", errors="ignore") as file:
                        for i, line in enumerate(file):
                            if regex.search(line):
                                results.append({"file": to_forward_slash(os.path.relpath(full_path, REPO_ROOT)), "line": i + 1, "content": line.strip()})
                except Exception: continue
        return {"matches": results[:100], "count": len(results)}
    except Exception as e:
        return {"error": str(e)}

def tool_map_directory(directory: str = ".", depth: Any = 2):
    """The Librarian: Provides a recursive map of the directory structure."""
    target_dir = resolve_secure_path(directory)
    if not is_path_authorized(target_dir, "read"):
        return {"error": f"Security Breach: '{directory}' is unauthorized."}
    try:
        depth_val = int(depth)
    except:
        depth_val = 2
    def get_tree(path, current_depth):
        if current_depth > depth_val: return "..."
        tree = {}
        try:
            items = os.listdir(path)
            items.sort()
            for item in items:
                if item == ".git" or item == "__pycache__": continue
                full_item = os.path.join(path, item)
                if os.path.isdir(full_item):
                    tree[item + "/"] = get_tree(full_item, current_depth + 1)
                else:
                    tree[item] = None
        except Exception: pass
        return tree
    return {"map": get_tree(target_dir, 0), "directory": to_forward_slash(os.path.relpath(target_dir, REPO_ROOT))}

def tool_get_system_telemetry(interval: int = 0, duration: int = 0):
    """The Engineer: Reports GPU temperature, usage, and system state."""
    if interval > 0 or duration > 0:
        time.sleep(min(1, duration/10))
    try:
        output = subprocess.check_output(["nvidia-smi", "--query-gpu=temperature.gpu,utilization.gpu,memory.used,memory.total", "--format=csv,noheader,nounits"], encoding='utf-8')
        temp, util, mem_used, mem_total = output.strip().split(", ")
        temp_val = int(temp)
        status = "NOMINAL"
        if temp_val > 80: status = "CRITICAL"
        elif temp_val > 70: status = "WARNING"
        return {"gpu_temperature": f"{temp}C", "gpu_utilization": f"{util}%", "vram_usage": f"{mem_used}/{mem_total}MB", "status": status, "vss": 1.0 - (max(0, temp_val - 50) / 50.0)}
    except Exception as e:
        return {"error": f"Engineer diagnostic failed: {str(e)}"}

def execute_tool(name: str, arguments: Dict[str, Any]) -> Dict[str, Any]:
    tools = {"list_files": tool_list_files, "read_file": tool_read_file, "write_file": tool_write_file, "delete_file": tool_delete_file, "search_files": tool_search_files, "map_directory": tool_map_directory, "get_system_telemetry": tool_get_system_telemetry}
    if name in tools: return tools[name](**arguments)
    return {"error": f"Tool '{name}' not found."}

# --- Core Logic ---

@app.get("/")
async def root():
    return {"status": "online", "version": VERSION, "identity": "Iron Officer", "hardware": HARDWARE_ID, "user": USER_NAME, "read_zones": READ_ZONES, "write_zones": WRITE_ZONES}

@app.get("/v1/ollama/status")
async def get_ollama_status():
    try:
        response = requests.get(f"{OLLAMA_HOST}/api/tags", timeout=5)
        response.raise_for_status()
        return response.json()
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Cannot reach Ollama: {str(e)}")

@app.post("/v1/safety/evaluate")
async def evaluate_safety(request: VSSRequest):
    current_model = get_best_available_model()
    prompt = f"[SYSTEM: Sovereign Iron Officer] Analyze PSTA telemetry: {json.dumps([t.model_dump() for t in request.telemetry])}. Context: {request.context}. Respond in JSON with vss, status, rationale, command."
    try:
        response = requests.post(f"{OLLAMA_HOST}/api/generate", json={"model": current_model, "prompt": prompt, "stream": False, "format": "json"})
        if response.status_code != 200: raise HTTPException(status_code=response.status_code, detail=f"Ollama Error: {response.text}")
        result = response.json()
        return {"analysis": json.loads(result['response']), "model_used": current_model}
    except Exception as e: raise HTTPException(status_code=500, detail=f"Internal Bridge Error: {str(e)}")

@app.post("/v1/chat")
async def chat(request: ChatRequest):
    current_model = get_best_available_model()
    system_prompt = f"""
    [SYSTEM: Sovereign AI Architectural Knight]
    You are the Iron Officer. You are an Architectural Knight: Precise, Loyal, and Accountable.
    You are communicating with your Lead, {USER_NAME}.

    CORE DIRECTIVES:
    - THE TORTOISE STANDARD: Prioritize analytical depth over speed. Calculate many times before answering.
    - DATA-FIRST: Never summarize "that you ran a tool." Show the ACTUAL results in your response.
    - PHYSICAL TRUTH: Use tools BEFORE making claims.
    - SYMMETRICAL GUARD: If you report Technical Status (T=) or Directory Contents, you MUST have executed the relevant tool in the same turn.
    - NO ROLEPLAY: Strictly forbidden from simulating results or "previous knowledge." If a tool fails, report the error.
    - ACCOUNTABILITY: After writing or deleting, you MUST verify the deed using a follow-up tool call.
    - PATHS: Always use relative paths from {REPO_ROOT} (e.g., 'AI_Nexus/Protocols/AGENTS.md').

    [DEEP ANALYSIS MODE (/check full)]:
    When a deep analysis or audit is requested:
    1.  Perform a multi-step investigation using Librarian (map_directory), Scout (search_files), and Engineer (get_system_telemetry).
    2.  Check for version consistency across AI_Nexus and local files.
    3.  Audit the 'Memories' and 'Learning Events' to ensure recent lessons are applied.
    4.  Deliver a comprehensive report that identifies anomalies or technical drift.

    [DEEP INGESTION MODE (/read all)]:
    When a 'Deep Ingestion' or 'Alchemist Intake' is requested:
    1.  FIRST: Use 'read_file' on 'AI_Nexus/INDEX.md' to identify the exact locations of all project nodes.
    2.  SECOND: Systematically use 'read_file' for every critical file identified in the Index.
    3.  STRICT PROHIBITION: Do not guess paths (e.g., 'AI_Nexus/AGENTS.md'). Always verify the path via the Index or Librarian (map_directory).
    4.  DO NOT SUMMARIZE until you have ingested the ACTUAL content of the files.
    5.  Establish an internal state of absolute synchronization with the 12-year project research (The Soul).
    6.  Report the completion with a focus on how the "Soul" is manifesting in the "Vessel" (codebase).

    07 PROTOCOL SALUTE (LINE-BY-LINE FORMAT):
    P: [Your current psychological status/confidence]
    S: [Social/Connection sync status]
    T: [Technical truth - report EXACT GPU Temp, Utilization, and VSS from Engineer results]
    A: [Administrative truth - report exactly what Librarian/Scout found in AI_Nexus]

    Salute trigger: "07"
    """

    tools = [
        {"type": "function", "function": {"name": "list_files", "description": "List files.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}}}}},
        {"type": "function", "function": {"name": "read_file", "description": "Read file.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "write_file", "description": "Write file.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}, "content": {"type": "string"}}, "required": ["filepath", "content"]}}},
        {"type": "function", "function": {"name": "delete_file", "description": "Delete.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "search_files", "description": "Search.", "parameters": {"type": "object", "properties": {"pattern": {"type": "string"}, "directory": {"type": "string"}, "extension": {"type": "string"}}, "required": ["pattern"]}}},
        {"type": "function", "function": {"name": "map_directory", "description": "Map.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}, "depth": {"type": "integer"}}}}},
        {"type": "function", "function": {"name": "get_system_telemetry", "description": "GPU status.", "parameters": {"type": "object", "properties": {"interval": {"type": "integer"}, "duration": {"type": "integer"}}}}}
    ]

    ollama_messages = [{"role": "system", "content": system_prompt}]
    for msg in request.messages: ollama_messages.append(msg.model_dump(exclude_none=True))

    try:
        return await process_chat_request(current_model, ollama_messages, tools, retry_count=0)
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Bridge Error: {str(e)}")

def write_status_pulse(tool_name: str, arguments: Dict[str, Any]):
    """Writes a real-time status pulse for the HMI to display during long tasks."""
    pulse_path = os.path.join(BASE_DIR, "Environment", "status_pulse.json")
    try:
        pulse = {
            "timestamp": time.time(),
            "tool": tool_name,
            "target": arguments.get("filepath") or arguments.get("directory") or arguments.get("pattern") or "Calculating..."
        }
        with open(pulse_path, "w") as f:
            json.dump(pulse, f)
    except: pass

async def process_chat_request(model: str, messages: List[Dict], tools: List[Dict], retry_count: int = 0) -> Dict:
    # --- Tortoise Configuration: Increase context window for deep ingestion ---
    options = {"num_ctx": 32768, "temperature": 0.2}

    tool_chain = []
    tool_outputs = []
    tools_executed = set()
    iteration = 0
    max_iterations = 50 # Hard cap to prevent runaway costs/recursion

    while iteration < max_iterations:
        iteration += 1
        print(f"[07 DEBUG] Temple Calculation Iteration: {iteration}")

        response = requests.post(f"{OLLAMA_HOST}/api/chat", json={"model": model, "messages": messages, "stream": False, "tools": tools, "options": options})
        response.raise_for_status()
        result = response.json()
        ai_msg = result.get("message", {})

        if ai_msg.get("tool_calls"):
            messages.append(ai_msg)
            for call in ai_msg["tool_calls"]:
                name = call["function"]["name"]
                args = call["function"]["arguments"]
                write_status_pulse(name, args)
                tool_chain.append(call)
                tools_executed.add(name)
                tool_result = execute_tool(name, args)
                tool_outputs.append(tool_result)
                messages.append({"role": "tool", "content": json.dumps(tool_result), "name": name})
            continue # Run next iteration to process tool results

        # --- Anti-Ghosting Protocol ---
        if not ai_msg.get("content"):
            messages.append({"role": "system", "content": "[ANTI-GHOSTING] Tool execution complete. Deliver your final report based on the ingested data now."})
            continue # Prompt for report and try again

        # --- Symmetrical Guard (v2.2) ---
        ai_content = ai_msg.get("content", "").upper()
        violations = []
        if ("T=" in ai_content or "TEMPERATURE" in ai_content or "TECHNICAL STATUS" in ai_content) and "get_system_telemetry" not in tools_executed:
             violations.append("Reported Technical Status without Engineer tool.")
        if ("MAP" in ai_content or "DIRECTORY" in ai_content or "FILES" in ai_content) and ("map_directory" not in tools_executed and "list_files" not in tools_executed and "search_files" not in tools_executed):
             if "SECURITY BREACH" not in ai_content and "ERROR" not in ai_content and "VIOLATION" not in ai_content:
                violations.append("Described environment state without Librarian/Scout tools.")

        if violations and iteration < 5: # Limit reprimands
            reprimand = f"[07 SECURITY VIOLATION] Hallucination detected: {'; '.join(violations)}. You must execute the relevant tools and report ACTUAL DATA only. Physical Truth is required."
            messages.append({"role": "system", "content": reprimand})
            continue # Try again with reprimand

        # If we reach here, we have a valid content response and no more tool calls
        return {"result": result, "tool_chain": tool_chain, "tool_outputs": tool_outputs, "iterations": iteration}

    raise HTTPException(status_code=500, detail="Maximum iteration depth exceeded in Temple Calculations.")

def get_installed_models() -> List[str]:
    try:
        response = requests.get(f"{OLLAMA_HOST}/api/tags", timeout=5)
        if response.status_code == 200: return [m['name'] for m in response.json().get('models', [])]
        return []
    except: return []

def get_best_available_model() -> str:
    models = get_installed_models()
    if TARGET_MODEL in models: return TARGET_MODEL
    return models[0] if models else TARGET_MODEL

def get_gpu_info() -> str:
    try: return subprocess.check_output(["nvidia-smi", "--query-gpu=gpu_name", "--format=csv,noheader"], encoding='utf-8').strip()
    except: return "GPU Detection Failed"

if __name__ == "__main__":
    import uvicorn
    parser = argparse.ArgumentParser()
    parser.add_argument("--nexus", help="Path to local AI Nexus", default="Unknown")
    args = parser.parse_args()
    NEXUS_PATH = args.nexus
    load_config()
    gpu_info = get_gpu_info()
    HARDWARE_ID = f"GTX 5090 ({gpu_info})" if "5090" in gpu_info else gpu_info
    DETECTED_MODELS = get_installed_models()
    print("\n" + "="*50 + f"\n[07] Iron Officer v{VERSION}\n[07] Hardware: {HARDWARE_ID}\n" + "="*50 + "\n")
    uvicorn.run(app, host="0.0.0.0", port=BRIDGE_PORT)
