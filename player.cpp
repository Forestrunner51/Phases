#include "player.h"

void Player::Update()
{

    if (IsKeyDown(KEY_A)) position.x -= Speed;
    if (IsKeyDown(KEY_D)) position.x += Speed;
    if (IsKeyDown(KEY_W)) position.y -= Speed;
    if (IsKeyDown(KEY_S)) position.y += Speed;
}

void Player::Draw() const
{
    DrawCircleV(position,Radius, GREEN);
}
