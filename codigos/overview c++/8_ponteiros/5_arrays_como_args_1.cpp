#include <iostream>

using namespace std;

// ! Quando passamos um array por valor, ele decai para um ponteiro.
// ! O que ele faz é enviar o primeiro endereço para o array que é um ponteiro, 
// ! portanto, o tamanho do array não é o original, mas aquele ocupado pelo ponteiro na memória.

void printSize(int array[]) {
  // array eh tratado como ponteiro aqui
  // o tamanho do ponteiro sera impresso
  cout << sizeof(array) << endl;
}

int main() {
  int array[] = {1, 1, 2, 3, 5, 8, 13, 21};

  cout << sizeof(array) << endl;

  printSize(array);

  return 0;
}