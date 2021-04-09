#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{

    static Vec3 p1 = {  15.0f, 10.0f, 1.0f};
    static Vec3 p2 = { -15.0f, 10.0f, 1.0f};
    static Vec3 p3 = {  15.0f,-10.0f, 1.0f};
    static Vec3 p4 = { -15.0f,-10.0f, 1.0f};

    DrawWireframeTriangle2D(canvas, p1, p2, p3, '*');
    DrawWireframeTriangle2D(canvas, p2, p4, p3, '*');

    RotateZ(&p1, 0.1f);
    RotateZ(&p2, 0.1f);
    RotateZ(&p3, 0.1f);
    RotateZ(&p4, 0.1f);

    return TRUE;
}

int main()
{
    Canvas canvas = CreateCanvas(160, 60, ' ');
    StartEngine(&canvas, update);

    return 0;
}