#include <iostream>

int main() {
  int z = 23; // Iniciação por atribuição - assignment
  std::cout << "Valor de z: " << z << std::endl;

  int k = 45.89; // ok --> pega apenas a parte inteira
  std::cout << "Valor de k: " << k << std::endl;

  int w(23); // Inicialização direta - direct initialization
  std::cout << "Valor de w: " << w << std::endl;

  int s(32.75); // ok --> pega apenas a parte inteira
  std::cout << "Valor de s: " << s << std::endl;

  int y{23}; // inicialização uniform --> uniform initialization (C++11)
  std::cout << "Valor de y: " << y << std::endl;

  int x{5.6}; /**Erro de compilação*/  
  std::cout << "Valor de x: " << x << std::endl;

  return 0;
}