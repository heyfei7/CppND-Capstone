#include <iostream>
#include "controller.h"
#include "SDL.h"
#include "runner.h"

void Controller::HandleInput(bool &running, Runner &runner) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN && runner.GetActive())
    {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          runner.ShiftX(-1);
          break;

        case SDLK_RIGHT:
          runner.ShiftX(1);
          break;
      }
    }
  }
}