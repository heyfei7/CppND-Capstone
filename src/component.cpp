#include "component.h"

int Component::idCounter = 0;
std::mutex Component::_mtx;
