#pragma once
#include "Vec3.h"

typedef struct Matrix
{
    float m[4][4];

} Matrix;

Matrix ProjectionMatrix(int width, int height);

Vec3 Mull(Matrix mat, Vec3 v);


