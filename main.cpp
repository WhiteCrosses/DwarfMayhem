#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include "game.h"
#include "constants.hpp"
#include <algorithm>
#include <random>
#include <vector>
#include <algorithm>


#define FROG_DISTANCE 80
#define HEART_DISTANCE 30
#define HEART_DISTANCE_BOTTOM 90
#define PARTICLE_COUNT 10

#define TURRET_POSX WindowConstants::Width/2
#define TURRET_POSY WindowConstants::Height-140


using namespace std;



//Black magic :)
template <typename T>
class pointer_is_equal_to_object
{
public:
    explicit pointer_is_equal_to_object(T const &);

    bool operator()(T const *) const;

private:
    T const & value;
};

template <typename T>
pointer_is_equal_to_object<T>::pointer_is_equal_to_object(T const & v) : value(v) {}

template <typename T>
bool pointer_is_equal_to_object<T>::operator()(T const * p) const
{
    return p && (*p == value);
}



int getRandom(){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 12); // define the range

    return 55*distr(gen);
}

int main( int argc, char *argv[] ){
    Game game;
    return 0;
}