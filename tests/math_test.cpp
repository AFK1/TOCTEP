
#include "../src/math/vector.hpp"
#include "./all_test.hpp"
#include <cstdio>

int math_test() {
  printf("Run math test\n");

  if (!(Vector2(3, 5) + Vector2(-1, 2) == Vector2(2, 7))) {
    printf("Vector sum error\n");
    return 1;
  }

  return 0;
}
