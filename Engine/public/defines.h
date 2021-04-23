#pragma once
#include "../math/mesh.h"
#include "../math/Matrix.h"

#define TRUE 1
#define FALSE 0
#define BOOL unsigned char

#define swap(T, x, y) \
    {                 \
        T tmp = x;    \
        x = y;        \
        y = tmp;}

typedef struct Transform
{
    Vec3 pos;
    Vec3 rot;
    Vec3 scale;
} Transform;

typedef struct GameObject
{
    Transform transform;
    Mesh mesh;
} GameObject;
