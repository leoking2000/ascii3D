#include "../Engine/Engine.h"

BOOL update(Canvas* canvas)
{
    static float x = 50;
    static float y = 20;

    PutPixel(canvas, (int)x    , (int)y    , '#');
    PutPixel(canvas, (int)x    , (int)y + 1, '#');
    PutPixel(canvas, (int)x + 1, (int)y    , '#');
    PutPixel(canvas, (int)x + 1, (int)y + 1, '#');

    x = x + 1.0f;
    if((int)x >= canvas->width - 1) x = 0.0f;

    return TRUE;
}

int main()
{
    Canvas canvas = CreateCanvas(160, 40, ' ');

    StartEngine(&canvas, update);

    return 0;
}