
#include "./camera.hpp"

Camera2d::Camera2d() : Camera2d(Vector2(0), Vector2(100)) {
  
}
Camera2d::Camera2d(Vector2 _pos) : Camera2d(_pos, Vector2(100)) {
  
}
Camera2d::Camera2d(Vector2 _pos, Vector2 _size) : pos(_pos), size(_size) {
  cameras.push_back(this);
}

void Camera2d::move_to_world(World2d *new_world) {
  this->world = new_world;
}
void Camera2d::select_viewport(Viewport *new_viewport) {
  this->viewport = new_viewport;
}

void Camera2d::draw() {
  if (this->world == nullptr || this->viewport == nullptr) return;
  this->world->draw(this->viewport, pos, size);
}

std::vector<Camera2d*> cameras;