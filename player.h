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
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Texture* texture_fr_1;
    SDL_Texture* texture_fr_2;
    int health;
    float x_acceleration;
    float y_acceleration;
    int facing_side;
    void update(const std::chrono::milliseconds elapsed_time);
    void updateX(const std::chrono::milliseconds elapsed_time);
    void updateY(const std::chrono::milliseconds elapsed_time);
    void render(SDL_Renderer* renderer);
    void animation_step();
};