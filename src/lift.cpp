#include <iostream>
#include <algorithm>
#include "lift.h"
#include "building.h"

Lift::Lift(Building *b, Floor* f): floor(f), building(b) {}
Lift::~Lift() {}

bool Lift::full()
{
    return _people.size() < Building::elevatorMaxCapacity;
}

void Lift::addPerson(Person *person)
{
    _people.push_back(person);
    std::cout << "Lift::addPerson(" << person->getID() << ") floor=" << getFloor() << " id=" << getID() << std::endl;
}

void Lift::moveUp()
{
    if (getFloor() < Building::numberOfFloors)
    {
        floor = building->getFloor(getFloor() + 1);
    }
    arrive();
}

void Lift::moveDown()
{
    if (getFloor() > 1)
    {
        floor = building->getFloor(getFloor() - 1);
    }
    arrive();
}

void Lift::arrive()
{
    auto part = std::partition(_people.begin(), _people.end(),
        [](Person *p) { return p->getDestFloor() != getFloor();});

    std::for_each(part, _people.end(), [](Person *p) { floor->addPerson(p); });
    _people.erase(part, _people.end());
    floor->movePeopleToLift(this);
}