// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-06-28
# Sovereign Framework: CURRENT SPRINT BACKLOG

This file tracks active tickets prioritized for the current iteration. Isolating these tasks optimizes real-time AI context loading and focuses active development.

> 💡 **Developer Note (Sprint Status):**
> **All active sprint tasks have been completed and verified!** The dynamic broker lifecycle (B-016, B-017), dynamic soul hub mediator orchestration (E-001a, E-001b, E-001c), and the AI-to-Unreal Mailbox Polling pattern (B-026) are fully operational and verified through C++ automated tests and play-in-editor sessions.

## 🏃‍♂️ Active Sprint Tickets

| ID | Task | Complexity | Status | Node | Why (Context) | What (Completion Outcome) |
|:---|:---|:---:|:---:|:---|:---|:---|
| AD-003 | Iron Officer: Session & Local Memory | 8 | Done | Admin/Research | Enable the local AI to ingest the AI_Nexus research directly. | Local RAG or context window management for 12 years of project data. |
| B-016 | Soul: Diagnostic Broker (Truth) | 5 | Done | DevOps | Implement the raw scientific/historical data layer for Lidar/Museum ingestion. | UDiagnosticBroker capturing and restoring vetted metadata and raw telemetry. |
| B-017 | Soul: Cultivation Broker (Magic) | 5 | Done | DevOps | Implement the gamified progression layer (Qi/Maturity) as a decoupled module. | UCultivationBroker managing optional simulation logic without breaking SSoT. |
| E-001a | Epic: Soul – Dynamic Broker Instantiation | 8 | Done | DevOps | Automatically instantiate and register UDiagnosticBroker and UCultivationBroker on BeginPlay. | Dynamic lifecycle complete with safe NewObject creation. |
| E-001b | Epic: Soul – Domain Namespace Isolation | 5 | Done | DevOps | Ensure strict separation of "Sovereign.Truth" and "Sovereign.Magic" save keys. | Decoupled namespace serialization verified under distinct JSON category keys. |
| E-001c | Epic: Soul – VSS & Paradox Coupling | 8 | Done | Research/DevOps | Bind Paradox Density and System Confidence to Diagnostic Broker vetting indicators. | Paradox scaling mapped to truth validation and unvetted telemetry. |
| B-026 | AI-to-Unreal Mailbox Polling | 8 | Done | DevOps | Implement proactive AI chat capabilities using the Mailbox Polling pattern. | Integration of /v1/unreal/mailbox HTTP loop in USovereignBridgeSubsystem and push_chat tool. |
| AD-005a | Spatial Sense: Save State Ingestion | 5 | Done | Research/DevOps | Map serialized JSON save payloads to the LLM's system context prompt framing. | Serialized component save packet (Identity, Bio, Qi, etc.) is injected during `/v1/unreal/chat` calls. |
| AD-005d | E2E Dialogue Console Logging | 2 | Done | DevOps | Enable immediate trace logging of the AI's response content in the bridge and client subsystem. | AI response is logged with prefix trace on both Python and C++ consoles. |

---

## 📋 Upcoming Prioritized Sprint Tickets (Next Phase)

The following tickets have been prioritized and added to the active backlog queue for the next development iteration:

| ID | Task | Complexity | Status | Node | Why (Context) | What (Completion Outcome) |
|:---|:---|:---:|:---:|:---|:---|:---|
| B-027 | AAS v1.4.0 Hardening | 3 | Todo | DevOps | Refactor the hardcoded diligence score to dynamically verify backup files on disk. | Diligence score is calculated dynamically based on actual .bak coverage ratios on disk. |
| AD-008 | Adaptive System Prompt Modulation | 5 | Todo | DevOps | Prevent the LLM from snapping back to rigid Knight behavior during roleplay. | System prompt dynamically softens tone and instructs model to write to active paths immediately. |
| AD-009 | Smart RAG Query Filtering | 3 | Todo | DevOps | Prevent irrelevant administrative documents from polluting the creative context. | RAG search is bypassed or restricted if the prompt is purely roleplay/conversational. |
| AD-010 | Transient Path Memory Anchor | 3 | Todo | DevOps | Keep the active file path anchored in the system context to stop repetitive parameter loops. | A last_active_file variable is dynamically tracked and injected into the system prompt. |

---

## 🏛️ Strategic Alignment
- **Combined Sprint Backlog Load:** **49 Points** (All Completed)
- **Sprint Goal:** Stabilize the decoupled Sovereign Soul Broker interface, establish dynamic broker instantiation, and enforce strict Truth/Magic domain separation. (100% Achieved)
