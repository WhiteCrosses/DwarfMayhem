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
    texture_fr_1 = IMG_LoadTexture(renderer, "src/player_fr_1.png");
    texture_fr_2 = IMG_LoadTexture(renderer, "src/player_fr_2.png");
    texture = texture_fr_1;
    //if(texture == NULL) std::cout<<"Error loading texture: " << SDL_GetError() << std::endl;
    setVariables(100, 100, 0);
    rect.w = 40;
    rect.h = 40;
    linSpeed = 0;
    linAcceleration = 0.5;
    health = 100;
    inUse = true;


    facing_side = 1;
    x_acceleration = 0;
    y_acceleration = 0;

}
void Player::render(SDL_Renderer *renderer){
    if(facing_side == 1) Entity::render(renderer, texture);
    else Entity::render_flipped(renderer, texture);
}


void Player::update(const std::chrono::milliseconds elapsed_time){
    updateX(elapsed_time);
    updateY(elapsed_time);
}

void Player::animation_step(){
    if (texture == texture_fr_1) texture = texture_fr_2;
    else if (texture == texture_fr_2) texture = texture_fr_1;
}

void Player::updateX(const std::chrono::milliseconds elapsed_time){
    if(abs(x_acceleration) >= 0.01){
        setX(getX() + x_acceleration * elapsed_time.count());
        x_acceleration *= 0.95;
    }
    else{
        x_acceleration = 0;
    }
}

void Player::updateY(const std::chrono::milliseconds elapsed_time){
    if(abs(y_acceleration) >= 0.01){
        setY(getY() + y_acceleration * elapsed_time.count());
        y_acceleration *= 0.95;
    }
    else{
        y_acceleration = 0;
    }
}