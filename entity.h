#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>


class Entity
{
public:
    Entity(int enemyType, int posX, int posY, float dangle);
    Entity();
    SDL_Rect rect;

    int dtime;
    float linAcceleration; //acceleration per game tick
    float linSpeed;   //px per sec
    int angSpeed;   //deg per sec
    float deltaTime;
    float angle;
    float constAngle;
    int startX;
    int startY;
    bool inUse;


    void setVariables(int posX, int posY, int angle);
    void setVariables(int posX, int posY, int angle, int linSpeedE);
    void setX(int x);
    void setY(int y);
    void updatePosition(int posX, int posY);
    void incrementX(int x);
    void incrementY(int y);
    bool move();
    void explosion(int posX, int posY);
    void render(SDL_Renderer* renderer,SDL_Texture* entityTexture);
    void render_flipped(SDL_Renderer* renderer,SDL_Texture* entityTexture);
    bool collisionCheck(SDL_Rect targetRect);

    int getX();
    int getY();

};