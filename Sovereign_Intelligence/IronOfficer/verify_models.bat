@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: 07 Model Parity Auditor

echo [07] Commencing Model Parity Audit...
echo.

echo --- 1. CLI PERSPECTIVE (system environment) ---
ollama list
echo.

echo --- 2. API PERSPECTIVE (bridge connection) ---
curl -s http://127.0.0.1:11434/api/tags | python -c "import sys, json; data = json.load(sys.stdin); models = [m['name'] for m in data.get('models', [])]; print('\n'.join(models) if models else '[07] No models found via API.')"
echo.

echo --- 3. ENVIRONMENT CHECK ---
echo User Profile: %USERPROFILE%
if "%OLLAMA_MODELS%"=="" (
    echo [07 WARNING] OLLAMA_MODELS is not set. Default path: %USERPROFILE%\.ollama\models
    echo --- 4. PHYSICAL TRUTH (FileSystem) ---
    dir "%USERPROFILE%\.ollama\models" /B 2>nul || echo [07 ERROR] Path not found.
) else (
    echo OLLAMA_MODELS = %OLLAMA_MODELS%
    echo --- 4. PHYSICAL TRUTH (FileSystem) ---
    dir "%OLLAMA_MODELS%" /B 2>nul || echo [07 ERROR] Path not found.
)
echo.

echo [07] If lists 1 and 2 and 4 do not match:
echo 1. Right-click Ollama in System Tray -> Quit.
echo 2. Run 'run_bridge.bat'.
echo 3. Verify parity again.
echo.
pause
