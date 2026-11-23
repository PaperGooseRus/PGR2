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
