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
BRIDGE_URL = "http://127.0.0.1:8000"
REPORT_DIR = os.path.dirname(__file__)

class ChatVessel:
    def __init__(self):
        self.session_id = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.history: List[Dict[str, str]] = []
        self.user_name = "User"
        self.identity = "Iron Officer"
        self.fetch_bridge_info()

    def fetch_bridge_info(self):
        """Syncs with the bridge to get user identity and status."""
        try:
            response = requests.get(f"{BRIDGE_URL}/", timeout=2)
            if response.status_code == 200:
                data = response.json()
                self.user_name = data.get("user", "Dan")
                self.identity = data.get("identity", "Iron Officer")
                print(f"[07] Connected to {self.identity}. Greetings, {self.user_name}.")
            else:
                print(f"[07 WARNING] Bridge returned status {response.status_code}")
        except Exception as e:
            print(f"[07 ERROR] Could not connect to Iron Officer Bridge at {BRIDGE_URL}")
            print("[07] Ensure 'run_bridge.bat' is active.")
            sys.exit(1)

    def print_header(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("="*60)
        print(f" SOVEREIGN IRON OFFICER | VESSEL {self.session_id}")
        print(f" User: {self.user_name} | Theme: Dark")
        print("="*60)
        print(" Commands: /report (Save Mission Report), /status (Health), /exit")
        print("-"*60)

    def save_mission_report(self):
        """Exports the current session history to a JSON Mission Report."""
        filename = f"Mission_Report_{self.session_id}.json"
        filepath = os.path.join(REPORT_DIR, filename)

        report = {
            "mission_id": self.session_id,
            "timestamp": datetime.datetime.now().isoformat(),
            "commander": self.identity,
            "lead": self.user_name,
            "transcript": self.history,
            "status": "COMPLETED"
        }

        try:
            with open(filepath, "w") as f:
                json.dump(report, f, indent=4)
            print(f"\n[07] Mission Report saved to: {filename}")
        except Exception as e:
            print(f"\n[07 ERROR] Failed to save report: {e}")

    def show_status(self):
        """Queries the bridge for health and hardware status."""
        try:
            response = requests.get(f"{BRIDGE_URL}/", timeout=2)
            data = response.json()
            print("\n" + "-"*30)
            print(f"BRIDGE STATUS: {data.get('status')}")
            print(f"HARDWARE: {data.get('hardware')}")
            print(f"ACTIVE MODELS: {', '.join(data.get('models', []))}")
            print("-"*30 + "\n")
        except Exception as e:
            print(f"\n[07 ERROR] Failed to fetch status: {e}")

    def run(self):
        self.print_header()

        while True:
            try:
                user_input = input(f"{self.user_name}> ").strip()

                if not user_input:
                    continue

                if user_input.lower() == "/exit":
                    print("[07] Terminating session. Goodbye.")
                    break

                if user_input.lower() == "/report":
                    self.save_mission_report()
                    continue

                if user_input.lower() == "/status":
                    self.show_status()
                    continue

                # Add to history
                self.history.append({"role": "user", "content": user_input})

                # Send to bridge
                response = requests.post(
                    f"{BRIDGE_URL}/v1/chat",
                    json={"messages": self.history},
                    timeout=60
                )

                if response.status_code == 200:
                    ai_msg = response.json().get("message", {})
                    content = ai_msg.get("content", "...")
                    print(f"\n{self.identity}> {content}\n")
                    self.history.append({"role": "assistant", "content": content})
                else:
                    print(f"\n[07 ERROR] Bridge Error: {response.text}\n")

            except KeyboardInterrupt:
                print("\n[07] Interrupted by user.")
                break
            except Exception as e:
                print(f"\n[07 ERROR] Communication failure: {e}\n")

if __name__ == "__main__":
    vessel = ChatVessel()
    vessel.run()
