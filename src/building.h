#ifndef BUILDING_H
#define BUILDING_H

#include <condition_variable>
#include <memory>
#include <thread>
#include <deque>
#include "component.h"
#include "person.h"
#include "lift.h"

class Building;

class Floor : public Component
{
public:
    Floor(Building *building, int number);
    ~Floor();

    int getFloor() { return _floorNumber; }
    void addPerson(Person *person);
    void movePeopleToLift(Lift *lift);

private:
    Building *building;

    int _floorNumber;
    std::deque<Person *> _people;
};

class Building
{
public:
    Building();
    ~Building();

    enum class Controls { Up, Down };

    static int elevatorMaxCapacity;
    static int personMaxPatience;
    static int numberOfFloors;
    static int numberOfPeople;
    static int getRandomFloor();

private:
    std::vector<std::thread> _threads;
    std::vector<Floor>  _floors;
    std::vector<Person> _residents;
    Lift liftL;
    Lift liftR;

public:
    Floor &getFloor(int i) { return _floors.at(i); }
    Lift  &leftLift  { return liftL; }
    Lift  &rightLift { return liftR; }
};

#endif