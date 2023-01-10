#pragma once

#include "texture.hpp"
#include "entity.hpp"
#include "memory.hpp"

#include <string>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

#include <functional>
#include <vector>

#define TITLE "Flappybirb"

#define __EV_CB std::function<void(SDL_Event & e)>
#define __RN_CB std::function<void()>
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

const int SCREEN_FPS = 75;
const int SCREEN_TICKS_PER_TIME = 1000 / SCREEN_FPS;

class Game {
public:
  Game();
  ~Game();

  void start();

  void setFont(TTF_Font *font);
  int createTexture(std::string path);

  

  void addEventHandler(__EV_CB*);
  void addRenderingHandler(__RN_CB*);

  mTexture *getTexture(int index);
  SDL_Renderer *getRenderer();
  TTF_Font *getFont(int index);

private:
  
  void clearTexturePool();

  void begin_loop();
  void proceed_events();
  void render_all();
  void end_loop();

  void close_game_event_handler(SDL_Event &e);

  bool init_game();
  bool create_window();
  bool create_renderer();
  bool init_subsystems();

  bool isRunning;
  int TextureIndex;

  std::vector<__EV_CB*> event_handlers;
  std::vector<__RN_CB*> render_handlers;

  SDL_Event e;

  Memory _memory;

  SDL_Renderer *gRenderer;
  TTF_Font *gFont;
  SDL_Window *gWindow;
};
