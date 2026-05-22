@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer Connection Tester (Resilient)

echo [07] Initializing Connection Test...
echo [07] Path: %~dp0

set "BASE_DIR=%~dp0"
cd /d "%BASE_DIR%"

:: 1. Try standard commands
set "PY_CMD="
python --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=python" & goto :FOUND)
py --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=py" & goto :FOUND)

:: 2. Search common local paths
for /d %%D in ("%LocalAppData%\Programs\Python\Python*") do (
    if exist "%%D\python.exe" (set "PY_CMD="%%D\python.exe"" & goto :FOUND)
)

if "%PY_CMD%"=="" (
    echo [ERROR] Python not found. See README for PATH fix.
    pause
    exit /b
)

:FOUND
%PY_CMD% test_connection.py

pause
