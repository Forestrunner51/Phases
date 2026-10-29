#pragma once
#include "raylib.h"

struct Bullet
{
    Vector2 position = {0,0};
    float angle = 0.0f;
    bool active = false;

    void Update();
    void Draw() const;
};
