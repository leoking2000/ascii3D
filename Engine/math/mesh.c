#include "mesh.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

Mesh CreateMesh(const char* filename)
{
    Mesh a;
    return a;
}

Mesh CreateCube()
{
    Mesh cube;

    cube.vcount = 8;
    cube.vertex_buffer = (Vertex*)malloc(sizeof(Vertex) * 8);
    cube.vertex_buffer[0] = (Vertex){{-0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[1] = (Vertex){{ 0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[2] = (Vertex){{ 0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[3] = (Vertex){{-0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[4] = (Vertex){{-0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[5] = (Vertex){{ 0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[6] = (Vertex){{ 0.5f,-0.5f,  0.5}};
    cube.vertex_buffer[7] = (Vertex){{-0.5f,-0.5f,  0.5}};

    cube.icount = 36;
    cube.index_buffer = (unsigned int*)malloc(sizeof(unsigned int*) * 36);
    // NORTH
    cube.index_buffer[0] = 0;
    cube.index_buffer[1] = 1;
    cube.index_buffer[2] = 3;

    cube.index_buffer[3] = 1;
    cube.index_buffer[4] = 2;
    cube.index_buffer[5] = 3;

    // SOUTH
    cube.index_buffer[6] = 4;
    cube.index_buffer[7] = 5;
    cube.index_buffer[8] = 7;

    cube.index_buffer[9] = 5;
    cube.index_buffer[10] = 6;
    cube.index_buffer[11] = 7;

    // WEST
    cube.index_buffer[12] = 1;
    cube.index_buffer[13] = 5;
    cube.index_buffer[14] = 2;

    cube.index_buffer[15] = 5;
    cube.index_buffer[16] = 6;
    cube.index_buffer[17] = 2;

    // EAST
    cube.index_buffer[18] = 0;
    cube.index_buffer[19] = 4;
    cube.index_buffer[20] = 3;

    cube.index_buffer[21] = 4;
    cube.index_buffer[22] = 7;
    cube.index_buffer[23] = 3;

    // FORWARD
    cube.index_buffer[24] = 3;
    cube.index_buffer[25] = 7;
    cube.index_buffer[26] = 6;

    cube.index_buffer[27] = 3;
    cube.index_buffer[28] = 6;
    cube.index_buffer[29] = 2;

    // BACK
    cube.index_buffer[30] = 0;
    cube.index_buffer[31] = 4;
    cube.index_buffer[32] = 1;

    cube.index_buffer[33] = 4;
    cube.index_buffer[34] = 5;
    cube.index_buffer[35] = 1;

    return cube;
}

void DestroyMesh(Mesh* mesh)
{
    free(mesh->vertex_buffer);
    free(mesh->index_buffer);
}