#include "building.h"

Floor::Floor(int number)
    : _floorNumber(number) {}
{
    std::cout << "Floor::Floor created with id=" << getID() << " floor=" << getFloor() << std::endl;
}

Floor::~Floor() {}

void Floor::addPerson(Person *person)
{
    _people.push_back(person);
    std::cout << "Floor::addPerson(" << person->getID() << ") floor=" << getFloor() << std::endl;
}

void Floor::movePeopleToLift(Lift *lift)
{
    while (!lift->full() && !_people.empty())
    {
        Person *p = _people.front();
        lift->addPerson(p);
        _people.pop_front();
    }
}

int Building::elevatorMaxCapacity = 5;
int Building::personMaxPatience = 10;
int Building::numberOfFloors = 8;
int Building::numberOfPeople = 16;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,Building::numberOfFloors);
auto dice = std::bind(distribution, generator);

static int Building::getRandomFloor()
{
    return floorDice();
}

Building::Building():
{
    for (int i = 0; i < numberOfFloors; i++)
    {
        _floors.emplace_back(Floor(this, i + 1));
    }
    for (int i = 0; i < numberOfPeople; i++)
    {
        _residents.emplace_back(Person());
        Person &lastPerson = _residents.at(i);
        getFloor(lastPerson.getDestFloor())->addPerson(&lastPerson);
    }
    liftL(this, getFloor(1));
    liftR(this, getFloor(1));
}

Building::~Building() {
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}

Floor *Building::getFloor(int i)
{
    return _floors.at(i)->get();
}