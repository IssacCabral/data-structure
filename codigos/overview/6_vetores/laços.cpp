#include <iostream>

int main() {
  // ! atenção: O vetor e o loop devem estar no mesmo escopo
  int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13};

  for (auto valor : fibonacci) {
    std::cout << valor << std::endl;
  }
}