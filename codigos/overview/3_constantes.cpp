#include <iostream>

using namespace std;

int main() {
  const double gravidade {9.7}; // constante em tempo de compilação
  cout << gravidade << endl;

  cout << "Digite sua idade: ";
  unsigned short int idade;
  cin >> idade;

  const unsigned short int idadeUsuario {idade}; // constante em tempo de execução
  cout << idadeUsuario << endl;

  return 0;
}