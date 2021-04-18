gcc -Wall src/TestMain.c Engine/Canvas.c Engine/Renderer.c Engine/Vec3.c -o bin/linux_exe -lm
cd bin
./linux_exe
