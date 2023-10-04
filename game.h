#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constants.hpp"
#include "player.h"
#include <iostream>
#include <chrono>
#include <cmath>

struct Game
{
    SDL_Window* window;             //Unsafe, but needs to stay in public for easy access.
    SDL_Renderer* renderer;
    Player player_;
    Entity background_;
    SDL_Texture* bg_txt;
    Game();
    ~Game();
    

private:
    void runEventLoop();
    
    void flip() const;
    void clear() const;
    void draw();
    void update(const std::chrono::milliseconds elapsed_time);

             //Might fix later :)

};