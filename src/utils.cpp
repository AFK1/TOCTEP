

#include "src/utils.hpp"

void wait_ns(Uint64 ns) {
  SDL_DelayNS(ns);
}
void wait(Uint32 s) {
  SDL_Delay(s);
}