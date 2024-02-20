#pragma once

#include <SDL3/SDL.h>
#include <cstdint>
#include <vector>

#include "../utils.hpp"
#include "../constants.hpp"
#include "../ui/ui_container.hpp"
#include "./viewport.hpp"

struct Window {
  SDL_Window *window;
  Ui_container *ui;

  std::vector<Viewport*> viewports;

  bool want_quit = false;
  bool key_pressed[300] = {0};
  Vector2 mouse_pos;
  uint8_t mouse_pressed = 0;

  Window();
  Window(const char* title, int w, int h);
  ~Window();

  void add_new_viewport(Viewport *new_viewport);

  void clear();
  void draw();
  void next_frame();
};

struct Window_manager {
  std::vector<Window*> arr;

  Window* get_by_id(unsigned int id);
  size_t get_index_by_id(unsigned int id);
};

extern Window_manager windows;
void do_inputs();