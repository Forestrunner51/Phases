#include "raylib.h"
#include <stdlib.h>
#include <math.h>
#include "iostream"

#define MAX_BULLETS 100

typedef struct{
    Vector2 position;
    bool active;
    float angle;
} Bullet;

int main()
{
    InitWindow(800, 600, "Pong");
    SetTargetFPS(60);


    Bullet bullets[MAX_BULLETS];
    for (int i = 0; i < MAX_BULLETS; i++){
        bullets[i].active = false;
    }

    Vector2 playerPos = {400, 240};
        float fireCooldown = 0.0f;
    int speed = 5;
    Texture2D texture = LoadTexture("enemy.png");
    Texture2D Tarray[1]{texture};

    while (!WindowShouldClose())
    {

        for (int i = 0; i < MAX_BULLETS; i++ ){
            if (bullets[i].active){
                bullets[i].position.x += cos(bullets[i].angle) * 5.0f;
                bullets[i].position.y += sin(bullets[i].angle) * 5.0f;

            if (bullets[i].position.x < -50 || bullets[i].position.x > 850 ||
                bullets[i].position.y < -50 || bullets[i].position.y > 500){
                bullets[i].active = false;
                }
            }
        }
        fireCooldown -= GetFrameTime();   // count down by how much time passed this fra
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)&& fireCooldown <=0.0f){
             fireCooldown = 0.2f;          // wait 0.2 seconds before the next shot
            for (int i = 0; i < MAX_BULLETS; i ++){
                if (!bullets[i].active){
                    Vector2 mouse = GetMousePosition();
                    bullets[i].active = true;
                    bullets[i].position = playerPos;
                    bullets[i].angle = atan2f(mouse.y - playerPos.y, mouse.x - playerPos.x);
                    break;
                }
            }
        }
        if (IsKeyDown(KEY_A)) playerPos.x -= speed;
        if (IsKeyDown(KEY_D)) playerPos.x += speed;
        if (IsKeyDown(KEY_W)) playerPos.y -= speed;
        if (IsKeyDown(KEY_S)) playerPos.y += speed;



        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib is working!", 12, 12, 20, BLACK);

        for (int i = 0; i < MAX_BULLETS; i++){
            if (bullets[i].active){
                DrawCircleV(bullets[i].position,5.0f,RED);
            }
        }

        DrawCircleV(playerPos, 30, GREEN);
        EndDrawing();

    }
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
