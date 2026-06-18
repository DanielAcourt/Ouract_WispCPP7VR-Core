# Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
"""
Iron Officer: Chat Vessel (AD-002)
A terminal-based HMI for communicating with the local AI bridge.
"""

import os
import sys
import json
import requests
import datetime
from typing import List, Dict

# --- Configuration ---
VESSEL_VERSION = "0.36.3.1-Knight"
BRIDGE_URL = "http://127.0.0.1:8000"

# Handle PyInstaller paths
if getattr(sys, 'frozen', False):
    REPORT_DIR = os.path.dirname(sys.executable)
else:
    REPORT_DIR = os.path.dirname(__file__)

class ChatVessel:
    def __init__(self):
        self.session_id = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.history: List[Dict[str, str]] = []
        self.user_name = "User"
        self.identity = "Iron Officer"
        self.show_tools = True
        self.bridge_version = "Unknown"
        self.fetch_bridge_info()

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
        print(" Commands: /07, /p, /t, /s, /a, /verify, /vss, /phi, /velocity, /backups, /handshake, /report, /status, /tools, /exit")
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

    def run_salute(self):
        print(f"\n{self.user_name}> /07")
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/salute?persona={self.identity.replace(' ', '_')}", timeout=10)
            if response.status_code == 200:
                data = response.json()
                print(f"\n{self.identity}> **07 Protocol Salute Initiated.**")
                print(f"P: **[Psychological Status]:** {data['P']['status']} operational capacity maintained. Assessment confirms high confidence in current objectives. Tonic State={data['P'].get('tonic_state', '1.0')}")
                print(f"S: **[Social Sync Status]:** {data['S']['status']} with Command vector (Lead {self.user_name}). Connection parameters stable and non-degraded.")

                t = data['T']
                if 'error' in t:
                    print(f"T: **[Technical Truth]:** ERROR - {t['error']}")
                else:
                    print(f"T: **[Technical Truth - GPU Metrics]:** {t.get('gpu_utilization', '??%')} Utilization, Temp={t.get('gpu_temperature', '??C')} ({t.get('status', 'Unknown')}). Phi={t.get('phi', '1.0')}")

                a = data['A']
                print(f"A: **[Administrative Truth - Nexus State]:** All AAS directives are {a['status']} and compliant with v{a['version']}. Nexus {'OK' if a['nexus_ok'] else 'FAILED'}. Diligence Score={a.get('diligence', '0.0')}")
                print("\n*Status Cycle Complete. Reporting nominal functionality.*\n")
            else:
                print(f"\n[07 ERROR] Salute failed: {response.text}\n")
        except Exception as e:
            print(f"\n[07 ERROR] Salute exception: {e}\n")

    def run_telemetry(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/telemetry", timeout=5)
            data = response.json()
            print(f"\n[TECHNICAL TRUTH - HARDWARE]")
            if "error" in data:
                print(f" -> ERROR: {data['error']}")
            else:
                for k, v in data.items():
                    print(f" -> {k.upper()}: {v}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Telemetry failed: {e}\n")

    def run_social(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/social", timeout=2)
            data = response.json()
            print(f"\n[SOCIAL SYNC - CONNECTION]")
            for k, v in data.items():
                print(f" -> {k.upper()}: {v}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Social sync failed: {e}\n")

    def run_admin(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/administrative", timeout=2)
            data = response.json()
            print(f"\n[ADMINISTRATIVE TRUTH - NEXUS]")
            print(f" -> STATUS: {data['status']}")
            print(f" -> NEXUS: {'OK' if data['nexus_ok'] else 'NOT FOUND'}")
            print(f" -> VERSION: {data['version']}")
            print(f" -> PROTECTED NODES: {len(data['protected_nodes'])}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Admin failed: {e}\n")

    def run_verify(self, args: List[str]):
        if not args:
            print("\n[07] Usage: /verify <node_path> [command]\n")
            return
        node = args[0]
        cmd = args[1] if len(args) > 1 else "read_file"
        try:
            payload = {"persona": self.identity.replace(" ", "_"), "target_node": node, "command": cmd}
            response = requests.post(f"{BRIDGE_URL}/v1/aas/verify", json=payload, timeout=5)
            data = response.json()
            print(f"\n[AAS AUTHORITY VERIFICATION]")
            print(f" -> NODE: {node}")
            print(f" -> ACTION: {cmd}")
            arb = data["arbitration"]
            print(f" -> STATUS: {arb['status']}")
            print(f" -> CONFIDENCE: {arb.get('confidence_score', 'N/A')}")
            if arb["status"] != "200_OK":
                print(f" -> REASON: {arb.get('reason', 'Access Denied')}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Verification failed: {e}\n")

    def run_vss(self, args: List[str]):
        node = args[0] if args else "AI_Nexus"
        cmd = args[1] if len(args) > 1 else "read_file"
        try:
            payload = {"persona": self.identity.replace(" ", "_"), "target_node": node, "command": cmd}
            response = requests.post(f"{BRIDGE_URL}/v1/aas/verify", json=payload, timeout=5)
            data = response.json()
            breakdown = data["vss_breakdown"]
            print(f"\n[VSS MATHEMATICAL BREAKDOWN]")
            print(f" V = ({breakdown['alpha']} * {breakdown['credibility']}) - ({breakdown['beta']} * {breakdown['risk']}) - ({breakdown['gamma']} * {breakdown['deviation']}) + {breakdown['memory_boost']}")
            print(f" RESULT: {breakdown['vss']:.4f}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] VSS failed: {e}\n")

    def run_phi(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/phi", timeout=5)
            data = response.json()
            print(f"\n[COHERENCE COEFFICIENT - PHI]")
            print(f" -> PHI: {data['phi']}")
            print(f" -> STATUS: {data['status']}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Phi failed: {e}\n")

    def run_velocity(self):
        try:
            response = requests.get(f"{BRIDGE_URL}/v1/psta/velocity", timeout=5)
            data = response.json()
            print(f"\n[RISK VELOCITY - V_i]")
            print(f" -> VELOCITY: {data['velocity']}")
            print(f" -> STATUS: {data['status']}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Velocity failed: {e}\n")

    def run_backups(self):
        print(f"\n[ARCHITECTURAL BACKUP INVENTORY]")
        try:
            response = requests.post(f"{BRIDGE_URL}/v1/chat", json={"messages": [{"role": "user", "name": self.user_name, "content": "list all .bak files in safe zones"}]}, timeout=10)
            if response.status_code == 200:
                data = response.json()
                print(f"{self.identity}> {data.get('result', {}).get('message', {}).get('content', 'No backup data found.')}\n")
            else:
                print(f"\n[07 ERROR] Backup list failed: {response.text}\n")
        except Exception as e:
            print(f"\n[07 ERROR] Backup inventory exception: {e}\n")

    def run_handshake(self):
        try:
            response = requests.post(f"{BRIDGE_URL}/v1/aas/handshake", timeout=5)
            data = response.json()
            print(f"\n[AAS AUTHORITY HANDSHAKE]")
            print(f" -> STATUS: {data['status']}")
            print(f" -> MESSAGE: {data['message']}")
            print("-" * 30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Handshake failed: {e}\n")

    def run(self):
        self.print_header()
        while True:
            try:
                user_input = input(f"{self.user_name}> ").strip()
                if not user_input: continue

                # --- Natural Command Bridge ---
                if "[ACTION]:" in user_input.upper():
                    # Simplified parsing for the "Glossary" format
                    action = ""
                    target = ""
                    lines = user_input.split('\n')
                    for line in lines:
                        if "[ACTION]:" in line.upper(): action = line.split(":", 1)[1].strip().lower()
                        if "[TARGET]:" in line.upper(): target = line.split(":", 1)[1].strip()

                    if "retrieve" in action or "read" in action:
                        user_input = f"/verify {target} read_file"
                    elif "list" in action:
                        user_input = f"/verify {target} list_files"
                    elif "write" in action or "save" in action or "commit" in action:
                        user_input = f"/verify {target} write_file"
                    elif "monitor" in action or "status" in action:
                        user_input = "/07"

                parts = user_input.split()
                cmd = parts[0].lower()
                args = parts[1:]

                if cmd == "/exit": break
                if cmd == "/report": self.save_mission_report(); continue
                if cmd == "/status": self.show_status(); continue
                if cmd == "/07" or cmd == "/p": self.run_salute(); continue
                if cmd == "/t": self.run_telemetry(); continue
                if cmd == "/s": self.run_social(); continue
                if cmd == "/a": self.run_admin(); continue
                if cmd == "/verify": self.run_verify(args); continue
                if cmd == "/vss": self.run_vss(args); continue
                if cmd == "/phi": self.run_phi(); continue
                if cmd == "/velocity": self.run_velocity(); continue
                if cmd == "/backups": self.run_backups(); continue
                if cmd == "/handshake": self.run_handshake(); continue
                if cmd == "/tools":
                    self.show_tools = not self.show_tools
                    print(f"[07] Logs: {'ON' if self.show_tools else 'OFF'}")
                    continue

                self.history.append({"role": "user", "content": user_input})
                response = requests.post(f"{BRIDGE_URL}/v1/chat", json={"messages": self.history}, timeout=120)

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

                            # Diligent Scribe: Feedback on writes
                            if name == "write_file":
                                print(f" -> [SCRIBE] TOTAL OVERWRITE: {args.get('filepath')}")
                                if isinstance(output, dict) and "backup" in output:
                                    print(f" -> [SCRIBE] BACKUP CREATED: {output['backup']}")
                                if isinstance(output, dict) and "scribe_warning" in output:
                                    print(f" -> [SCRIBE WARNING]: {output['scribe_warning']}")
                            elif name == "patch_file":
                                print(f" -> [SCRIBE] SURGICAL PATCH: {args.get('filepath')}")
                                if isinstance(output, dict) and "backup" in output:
                                    print(f" -> [SCRIBE] BACKUP CREATED: {output['backup']}")

                            print(f" -> EXECUTING: {name}({args})")
                            print(f" -> RESULT: {str(output)[:200]}...") # Cap output length for display
                        print("-" * 20)

                    ai_msg = result.get("message", {})
                    content = ai_msg.get("content", "...")
                    print(f"\n{self.identity}> {content}\n")
                    self.history.append({"role": "assistant", "content": content})
                else:
                    print(f"\n[07 ERROR] Bridge Error: {response.text}\n")

            except KeyboardInterrupt: break
            except Exception as e: print(f"\n[07 ERROR] {e}\n")

if __name__ == "__main__":
    vessel = ChatVessel()
    vessel.run()
