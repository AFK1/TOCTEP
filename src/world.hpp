#pragma once

#include "./math/vector.hpp"
#include "./object/object.hpp"
#include "./object/tiles.hpp"
#include "./render/viewport.hpp"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <vector>

struct World2d {
  void draw(Viewport *viewport, Vector2 position, Vector2 size);

  Uint32 bg_color = 0x000000;
  SDL_Texture *atlas;
  std::vector<Object_container*> objects;
};
