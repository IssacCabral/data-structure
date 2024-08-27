#include <iostream>

using namespace std;

int main() {
  char name[10]; // declara um array de tamanho 10

  std::cout << "Digite seu nome: ";
  std::cin.get(name, 10);
  std::cout << "Você digitou: " << name << std::endl;

  return 0;
}