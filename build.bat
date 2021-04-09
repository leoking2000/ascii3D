@echo off

gcc -Wall src/TestMain.c -o bin/win_exe
cd bin
win_exe
