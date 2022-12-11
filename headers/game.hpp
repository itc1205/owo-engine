#pragma once

#include "texture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

#define TITLE "Flappybirb"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

const int SCREEN_FPS = 75;
const int SCREEN_TICKS_PER_TIME = 1000 / SCREEN_FPS;

class Game {
public:
  Game();
  ~Game();
  
  void setFont(TTF_Font* font);
  void addTexture(mTexture *texture);

  mTexture* getTexture(int index);

  SDL_Renderer *getRenderer();
  TTF_Font *getFont();

  

private:
  bool init_game();
  bool create_window();
  bool create_renderer();
  bool init_subsystems();

  int TextureCounter;

  mTexture* texturePool[20];
  SDL_Renderer *gRenderer;
  TTF_Font *gFont;
  SDL_Window *gWindow;
};