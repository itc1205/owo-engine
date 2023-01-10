#pragma once

#include "texture.hpp"

#include <SDL2/SDL.h>

class Entity {
private:
  int cordX;
  int cordY;

  mTexture *gTexture;

public:
  Entity();
  ~Entity();
  


  int GetCordX() { return cordX; }
  int GetCordY() { return cordY; }
  void render_handler(SDL_Renderer* gRenderer);
  void event_handler(SDL_Event &e);

  void setTexture(mTexture* nTexture);

};
