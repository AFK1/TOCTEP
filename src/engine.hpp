#pragma once

enum Engine_init_flags {
  Engine_init_nothing,
  Engine_init_video,
  Engine_init_audio,
  Engine_init_network,
  Engine_init_everything = 0b1111
};


void engine_init(Engine_init_flags flags);
void engine_deinit();
void engine_thread();