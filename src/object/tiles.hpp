#pragma once

#include "../math/vector.hpp"
#include <SDL3/SDL_stdinc.h>
#include <vector>


struct Tile {
  Uint64 tile_id = 0;
  Uint32 atlas_id;
  Uint32 atlas_pos;
};

struct Grid {
  Uint32 width;
  Uint32 height;

  Vector2 pos;
  float rot;

  std::vector<Tile> tiles;
};