#include "../Engine/public/Engine.h"

void setup()
{

}

void update(float dt)
{
    GameObject* obj = (GameObject*)GetUserData();
    obj->transform.rot.z += 0.1f;
}

void draw()
{
    Render((GameObject*)GetUserData());
}

int main()
{
    InitializeEngine(100, 100, ' ');
    SetInitCallback(setup);
    SetUpdateCallback(update);
    SetDrawCallback(draw);

    GameObject cube;
    cube.transform.pos = (Vec3){0.0f, 0.0f, 1.0f};
    cube.transform.rot = (Vec3){-1.0f, 1.0f, 0.0f};
    cube.transform.scale = (Vec3){1.0f, 1.0f, 1.0f};
    cube.mesh = CreateCube();

    SetUserData(&cube);

    StartEngine();

    DestroyMesh(&cube.mesh);

    return 0;
}