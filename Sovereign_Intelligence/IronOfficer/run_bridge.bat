@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer One-Click Launcher

echo [07] Initializing Iron Officer Bridge...
echo [07] Hardware Target: GTX 5090

:: Get the directory where this batch file is located
set "BASE_DIR=%~dp0"

:: Navigate to the directory (quotes handle spaces automatically)
cd /d "%BASE_DIR%"

:: Check if python is in PATH
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] Python not found. Please install Python 3.10+ and add it to your PATH.
    pause
    exit /b
)

:: Run the bridge
echo [07] Starting FastAPI Service...
python bridge.py

pause
