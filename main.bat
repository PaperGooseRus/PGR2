
@echo off
setlocal
cls
chcp 65001 >nul

REM ==========================================
REM 1. ENVIRONMENT
REM ==========================================

set "PATH=C:\msys64\ucrt64\bin;C:\msys64\usr\bin;%PATH%"

REM ==========================================
REM 2. GTK4 COMPILER FLAGS
REM ==========================================

set "GTK_CFLAGS="
for /f "usebackq delims=" %%i in (`pkg-config --cflags gtk4`) do (
    set "GTK_CFLAGS=%%i"
)

set "GTK_LIBS="
for /f "usebackq delims=" %%i in (`pkg-config --libs gtk4`) do (
    set "GTK_LIBS=%%i"
)

if not defined GTK_CFLAGS (
    echo ERROR: GTK4 CFLAGS not found.
    pause
    exit /b 1
)

if not defined GTK_LIBS (
    echo ERROR: GTK4 LIBS not found.
    pause
    exit /b 1
)

REM ==========================================
REM 3. PROJECT INCLUDE DIRECTORIES
REM ==========================================

set "PROJECT_CFLAGS=-I. -Igui -Igui/table -Igui/tabe -Icore -Icore/system"

REM ==========================================
REM 4. COMPILER OPTIONS
REM ==========================================

set "CFLAGS=-Wall -Wextra -std=c11"

REM ==========================================
REM 5. BUILD
REM ==========================================

if not exist bin mkdir bin

echo.
echo ==========================================
echo BUILDING PROJECT...
echo ==========================================

gcc %CFLAGS% %GTK_CFLAGS% %PROJECT_CFLAGS% ^
    -o bin\main.exe ^
    main.c gui\activate.c gui\table\table.c gui\tabe\tabe1.c core\system\system.c ^
    %GTK_LIBS% ^
    -mwindows

if errorlevel 1 (
    echo.
    echo BUILD FAILED.
    pause
    exit /b 1
)

REM ==========================================
REM 6. RUN
REM ==========================================

echo.
echo ==========================================
echo BUILD SUCCESSFUL.
echo STARTING APPLICATION...
echo ==========================================

bin\main.exe

if errorlevel 1 (
    echo.
    echo APPLICATION EXITED WITH ERROR.
    pause
)

endlocal
