#pragma once

#include "../math/vector.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>

struct Viewport {
  SDL_Surface *surface;
  SDL_Rect *src;
  SDL_Rect *dst;

  Viewport();
  Viewport(Vector2 size);
  Viewport(Vector2 size, Vector2 pos);
};
