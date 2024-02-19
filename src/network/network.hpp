#pragma once

#include <SDL3_net/SDL_net.h>
#include <vector>

void network_init();

struct Server_net {
  SDLNet_Server *server;
  std::vector<SDLNet_Address*> clients;

  void start();
};