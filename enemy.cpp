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
    float deltaTime = GetFrameTime();

    if (movingRight){
        EnemyPosition.x += enemySpeed * deltaTime;
    } else {
        EnemyPosition.x -= enemySpeed * deltaTime;
    }

    if  (EnemyPosition.x >= 800 - texture.width ){
        movingRight = false;
    }
    else if (EnemyPosition.x <= 0 ){
        movingRight = true;
    }

    }

//  EnemyPosition.x += 1.0f;
// if ((present == false && EnemyPosition.x == 800 - texture.width)){
//     EnemyPosition.x -= 2.0f;
//
// } else if  ((present == false && EnemyPosition.x == 300 - texture.width)){
//     EnemyPosition.x += 1.0f;
//
// }

// if ((EnemyPosition.x > 500 || EnemyPosition.y > 800)){
//     EnemyPosition.x
// }


void Enemy::Draw() const
{
    DrawRectangleV(EnemyPosition, {10, 10}, GREEN);
    DrawTextureV(texture, EnemyPosition, WHITE);
}
