#include "game.h"
#include "entity.h"
#include <chrono>

#include <fstream>

const auto kfps = 60;
const auto dtime = std::chrono::milliseconds{5 * 1000 / 60};

Game::Game():
    player_(NULL),
    window(NULL),
    renderer(NULL)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    std::ifstream in("game.config");
     if (!in.is_open()){
         std::cout<<"Failed to load config file!"<<std::endl;
     }

    std::string param;
    int value;

     while(!in.eof()){
        in >> param;
        in >> value;

        std::cout<<param<<" : "<<value<<std::endl;

     }

     in.close();



    window = SDL_CreateWindow("test",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        500,
                        500,
                        SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout<<"Failed to load! Error: "<<SDL_GetError()<<std::endl;

    renderer = SDL_CreateRenderer(window,
                        -1,
                        SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
        std::cout<<"Failed to load! Error: "<<SDL_GetError()<<std::endl;
    //Create player object
    player_ = Player(renderer);
    
    //create background object and adjust sizing
    background_ = Entity();
    background_.rect.x = 0;
    background_.rect.y = 0;
    background_.rect.w = 1920;
    background_.rect.h = 1080;
    background_.angle = 0;

    SDL_Texture* bg_txt = IMG_LoadTexture(renderer, "src/pxfuel.png");
    if(bg_txt == NULL) std::cout<<"Error loading texture: " << SDL_GetError() << std::endl;
    //SDL_SetRenderDrawColor(renderer, 158,132,146,1);
    
    runEventLoop();
}

Game::~Game()
{
}

void Game::runEventLoop() {
    
    SDL_Event event;

    bool running{true};
    auto last_updated_time = std::chrono::high_resolution_clock::now();
    while (running) {
        using std::chrono::high_resolution_clock;
        using std::chrono::milliseconds;
        using std::chrono::duration_cast;

        const auto start_time = high_resolution_clock::now();

        //TODO wrap full event polling into new class
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
            //User presses a key
            else if( event.type == SDL_KEYDOWN )
            {
                if(event.key.keysym.sym == SDLK_q){
                    running = false;
                    
                    }


                if(event.key.keysym.sym == SDLK_d){
                    if(abs(player_.x_acceleration) < 1) player_.x_acceleration += 1;
                    player_.facing_side = 1;
                }
                    
                if(event.key.keysym.sym == SDLK_a){
                    if(abs(player_.x_acceleration) < 1) player_.x_acceleration = -1;
                    player_.facing_side = -1;
                }
                    

                if(event.key.keysym.sym == SDLK_w){
                    if(abs(player_.y_acceleration) < 1) player_.y_acceleration = -1;    
                }

                if(event.key.keysym.sym == SDLK_s){
                    if(abs(player_.y_acceleration) < 1) player_.y_acceleration = 1;
                    
                    }
            }
        }

        
        
        // update scene and last_updated_time
        const auto current_time = high_resolution_clock::now();
        const auto upd_elapsed_time = current_time - last_updated_time;

        last_updated_time = current_time;

        // calculate delay for constant fps
        const auto end_time = high_resolution_clock::now();
        const auto elapsed_time = duration_cast<milliseconds>(
                end_time - start_time);

        const auto delay_duration = milliseconds(1000) / kfps - elapsed_time;
        if (delay_duration.count() >= 0)
            SDL_Delay(delay_duration.count());
        
        update(milliseconds(1000) / kfps);
        draw();
    }
}

void Game::update(const std::chrono::milliseconds elapsed_time)
{
    player_.update(elapsed_time);
}

void Game::flip() const
{
    SDL_RenderPresent(renderer);
}

void Game::clear() const
{
    SDL_RenderClear(renderer);
}

void Game::draw()
{
    clear();
    background_.render(renderer, bg_txt);
    player_.render(renderer);
    //flip();
    SDL_RenderPresent(renderer);
}