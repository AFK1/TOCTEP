

#include "src/math/vector.hpp"
#include <math.h>

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float a) : x(a), y(a) {}
Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

Vector2 Vector2::operator+(Vector2 vec2) {
  return Vector2(x+vec2.x, y+vec2.y);
}
Vector2 Vector2::operator-(Vector2 vec2) {
  return Vector2(x-vec2.x, y-vec2.y);
}
Vector2 Vector2::operator*(Vector2 vec2) {
  return Vector2(x*vec2.x, y*vec2.y);
}
Vector2 Vector2::operator/(Vector2 vec2) {
  return Vector2(x/vec2.x, y/vec2.y);
}
bool Vector2::operator==(Vector2 vec2) {
  return x==vec2.x && y==vec2.y;
}

Vector2 Vector2::operator+(float a) {
  return Vector2(x+a, y+a);
}
Vector2 Vector2::operator-(float a) {
  return Vector2(x-a, y-a);
}
Vector2 Vector2::operator*(float a) {
  return Vector2(x*a, y*a);
}
Vector2 Vector2::operator/(float a) {
  return Vector2(x/a, y/a);
}
Vector2 Vector2::operator=(float a) {
  x = a;
  y = a;
  return Vector2(a);
}

float Vector2::length() {
  return sqrtf(x*x+y*y);
}
float Vector2::distance(Vector2 vec2) {
  return (*this - vec2).length();
}
float Vector2::dot(Vector2 vec2) {
  return x*vec2.x + y*vec2.y;
}
Vector2 Vector2::normalize() {
  return Vector2(x/length(), y/length());
}