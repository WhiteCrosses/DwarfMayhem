#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include "player.h"
#include "entity.h"

using namespace std;

Player::Player(){
    cout<<"SDL Event: 2"<<endl;
    SDL_Surface *player_sprite = SDL_LoadBMP("src/player_fr_1.bmp");
    rect.x = 100;
    rect.y = 100;
    }

void Player::updateRect(){
    rect.x = position.x;
    rect.y = position.y;

    cout<<"rect.x: "<<rect.x<<endl;
    cout<<"rect.y: "<<rect.y<<endl;
}

void Player::move(SDL_Event e){
    switch(e.key.keysym.sym){
        case SDLK_a:
            cout<<"a was pressed"<<endl;
            position.x--;
            break;
        case SDLK_s:
            cout<<"s was pressed"<<endl;
            position.y--;
            break;
        case SDLK_d:
            cout<<"d was pressed"<<endl;
            position.x++;
            break;
        case SDLK_w:
            cout<<"w was pressed"<<endl;
            position.y++;
            break;
        }
    updateRect();
}
