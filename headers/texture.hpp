#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class mTexture {
public:
  mTexture();
  ~mTexture();

  bool loadTextureFromFile(std::string path);
  bool loadTextureFromText(std::string text, SDL_Color color, TTF_Font *font);

  int getWidth();
  int getHeight();

  void setRenderer(SDL_Renderer* newRenderer);

  void render(int x, int y, SDL_Rect *clip = nullptr, double angle = 0.0,
              SDL_Point *center = nullptr,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

  SDL_Texture *getTexture();

private:
  void free();

  SDL_Renderer *gRenderer;

  SDL_Texture *gTexture;
  int tWidth;
  int tHeight;
};