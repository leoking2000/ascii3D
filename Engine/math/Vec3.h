#pragma once

typedef struct {
    float x;
    float y;
    float z;
} Vec3;


Vec3 Add(Vec3 a, Vec3 b);
Vec3 Sub(Vec3 a, Vec3 b);

void RotateZ(Vec3* vec, float radians);
void RotateX(Vec3* vec, float radians);
void RotateY(Vec3* vec, float radians);

void Normalize(Vec3* a);

float Dot(Vec3 a, Vec3 b);
Vec3 Cross(Vec3 a, Vec3 b);
