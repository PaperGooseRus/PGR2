@echo off
setlocal
chcp 65001 >nul

cls

rem ПРОВЕРКА УСТАНОВЛЕННЫХ ИНСТРУМЕНТОВ
echo ИНСТРУМЕНТ GCC:
echo.
echo КРАТКАЯ ИНФОРМАЦИЯ
gcc --version
echo ДЕТАЛЬНАЯ ИНФОРМАЦИЯ
gcc -v

echo.
echo.
echo.

echo ИНСТРУМЕНТ G++
echo.
echo КРАТКАЯ ИНФОРМАЦИЯ
g++ --version
echo ДЕТАЛЬНАЯ ИНФОРМАЦИЯ
g++ -v

echo.
echo.
echo.

rem ПОДГОТОВКА ДИРЕКТОРИИ ДЛЯ СБОРКИ
echo УДАЛЕНИЕ СТАРОЙ СБОРКИ
rmdir /s /q bin
echo СОЗДАНИЕ ДИРЕКТОРИИ ДЛЯ СБОРК
mkdir bin

echo.
echo.
echo.

rem СБОРКА ПРОЕКТА
echo СБОРКА ПРОЕКТА
gcc main.c -o bin\main.exe

echo ЗАПУСК ПРИЛОЖЕНИЯ
.\bin\main.exe
