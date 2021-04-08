#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{
    static float x = 50;
    static float y = 20;
    static float a = 0.0;

    PutPixel(canvas, (int)x    , (int)y    , '#');
    PutPixel(canvas, (int)x    , (int)y + 1, '#');
    PutPixel(canvas, (int)x + 1, (int)y    , '#');
    PutPixel(canvas, (int)x + 1, (int)y + 1, '#');

    x = x + 0.05f;
    if((int)x >= canvas->width) x = 0.0f;

    a = a + 0.01f;
    if(a > 15.0f) return FALSE;

    return TRUE;
}

int main()
{
    Canvas canvas = CreateCanvas(160, 40, ' ');

    StartEngine(&canvas, update);

    return 0;
}