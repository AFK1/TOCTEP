#pragma once

#include <SDL3/SDL_surface.h>
#include <vector>

#include "../math/vector.hpp"
#include "../constants.hpp"
#include "../render/window.hpp"

struct Ui_container {
  Vector2 pos;
  std::vector<Ui_container*> children;

  virtual void draw(SDL_Surface *surf_to, Window *window, Vector2 margin);
};