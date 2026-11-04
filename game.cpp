#include "game.h"
#include <math.h>
#include <raylib.h>

void Game::Run()
{
    Init();

    while (!WindowShouldClose())
    {

        Update(GetFrameTime());
        Draw();

    }

    enemy.Unload();
    CloseWindow();
}

void Game::Init()
{
    InitWindow(ScreenWidth,ScreenHeight,"Pong");
    SetTargetFPS(60);

    enemy.Load();
}

void Game::Update(float dt)
{
    for (int i = 0; i < MaxBullets; i++)
        {
            bullets[i].Update();
        }
    fireCooldown -= dt;
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && fireCooldown<= 0.0f)
    {
        fireCooldown = FireDelay;
        Shoot();
    }

    //collision = CheckCollisionCircleRec();
    player.Update();
}

void Game::Shoot()
{
    for(int i = 0; i < MaxBullets; i++)
    {
        if (!bullets[i].active)
        {
            Vector2 mouse = GetMousePosition();
            bullets[i].active = true;
            bullets[i].position = player.position;
            bullets[i].angle = atan2f(mouse.y - player.position.y, mouse.x - player.position.x);
            break;
        }
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Raylib is working!", 12, 12 ,20, BLACK);

    for (int i = 0; i < MaxBullets; i++)
    {
        bullets[i].Draw();
    }

    enemy.Draw();
    enemy.Update();
    player.Draw();

    EndDrawing();
}
