#include "../Engine/public/Engine.h"

void update(char in)
{
    static float offset = 0.1f;

    GameObject* obj = (GameObject*)GetUserData();

    switch (in)
    {
    case 'x':
        obj->transform.rot.x += offset;
        break;
    case 'X':
        obj->transform.rot.x -= offset;
        break;
    case 'y':
        obj->transform.rot.y += offset;
        break;
    case 'Y':
        obj->transform.rot.y -= offset;
        break;
    case 'z':
        obj->transform.rot.z += offset;
        break;
    case 'Z':
        obj->transform.rot.z -= offset;
        break;
    default:
        break;
    }


    Render((GameObject*)GetUserData());
}

int main()
{
    InitializeEngine(100, 100, ' ');
    SetUpdateCallback(update);

    GameObject cube;
    cube.transform.pos = (Vec3){0.0f, 0.0f, 1.3f};
    cube.transform.rot = (Vec3){0.0f, 0.0f, 0.0f};
    cube.transform.scale = (Vec3){1.0f, 1.0f, 1.0f};
    cube.mesh = CreateCube();

    SetUserData(&cube);

    StartEngine();

    DestroyMesh(&cube.mesh);

    return 0;
}