#include "Canvas.h"

void putPixel(Canvas *p_canvas, int x, int y, char c)
{
    assert(x >= 0);
    assert(x < p_canvas->width);
    assert(y >= 0);
    assert(y < p_canvas->height);

    p_canvas->_data[y * p_canvas->width + x] = c;
}

char getPixel(Canvas *p_canvas, int x, int y)
{
    assert(x >= 0);
    assert(x < p_canvas->width);
    assert(y >= 0);
    assert(y < p_canvas->height);

    return p_canvas->_data[y * p_canvas->width + x];
}

void FillCanvas(Canvas *p_canvas, char c)
{
    memset(p_canvas->_data, c,p_canvas->width * p_canvas->height * sizeof(char));
}

void Display(Canvas *p_canvas)
{
    system("clear"); // NOTE: for linux system("clear"); in win is system("cls");

    for(int y = 0; y < p_canvas->height; ++y)
    {
        for(int x = 0; x < p_canvas->width; ++x)
        {
            char c = getPixel(p_canvas, x, y);
            printf("%c",c);
        }
        printf("\n");
    }

}

Canvas CreateCanvas(int width, int height, char fill)
{
    assert(width > 0);
    assert(height > 0);

    Canvas new_canvas;
    new_canvas.width = width;
    new_canvas.height = height;
    new_canvas._data = (char*)malloc(width*height*sizeof(char));

    assert(new_canvas._data != NULL);

    memset(new_canvas._data, fill,width*height*sizeof(char));

    return new_canvas;
}

void DestroyCanvas(Canvas *p_canvas)
{
    assert(p_canvas->_data != NULL);

    p_canvas->width = 0;
    p_canvas->height = 0;
    free(p_canvas->_data);
    p_canvas->_data = NULL;
}