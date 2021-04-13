#pragma once
#include "Renderer.h"


void StartEngine(Canvas* canvas, BOOL (*mainloop)(Canvas* canvas), char c)
{
    BOOL run = TRUE;

    while(run)
    {
        FillCanvas(canvas, c);
        run = mainloop(canvas);
        Display(canvas);

        printf("\nType the letter e to exit or ender to continie\n");
        printf(">>> ");
        if(getchar() == 'e')
        {
            run = FALSE;
        }
    }

    DestroyCanvas(canvas);
}

