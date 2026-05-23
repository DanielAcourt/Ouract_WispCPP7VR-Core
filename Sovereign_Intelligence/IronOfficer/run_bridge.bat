@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer One-Click Launcher (Self-Healing)

echo [07] Initializing Iron Officer Bridge...
echo [07] Hardware Target: GTX 5090

:: Get the directory where this batch file is located (IronOfficer folder)
set "IRON_OFFICER_DIR=%~dp0"

:: Navigate to the directory
cd /d "%IRON_OFFICER_DIR%"

:: Calculate the Nexus Path (Up two levels from IronOfficer/ to repo root)
:: We use double-backslashes to ensure Python handles the path correctly
set "REPO_ROOT=%~dp0..\.."
pushd "%REPO_ROOT%"
set "NEXUS_PATH=%cd%\AI_Nexus"
popd

:: 1. Try standard commands
set "PY_CMD="

python --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=python" & goto :FOUND)

py --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=py" & goto :FOUND)

python3 --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=python3" & goto :FOUND)

:: 2. Search common local paths
for /d %%D in ("%LocalAppData%\Programs\Python\Python*") do (
    if exist "%%D\python.exe" (set "PY_CMD="%%D\python.exe"" & goto :FOUND)
)

for /d %%D in ("%ProgramFiles%\Python*") do (
    if exist "%%D\python.exe" (set "PY_CMD="%%D\python.exe"" & goto :FOUND)
)

echo [ERROR] Python not found. Please install Python 3.10+.
pause
exit /b

:FOUND
:: 4. Check for and Install Dependencies
%PY_CMD% -c "import requests, fastapi, uvicorn" >nul 2>&1
if %errorlevel% NEQ 0 (
    echo [07] Missing dependencies detected. Installing now...
    %PY_CMD% -m pip install -r requirements.txt
)

:: 5. Pre-flight Checks (Port 8000 & Ollama)
netstat -ano | findstr :8000 | findstr LISTENING >nul
if %errorlevel% EQU 0 (
    echo [07 WARNING] Port 8000 is already in use.
    echo [07] Run this to kill the blocker: taskkill /F /PID [PID_FROM_NETSTAT]
    netstat -ano | findstr :8000
    pause
)

tasklist /FI "IMAGENAME eq ollama.exe" 2>NUL | find /I /N "ollama.exe">NUL
if "%ERRORLEVEL%" NEQ "0" (
    echo [07 CRITICAL] Ollama is not running.
    echo [07] Please start Ollama from your System Tray or Start Menu.
    pause
)

:: 6. Start the Bridge with the local Nexus path
echo [07] Starting FastAPI Service...
%PY_CMD% bridge.py --nexus "%NEXUS_PATH%"

pause
