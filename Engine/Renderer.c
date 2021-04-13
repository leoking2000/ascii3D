#include "Renderer.h"
// define function to render into a canvas

void WorldToScren(Canvas *canvas, Vec3* p)
{
	p->y = - p->y;
	p->x = p->x + canvas->width / 2;
	p->y = p->y + canvas->height / 2;
}

// 2D rendering
void DrawLine2D(Canvas *canvas, Vec3 p0, Vec3 p1, char c)
{
	WorldToScren(canvas, &p0);
	WorldToScren(canvas, &p1);

    float dy = (p1.y - p0.y);
	float dx = (p1.x - p0.x);
	float steps = fmaxf(abs(dy), abs(dx));

	float x_inclese = dx / steps;
	float y_inclese = dy / steps;

	float x = p0.x;
	float y = p0.y;
	for (int i = 0; i < steps; ++i)
	{
		x += x_inclese;
		y += y_inclese;
		if (x >= 0.0f && x < canvas->width && y >= 0.0f && y < canvas->height)
		{
			putPixel(canvas, (int)x, (int)y, c);
		}
	}
}

void DrawWireframeTriangle2D(Canvas *canvas, Vec3 p1, Vec3 p2, Vec3 p3, char c)
{
    DrawLine2D(canvas, p1, p2, c);
    DrawLine2D(canvas, p2, p3, c);
    DrawLine2D(canvas, p3, p1, c);
}

void topFlatTri(Canvas *canvas, Vec3 p0, Vec3 p1, Vec3 p2, char c)
{
    float m0 = (p2.x - p0.x) / (p2.y - p0.y);
    float m1 = (p2.x - p1.x) / (p2.y - p1.y);

    int ystart = (int)ceil(p0.y - 0.5);
    int yend   = (int)ceil(p2.y - 0.5);

    for(int y = ystart; y < yend; ++y)
    {
        float px0 = m0 * ((float)y + 0.5f - p0.y ) + p0.x;
        float px1 = m1 * ((float)y + 0.5f - p1.y ) + p1.x;
        int xstart = (int)ceil(px0 - 0.5f);
        int xend   = (int)ceil(px1 - 0.5f);

        for(int x = xstart; x < xend; ++x)
        {
            putPixel(canvas, x, y, c);
        }

    }
}

void bottomFlatTri(Canvas *canvas, Vec3 p0, Vec3 p1, Vec3 p2, char c)
{
    float m0 = (p1.x - p0.x) / (p1.y - p0.y);
    float m1 = (p2.x - p0.x) / (p2.y - p0.y);

    int ystart = (int)ceil(p0.y - 0.5);
    int yend   = (int)ceil(p2.y - 0.5);

    for(int y = ystart; y < yend; ++y)
    {
        float px0 = m0 * ((float)y + 0.5f - p0.y ) + p0.x;
        float px1 = m1 * ((float)y + 0.5f - p0.y ) + p0.x;
        int xstart = (int)ceil(px0 - 0.5f);
        int xend   = (int)ceil(px1 - 0.5f);

        for(int x = xstart; x < xend; ++x)
        {
            putPixel(canvas, x, y, c);
        }

    }
}

void DrawFilledTriangle2D(Canvas *canvas, Vec3 p0, Vec3 p1, Vec3 p2, char c)
{
    WorldToScren(canvas, &p0);
    WorldToScren(canvas, &p1);
    WorldToScren(canvas, &p2);

    if (p1.y < p0.y) { swap(Vec3, p1, p0) }
    if (p2.y < p0.y) { swap(Vec3, p2, p0) }
    if (p2.y < p1.y) { swap(Vec3, p2, p1) }

    if(p0.y == p1.y) // top flat
    {
        if(p1.x < p0.x) { swap(Vec3, p1, p0) }
        topFlatTri(canvas, p0, p1, p2, c);
    }
    else if(p1.y == p2.y) // botton flat
    {
        if(p2.x < p1.x) { swap(Vec3, p2, p1) }
        bottomFlatTri(canvas, p0, p1, p2, c);
    }
    else // generic
    {
        float alphaSplit = 
            (p1.y - p0.y) /
            (p2.y - p0.y);
        Vec3 vi;
        vi.x = p0.x + (p2.x - p0.x) * alphaSplit;
        vi.y = p0.y + (p2.y - p0.y) * alphaSplit;

        if(p1.x < vi.x) // major right
        {
            bottomFlatTri(canvas, p0, p1, vi, c);
            topFlatTri(canvas, p1, vi, p2, c);
        }
        else // major left
        {
            bottomFlatTri(canvas, p0, vi, p1, c);
            topFlatTri(canvas, vi, p1, p2, c);
        }
    }
}


// 3D rendering