@echo off
if "%1"=="python" (
    taskkill /F /IM python.exe /T 2>nul
    taskkill /F /IM python2.exe /T 2>nul
    taskkill /F /IM python3.exe /T 2>nul
    echo All running Python processes terminated.
) else if "%1"=="java" (
    taskkill /F /IM jqs.exe /T 2>nul
    taskkill /F /IM javaw.exe /T 2>nul
    taskkill /F /IM java.exe /T 2>nul
    echo All running Java processes terminated.
) else (
    echo Invalid argument. Please provide "python" or "java" as an argument.
)
