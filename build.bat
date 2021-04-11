@echo off

gcc -Wall src/TestMain.c Engine/Canvas.c -o bin/win_exe
cd bin
win_exe
