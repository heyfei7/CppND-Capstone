
#ifndef PERSON_H
#define PERSON_H

#include <chrono>
#include "component.h"

class Person : public Component {
public:
    Person();
    ~Person() {};

    int getPatience() { return _patience; };
    int getDestFloor() { return _destFloor; }
    void reset();

private:
    int _destFloor;
    int _patience;
    int _calmness; // time it takes for patience to drop 1 level (ms)
    std::chrono::time_point<std::chrono::system_clock> _lastCheck; // last time patience level is checked

    void checkPatience();
};

#endif