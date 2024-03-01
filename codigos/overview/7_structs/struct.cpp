#include <iostream>
#include <string>

using namespace std;

struct Empregado {
  short id;
  string nome;
  int idade;
  double salario;

  Empregado(short _id, string n, int i, double s) {
    id = _id;
    nome = n;
    idade = i;
    salario = s;
  }
};

void imprime_info(Empregado empregado) {
  cout << "ID: " << empregado.id
    << "\nNome: " << empregado.nome
    << "\nIdade: " << empregado.idade
    << "\nSalario: " << empregado.salario << endl;
}

int main() {
  Empregado issac(1111, "Clidenor Issac", 26, 10000);
  imprime_info(issac);

  return 0;
}