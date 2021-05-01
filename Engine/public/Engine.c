#include "Engine.h"
#include "../private/Renderer.h"

typedef struct Engine
{
    Canvas canvas;
    char bg;

    void(*Update)(char in);

    void* userData;

} Engine;

static Engine engine;

void InitializeEngine(int width, int height, char bg)
{
    engine.canvas = CreateCanvas(width, height, bg);
    engine.bg = bg;
}

void SetUpdateCallback(void(*update)(char in))
{
    engine.Update = update;
}

void  SetUserData(void* data)
{
    engine.userData = data;
}
void* GetUserData()
{
    return engine.userData;
}

void StartEngine()
{
    BOOL run = TRUE;
    char input = 0;

    while(run)
    {
        FillCanvas(&engine.canvas, engine.bg);

        engine.Update(input);

        Display(&engine.canvas);

        printf("\nType the letter e to exit or ender to continie\n");
        printf(">>> ");
        input = getchar();
        if(input == 'e')
        {
            run = FALSE;
        }
    }

    DestroyCanvas(&engine.canvas);
}

void Render(const GameObject* obj)
{
    //Matrix proj = ProjectionMatrix(engine.canvas.width, engine.canvas.height);

    // copy transforme Vartex
    Vertex* proj_Vbuffer = (Vertex*)malloc(sizeof(Vertex) * obj->mesh.vcount);

    // Apply Tranformation of the obj
    for(unsigned int i = 0; i < obj->mesh.vcount; i++ )
    {
        proj_Vbuffer[i] = obj->mesh.vertex_buffer[i];

        // rotation
        RotateZ(&proj_Vbuffer[i].pos, obj->transform.rot.z);
        RotateX(&proj_Vbuffer[i].pos, obj->transform.rot.x);
        RotateY(&proj_Vbuffer[i].pos, obj->transform.rot.y);

        //scale
        proj_Vbuffer[i].pos.x *= obj->transform.scale.x;
        proj_Vbuffer[i].pos.y *= obj->transform.scale.y;
        proj_Vbuffer[i].pos.z *= obj->transform.scale.z;

        // translation
        proj_Vbuffer[i].pos = Add(proj_Vbuffer[i].pos, obj->transform.pos);

        //proj_Vbuffer[i].pos = Mull(proj, proj_Vbuffer[i].pos);

    }

    // draw lines
    for(unsigned int i = 0; i < obj->mesh.icount; i += 3)
    {
        unsigned int v0 = obj->mesh.index_buffer[i];
        unsigned int v1 = obj->mesh.index_buffer[i+1];
        unsigned int v2 = obj->mesh.index_buffer[i+2];

        Vec3 lineA = Add(proj_Vbuffer[v1].pos, proj_Vbuffer[v0].pos);
		Vec3 lineB = Add(proj_Vbuffer[v2].pos, proj_Vbuffer[v0].pos);
		Vec3 normal = Cross(lineA, lineB);
        Normalize(&normal);

		if (Dot(normal, proj_Vbuffer[v0].pos) > 0.0f) continue;

        //DrawFilledTriangle2D(&engine.canvas, proj_Vbuffer[v0].pos,
        //                                     proj_Vbuffer[v1].pos,
        //                                     proj_Vbuffer[v2].pos, c);

        DrawWireframeTriangle2D(&engine.canvas, proj_Vbuffer[v0].pos,
                                                proj_Vbuffer[v1].pos,
                                                proj_Vbuffer[v2].pos, '.');


    }


    free(proj_Vbuffer);
}