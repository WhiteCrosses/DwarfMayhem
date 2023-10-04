#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constants.hpp"
#include <iostream>
#include <chrono>
#include <cmath>

struct Physics
{
    Physics();
    ~Physics();

    SDL_Rect rect;
    struct movement{
        float x;
        float y;
        float angle;
        float speed;
        float acceleration;

    } mov;

    void setAcceleration(float a);
    void setSpeed(float s);
    void setAngle(float a);

    void update(const std::chrono::milliseconds elapsed_time);

};