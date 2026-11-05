#pragma once
#include "raylib.h"

class Enemy
{
    public:
        Vector2 EnemyPosition = {600,150};
        bool present = false;
        bool movingRight = true;
        float enemySpeed = 200.0f;

        void Load();
        void Unload();
        void Update();
        void EShoot();
        void Draw() const;
    private:
        Texture2D texture = {};
};
