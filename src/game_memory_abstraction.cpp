#include "../headers/game.hpp"

void Game::setFont(TTF_Font *font) { gFont = font; }

SDL_Renderer *Game::getRenderer() { return gRenderer; }

TTF_Font* Game::getFont(int index) { return _memory.getFont(index); }

int Game::createTexture(std::string path) { 
  auto texture_id = _memory.createTexture();
  auto texture_p = _memory.getTexturePointer(texture_id);
  texture_p->loadTextureFromFile(path);
  return texture_id;
}

mTexture *Game::getTexture(int index) {
  return _memory.getTexturePointer(index);
}

void Game::clearTexturePool() {
  // TODO: Memory cleanup
  return;
}
