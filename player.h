#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "entity.h"

class Player : public Entity{
    public:
        Player();
        SDL_Surface *player_sprite;
        SDL_Rect rect;
        void move(SDL_Event e);
        void updateRect();
};