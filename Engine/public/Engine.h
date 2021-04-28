#pragma once
#include "defines.h"

// Initialition

void InitializeEngine(int width, int height, char bg);

void SetUpdateCallback(void(*update)());

void  SetUserData(void* data);
void* GetUserData();

void StartEngine();

// rendering

void Render(const GameObject* obj);

