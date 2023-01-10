#pragma once

#include <SDL2/SDL.h>

class mTimer {
public:
  mTimer();
  ~mTimer();

  void stop();
  void start();

  void pause();
  void resume();

  Uint32 getTicks();

private:
  Uint32 startTicks;
  Uint32 pausedTicks;

  bool Paused;
  bool Started;
};