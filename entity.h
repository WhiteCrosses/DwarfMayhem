#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class Entity{
private:
    /* data */
public:
    Entity(/* args */);
    struct {
        int x;
        int y;
    } position;
};