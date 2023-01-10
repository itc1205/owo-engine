#include "entity.hpp"
#include "texture.hpp"
#include "timer.hpp"

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

#include <vector>

class Memory {
  /*
  Abstraction to workaround with heap memory
  */
  public:
  Memory();
  ~Memory();

  mTexture *getTexturePointer(int id);
  Entity *getEntityPointer(int id);
  mTimer* getTimer(int id);
  TTF_Font* getFont(int id);

  int createTexture();
  int createEntity();
  int createTimer();
  int createFont(std::string path);

private:
  std::vector<mTexture *> _textures;
  std::vector<Entity *> _entities;
  std::vector<TTF_Font *> _fonts;
  std::vector<mTimer *> _timers;
};
