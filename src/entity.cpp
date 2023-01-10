#include "../headers/entity.hpp"
#include "../headers/texture.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

Entity::Entity() {
    cordX = 0;
    cordY = 0;
}

void Entity::event_handler(SDL_Event &e) {
    if (e.type == SDL_KEYDOWN) {
        cordX += 1;
    }
}

void Entity::render_handler(SDL_Renderer *gRenderer) {
    gTexture->render(cordX, cordY);
}

Entity::~Entity() {
    
}