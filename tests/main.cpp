
#include "./all_test.hpp"
#include <cstdio>

int main() {

  if (run_test()) {
    printf("Test not passed\n");
    return 1;
  }

  return 0;
}