#include "player.h"
#include "game.h"
void Player::Update()
{

    if (IsKeyDown(KEY_A) && position.x > Radius) position.x -= Speed;
    if (IsKeyDown(KEY_D) && position.x < GetScreenWidth() - Radius) position.x += Speed;
    if (IsKeyDown(KEY_W) && position.y >Radius) position.y -= Speed;
    if (IsKeyDown(KEY_S) && position.y < GetScreenHeight() - Radius) position.y += Speed;
}

void Player::Draw() const
{

  DrawCircleV(position,Radius, GREEN);
}
