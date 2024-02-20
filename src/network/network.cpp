
#include "./network.hpp"
#include <SDL3_net/SDL_net.h>

void network_init() {
  SDLNet_Init();
}

void Server_net::start() {
  SDLNet_CreateServer(NULL, 585);
}