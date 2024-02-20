

#include "./viewport.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_surface.h>

Viewport::Viewport() : Viewport(Vector2(100)) {

}
Viewport::Viewport(Vector2 size) : Viewport(Vector2(size), Vector2(0)) {

}
Viewport::Viewport(Vector2 size, Vector2 pos) {
  src = new SDL_Rect();
  src->x=pos.x;
  src->y=pos.y;
  src->w=size.x;
  src->h=size.y;
  dst = new SDL_Rect();
  dst->x=0;
  dst->y=0;
  dst->w=size.x;
  dst->h=size.y;
  surface = SDL_CreateSurface(size.x, size.y, SDL_PIXELFORMAT_XRGB8888);
}