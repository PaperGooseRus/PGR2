@echo off
setlocal
cls

chcp 65001 >nul
git log --graph --oneline --all --decorate
git status

endlocal