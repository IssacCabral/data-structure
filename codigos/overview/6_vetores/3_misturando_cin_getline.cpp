#include <iostream>

using namespace std;

int main() {
  cout << "Escolha 1 ou 2: ";
  int escolha{0};
  cin >> escolha;

  cin.ignore(); // ignora o primeiro caractere armazenado no buffer

  cout << "Digite seu nome: ";
  string nome;
  getline(cin, nome);

  cout << "Ola, " << nome;
  cout << ", voce escolheu " << escolha << endl;
}