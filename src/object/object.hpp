#pragma once

enum class Object_type {
  None,

  Grid,
};

struct Object_container {
  Object_type type;
  void *object;
};