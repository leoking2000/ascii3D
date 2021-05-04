gcc -Wall src/TestMain.c Engine/public/Engine.c Engine/private/Canvas.c Engine/private/Renderer.c Engine/math/Vec3.c Engine/math/Maxtrix.c Engine/math/mesh.c -o bin/linux_exe -lm
cd bin
./linux_exe
