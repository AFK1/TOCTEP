
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "src/utils.hpp"
#include "src/render/window.hpp"

void do_inputs() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_EVENT_QUIT:
      SDL_GetWindowFromID(event.window.windowID);
      windows[event.window.windowID]->want_quit = true;
      break;
      case SDL_EVENT_KEY_DOWN:
      windows[event.window.windowID]->key_pressed[event.key.keysym.scancode % 300] = true;
      break;
      case SDL_EVENT_KEY_UP:
      windows[event.window.windowID]->key_pressed[event.key.keysym.scancode % 300] = false;
      break;
    }
  }
}

Window::Window(const char* title, int w, int h) : window(SDL_CreateWindow(title, w, h, 0)), renderer(SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED)) {
  windows.windows.push_back(this);
}
Window::~Window() {
  windows.windows.erase(windows.windows.begin() + windows.get_index_by_id(SDL_GetWindowID(window)));
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Window::clear(Color color) {
  SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(this->renderer);
}
void Window::next_frame() {
  SDL_RenderPresent(this->renderer);
}


Window* Window_manager::operator[](int index) {
  return this->windows[index];
}
Window* Window_manager::get_by_id(unsigned int id) {
  for (Window *window : this->windows) {
    if (SDL_GetWindowID(window->window) == id) {
      return window;
    }
  }
  return nullptr;
}
int Window_manager::get_index_by_id(unsigned int id) {
  for (size_t i = 0; i<this->windows.size(); ++i) {
    if (SDL_GetWindowID(windows[i]->window) == id) {
      return i;
    }
  }
  return -1;
}