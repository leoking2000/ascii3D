#pragma once
#include "Vec3.h"

typedef struct Vertex
{
    Vec3 pos;

} Vertex;

typedef struct Mesh
{
    Vertex* vertex_buffer;
    unsigned int vcount;

    unsigned int* index_buffer;
    unsigned int icount;
} Mesh;

Mesh CreateMesh(const char* filename);

Mesh CreateCube();

void DestroyMesh(Mesh* mesh);