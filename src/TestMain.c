#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{
    static Vec3 p0 = {  -5.0f,  5.0f, 1.0f};
    static Vec3 p1 = {   0.0f,  29.0f, 1.0f};
    static Vec3 p2 = {   5.0f,   5.0f, 1.0f};
    static Vec3 p3 = {  29.0f,   0.0f, 1.0f};
    static Vec3 p4 = {   5.0f,  -5.0f, 1.0f};
    static Vec3 p5 = {   0.0f, -29.0f, 1.0f};
    static Vec3 p6 = {  -5.0f,  -5.0f, 1.0f};
    static Vec3 p7 = { -29.0f,   0.0f, 1.0f};

    DrawFilledTriangle2D(canvas, p0, p1, p2, 254);
    DrawFilledTriangle2D(canvas, p0, p2, p4, 'H');
    DrawFilledTriangle2D(canvas, p2, p3, p4, 'Y');
    DrawFilledTriangle2D(canvas, p0, p6, p4, 'J');
    DrawFilledTriangle2D(canvas, p6, p4, p5, 'n');
    DrawFilledTriangle2D(canvas, p0, p6, p7, 'g');

    RotateZ(&p0, 0.1f);
    RotateZ(&p1, 0.1f);
    RotateZ(&p2, 0.1f);
    RotateZ(&p3, 0.1f);
    RotateZ(&p4, 0.1f);
    RotateZ(&p5, 0.1f);
    RotateZ(&p6, 0.1f);
    RotateZ(&p7, 0.1f);

    return TRUE;
}

int main()
{
    char bg = ' ';
    Canvas canvas = CreateCanvas(100, 60, bg);
    StartEngine(&canvas, update, bg);

    return 0;
}