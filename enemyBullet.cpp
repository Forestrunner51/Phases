#include "enemybullet.h"
#include <math.h>

void EnemyBullet::Update()
{
    if(!active) return;

    Eposition.x += cosf(angle) * 5.0f;
    Eposition.y += sinf(angle) * 5.0f;

    if (Eposition.x < -50 || Eposition.x > GetScreenWidth() + 50 ||
        Eposition.y < -50 || Eposition.y > GetScreenHeight() + 50)
    {
        active = false;
    }
}


void EnemyBullet::Draw() const
{
    if (active) DrawCircleV(Eposition, 5.0f, RED);
}
