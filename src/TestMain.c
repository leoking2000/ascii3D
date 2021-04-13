#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{

    static Vec3 p1 = {  10.0f, 10.0f, 1.0f};
    static Vec3 p2 = { -10.0f, 10.0f, 1.0f};
    static Vec3 p3 = {  10.0f,-10.0f, 1.0f};
    static Vec3 p4 = { -10.0f,-10.0f, 1.0f};

    DrawFilledTriangle2D(canvas, p1, p2, p3, 254);
    DrawFilledTriangle2D(canvas, p2, p4, p3, 254);

    RotateZ(&p1, 0.1f);
    RotateZ(&p2, 0.1f);
    RotateZ(&p3, 0.1f);
    RotateZ(&p4, 0.1f);

    return TRUE;
}

int main()
{
    char bg = ' ';
    Canvas canvas = CreateCanvas(100, 60, bg);
    StartEngine(&canvas, update, bg);

    return 0;
}