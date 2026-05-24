@echo off
:: Copyright (c) 2013-2025 Daniel Acourt. Version 0.36.3.1MABackup.
echo [07] Iron Officer: Building Chat Vessel Executable...

:: Check for PyInstaller
python -m pip install pyinstaller requests

:: Build the EXE
:: --onefile: Create a single executable
:: --name: Name of the output file
:: --distpath: Where to put the finished EXE
python -m PyInstaller --onefile --name IronOfficer_Chat --distpath . vessel.py

echo.
echo [07] Build Complete. 'IronOfficer_Chat.exe' is ready in the Environment folder.
echo [07] Note: Ensure 'run_bridge.bat' is active before launching the chat.
pause
