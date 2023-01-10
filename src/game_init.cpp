#include "../headers/game.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

bool Game::create_window() {
  printf("Creating window...\n");

  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Warning: Liniear texture filtering is not enabled!\n");
  }

  gWindow = SDL_CreateWindow(TITLE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  if (gWindow == nullptr) {
    return false;
  }

  return true;
}

bool Game::create_renderer() {
  printf("Creating renderer...\n");
  gRenderer = SDL_CreateRenderer(
      gWindow, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);
  if (gRenderer == nullptr) {
    return false;
  }
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  return true;
}

bool Game::init_subsystems() {
  int imgFlags = IMG_INIT_PNG;
  if (SDL_Init(SDL_INIT_VIDEO) < 0 && !(IMG_Init(imgFlags) & imgFlags)) {
    return false;
  }

  if (TTF_Init() == -1) {
    return false;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    return false;
  }

  return true;
}

bool Game::init_game() {
  if (!init_subsystems()) {
    printf("Error while initting a subsystems: %s\n", SDL_GetError());
    return false;
  }

  if (!create_window()) {
    printf("Error while creating window: %s\n", SDL_GetError());
    return false;
  }

  if (!create_renderer()) {
    printf("Error while creating a renderer: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

