#pragma once
#include "defines.h"

// Initialition

void InitializeEngine(int width, int height, char bg);

void SetInitCallback(void(*init)());
void SetUpdateCallback(void(*update)(float dt));
void SetDrawCallback(void(*draw)());

void  SetUserData(void* data);
void* GetUserData();

void StartEngine();

// rendering

void Render(const GameObject* obj);

