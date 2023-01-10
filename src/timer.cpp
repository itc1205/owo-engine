#include "../headers/timer.hpp"

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

mTimer::mTimer() {
  startTicks = 0;
  pausedTicks = 0;
  Paused = false;
  Started = false;
}

void mTimer::start() {
  startTicks = SDL_GetTicks();
  pausedTicks = 0;
  Paused = false;
  Started = true;
}

void mTimer::stop() {
  Started = false;
  Paused = false;
  startTicks = 0;
  pausedTicks = 0;
}

void mTimer::pause() {
  if (Started && !Paused) {
    pausedTicks = SDL_GetTicks() - startTicks;
    Paused = true;
    startTicks = 0;
  }
}

Uint32 mTimer::getTicks() {
  if (Started) {
    if (Paused) {
      return pausedTicks;
    } else {
      return SDL_GetTicks() - startTicks;
    }
  }

  return 0;
}

mTimer::~mTimer() {
  
}