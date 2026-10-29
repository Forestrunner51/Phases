#pragma once
#include "raylib.h"

class Enemy
{
    public:
        Vector2 position = {600,150};

        void Load();
        void Unload();
        void Draw() const;
    private:
        Texture2D texture = {};
};
