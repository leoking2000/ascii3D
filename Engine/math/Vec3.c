#include "../private/includes.h"
#include "Vec3.h"

Vec3 Add(Vec3 a, Vec3 b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;

    return r;
}

Vec3 Sub(Vec3 a, Vec3 b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;

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

void Normalize(Vec3* a)
{
    float len = sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);

    a->x /= len;
    a->y /= len;
    a->z /= len;
}

float Dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Cross(Vec3 a, Vec3 b)
{
    Vec3 out;

    out.x = a.y * b.z - a.z * b.y;
    out.y = a.z * b.x - a.x * b.z;
    out.z = a.x * b.y - a.y * b.x;

    return out;
}
