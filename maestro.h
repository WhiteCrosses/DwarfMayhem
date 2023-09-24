#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "entity.h"

using namespace std;

//class which holds entity list and window object etc
class Maestro{
    public:
        Maestro(SDL_Window *window);
        vector <Entity> entity_list;
};