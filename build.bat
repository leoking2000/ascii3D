@echo off

gcc -Wall src/TestMain.c Engine/Canvas.c Engine/Renderer.c Engine/Vec3.c -o bin/win_exe
cd bin
win_exe
