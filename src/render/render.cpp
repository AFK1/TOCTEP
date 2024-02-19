
#include "src/render/render.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

void render_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
}