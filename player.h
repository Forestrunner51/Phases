#pragma once
#include "raylib.h"

class Player
{
    public:
        Vector2 position = {400,240}; //
        static constexpr float Radius = 30.0f;

        void Update();
        void Draw() const;

    private:
        static constexpr float Speed = 5.0f;
};
