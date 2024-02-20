#pragma once

struct Vector2 {
  float x;
  float y;

  Vector2();
  Vector2(float a);
  Vector2(float _x, float _y);

  Vector2 operator+(Vector2 vec2) const;
  Vector2 operator-(Vector2 vec2) const;
  Vector2 operator*(Vector2 vec2) const;
  Vector2 operator/(Vector2 vec2) const;
  bool operator==(Vector2 vec2) const;

  Vector2 operator+(float a) const;
  Vector2 operator-(float a) const;
  Vector2 operator*(float a) const;
  Vector2 operator/(float a) const;
  Vector2 operator=(float a);

  float length() const;
  float distance(Vector2 vec2) const;
  float dot(Vector2 vec2) const;
  Vector2 normalize() const;
  Vector2 rotate(float rot) const;
  Vector2 rotate_right() const;
  Vector2 rotate_left() const;
};