#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <chrono>
#include "player.h"
#include "entity.h"
#include <cmath>


//Init of game
Player::Player() : Entity(1, 100, 100, 0)
{
}

Player::Player(SDL_Renderer* renderer) : Entity(1, 100, 100, 0)
{
    //SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, "src/player_fr_1.png");
    if(texture == NULL) std::cout<<"Error loading texture: " << SDL_GetError() << std::endl;
    setVariables(100, 100, 0);
    rect.w = 100;
    rect.h = 100;
    linSpeed = 0;
    linAcceleration = 0.5;
    health = 100;
    inUse = true;

    x_acceleration = 0;
    y_acceleration = 0;

}
void Player::render(SDL_Renderer *renderer){
    Entity::render(renderer, texture);
}


void Player::update(const std::chrono::milliseconds elapsed_time){
    updateX(elapsed_time);
    updateY(elapsed_time);
}

void Player::updateX(const std::chrono::milliseconds elapsed_time){
    setX(getX() + x_acceleration * elapsed_time.count());
}

void Player::updateY(const std::chrono::milliseconds elapsed_time){
    setY(getY() + y_acceleration * elapsed_time.count());
}