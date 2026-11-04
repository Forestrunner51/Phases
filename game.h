#pragma once
#include "raylib.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"

class Game
{
    public:
        void Run();
    private:
        static constexpr int ScreenWidth = 800;
        static constexpr int ScreenHeight = 600;
        static constexpr int MaxBullets = 100;
        static constexpr float FireDelay = 0.2f;   // seconds between shots
        Player player;
        Enemy enemy;
        Bullet bullets[MaxBullets];
        float fireCooldown = 0.0f;

        bool collision = false;

        void Init();
        void Update(float dt);
        void Draw();
        void Shoot();
};
