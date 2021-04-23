#include "../private/includes.h"
#include "Vec3.h"

Vec3 Add(Vec3 a, Vec3 b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;

    return r;
}


void RotateZ(Vec3* vec, float radians)
{
	float x = cosf(radians) * vec->x - sinf(radians) * vec->y;
	float y = sinf(radians) * vec->x + cosf(radians) * vec->y;

    vec->x = x;
    vec->y = y;
}

void RotateX(Vec3* vec, float radians)
{
	float y = cosf(radians) * vec->y - sinf(radians) * vec->z;
	float z = sinf(radians) * vec->y + cosf(radians) * vec->z;

    vec->z = z;
    vec->y = y;
}

void RotateY(Vec3* vec, float radians)
{
	float z = cosf(radians) * vec->z - sinf(radians) * vec->x;
	float x = sinf(radians) * vec->z + cosf(radians) * vec->x;

    vec->x = x;
    vec->z = z;
}
