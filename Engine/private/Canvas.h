#pragma once
#include "includes.h"

typedef struct
{
    int width;
    int height;
    char* _data;
} Canvas;

void putPixel(Canvas *p_canvas, int x, int y, char c);

char getPixel(Canvas *p_canvas, int x, int y);

void FillCanvas(Canvas *p_canvas, char c);

void Display(Canvas *p_canvas);

Canvas CreateCanvas(int width, int height, char fill);

void DestroyCanvas(Canvas *p_canvas);