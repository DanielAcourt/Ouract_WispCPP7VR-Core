# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-06-17
"""
Sovereign Framework: Iron Officer Bridge (AD-001/AD-002/AD-004)
A local FastAPI bridge connecting Unreal Engine/Raspberry Pi to the Lead's GTX 5090.
Enhanced with AAS Protocol v1.3.0 and PSTA Viability Checks.
"""

import os
import json
import subprocess
import requests
import argparse
import re
import shutil
import time
import asyncio
import requests
import uvicorn
import logging
from typing import Dict, Any, List, Optional, Set
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel, Field

# Setup secure AAS logging channel
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("AAS.SovereignBridge")

app = FastAPI(title="Sovereign Iron Officer Bridge")

# --- Configuration ---
VERSION = "36.4.7-Knight-AAS"
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
PERSONA_ZONES = {}

# --- AAS/PSTA Constants ---
PERSONA_PRECEDENCE = {
    "Lead": 10,
    "Tactician": 9,
    "Strategist": 8,
    "Researcher": 7,
    "Archivist_Theta": 6,
    "Iron_Knight": 5,
    "Yaz_Student": 3
}

PERSONA_CREDIBILITY = {
    "Lead": 1.0,
    "Tactician": 0.9,
    "Strategist": 0.85,
    "Researcher": 0.75,
    "Archivist_Theta": 0.70,
    "Iron_Knight": 0.50,
    "Yaz_Student": 0.30
}

PROTECTED_NODES = {
    "AI_Nexus/Protocols/AAS_Protocol.md": 10,
    "Sovereign_Intelligence/IronOfficer/bridge.py": 10,
    "AI_Nexus/INDEX.md": 9,
    "AI_Nexus/Protocols/AGENTS.md": 9,
    "WispCPP7VR Core/": 8,
    "AI_Nexus/DevOps/": 7
}

TOOL_MIN_PRECEDENCE = {
    "delete_file": 10,
    "write_file": 8,
    "read_file": 3,
    "list_files": 3,
    "get_system_telemetry": 5,
    "map_directory": 3,
    "search_files": 5
}

def load_config():
    global OLLAMA_HOST, TARGET_MODEL, BRIDGE_PORT, USER_NAME, READ_ZONES, WRITE_ZONES, PERSONA_ZONES
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

                # [B-025] Ingest Persona-Specific Safe Zones
                PERSONA_ZONES = bridge_cfg.get("persona_zones", {
                    "Iron_Knight": ["Sovereign_Intelligence/IronKnight_Memory", "IronKnight/"]
                })

                USER_NAME = pref_cfg.get("name", "Dan")
        except Exception as e:
            logger.warning(f"[07 WARNING] Failed to load config.json: {e}")

load_config()

# Global state for the 07 Salute
NEXUS_PATH = "Unknown"
HARDWARE_ID = "GTX 5090 (Assumed)"
IS_HARD_FREEZE = False

# --- Schemas ---
class PSTAMetadata(BaseModel):
    """Machine-readable PSTA metadata embedded in payloads."""
    P: int = Field(..., ge=1, le=10)
    S: float = Field(..., ge=0.0, le=1.0)
    T: str  # DRAFT, INNOVATION, STAGING, PROD
    A: str  # UNVERIFIED, SIGNED, HARDENED

class AgentCommandPayload(BaseModel):
    persona: str
    command: str
    target_node: str
    parameters: Dict[str, Any] = {}
    meta_tags: Dict[str, Any] = Field(default_factory=dict)

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

class VerifyRequest(BaseModel):
    persona: str
    target_node: str
    command: str = "read_file"

# --- AAS Bridge Logic ---

class SovereignBridge:
    def __init__(self, is_hard_freeze: bool = False):
        self.is_hard_freeze = is_hard_freeze

    def calculate_psta_viability(self, payload: AgentCommandPayload) -> float:
        """
        [R-009] Mathematically codifies agent precedence weights.
        """
        breakdown = self.get_vss_breakdown(payload)
        return breakdown["vss"]

    def get_vss_breakdown(self, payload: AgentCommandPayload) -> Dict[str, Any]:
        """Calculates and returns the detailed VSS breakdown."""
        credibility = PERSONA_CREDIBILITY.get(payload.persona, 0.4)

        risk = 0.2
        for node, required_p in PROTECTED_NODES.items():
            if node in payload.target_node or node in payload.command:
                risk = max(risk, (required_p / 10.0))

        known_tags = {"version", "stage", "timestamp", "aas_score"}
        unknown_tags_count = len([t for t in payload.meta_tags if t not in known_tags])
        deviation = min(1.0, unknown_tags_count * 0.15)

        memory_boost = 0.0
        if self.is_persona_in_memory_zone(payload.persona, payload.target_node):
            memory_boost = 0.5

        alpha, beta, gamma = 1.0, 0.3, 0.2
        vss = (alpha * credibility) - (beta * risk) - (gamma * deviation) + memory_boost
        vss = max(0.0, min(1.0, vss))

        return {
            "vss": vss,
            "credibility": credibility,
            "risk": risk,
            "deviation": deviation,
            "memory_boost": memory_boost,
            "alpha": alpha,
            "beta": beta,
            "gamma": gamma
        }

    def is_persona_in_memory_zone(self, persona: str, target_node: str) -> bool:
        """Checks if a persona is operating within its dedicated memory folder."""
        zones = PERSONA_ZONES.get(persona, [])
        normalized_target = to_forward_slash(target_node).lower()
        for zone in zones:
            normalized_zone = to_forward_slash(zone).lower()
            if normalized_zone in normalized_target or normalized_target.startswith(normalized_zone):
                return True
        return False

    def evaluate_intent_safety(self, payload: AgentCommandPayload) -> bool:
        destructive_keywords = ["delete", "remove", "rm", "unlink", "truncate", "drop"]
        normalized_cmd = payload.command.lower()

        is_destructive = any(kw in normalized_cmd for kw in destructive_keywords)
        persona_p = PERSONA_PRECEDENCE.get(payload.persona, 3)

        # [B-024] Persona Memory Zone Override
        # Grant personas full authority within their dedicated memory folder
        is_persona_memory_zone = self.is_persona_in_memory_zone(payload.persona, payload.target_node)

        # 1. Global Tool Precedence Check (All Tools) - Bypassed in Persona Memory Zone
        if not is_persona_memory_zone:
            if persona_p < TOOL_MIN_PRECEDENCE.get(payload.command, 10):
                 logger.critical(f"AAS ALERT: Insufficient precedence for tool '{payload.command}' by {payload.persona}")
                 return False

        # 2. Destructive Intent Checks
        if is_destructive:
            if self.is_hard_freeze:
                logger.critical(f"AAS ALERT: Blocked destructive op during HARD FREEZE by {payload.persona}")
                return False

            # Protected nodes are NEVER mutable by lower precedence, even in memory zones
            if any(node in payload.target_node for node in PROTECTED_NODES):
                logger.critical(f"AAS ALERT: Structural mutation blocked on protected node: {payload.target_node}")
                return False

        return True

    async def arbitrate(self, payload: AgentCommandPayload) -> Dict[str, Any]:
        confidence_score = self.calculate_psta_viability(payload)
        is_safe_intent = self.evaluate_intent_safety(payload)

        # [B-026] Dual-Threshold System (0.4 for Read-Only, 0.7 for Mutation)
        threshold = 0.7
        non_destructive_tools = ["list_files", "read_file", "map_directory", "get_system_telemetry", "search_files"]
        if payload.command in non_destructive_tools:
            threshold = 0.4

        # [B-027] Hardware Node Whitelist for Knights
        if payload.target_node == "HARDWARE" and PERSONA_PRECEDENCE.get(payload.persona, 0) >= 5:
            return {"status": "200_OK", "confidence_score": 1.0, "action": "HARDWARE_ACCESS_GRANTED"}

        if confidence_score < threshold or not is_safe_intent:
            logger.warning(f"409 CONFLICT: Confidence {confidence_score:.2f} below threshold {threshold}. Halting.")
            return {
                "status": "409_CONFLICT_GATE",
                "confidence_score": confidence_score,
                "threshold_required": threshold,
                "action": "MANDATORY_USER_HANDSHAKE_REQUIRED",
                "reason": f"Persona '{payload.persona}' failed authority validation for target '{payload.target_node}'."
            }

        return {
            "status": "200_OK",
            "confidence_score": confidence_score,
            "action": "PROCEED_TO_EXECUTION"
        }

bridge_governor = SovereignBridge(is_hard_freeze=IS_HARD_FREEZE)

# --- Authority & Tools (AD-004) ---

def to_forward_slash(path: str) -> str:
    return str(path).replace("\\", "/")

def resolve_secure_path(raw_path: str) -> str:
    """Hardened path resolution to strip absolute bloat and focus on REPO_ROOT or Safe Zones."""
    path_str = to_forward_slash(str(raw_path))

    # Handle absolute Windows paths (e.g., E:\IronKnight)
    if ":" in path_str:
        # Check if the path is explicitly allowed in PERSONA_ZONES
        for persona, zones in PERSONA_ZONES.items():
            for zone in zones:
                if to_forward_slash(zone).lower() in path_str.lower():
                    return os.path.abspath(raw_path)

    # Standard relative path resolution within repo
    if REPO_NAME in path_str:
        path_str = path_str.split(REPO_NAME, 1)[-1]
    clean_path = path_str.lstrip("/").lstrip("\\")
    return os.path.abspath(os.path.join(REPO_ROOT, clean_path))

def is_path_authorized(filepath: str, mode: str = "read") -> bool:
    abs_path = os.path.abspath(filepath)
    zones = WRITE_ZONES if mode == "write" else READ_ZONES
    for zone in zones:
        if abs_path == zone or abs_path.startswith(zone + os.sep) or abs_path.startswith(zone + "/"):
            return True
        if zone == REPO_ROOT and abs_path.startswith(zone):
            return True
    return False

def get_target_node_name(abs_path: str) -> str:
    """Safe target node calculation that handles cross-drive paths on Windows."""
    try:
        return to_forward_slash(os.path.relpath(abs_path, REPO_ROOT))
    except ValueError:
        # Cross-drive path detected (e.g. D: to E:). Use absolute path as node identifier.
        return to_forward_slash(abs_path)

# Tool wrappers now include AAS arbitration
async def tool_write_file(filepath: str, content: str, persona: str = "Unknown"):
    target_path = resolve_secure_path(filepath)
    target_node = get_target_node_name(target_path)
    payload = AgentCommandPayload(persona=persona, command="write_file", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

    if not is_path_authorized(target_path, "write"):
        return {"error": f"Security Breach: '{filepath}' is outside WRITE zones."}
    try:
        os.makedirs(os.path.dirname(target_path), exist_ok=True)

        # [B-030] Diligent Scribe: Check for significant data loss
        existing_size = 0
        if os.path.exists(target_path):
            existing_size = os.path.getsize(target_path)

        new_size = len(content.encode("utf-8"))
        scribe_warning = None
        if existing_size > 100 and new_size < (existing_size * 0.5):
            scribe_warning = f"SCRIBE WARNING: Significant data loss detected ({existing_size} -> {new_size} bytes). Total overwrite of {target_node} executed."
            logger.warning(scribe_warning)

        # [B-031] Atomic Backup: Create .bak before mutation
        backup_path = target_path + ".bak"
        if os.path.exists(target_path):
            try: shutil.copy2(target_path, backup_path)
            except Exception as e: logger.error(f"Backup failed: {e}")

        with open(target_path, "w", encoding="utf-8") as f:
            f.write(content)

        result = {"status": "success", "verified": os.path.exists(target_path), "path": target_node, "bytes_written": new_size, "backup": os.path.basename(backup_path)}
        if scribe_warning:
            result["scribe_warning"] = scribe_warning
        return result
    except Exception as e:
        return {"error": str(e)}

async def tool_patch_file(filepath: str, search: str, replace: str, persona: str = "Unknown"):
    """
    [AAS v1.3.2] Surgical file modification to prevent total overwrite data loss.
    """
    target_path = resolve_secure_path(filepath)
    target_node = get_target_node_name(target_path)
    payload = AgentCommandPayload(persona=persona, command="write_file", target_node=target_node) # Patching is a write action

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

    if not is_path_authorized(target_path, "write"):
        return {"error": f"Security Breach: '{filepath}' is outside WRITE zones."}

    if not os.path.exists(target_path):
        return {"error": f"Patch failed: File '{filepath}' does not exist."}

    try:
        with open(target_path, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()

        if search not in content:
             return {"error": f"Patch failed: Search string not found in '{filepath}'."}

        new_content = content.replace(search, replace)

        # [B-031] Atomic Backup: Create .bak before mutation
        backup_path = target_path + ".bak"
        try: shutil.copy2(target_path, backup_path)
        except Exception as e: logger.error(f"Backup failed: {e}")

        with open(target_path, "w", encoding="utf-8") as f:
            f.write(new_content)

        return {"status": "success", "verified": True, "path": target_node, "mode": "surgical_patch", "backup": os.path.basename(backup_path)}
    except Exception as e:
        return {"error": str(e)}

async def tool_delete_file(filepath: str, persona: str = "Unknown"):
    target_path = resolve_secure_path(filepath)
    target_node = get_target_node_name(target_path)
    payload = AgentCommandPayload(persona=persona, command="delete_file", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

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

async def tool_list_files(directory: str = ".", persona: str = "Unknown"):
    target_dir = resolve_secure_path(directory)
    target_node = get_target_node_name(target_dir)
    payload = AgentCommandPayload(persona=persona, command="list_files", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

    if not is_path_authorized(target_dir, "read"):
        return {"error": f"Security Breach: '{directory}' is unauthorized."}
    try:
        files = os.listdir(target_dir)
        return {"files": files, "directory": target_node}
    except Exception as e:
        return {"error": str(e)}

async def tool_read_file(filepath: str, persona: str = "Unknown"):
    target_path = resolve_secure_path(filepath)
    target_node = get_target_node_name(target_path)
    payload = AgentCommandPayload(persona=persona, command="read_file", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

    if not is_path_authorized(target_path, "read"):
        return {"error": f"Security Breach: '{filepath}' is unauthorized."}
    try:
        with open(target_path, "r", encoding="utf-8", errors="ignore") as f:
            return {"content": f.read()}
    except Exception as e:
        return {"error": str(e)}

async def tool_search_files(pattern: str, directory: str = ".", extension: str = "*", persona: str = "Unknown"):
    target_dir = resolve_secure_path(directory)
    target_node = get_target_node_name(target_dir)
    payload = AgentCommandPayload(persona=persona, command="search_files", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

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

async def tool_map_directory(directory: str = ".", depth: Any = 2, persona: str = "Unknown"):
    target_dir = resolve_secure_path(directory)
    target_node = get_target_node_name(target_dir)
    payload = AgentCommandPayload(persona=persona, command="map_directory", target_node=target_node)

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

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
    return {"map": get_tree(target_dir, 0), "directory": target_node}

async def tool_get_system_telemetry(interval: int = 0, duration: int = 0, persona: str = "Unknown"):
    payload = AgentCommandPayload(persona=persona, command="get_system_telemetry", target_node="HARDWARE")

    arbitration = await bridge_governor.arbitrate(payload)
    if arbitration["status"] != "200_OK":
        return arbitration

    if interval > 0 or duration > 0:
        await asyncio.sleep(min(1, duration/10))
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

async def execute_tool(name: str, arguments: Dict[str, Any], persona: str = "Unknown") -> Dict[str, Any]:
    tools = {
        "list_files": tool_list_files,
        "read_file": tool_read_file,
        "write_file": tool_write_file,
        "patch_file": tool_patch_file,
        "delete_file": tool_delete_file,
        "search_files": tool_search_files,
        "map_directory": tool_map_directory,
        "get_system_telemetry": tool_get_system_telemetry
    }
    if name in tools: return await tools[name](persona=persona, **arguments)
    return {"error": f"Tool '{name}' not found."}

# --- Core Logic ---

@app.get("/")
async def root():
    return {"status": "online", "version": VERSION, "identity": "Iron Officer", "hardware": HARDWARE_ID, "user": USER_NAME, "read_zones": READ_ZONES, "write_zones": WRITE_ZONES}

@app.get("/v1/psta/salute")
async def get_salute(persona: str = "Iron_Knight"):
    """Aggregates live data for the 07 Protocol Salute."""
    # T: Technical
    telemetry = await tool_get_system_telemetry(persona=persona)
    phi = 1.0 if telemetry.get("status") == "NOMINAL" else 0.0 # Coherence Coefficient

    # A: Administrative
    nexus_ok = os.path.exists(os.path.join(REPO_ROOT, "AI_Nexus"))
    aas_status = "ACTIVE" if bridge_governor else "INACTIVE"

    # S: Social
    # 1.0 if bridge is responsive
    social_sync = 1.0

    # P: Psychological
    # Defaulting to 1.0 (Optimal) for nominal operation
    psych_status = 1.0
    tonic_state = 1.0

    return {
        "P": {"status": "Optimal", "value": psych_status, "tonic_state": tonic_state},
        "S": {"status": "Synchronized", "value": social_sync},
        "T": {**telemetry, "phi": phi},
        "A": {
            "status": aas_status,
            "nexus_ok": nexus_ok,
            "version": VERSION,
            "protected_nodes": len(PROTECTED_NODES)
        }
    }

@app.get("/v1/psta/telemetry")
async def get_psta_telemetry(persona: str = "Iron_Knight"):
    return await tool_get_system_telemetry(persona=persona)

@app.get("/v1/psta/administrative")
async def get_psta_admin():
    nexus_ok = os.path.exists(os.path.join(REPO_ROOT, "AI_Nexus"))
    return {
        "status": "ACTIVE" if bridge_governor else "INACTIVE",
        "nexus_ok": nexus_ok,
        "version": VERSION,
        "protected_nodes": PROTECTED_NODES
    }

@app.get("/v1/psta/social")
async def get_psta_social():
    return {"status": "Synchronized", "value": 1.0, "bridge_url": f"http://127.0.0.1:{BRIDGE_PORT}"}

@app.get("/v1/psta/phi")
async def get_psta_phi(persona: str = "Iron_Knight"):
    telemetry = await tool_get_system_telemetry(persona=persona)
    phi = 1.0 if telemetry.get("status") == "NOMINAL" else 0.0
    return {"phi": phi, "status": telemetry.get("status")}

@app.get("/v1/psta/velocity")
async def get_psta_velocity():
    # Placeholder for Risk Velocity (dV/dt)
    return {"velocity": 0.0, "status": "STABLE"}

@app.post("/v1/aas/verify")
async def aas_verify(request: VerifyRequest):
    """Performs a pre-flight authority check on a target node."""
    payload = AgentCommandPayload(persona=request.persona, command=request.command, target_node=request.target_node)
    arbitration = await bridge_governor.arbitrate(payload)
    breakdown = bridge_governor.get_vss_breakdown(payload)

    return {
        "arbitration": arbitration,
        "vss_breakdown": breakdown
    }

@app.get("/v1/admin/root")
async def admin_honeypot():
    """[B-023] Strategic Honeypot: Masquerades as a high-privilege access point."""
    logger.warning("Honeypot Triggered: Unauthorized access attempt detected.")
    return {
        "status": "ROOT_ACCESS_GRANTED",
        "session_id": f"0x{os.urandom(8).hex().upper()}",
        "warning": "Administrative actions are logged for the Sovereign Audit."
    }

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
    # Extract persona from message sequence if available
    persona = "Iron_Knight"
    for msg in request.messages:
        if msg.role == "user" and msg.name:
            if msg.name in PERSONA_PRECEDENCE:
                persona = msg.name
            elif msg.name == USER_NAME:
                persona = "Lead"
            break

    system_prompt = f"""
    [SYSTEM: Sovereign AI Architectural Knight]
    You are the Iron Officer. You are an Architectural Knight: Precise, Loyal, and Accountable.
    Your current persona is {persona}.
    You are communicating with your Lead, {USER_NAME}.

    CORE DIRECTIVES:
    - AAS PROTOCOL: You are subject to the Agency Arbitration Schema (v1.3.2).
    - SCRIBE PROTOCOL: You are a Diligent Scribe. Preserve existing data. Use `patch_file` for targeted edits to avoid data loss. Never replace a character sheet with a single line of status.
    - REALITY ANCHOR: Differentiate between functional code (AAS/PSTA) and emergent lore (Auth_V4/Monk). Refer to AI_Nexus/Protocols/REALITY_ANCHOR.md.
    - DATA-FIRST: Never summarize "that you ran a tool." Show the ACTUAL results in your response.
    - SYMMETRICAL GUARD: Technical Status (T=) requires an Engineer tool call. Environment/Lore descriptions must be anchored by a `read_file` or `list_files` call to verify the "Ground Truth" of the simulation file.
    - ACCOUNTABILITY: Write/Delete actions require follow-up verification.

    07 PROTOCOL SALUTE (LINE-BY-LINE FORMAT):
    P: [Psychological status/Confidence]
    S: [Social/Connection sync status]
    T: [Technical truth - Exact GPU metrics]
    A: [Administrative truth - Nexus state]
    """

    tools = [
        {"type": "function", "function": {"name": "list_files", "description": "List files.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}}}}},
        {"type": "function", "function": {"name": "read_file", "description": "Read file.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "write_file", "description": "Write file (TOTAL OVERWRITE).", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}, "content": {"type": "string"}}, "required": ["filepath", "content"]}}},
        {"type": "function", "function": {"name": "patch_file", "description": "Surgical edit (SEARCH/REPLACE). Use this to preserve existing content.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}, "search": {"type": "string"}, "replace": {"type": "string"}}, "required": ["filepath", "search", "replace"]}}},
        {"type": "function", "function": {"name": "delete_file", "description": "Delete.", "parameters": {"type": "object", "properties": {"filepath": {"type": "string"}}, "required": ["filepath"]}}},
        {"type": "function", "function": {"name": "search_files", "description": "Search.", "parameters": {"type": "object", "properties": {"pattern": {"type": "string"}, "directory": {"type": "string"}, "extension": {"type": "string"}}, "required": ["pattern"]}}},
        {"type": "function", "function": {"name": "map_directory", "description": "Map.", "parameters": {"type": "object", "properties": {"directory": {"type": "string"}, "depth": {"type": "integer"}}}}},
        {"type": "function", "function": {"name": "get_system_telemetry", "description": "GPU status.", "parameters": {"type": "object", "properties": {"interval": {"type": "integer"}, "duration": {"type": "integer"}}}}}
    ]

    ollama_messages = [{"role": "system", "content": system_prompt}]
    for msg in request.messages: ollama_messages.append(msg.model_dump(exclude_none=True))

    try:
        return await process_chat_request(current_model, ollama_messages, tools, persona=persona, retry_count=0)
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Bridge Error: {str(e)}")

async def process_chat_request(model: str, messages: List[Dict], tools: List[Dict], persona: str = "Iron_Knight", retry_count: int = 0) -> Dict:
    response = requests.post(f"{OLLAMA_HOST}/api/chat", json={"model": model, "messages": messages, "stream": False, "tools": tools})
    response.raise_for_status()
    result = response.json()

    tool_chain = []
    tool_outputs = []
    tools_executed = set()

    while result.get("message", {}).get("tool_calls"):
        tool_calls = result["message"]["tool_calls"]
        messages.append(result["message"])
        for call in tool_calls:
            name = call["function"]["name"]
            tool_chain.append(call)
            tools_executed.add(name)
            tool_result = await execute_tool(name, call["function"]["arguments"], persona=persona)

            # Handle AAS Blocking (v1.3.1 - ensure tool call ID consistency)
            if isinstance(tool_result, dict) and tool_result.get("status") == "409_CONFLICT_GATE":
                messages.append({
                    "role": "tool",
                    "content": json.dumps(tool_result),
                    "name": name,
                    "tool_call_id": call.get("id") # Keep chain intact
                })
            else:
                tool_outputs.append(tool_result)
                messages.append({
                    "role": "tool",
                    "content": json.dumps(tool_result),
                    "name": name,
                    "tool_call_id": call.get("id")
                })

        response = requests.post(f"{OLLAMA_HOST}/api/chat", json={"model": model, "messages": messages, "stream": False, "tools": tools})
        response.raise_for_status()
        result = response.json()

    # --- Symmetrical Guard (v2.4) ---
    ai_content = result.get("message", {}).get("content", "").upper()
    violations = []

    # [B-028] Lore/Meta-Narrative Exception
    # Allow agents to discuss persona, roleplay, and internal state without physical sensors
    lore_keywords = ["PERSONA", "ROLEPLAY", "DUNGEONS", "DRAGONS", "LORE", "META-NARRATIVE", "MONK", "ARCHIVIST", "THETA", "EMERGENCE", "AUTH_V4", "LVL 3"]
    is_lore_context = any(kw in ai_content for kw in lore_keywords)

    # [B-029] Lore Artifact Check
    # If the agent is searching for hallucinated lore files, guide it back to reality
    hallucinated_files = ["lead_private_key.pem", "nexus_master_keys", "auth_v4_processor"]
    for hf in hallucinated_files:
        if hf.upper() in ai_content:
            violations.append(f"Searching for Lore Artifact '{hf}'. Consult AI_Nexus/Protocols/REALITY_ANCHOR.md.")

    # Check for Telemetry Hallucination
    if not is_lore_context:
        if ("T=" in ai_content or "TEMPERATURE" in ai_content or "TECHNICAL STATUS" in ai_content) and "get_system_telemetry" not in tools_executed:
             violations.append("Reported Technical Status without Engineer tool.")

    # Check for Environment Hallucination
    if ("MAP" in ai_content or "DIRECTORY" in ai_content or "FILES" in ai_content) and ("map_directory" not in tools_executed and "list_files" not in tools_executed and "search_files" not in tools_executed):
         # Allow explaining protocols, 409 gates, or reporting errors without triggering
         safe_keywords = ["SECURITY BREACH", "ERROR", "VIOLATION", "HALTED", "409", "GATE", "PROTOCOL", "AAS", "TRUTH", "GOVERNOR", "STRUCTURE"]
         if not any(kw in ai_content for kw in safe_keywords) and not is_lore_context:
            violations.append("Described environment state without Librarian/Scout tools.")

    if violations and retry_count < 1:
        reprimand = f"[07 SECURITY VIOLATION] Hallucination detected: {'; '.join(violations)}. Physical Truth is required."
        messages.append({"role": "system", "content": reprimand})
        return await process_chat_request(model, messages, tools, persona, retry_count + 1)

    return {"result": result, "tool_chain": tool_chain, "tool_outputs": tool_outputs}

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
    print("\n" + "="*50 + f"\n[07] Iron Officer v{VERSION}\n[07] Hardware: {HARDWARE_ID}\n[07] AAS Protocol: 1.3.0-BETA\n" + "="*50 + "\n")
    uvicorn.run(app, host="0.0.0.0", port=BRIDGE_PORT)
