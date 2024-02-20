

#include "./engine.hpp"
#include "./audio/audio.hpp"
#include "./network/network.hpp"
#include "./render/camera.hpp"
#include "./render/render.hpp"
#include "./render/window.hpp"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_net/SDL_net.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdio>
#include <thread>

bool need_deinit = false;
bool ready_deinit = false;

void engine_thread() {
  do_inputs();
  for (Camera2d *camera : cameras) {
    camera->draw();
  }
  for (Window *window : windows.arr) {
    window->clear();
    window->draw();
    window->next_frame();
  }
}

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
  return;
}