#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "building.h"

class Controller {
 public:
  void HandleInput(bool &running, Building &building) const;
};

#endif