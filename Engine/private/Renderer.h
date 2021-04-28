#pragma once
#include "Canvas.h"

// define function to render into a canvas

void NDC_To_CancasSpace(Canvas *canvas, Vec3* p);

// 2D rendering
void DrawLine2D(Canvas *canvas, Vec3 p0, Vec3 p1, char c);

void DrawWireframeTriangle2D(Canvas *canvas, Vec3 p1, Vec3 p2, Vec3 p3, char c);

void DrawFilledTriangle2D(Canvas *canvas, Vec3 p0, Vec3 p1, Vec3 p2, char c);

// 3D rendering
