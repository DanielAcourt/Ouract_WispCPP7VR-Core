@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer Connection Tester (Hardened)

echo [07] Initializing Connection Test...
echo [07] Path: %~dp0

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
        echo [ERROR] Python not found. See README for PATH fix.
        pause
        exit /b
    )
)

%PY_CMD% test_connection.py

pause
