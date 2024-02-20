#pragma once

#include "./viewport.hpp"
#include "../world.hpp"
#include "../math/vector.hpp"
#include <vector>

struct Camera2d {
  Vector2 pos;   /* positon in world */
  Vector2 size;  /* render zone      */
  World2d *world;
  Viewport *viewport;

  Camera2d();
  Camera2d(Vector2 _pos);
  Camera2d(Vector2 _pos, Vector2 _size);

  void move_to_world(World2d *new_world);
  void select_viewport(Viewport *new_viewport);

  void draw();
};

extern std::vector<Camera2d*> cameras;