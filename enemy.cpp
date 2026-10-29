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

void Enemy::Draw() const
{
    DrawTexxtureV(texture, position, WHITE);
}
