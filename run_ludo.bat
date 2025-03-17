@echo off
echo Compiling Ludo Game...
gcc "Project Ludo Final.c" -o ludo.exe
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b %errorlevel%
)
echo Compilation successful!
echo Starting game...
ludo.exe
pause 