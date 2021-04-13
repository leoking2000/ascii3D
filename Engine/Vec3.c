#include "Vec3.h"
#include <math.h>

void RotateZ(Vec3* vec, float radians)
{
	float x = cosf(radians) * vec->x - sinf(radians) * vec->y;
	float y = sinf(radians) * vec->x + cosf(radians) * vec->y;

    vec->x = x;
    vec->y = y;
}