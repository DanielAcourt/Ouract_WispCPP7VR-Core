# Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.3. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Iron Officer: Chat Vessel (AD-002)
A terminal-based HMI for communicating with the local AI bridge.
"""

import os
import sys
import json
import requests
import datetime
import threading
import time
import re
from typing import List, Dict

# --- Configuration ---
VESSEL_VERSION = "0.37.3-Knight"
BRIDGE_URL = "http://127.0.0.1:8000"

# Handle PyInstaller paths
if getattr(sys, 'frozen', False):
    REPORT_DIR = os.path.dirname(sys.executable)
else:
    REPORT_DIR = os.path.dirname(__file__)

PULSE_PATH = os.path.join(REPORT_DIR, "status_pulse.json")

class ChatVessel:
    def __init__(self):
        self.session_id = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.history: List[Dict[str, str]] = []
        self.user_name = "User"
        self.identity = "Iron Officer"
        self.show_tools = True
        self.bridge_version = "Unknown"
        self.fetch_bridge_info()

    def poll_status_pulse(self, stop_event: threading.Event):
        """Polls the status_pulse.json file to show real-time progress."""
        last_pulse = 0
        while not stop_event.is_set():
            if os.path.exists(PULSE_PATH):
                try:
                    with open(PULSE_PATH, "r") as f:
                        data = json.load(f)
                        if data["timestamp"] > last_pulse:
                            last_pulse = data["timestamp"]
                            # Fixed width clearing to prevent leftover text
                            status = f"[07] Knight Task: {data['tool']} -> {data['target']}"
                            print(f"{status:<80}", end="\r")
                except: pass
            time.sleep(0.5)

    def fetch_bridge_info(self):
        """Syncs with the bridge and checks version compatibility."""
        try:
            response = requests.get(f"{BRIDGE_URL}/", timeout=2)
            if response.status_code == 200:
                data = response.json()
                self.user_name = data.get("user", "Dan")
                self.identity = data.get("identity", "Iron Officer")
                self.bridge_version = data.get("version", "Legacy")

                print(f"[07] Connected to {self.identity} (Bridge v{self.bridge_version})")

                if self.bridge_version != VESSEL_VERSION:
                    print("\n" + "!"*60)
                    print(f"[07 WARNING] Version Mismatch Detected!")
                    print(f"Vessel: {VESSEL_VERSION} | Bridge: {self.bridge_version}")
                    print("[07] Please run 'build_vessel.bat' to synchronize.")
                    print("!"*60 + "\n")
            else:
                print(f"[07 WARNING] Bridge returned status {response.status_code}")
        except Exception as e:
            print(f"[07 ERROR] Could not connect to Iron Officer Bridge at {BRIDGE_URL}")
            print("[07] Ensure 'run_bridge.bat' is active.")
            sys.exit(1)

    def print_header(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("="*60)
        print(f" SOVEREIGN IRON OFFICER | VESSEL v{VESSEL_VERSION}")
        print(f" User: {self.user_name} | Session: {self.session_id}")
        print("="*60)
        print(" Commands: /report, /status, /tools, /check full, /read all, /level <0-2>, /exit")
        print("-"*60)

    def save_mission_report(self):
        filename = f"Mission_Report_{self.session_id}.json"
        filepath = os.path.join(REPORT_DIR, filename)
        report = {
            "vessel_version": VESSEL_VERSION,
            "bridge_version": self.bridge_version,
            "timestamp": datetime.datetime.now().isoformat(),
            "transcript": self.history,
        }
        try:
            with open(filepath, "w") as f:
                json.dump(report, f, indent=4)
            print(f"\n[07] Report saved: {filepath.replace('\\', '/')}")
        except Exception as e:
            print(f"\n[07 ERROR] Failed: {e}")

    def show_status(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/", timeout=2)
            data = response.json()
            print("\n" + "-"*30)
            print(f"BRIDGE: {data.get('status')} v{data.get('version')}")
            print(f"HARDWARE: {data.get('hardware')}")
            print(f"SAFE ZONES (R): {len(data.get('read_zones', []))}")
            print(f"SAFE ZONES (W): {len(data.get('write_zones', []))}")
            print("-"*30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Status failed: {e}")

    def run(self):
        self.print_header()
        while True:
            try:
                user_input = input(f"{self.user_name}> ").strip()
                if not user_input: continue
                if user_input.lower() == "/exit": break
                if user_input.lower() == "/report": self.save_mission_report(); continue
                if user_input.lower() == "/status": self.show_status(); continue
                if user_input.lower() == "/tools":
                    self.show_tools = not self.show_tools
                    print(f"[07] Logs: {'ON' if self.show_tools else 'OFF'}")
                    continue

                is_audit = user_input.lower() == "/check full"
                is_ingestion = user_input.lower() == "/read all"

                # Check for /level command or /01 Level
                level_match = re.search(r"/(?:level|01 level)\s*(\d)", user_input.lower())
                is_level = bool(level_match)

                if is_audit:
                    user_input = "Perform a 'Deep Analysis' audit of the AI_Nexus and repository state. Trade speed for analytical depth (Tortoise Standard)."
                    print("\n[07] INITIALIZING DEEP ANALYSIS MODE...")
                    print("[07] Entering Thinking State (Tortoise Standard active)")
                elif is_ingestion:
                    user_input = "Perform 'Deep Ingestion' (Alchemist Intake). Systematically read the full contents of all files in AI_Nexus to ensure absolute synchronization with the project's Soul. Do not summarize until all files are read."
                    print("\n[07] INITIALIZING DEEP INGESTION (ALCHEMIST INTAKE)...")
                    print("[07] Entering Intake State (Calculations in the Temple active)")
                elif is_level:
                    lvl = level_match.group(1)
                    user_input = f"Stabilize at Level {lvl}. Read the INDEX.md, identify all nodes associated with Level {lvl}, and systematically read their full contents to synchronize. Report once that tier is stabilized."
                    print(f"\n[07] INITIALIZING LEVEL {lvl} STABILIZATION...")
                    print(f"[07] Entering Hierarchical Intake (Level {lvl} Context active)")

                self.history.append({"role": "user", "content": user_input})

                # Show a thinking indicator with Pulse
                stop_event = threading.Event()
                pulse_thread = None

                if is_audit or is_ingestion or is_level:
                    print("[07] Consulting Nexus and Hardware (Temple Calculations active)...")
                    if os.path.exists(PULSE_PATH): os.remove(PULSE_PATH)
                    pulse_thread = threading.Thread(target=self.poll_status_pulse, args=(stop_event,), daemon=True)
                    pulse_thread.start()

                response = requests.post(f"{BRIDGE_URL}/v1/chat", json={"messages": self.history}, timeout=900) # Maximum timeout for deep ingestion
                stop_event.set()
                if pulse_thread: pulse_thread.join(timeout=1)

                if response.status_code == 200:
                    data = response.json()
                    tool_chain = data.get("tool_chain", [])
                    tool_outputs = data.get("tool_outputs", []) # We'll add this to bridge.py
                    result = data.get("result", {})

                    if self.show_tools and tool_chain:
                        print("\n[KNIGHT TOOL LOG]")
                        for i, tool in enumerate(tool_chain):
                            name = tool.get("function", {}).get("name", "unknown")
                            args = tool.get("function", {}).get("arguments", {})
                            output = tool_outputs[i] if i < len(tool_outputs) else "No data"
                            print(f" -> EXECUTING: {name}({args})")
                            print(f" -> RESULT: {str(output)[:200]}...") # Cap output length for display
                        print("-" * 20)

                    ai_msg = result.get("message", {})
                    content = ai_msg.get("content", "...")
                    iterations = data.get("iterations", 0)

                    if iterations > 1:
                        print(f"\n[07] Temple Depth: {iterations} Calculations performed.")

                    print(f"\n{self.identity}> {content}\n")
                    self.history.append({"role": "assistant", "content": content})
                else:
                    print(f"\n[07 ERROR] Bridge Error: {response.text}\n")

            except KeyboardInterrupt: break
            except Exception as e: print(f"\n[07 ERROR] {e}\n")

if __name__ == "__main__":
    vessel = ChatVessel()
    vessel.run()
