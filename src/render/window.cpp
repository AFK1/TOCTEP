
#include <SDL3/SDL.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "./window.hpp"

void do_inputs() { /* TODO: move from render/ */
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_EVENT_MOUSE_MOTION:

      break;
      case SDL_EVENT_MOUSE_BUTTON_DOWN:

      break;
      case SDL_EVENT_KEY_DOWN:
      windows.arr[windows.get_index_by_id(event.window.windowID)]->key_pressed[event.key.keysym.scancode % 300] = true;
      break;
      case SDL_EVENT_KEY_UP:
      windows.arr[windows.get_index_by_id(event.window.windowID)]->key_pressed[event.key.keysym.scancode % 300] = false;
      break;
    }
  }
}

Window::Window() : Window(default_window_title, default_window_width, default_window_height) {
  
}
Window::Window(const char* title, int w, int h) {
  this->window = SDL_CreateWindow(title, w, h, 0);
  windows.arr.push_back(this);
}
Window::~Window() {
  windows.arr.erase(windows.arr.begin() + windows.get_index_by_id(SDL_GetWindowID(window)));
  SDL_DestroyWindow(window);
}

void Window::add_new_viewport(Viewport *new_viewport) {
  this->viewports.push_back(new_viewport);
}

void Window::clear() {
  SDL_FillSurfaceRect(SDL_GetWindowSurface(this->window), NULL, 0x000000);
}
void Window::draw() {
  for (Viewport *viewport : this->viewports) {
    SDL_BlitSurface(viewport->surface, viewport->src, SDL_GetWindowSurface(this->window), viewport->dst);
  }
  ui->draw(SDL_GetWindowSurface(this->window), this, Vector2(0));
}
void Window::next_frame() {
  SDL_UpdateWindowSurface(this->window);
}

Window* Window_manager::get_by_id(unsigned int id) {
  for (Window *window : this->arr) {
    if (SDL_GetWindowID(window->window) == id) {
      return window;
    }
  }
  return nullptr;
}
size_t Window_manager::get_index_by_id(unsigned int id) {
  for (size_t i = 0; i<this->arr.size(); ++i) {
    if (SDL_GetWindowID(windows.arr[i]->window) == id) {
      return i;
    }
  }
  printf("Not found id:%u\n", id);
  return -1;
}

Window_manager windows;