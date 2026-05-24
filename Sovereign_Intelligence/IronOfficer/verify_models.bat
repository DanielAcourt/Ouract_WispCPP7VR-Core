@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: 07 Model Parity Auditor

echo [07] Commencing Model Parity Audit...
echo.

echo --- 1. CLI PERSPECTIVE (system environment) ---
ollama list
echo.

echo --- 2. API PERSPECTIVE (bridge connection) ---
curl -s http://127.0.0.1:11434/api/tags | python -c "import sys, json; print('\n'.join([m['name'] for m in json.load(sys.stdin)['models']]))"
echo.

echo --- 3. ENVIRONMENT CHECK ---
echo OLLAMA_MODELS = %OLLAMA_MODELS%
echo.

echo [07] If lists 1 and 2 do not match:
echo 1. Right-click Ollama in System Tray -> Quit.
echo 2. Run 'run_bridge.bat'.
echo 3. Verify parity again.
echo.
pause
