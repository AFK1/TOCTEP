

#include "./ui_container.hpp"

void Ui_container::draw(SDL_Surface *surf_to, Window *window, Vector2 margin) {
  for (Ui_container *child : children) {
    child->draw(surf_to, window, margin + 5);
  }
}