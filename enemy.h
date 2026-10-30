#pragma once
#include "raylib.h"

class Enemy
{
    public:
        Vector2 EnemyPosition = {600,150};
        bool present = false;

        void Load();
        void Unload();
        void Update();
        void Draw() const;
    private:
        Texture2D texture = {};
};
