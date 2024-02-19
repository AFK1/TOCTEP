#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <vector>

#include "src/utils.hpp"

struct Window {
  SDL_Window *window;
  SDL_Renderer *renderer;

  bool want_quit = false;
  bool key_pressed[300];

  Window(const char* title, int w, int h);
  ~Window();

  void clear(Color color);
  void next_frame();
};

struct Window_manager {
  std::vector<Window*> windows;

  Window* operator[](int index);
  Window* get_by_id(unsigned int id);
  int get_index_by_id(unsigned int id);
};

extern Window_manager windows;