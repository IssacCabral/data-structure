#include <iostream>
#include "mymath.h"

using namespace math;

int main() {
  int a{5}, b{10};

  std::cout << math::sum(a, b) << std::endl;
  std::cout << math::sub(a, b) << std::endl;
  std::cout << math::mul(a, b) << std::endl;
  std::cout << math::div(a, b) << std::endl;

  return 0;
}