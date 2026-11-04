#include "bullet.h"
#include <math.h>
#include <raylib.h>

void Bullet::Update()
{
    if(!active) return;

    position.x += cosf(angle) * 5.0f;
    position.y += sinf(angle) * 5.0f;

    if (position.x < -50 || position.x > GetScreenWidth() + 50 ||
        position.y < -50 || position.y > GetScreenHeight() + 50)
    {
        active = false;
    }
}

void Bullet::Draw() const
{
    DrawCircleV(position, 6.0f, BLUE);
    if (active) DrawCircleV(position, 5.0f, RED);
}
