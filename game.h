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
}
