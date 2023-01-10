#include "../headers/game.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

Game::Game() {
  if (!init_game()) {
    exit(1);
  }
}

Game::~Game() {
  printf("Exiting...\n");
  // Destroy window
  //TTF_CloseFont(gFont);
  //gFont = nullptr;
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  gRenderer = nullptr;

  clearTexturePool();

  // Quit SDL subsystems
  Mix_Quit();
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
