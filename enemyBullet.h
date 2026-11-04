#pragma once
#include "raylib.h"

struct EnemyBullet
{
    Vector2 Eposition = {0,0};
    float angle = 0.0f;
    bool active = false;

    void Update();
    void Draw() const;
};
