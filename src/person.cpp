#include <random>
#include <functional>
#include <iostream>
#include "person.h"
#include "building.h"

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(3000,10000);
auto dice = std::bind(distribution, generator);

Person::Person()
{
    _calmness = dice();
    reset();
    std::cout << "Person::Person created with id=" << getID() << " calmness=" << _calmness << " destFloor=" << _destFloor << std::endl;
}

void Person::reset()
{
    _patience = Building::personMaxPatience;
    _destFloor = Building::getRandomFloor();
}

void Person::checkPatience()
{
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _lastCheck).count();
    if (duration >= _calmness && _patience > 0)
    {
        _patience--;
    }
    _lastCheck = std::chrono::system_clock::now();
}