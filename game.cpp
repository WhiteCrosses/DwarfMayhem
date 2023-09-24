#include "game.h"
#include <chrono>

const auto kfps = 60;
const auto dtime = std::chrono::milliseconds{5 * 1000 / 60};

Game::Game():player_(NULL), window(NULL), renderer(NULL)
{
    SDL_Init(SDL_INIT_EVERYTHING);
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

    player_ = Player(renderer);

    SDL_SetRenderDrawColor(renderer, 158,132,146,1);
    

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
        std::cout<<"FPS: "<<1.0/dtime.count()<<"\n";
        while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
        }
    }

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        
        if(keystates[SDL_SCANCODE_D]){
            player_.x_acceleration = 5;
        }
        else if(keystates[SDL_SCANCODE_A]){
            player_.x_acceleration = -5;
        }
        else if(keystates[SDL_SCANCODE_W]){
            player_.y_acceleration = 5;
        }
        else if(keystates[SDL_SCANCODE_S]){
            player_.y_acceleration = -5;
        }
        else if(keystates[SDL_SCANCODE_Q]){
            std::cout<<"HP\n";
            running = false;
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
        
        update(elapsed_time);
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
    player_.render(renderer);
    flip();
}