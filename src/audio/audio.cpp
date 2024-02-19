
#include "src/audio/audio.hpp"
#include <SDL3_mixer/SDL_mixer.h>

void audio_init() {
  Mix_Init(MIX_INIT_OGG);
}