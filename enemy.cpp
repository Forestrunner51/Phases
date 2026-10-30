#include "enemy.h"
#include "raylib.h"

void Enemy::Load()
{
    texture = LoadTexture("enemy.png");
}

void Enemy::Unload()
{
    UnloadTexture(texture);
}

void Enemy::Update()
{
if ((present = false)){
    EnemyPosition.x += 5.0f;
}
}

void Enemy::Draw() const
{
    DrawTextureV(texture, EnemyPosition, WHITE);
}
