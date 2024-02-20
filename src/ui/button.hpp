#pragma once

#include "ui_container.hpp"
#include <SDL3/SDL_stdinc.h>

struct Button : Ui_container {
  Uint32 default_color = 0x888888;
  Uint32 hovered_color = 0xaaaaaa;
  Uint32 clicked_color = 0x444444;
  void (*on_hovered)();
  void (*on_click)();
};