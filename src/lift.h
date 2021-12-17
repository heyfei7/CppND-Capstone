#ifndef LIFT_H
#define LIFT_H

#include <condition_variable>
#include "component.h"
#include "person.h"
#include "building.h"

class Lift : public Component {
public:
    Lift(Building *building, Floor *floor);
    ~Lift();

    bool full();
    int getFloor() { return floor->getFloor(); }
    void addPerson(Person *p);

    void moveUp();
    void moveDown();

private:
    void arrive();

    Building *building;
    Floor *floor;

    std::vector<Person *> _people;
    std::condition_variable _condition;
    std::mutex _mutex;
};

#endif