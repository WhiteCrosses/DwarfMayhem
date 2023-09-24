// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

#include "entity.h"
#include "player.h"
#include "maestro.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void eventLoop(SDL_Window *window){
  cout<<"SDL Event: 1"<<endl;
  Maestro maestro(window);

  Player player;
  maestro.entity_list.push_back(player);
  
  bool keep_window_open = true;
  while(keep_window_open){
    SDL_Event e;
    while(SDL_PollEvent(&e) > 0){
      switch(e.type){
        case SDL_QUIT:
          keep_window_open = false;
          break;
        case SDL_KEYDOWN:
          switch(e.key.keysym.sym){
            case SDLK_ESCAPE:
              keep_window_open = false;
              break;
            case SDLK_a:
              player.move(e);
              break;
            case SDLK_s:
              player.move(e);
              break;
            case SDLK_d:
              player.move(e);
              break;
            case SDLK_w:
              player.move(e);
              break;
            }
      }
      SDL_Delay(1000/20);
      //move player sprite according to its coords
      SDL_Surface *window_surface = SDL_GetWindowSurface(window);
      SDL_Surface *player_sprite = SDL_LoadBMP("src/player_fr_1.bmp");
      SDL_BlitSurface(player_sprite, NULL, window_surface, &player.rect);
      SDL_UpdateWindowSurface(window);
    }
}

}

int initWindow(){
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow(
    "SDL2 Window",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    SCREEN_WIDTH, SCREEN_HEIGHT,
    0);

  if(!window){
      cout<<"Failed to create window\n";
      return -1;
    }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  
  if(!window_surface){
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }
  
  eventLoop(window);
  return 1;
}

int main(int argc, char* args[]) {
  initWindow();
  return 0;
}
