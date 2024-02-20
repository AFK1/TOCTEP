
#include "./all_test.hpp"
#include <cstdio>

int run_test() {

  printf("run math test\n");
  if (math_test()) {
    return 1;
  }
  printf("math test end\n");
  return 0;
}