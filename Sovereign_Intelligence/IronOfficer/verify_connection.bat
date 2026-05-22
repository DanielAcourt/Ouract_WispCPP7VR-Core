@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.1. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22
:: Sovereign Framework: Iron Officer Connection Tester

echo [07] Initializing Connection Test...
echo [07] Path: %~dp0

set "BASE_DIR=%~dp0"
cd /d "%BASE_DIR%"

python test_connection.py

pause
