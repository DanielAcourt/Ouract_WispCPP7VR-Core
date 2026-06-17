// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-06-17
# PROTOCOL: AGENCY ARBITRATION SCHEMA (AAS)

## Version: 1.3.0-BETA
## Classification: SSoT / Directive Level

### 1. MISSION STATEMENT
The AAS provides a formal, computational framework to resolve logical conflicts arising between the Conceptual Core (Identity), Theoretical Frameworks (Research), and Runtime Execution (C++).

### 2. PERSONA REGISTRY (Authority Levels)
| Persona | Precedence (P) | Zone Authority | Credibility Score |
| :--- | :---: | :--- | :---: |
| **Lead** | 10 | ALL (Root) | 1.0 |
| **Tactician** | 9 | STAGING / DEV | 0.9 |
| **Strategist** | 8 | PLANNING | 0.85 |
| **Researcher** | 7 | INNOVATION | 0.75 |
| **Iron_Knight** | 5 | STAGING (Unverified) | 0.5 |
| **Yaz_Student** | 3 | SANDBOX (Honeypot) | 0.3 |

### 3. TOOL PRECEDENCE (Minimum P Required)
| Tool Action | Min Precedence | Operational Risk |
| :--- | :---: | :--- |
| `delete_file` | 10 | CRITICAL (Structural Destruction) |
| `write_file` (Protected) | 10 | CRITICAL (Kernel Mutation) |
| `write_file` (Nexus) | 8 | HIGH (SOP Drift) |
| `get_system_telemetry`| 5 | MEDIUM (Information Disclosure) |
| `read_file` / `list_files` | 3 | LOW (Standard Access) |

### 4. OPERATIONAL TRIGGERS
AAS must be invoked if any system component detects a 'Logic Mismatch' (e.g., C++ module returning an Error Code 409: Agency Conflict).

### 5. MANDATORY INTERFACE
Any module implementing an AAS check must include:
* `Authority_ID`: The agent invoking the request.
* `Confidence_Score`: A 0.0-1.0 float representing certainty.
* `AAS_Route`: The specific directive from the Protocol path utilized.

### 6. THE 409 CONFLICT GATE (PSTA Viability)
If the calculated **Viability Score** falls below **0.7**, the system must trigger a `409_CONFLICT_GATE`. This halts execution and requires a mandatory user handshake (Lead authorization) to proceed.

**Viability Formula:**
`V = (0.5 * Credibility) - (0.3 * NodeRisk) - (0.2 * StructuralDeviation)`