#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{
    Vec3 p1 = { 80.0f,  5.0f, 1.0f};
    Vec3 p2 = { 40.0f, 30.0f, 1.0f};
    Vec3 p3 = {120.0f, 30.0f, 1.0f};

    DrawWireframeTriangle2D(canvas, p1, p2, p3, '*');
    return TRUE;
}

int main()
{
    Canvas canvas = CreateCanvas(160, 40, ' ');
    StartEngine(&canvas, update);

    return 0;
}