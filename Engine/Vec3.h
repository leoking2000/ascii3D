#pragma once

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

void RotateZ(Vec3* vec, float radians);
