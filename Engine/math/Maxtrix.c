#include "Matrix.h"
#include <math.h>
#include <string.h>

Matrix ProjectionMatrix(int width, int height)
{
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 1.57079633f; // 90 deg
    float fAspectRatio = (float)height / (float)width;
    float fFovTan = 1.0f / tanf(fFov);

    Matrix mat;
    memset(&mat, 0.0f, sizeof(Matrix));

    mat.m[0][0] = fAspectRatio * fFovTan;
    mat.m[1][1] = fFovTan;
    mat.m[2][2] = fFar / (fFar - fNear);
    mat.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    mat.m[2][3] = 1.0f;
    mat.m[3][3] = 0.0f;

    return mat;
}

Vec3 Mull(Matrix mat, Vec3 v)
{
    Vec3 out;
    out.x   = v.x * mat.m[0][0] + v.y * mat.m[1][0] + v.z * mat.m[2][0] + mat.m[3][0];
    out.y   = v.x * mat.m[0][1] + v.y * mat.m[1][1] + v.z * mat.m[2][1] + mat.m[3][1];
    out.z   = v.x * mat.m[0][2] + v.y * mat.m[1][2] + v.z * mat.m[2][2] + mat.m[3][2];
    float w = v.x * mat.m[0][3] + v.y * mat.m[1][3] + v.z * mat.m[2][3] + mat.m[3][3];

    if(w != 0)
    {
        out.x /= w;
        out.y /= w;
        out.z /= w;
    }

    return out;
}