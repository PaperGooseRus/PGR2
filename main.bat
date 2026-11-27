@echo off
setlocal
cls

chcp 65001 >nul
set "PATH=C:\msys64\ucrt64\bin;C:\msys64\usr\bin;%PATH%"

rmdir /s /q bin
mkdir bin

set "GTK_CFLAGS="
for /f "usebackq delims=" %%i in (`pkg-config --cflags gtk4`) do set "GTK_CFLAGS=%%i"
echo GTK_CFLAGC = %GTK_CFLAGS%
if not defined GTK_CFLAGS (
    echo ОШИБКА: pkg-config не вернул --cflags для gtk4.
    exit /b 1
)

set "GTK_LIBS="
for /f "usebackq delims=" %%i in (`pkg-config --libs gtk4`)   do set "GTK_LIBS=%%i"
echo GTK_LIBS = %GTK_LIBS%
if not defined GTK_LIBS (
    echo ОШИБКА: pkg-config не вернул --libs для gtk4.
    exit /b 1
)

gcc %GTK_CFLAGS% -o bin\main.exe main.c gui\activate.c %GTK_LIBS% -mwindows
if errorlevel 1 (
    echo.
    echo СБОРКА НЕ УДАЛАСЬ.
    exit /b 1
)

.\bin\main.exe
endlocal
