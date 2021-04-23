#include "Engine.h"
#include "../private/Renderer.h"

typedef struct Engine
{
    Canvas canvas;
    char bg;

    void(*Init)();
    void(*Update)(float dt);
    void(*Draw)();

    void* userData;

} Engine;

static Engine engine;

void InitializeEngine(int width, int height, char bg)
{
    engine.canvas = CreateCanvas(width, height, bg);
    engine.bg = bg;
}

void SetInitCallback(void(*init)())
{
    engine.Init = init;
}

void SetUpdateCallback(void(*update)(float dt))
{
    engine.Update = update;
}

void SetDrawCallback(void(*draw)())
{
    engine.Draw = draw;
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
    engine.Init();

    while(run)
    {
        FillCanvas(&engine.canvas, engine.bg);

        engine.Update(0.1f);
        engine.Draw();

        Display(&engine.canvas);

        printf("\nType the letter e to exit or ender to continie\n");
        printf(">>> ");
        if(getchar() == 'e')
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
    // translation and project.
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

        
        proj_Vbuffer[i].pos.x *= 0.5f * engine.canvas.width;
        proj_Vbuffer[i].pos.y *= 0.5f * engine.canvas.height;

        //proj_Vbuffer[i].pos = Mull(proj, proj_Vbuffer[i].pos);

    }

    // draw triangles
    for(unsigned int i = 0; i < obj->mesh.icount; i += 3)
    {
        unsigned int v1 = obj->mesh.index_buffer[i];
        unsigned int v2 = obj->mesh.index_buffer[i+1];
        unsigned int v3 = obj->mesh.index_buffer[i+2];

       //DrawFilledTriangle2D(&engine.canvas, proj_Vbuffer[v1].pos,
       //                                         proj_Vbuffer[v2].pos,
       //                                         proj_Vbuffer[v3].pos, 254);

       DrawWireframeTriangle2D(&engine.canvas, proj_Vbuffer[v1].pos,
                                               proj_Vbuffer[v2].pos,
                                               proj_Vbuffer[v3].pos, '.');
    }


    free(proj_Vbuffer);
}