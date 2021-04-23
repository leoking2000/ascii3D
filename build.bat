@echo off

gcc -Wall src/TestMain.c Engine/public/Engine.c Engine/private/Canvas.c Engine/private/Renderer.c Engine/math/Vec3.c Engine/math/Maxtrix.c Engine/math/mesh.c -o bin/win_exe
cd bin
win_exe
