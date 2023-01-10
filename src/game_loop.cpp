#include "../headers/game.hpp"


void Game::start() {
  isRunning = true;
  while (isRunning) {
    proceed_events();

    begin_loop();

    render_all();

    end_loop();
  }
}

void Game::proceed_events() {
  while (SDL_PollEvent(&e)) {
    close_game_event_handler(e);
  }
}

void Game::begin_loop() {
  // TODO: some cleanup before rendering
  SDL_RenderClear(gRenderer);
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Game::render_all() {
  // TODO: render everything in texture/objects pool
}

void Game::end_loop() {
  // TODO: flush everything to renderer
  SDL_RenderPresent(gRenderer);
}

void Game::close_game_event_handler(SDL_Event &e) {
  if (e.type == SDL_QUIT) {
    isRunning = false;
  }
}