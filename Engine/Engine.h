#pragma once
#include "Renderer.h"


void StartEngine(Canvas* canvas, BOOL (*mainloop)(Canvas* canvas))
{
    BOOL run = TRUE;

    while(run)
    {
        FillCanvas(canvas, ' ');
        run = mainloop(canvas);
        Display(canvas);
    }

    DestroyCanvas(canvas);
}

