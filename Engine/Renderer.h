#pragma once
#include "Canvas.h"
#include <stdio.h>

// define function to render into a canvas

void FillCanvas(Canvas *p_canvas, char c)
{
    memset(p_canvas->_data, c,p_canvas->width * p_canvas->height * sizeof(char));
}

void DrawLine(int x0, int y0, int x1, int x2, char x)
{

}

void Display(Canvas *p_canvas)
{
    system("clear"); // NOTE: only for linux in win is system("clr");

    for(int y = 0; y < p_canvas->height; ++y)
    {
        for(int x = 0; x < p_canvas->width; ++x)
        {
            char c = GetPixel(p_canvas, x, y);
            printf("%c",c);
        }
        printf("\n");
    }

}
