#pragma once

#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>

typedef SDL_Color Color;

void wait_ns(Uint64 ns);
void wait(Uint32 s);
#define when(a) while(a){}