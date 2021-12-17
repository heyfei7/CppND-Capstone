#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <mutex>

enum ComponentType
{
    nPerson,
    nFloor,
    nLift
};

class Component
{
public:
    // constructor / destructor
    Component(): _id(++idCounter) {}
    ~Component() {}

    // getter and setter
    int getID() { return _id; };
    void setPos(double x, double y) {
        _x = x;
        _y = y;
    }
    void getPos(double &x, double &y)
    {
        x = _x;
        y = _y;
    }

    // others
    virtual void simulate();

protected:
    double _x, _y, _width, _height;
    int _id;
    ComponentType _type;

    static std::mutex _mtx;

private:
    static int idCounter;
};

int Component::idCounter = 0;
std::mutex Component::_mtx;

#endif