@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer One-Click Launcher (Hardened)

echo [07] Initializing Iron Officer Bridge...
echo [07] Hardware Target: GTX 5090

set "BASE_DIR=%~dp0"
cd /d "%BASE_DIR%"

:: Check for python, fallback to py (Python Launcher)
set "PY_CMD=python"
python --version >nul 2>&1
if %errorlevel% neq 0 (
    py --version >nul 2>&1
    if %errorlevel% eq 0 (
        set "PY_CMD=py"
    ) else (
        echo [ERROR] Python not found in your PATH.
        echo ---------------------------------------------------------
        echo SOLUTION:
        echo 1. Re-install Python from python.org
        echo 2. Check "Add Python to PATH" during installation.
        echo 3. OR, search for "App execution aliases" in Windows and
        echo    DISABLE the Python aliases to stop the Microsoft Store prompt.
        echo ---------------------------------------------------------
        pause
        exit /b
    )
)

echo [07] Using Command: %PY_CMD%
echo [07] Starting FastAPI Service...
%PY_CMD% bridge.py

pause
