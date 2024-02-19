#pragma once

struct Vector2 {
  float x;
  float y;

  Vector2();
  Vector2(float a);
  Vector2(float _x, float _y);

  Vector2 operator+(Vector2 vec2);
  Vector2 operator-(Vector2 vec2);
  Vector2 operator*(Vector2 vec2);
  Vector2 operator/(Vector2 vec2);
  bool operator==(Vector2 vec2);

  Vector2 operator+(float a);
  Vector2 operator-(float a);
  Vector2 operator*(float a);
  Vector2 operator/(float a);
  Vector2 operator=(float a);

  float length();
  float distance(Vector2 vec2);
  float dot(Vector2 vec2);
  Vector2 normalize();
};