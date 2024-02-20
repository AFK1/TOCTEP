
#include "./world.hpp"
#include <SDL3/SDL_surface.h>
#include <cstddef>

void World2d::draw(Viewport *viewport, Vector2 position, Vector2 size) {
  SDL_FillSurfaceRect(viewport->surface, NULL, this->bg_color);
  for (Object_container *object : objects) {
    switch (object->type) {
      case Object_type::None: {
      } break;
      case Object_type::Grid: {
        Grid *grid = ((Grid*)(object->object));
        SDL_Rect rect;
        const Vector2 mv_right = Vector2(1, 0).rotate(grid->rot);
        const Vector2 mv_down = mv_right.rotate_right();
        const Vector2 start = grid->pos + (mv_right * -grid->width/2) + (mv_down * -grid->height/2) - position;
        rect.x = start.x;
        rect.y = start.y;
        rect.w = 50;
        rect.h = 50;
        for (size_t i=0; grid->tiles.size(); ++i) {
          if (i%grid->width == 0) {
            rect.x = start.x + (mv_down * i/grid->width).x - mv_right.x;
            rect.y = start.y + (mv_down * i/grid->width).y - mv_right.x;
          }
          rect.x += mv_right.x;
          rect.y += mv_right.y;
          if (grid->tiles[i].tile_id == 0) continue;
          SDL_FillSurfaceRect(viewport->surface, &rect, 0xffffff);
        }
      } break;
      default: {
      } break;
    }
  }
}