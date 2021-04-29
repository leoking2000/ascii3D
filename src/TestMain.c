#include "../Engine/public/Engine.h"

void update()
{
    static float z = 0.1f;

    GameObject* obj = (GameObject*)GetUserData();
    obj->transform.rot.z += z;
    obj->transform.pos.z += z;

    if(obj->transform.pos.z > 2.5f || obj->transform.pos.z <= 1.0f) z *= -1.0f;

    Render((GameObject*)GetUserData());
}

int main()
{
    InitializeEngine(100, 100, ' ');
    SetUpdateCallback(update);

    GameObject cube;
    cube.transform.pos = (Vec3){0.0f, 0.0f, 1.5f};
    cube.transform.rot = (Vec3){-1.0f, 1.0f, 0.0f};
    cube.transform.scale = (Vec3){1.0f, 1.0f, 1.0f};
    cube.mesh = CreateCube();

    SetUserData(&cube);

    StartEngine();

    DestroyMesh(&cube.mesh);

    return 0;
}