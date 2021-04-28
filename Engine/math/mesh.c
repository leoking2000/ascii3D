#include "mesh.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

Mesh CreateMesh(const char* filename)
{
    Mesh a;
    return a;
}
/*
Mesh CreateCube()
{
    Mesh cube;

    cube.vcount = 8;
    cube.vertex_buffer = (Vertex*)malloc(sizeof(Vertex) * 8);
    cube.vertex_buffer[0] = (Vertex){{-0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[1] = (Vertex){{-0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[2] = (Vertex){{ 0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[3] = (Vertex){{ 0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[4] = (Vertex){{ 0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[5] = (Vertex){{ 0.5f,-0.5f,  0.5}};
    cube.vertex_buffer[6] = (Vertex){{-0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[7] = (Vertex){{-0.5f,-0.5f,  0.5}};

    cube.icount = 36;
    cube.index_buffer = (unsigned int*)malloc(sizeof(unsigned int*) * 36);
    // NORTH
    cube.index_buffer[0] = 1;
    cube.index_buffer[1] = 6;
    cube.index_buffer[2] = 4;

    cube.index_buffer[3] = 1;
    cube.index_buffer[4] = 4;
    cube.index_buffer[5] = 2;

    // SOUTH
    cube.index_buffer[6] = 5;
    cube.index_buffer[7] = 7;
    cube.index_buffer[8] = 0;

    cube.index_buffer[9]  = 5;
    cube.index_buffer[10] = 0;
    cube.index_buffer[11] = 3;

    // WEST
    cube.index_buffer[12] = 7;
    cube.index_buffer[13] = 6;
    cube.index_buffer[14] = 1;

    cube.index_buffer[15] = 7;
    cube.index_buffer[16] = 1;
    cube.index_buffer[17] = 0;

    // EAST
    cube.index_buffer[18] = 3;
    cube.index_buffer[19] = 2;
    cube.index_buffer[20] = 4;

    cube.index_buffer[21] = 3;
    cube.index_buffer[22] = 4;
    cube.index_buffer[23] = 5;

    // FORWARD
    cube.index_buffer[24] = 5;
    cube.index_buffer[25] = 4;
    cube.index_buffer[26] = 6;

    cube.index_buffer[27] = 5;
    cube.index_buffer[28] = 6;
    cube.index_buffer[29] = 7;

    // BACK
    cube.index_buffer[30] = 0;
    cube.index_buffer[31] = 1;
    cube.index_buffer[32] = 2;

    cube.index_buffer[33] = 0;
    cube.index_buffer[34] = 2;
    cube.index_buffer[35] = 3;

    return cube;
}
*/

Mesh CreateCube()
{
    Mesh cube;

    cube.vcount = 8;
    cube.vertex_buffer = (Vertex*)malloc(sizeof(Vertex) * 8);
    cube.vertex_buffer[0] = (Vertex){{-0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[1] = (Vertex){{-0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[2] = (Vertex){{ 0.5f, 0.5f, -0.5}};
    cube.vertex_buffer[3] = (Vertex){{ 0.5f,-0.5f, -0.5}};
    cube.vertex_buffer[4] = (Vertex){{ 0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[5] = (Vertex){{ 0.5f,-0.5f,  0.5}};
    cube.vertex_buffer[6] = (Vertex){{-0.5f, 0.5f,  0.5}};
    cube.vertex_buffer[7] = (Vertex){{-0.5f,-0.5f,  0.5}};

    cube.icount = 24;
    cube.index_buffer = (unsigned int*)malloc(sizeof(unsigned int*) * cube.icount);

    cube.index_buffer[0] = 1;
    cube.index_buffer[1] = 2;

    cube.index_buffer[2] = 2;
    cube.index_buffer[3] = 4;

    cube.index_buffer[4] = 4;
    cube.index_buffer[5] = 6;

    cube.index_buffer[6] = 6;
    cube.index_buffer[7] = 1;


    cube.index_buffer[8] = 6;
    cube.index_buffer[9]  = 7;

    cube.index_buffer[10] = 1;
    cube.index_buffer[11] = 0;

    cube.index_buffer[12] = 2;
    cube.index_buffer[13] = 3;

    cube.index_buffer[14] = 4;
    cube.index_buffer[15] = 5;


    cube.index_buffer[16] = 7;
    cube.index_buffer[17] = 0;

    cube.index_buffer[18] = 0;
    cube.index_buffer[19] = 3;

    cube.index_buffer[20] = 3;
    cube.index_buffer[21] = 5;

    cube.index_buffer[22] = 5;
    cube.index_buffer[23] = 7;

    return cube;
}

void DestroyMesh(Mesh* mesh)
{
    free(mesh->vertex_buffer);
    free(mesh->index_buffer);
}