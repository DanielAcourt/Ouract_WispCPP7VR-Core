@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer One-Click Launcher (Resilient)

echo [07] Initializing Iron Officer Bridge...
echo [07] Hardware Target: GTX 5090

set "BASE_DIR=%~dp0"
cd /d "%BASE_DIR%"

:: 1. Try standard commands
set "PY_CMD="

python --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=python" & goto :FOUND)

py --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=py" & goto :FOUND)

python3 --version >nul 2>&1
if %errorlevel% EQU 0 (set "PY_CMD=python3" & goto :FOUND)

:: 2. Search common local paths
echo [07] Python not in PATH. Searching common directories...

for /d %%D in ("%LocalAppData%\Programs\Python\Python*") do (
    if exist "%%D\python.exe" (
        set "PY_CMD="%%D\python.exe""
        goto :FOUND
    )
)

for /d %%D in ("%ProgramFiles%\Python*") do (
    if exist "%%D\python.exe" (
        set "PY_CMD="%%D\python.exe""
        goto :FOUND
    )
)

:: 3. If still not found, fail with instructions
echo [ERROR] Python not found.
echo ---------------------------------------------------------
echo SOLUTION:
echo 1. Re-install Python from https://www.python.org/
echo 2. Check "Add Python to PATH" during installation.
echo 3. Search for "App execution aliases" in Windows and
echo    DISABLE the Python aliases to stop the Microsoft Store prompt.
echo ---------------------------------------------------------
pause
exit /b

:FOUND
echo [07] Using Command: %PY_CMD%
echo [07] Starting FastAPI Service...
%PY_CMD% bridge.py

pause
