#include "../headers/texture.hpp"

#include <string>

#include <SDL2/SDL_image.h>

mTexture::mTexture() {
  printf("creating texture!\n");
  gTexture = nullptr;
  tWidth = 0;
  tHeight = 0;
}

mTexture::~mTexture() {
  printf("destroying texture!\n");
  free();
}

bool mTexture::loadTextureFromFile(std::string path) {
  free();
  SDL_Texture *newTexture = nullptr;

  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == nullptr) {
    printf("Texture load error: %s\n", SDL_GetError());
    SDL_FreeSurface(loadedSurface);
    return false;
  }

  tWidth = loadedSurface->w;
  tHeight = loadedSurface->h;

  SDL_FreeSurface(loadedSurface);

  gTexture = newTexture;

  return gTexture != nullptr;
}

void mTexture::free() {
  if (gTexture != nullptr) {
    SDL_DestroyTexture(gTexture);
    gTexture = nullptr;
    tWidth = 0;
    tHeight = 0;
  }
}

bool mTexture::loadTextureFromText(std::string text, SDL_Color color,
                                   TTF_Font *font) {
  free();
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

  if (textSurface == nullptr) {
    printf("Failed loading fonts: %s\n", TTF_GetError());
    SDL_FreeSurface(textSurface);
    return false;
  }

  gTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);

  if (gTexture == nullptr) {
    printf("Failed to create a texture from font: %s\n", SDL_GetError());
    SDL_FreeSurface(textSurface);
    return false;
  }

  tWidth = textSurface->w;
  tHeight = textSurface->h;

  SDL_FreeSurface(textSurface);

  return true;
}

int mTexture::getHeight() { return tHeight; }

int mTexture::getWidth() { return tWidth; }

void mTexture::setRenderer(SDL_Renderer *newRenderer) {
  gRenderer = newRenderer;
}

void mTexture::render(int x, int y, SDL_Rect *clip, double angle,
                      SDL_Point *center, SDL_RendererFlip flip) {
  SDL_Rect renderQuad = {x, y, tWidth, tHeight};
  if (clip != nullptr) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }
  SDL_RenderCopyEx(gRenderer, gTexture, clip, &renderQuad, angle, center, flip);
}
