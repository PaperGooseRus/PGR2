@echo off
setlocal
cls

rem НАЧАЛЬНЫЕ УСТАНОВКИ
chcp 65001 >nul
set "PATH=C:\msys64\ucrt64\bin;C:\msys64\usr\bin;%PATH%"

echo.
echo.
echo.

rem ПРОВЕРКА УСТАНОВЛЕННЫХ ИНСТРУМЕНТОВ
echo ИНСТРУМЕНТ GCC:
gcc -v

echo.
echo.
echo.

rem ПОДГОТОВКА ДИРЕКТОРИИ ДЛЯ СБОРКИ
echo УДАЛЕНИЕ СТАРОЙ СБОРКИ
rmdir /s /q bin
echo.
echo СОЗДАНИЕ ДИРЕКТОРИИ ДЛЯ СБОРК
mkdir bin

echo.
echo.
echo.

rem СБОРКА ПРОЕКТА
echo СБОРКА ПРОЕКТА
set "GTK_CFLAGS="
for /f "usebackq delims=" %%i in (`pkg-config --cflags gtk4`) do set "GTK_CFLAGS=%%i"
echo GTK_CFLAGC = %GTK_CFLAGS%
if not defined GTK_CFLAGS (
    echo ОШИБКА: pkg-config не вернул --cflags для gtk4.
    exit /b 1
)

echo.

set "GTK_LIBS="
for /f "usebackq delims=" %%i in (`pkg-config --libs gtk4`)   do set "GTK_LIBS=%%i"
echo GTK_LIBS = %GTK_LIBS%
if not defined GTK_LIBS (
    echo ОШИБКА: pkg-config не вернул --libs для gtk4.
    exit /b 1
)

echo.

echo Команда сборки:
echo gcc %GTK_CFLAGS% -o bin\main.exe main.c %GTK_LIBS% -mwindows
echo.
gcc %GTK_CFLAGS% -o bin\main.exe main.c gui\activate.c %GTK_LIBS% -mwindows

echo.

if errorlevel 1 (
    echo.
    echo СБОРКА НЕ УДАЛАСЬ.
    exit /b 1
)

echo ЗАПУСК ПРИЛОЖЕНИЯ
.\bin\main.exe
endlocal

clear.bat
