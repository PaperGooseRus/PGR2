@echo off
setlocal

echo ПРОВЕРКА СОСТОЯНИЯ РЕПОЗИТОРИЯ:
git status

echo.
echo.
echo.

echo ОТОБРАЖЕНИЕ ГРАФА РЕПОЗИТОРИЯ:
git log --graph --oneline --all --decorate
