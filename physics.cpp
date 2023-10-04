#include "physics.h"
#include <chrono>

const auto kfps = 60;
const auto dtime = std::chrono::milliseconds{5 * 1000 / 60};



Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::update(const std::chrono::milliseconds elapsed_time) {
    
}

void Physics::updatePosition(const std::chrono::milliseconds elapsed_time) {
    
}


void Physics::setAcceleration(float a) {
    mov.acceleration = a;
}

void Physics::setSpeed(float s) {
    mov.speed = s;
}

void Physics::setAngle(float a) {
    mov.angle = a;
}