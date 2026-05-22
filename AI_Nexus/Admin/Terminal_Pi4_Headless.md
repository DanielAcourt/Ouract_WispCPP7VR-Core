// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Terminal: Pi4_Headless (The Safety Kernel)

## 🏛️ 1. Overview
The **Pi4_Headless** node is the dedicated hardware monitor for physical vessel safety. It runs the PSTA Safety Kernel in a non-graphical environment to maximize resource availability for sensor processing.

## 🛠️ 2. Hardware Profile
*   **Platform:** Raspberry Pi 4 Model B.
*   **Memory:** 4GB/8GB LPDDR4 RAM.
*   **Storage:** High-Endurance microSD (Industrial Grade).
*   **Role:** Headless Linux Environment (Command Line Only).

## 📡 3. Sovereign Role
*   **Pillar Host:** Technical (T).
*   **Function:** Real-time PSTA VSS calculation for physical hardware.
*   **Connectivity:** UDP/TCP socket bridge to the MainDesktop for telemetry reflection.
*   **I/O:** Direct GPIO interaction for E-Stop relays and sensor data acquisition.

---

## 🛡️ 4. Security Status
*   **Classification:** HARDENED.
*   **Networking:** Isolated safety subnet (Optional).
*   **Protocol:** Mandatory 07 Handshake for data transmission to the Nexus.
