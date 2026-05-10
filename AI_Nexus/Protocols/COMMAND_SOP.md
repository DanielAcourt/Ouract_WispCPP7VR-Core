# Command & Delegation Protocol (The Sun Tzu SOP)

> "If words of command are not clear and distinct, if orders are not thoroughly understood, then the general is to blame. But, if orders are clear and the soldiers nevertheless disobey, then it is the fault of their officers." — *Sun Tzu*

## 📜 Purpose
To eliminate **Assumption Drift** and ensure that delegation between the Technical Lead and AI Agents (Jules/Claude) is 100% deterministic.

**The Cognitive Bridge:** Because the Technical Lead thinks in **Volumes/Space (99th percentile)** but communicates in **Linear Language (30th percentile)**, this protocol acts as a translator. It ensures that the "Spatial Soul" of an idea is accurately converted into a "Linear Vessel" of instructions that an AI can execute without hallucination.

---

## 🛠 The Task Issuance Framework: WHY, WHAT, HOW

To prevent agents from running on assumptions, every major task command should ideally follow this structure:

### 1. The WHY (Objective/Philosophy)
*   **Definition:** The strategic reason for the task.
*   **Goal:** Provides context so the agent understands the "Soul" of the request.
*   **Agent Constraint:** If the "Why" is unclear, the agent MUST use `request_user_input` before proceeding.

### 2. The WHAT (Scope/Deliverables)
*   **Definition:** The specific, tangible outcomes required.
*   **Goal:** Defines the boundaries of the task to prevent feature creep or "tangents."
*   **Agent Constraint:** The agent must list these deliverables in the `set_plan` tool.

### 3. The HOW (Technical Specifics/Constraints)
*   **Definition:** The exact implementation details, file paths, or architectural rules (e.g., The Sovereign Rule).
*   **Goal:** Eliminates technical ambiguity.
*   **Agent Constraint:** The agent must follow these instructions to the letter. Deviation requires explicit approval.

---

## ⚖️ Accountability & Correction
*   **Lead Responsibility:** Ensure commands are "clear and distinct." Avoid ambiguous language.
*   **Agent Responsibility:** Execute without "hallucinating" intent. If a command is 90% clear, the agent must ask about the remaining 10% rather than assuming.
*   **Correction Loop:** If an agent goes off on a tangent, the Lead should point to the specific section of the "What" or "How" that was violated.

---

## 🛡️ Assumption Kill-Switch
If an agent detects it is making an assumption about a critical system (Saving, Spawning, Identity), it MUST:
1.  Stop execution.
2.  State the assumption clearly to the Lead.
3.  Wait for confirmation or correction.
