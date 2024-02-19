

#include "src/engine.hpp"
#include "src/audio/audio.hpp"
#include "src/network/network.hpp"
#include "src/render/render.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_net/SDL_net.h>
#include <SDL3_ttf/SDL_ttf.h>

void engine_init(Engine_init_flags flags) {
  if (flags & Engine_init_video) {
    render_init();
  }
  if (flags & Engine_init_audio) {
    audio_init();
  }
  if (flags & Engine_init_network) {
    network_init();
  }
}

void engine_deinit() {
  TTF_Quit();
  IMG_Quit();
  SDLNet_Quit();
  Mix_Quit();
  SDL_Quit();
}