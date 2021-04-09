#pragma once
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

void RotateZ(Vec3* vec, float radians)
{
	float x = cosf(radians) * vec->x - sinf(radians) * vec->y;
	float y = sinf(radians) * vec->x + cosf(radians) * vec->y;

    vec->x = x;
    vec->y = -y;
}
