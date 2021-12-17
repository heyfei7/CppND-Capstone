#include <iostream>
#include "controller.h"
#include "SDL.h"
#include "building.h"

void Controller::HandleInput(bool &running, Building &building) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          building.rightLift().moveUp();
          break;

        case SDLK_DOWN:
          building.rightLift().moveDown();
          break;

        case SDLK_w:
          building.leftLift().moveUp();
          break;

        case SDLK_s:
          building.leftLift().moveDown();
          break;
      }
    }
  }
}