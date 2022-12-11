#include "headers/game.hpp"
#include "headers/texture.hpp"
#include "headers/timer.hpp"

#include <string>
#include <SDL2/SDL.h>
#include <stdio.h>

bool memoryLeak(Game &game) {
  game.setFont(TTF_OpenFont("assets/Minecraft.ttf", 18));
  while(true) {
    mTexture* fontTexture = new mTexture;
    fontTexture->setRenderer(game.getRenderer());
    fontTexture->loadTextureFromText("Hello, world!", SDL_Color{0, 0, 0},
                                   game.getFont());
  }
}

bool loadMedia(Game &game) {
  game.setFont(TTF_OpenFont("assets/Minecraft.ttf", 18));

  mTexture* fontTexture = new mTexture;
  fontTexture->setRenderer(game.getRenderer());
  fontTexture->loadTextureFromText("Hello, world!", SDL_Color{0, 0, 0},
                                   game.getFont());

  game.addTexture(fontTexture);
  delete fontTexture;

}

int main(int argc, char const *argv[]) {
  Game game;
  memoryLeak(game);
  loadMedia(game);

  SDL_Event e;

  bool isRunning = true;

  while (isRunning) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        isRunning = false;
      }
    }
    SDL_SetRenderDrawColor(game.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(game.getRenderer());

    mTexture *font = game.getTexture(0);
    font->render((SCREEN_WIDTH - font->getWidth()) / 2,
                                      (SCREEN_HEIGHT - font->getHeight()) - 28);

    SDL_RenderPresent(game.getRenderer());
  }

  

  return 0;
}