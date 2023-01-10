#include "../headers/memory.hpp"
#include <SDL2/SDL_ttf.h>

int Memory::createFont(std::string path) {
    _fonts.push_back(TTF_OpenFont(path.c_str(), 18));
    return _fonts.size() - 1;
}

int Memory::createTexture() {
    mTexture* texture = new mTexture;
    _textures.push_back(texture);
    return _textures.size() - 1;
}

int Memory::createEntity() {
    Entity* entity = new Entity;
    _entities.push_back(entity);
    return _entities.size() - 1;
}

int Memory::createTimer() {
    mTimer* timer = new mTimer;
    _timers.push_back(timer);
    return _timers.size() - 1;
}

Entity* Memory::getEntityPointer(int id) {
   if (id > _entities.size() - 1) {
       return nullptr;
   }
   return _entities[id];
}


mTexture* Memory::getTexturePointer(int id) {
   if (id > _textures.size() - 1) {
       return nullptr;
   }
   return _textures[id];
}

mTimer* Memory::getTimer(int id) {
   if (id > _timers.size() - 1) {
       return nullptr;
   }
   return _timers[id];
}

TTF_Font* Memory::getFont(int id) {
   if (id > _fonts.size() - 1) {
       return nullptr;
   }
   return _fonts[id];
}

Memory::Memory() {

}

Memory::~Memory() {
    for (auto &item: _textures) {
        delete item;
    }
    for (auto &item: _timers) {
        delete item;
    }
    for (auto &item: _entities) {
        delete item;
    }

    for (auto &item: _fonts) {
        TTF_CloseFont(item);
        item = nullptr;
    }
}
