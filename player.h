#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.h"
#include <chrono>

class Player : public Entity
{
public:
    Player();
    Player(SDL_Renderer* renderer);
    SDL_Texture* texture;
    int health;
    int x_acceleration;
    int y_acceleration;
    void update(const std::chrono::milliseconds elapsed_time);
    void updateX(const std::chrono::milliseconds elapsed_time);
    void updateY(const std::chrono::milliseconds elapsed_time);
    void render(SDL_Renderer* renderer);
};