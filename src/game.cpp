#include "../headers/game.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

Game::Game() {
  if (!init_game()) {
    exit(1);
  }
  TextureCounter = 0;
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

void Game::setFont(TTF_Font* font) {
    gFont = font;
}

SDL_Renderer *Game::getRenderer() {
    return gRenderer;
}

TTF_Font *Game::getFont() {
    return gFont;
}

void Game::addTexture(mTexture *texture) {
    if (TextureCounter > 20) {
        return;
    }
    
    texturePool[TextureCounter] = texture;
    TextureCounter++;
}

mTexture* Game::getTexture(int index) {
    if (index > TextureCounter) {
        return nullptr;
    }
    return texturePool[index];
}

Game::~Game() {
  printf("Exiting...\n");
  // Destroy window
  TTF_CloseFont(gFont);
  gFont = nullptr;
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  gRenderer = nullptr;
  
  for (int i = 0; i < TextureCounter; i++) {
    delete texturePool[i];
  }

  // Quit SDL subsystems
  Mix_Quit();
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}