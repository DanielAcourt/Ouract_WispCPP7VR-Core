// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
# Local AI Model Catalog (GTX 5090 Deployment)

This catalog lists the verified and recommended models for the **Iron Officer** local hosting solution.

## 🏆 Tier 2: Commander Class (70B+)
*High-fidelity reasoning, complex research, and architectural synthesis.*

| Model | ID | VRAM Req. | Use Case |
| :--- | :--- | :--- | :--- |
| **Llama 3 70B** | `llama3:70b` | ~40GB | Primary Mission Lead. Strategic Roadmap alignment. |
| **Mixtral 8x7B** | `mixtral` | ~24GB | High-speed multi-lingual and logic processing. |

---

## 🎖️ Tier 1: Officer Class (14B - 34B)
*Technical analysis, C++ code review, and metadata transcription.*

| Model | ID | VRAM Req. | Use Case |
| :--- | :--- | :--- | :--- |
| **Qwen-Coder 30B** | `qwen3-coder:30b` | ~18GB | Best-in-class local coding and JSON structure analysis. |
| **CodeLlama 34B** | `codellama:34b` | ~20GB | Specialized C++ implementation review. |

---

## 👣 Tier 0: Instinct Class (1B - 8B)
*Real-time PSTA VSS heartbeat and high-frequency anomaly detection.*

| Model | ID | VRAM Req. | Use Case |
| :--- | :--- | :--- | :--- |
| **Llama 3 8B** | `llama3:8b` | ~5GB | Low-latency PSTA safety kernel operations. |
| **Phi-3 Mini** | `phi3` | ~2.5GB | Edge-case validation and fast metadata tagging. |

---

## ⚙️ Deployment Strategy (Ollama)
To install all models into the same local directory on the **MainDesktop**, run:
```bash
ollama pull llama3:70b
ollama pull qwen3-coder:30b
ollama pull llama3:8b
```
All models are automatically managed by the Ollama background service and are instantly switchable via the `config.json` in `Sovereign_Intelligence/IronOfficer/`.
