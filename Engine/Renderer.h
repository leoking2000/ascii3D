#pragma once
#include "Canvas.h"
#include "Vec3.h"

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

// 3D rendering
