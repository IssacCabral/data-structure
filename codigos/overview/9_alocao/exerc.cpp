#include <iostream>

using namespace std;

void preencherArray(int *A, int n) {
  cout << "Digite os valores do array: " << endl;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }
}

void imprimeArray(int *A, int n) {
  for(int i = 0; i < n; i++) {
    printf("Array[%d]: %d\n", i, *(A+i));
  }
}

void liberarMemoria(int *&A) {
  delete[] A;
  A = nullptr;
}

int main() {
  int *ptr = nullptr;
  int quantity;

  cout << "Digite a quantidade de inteiros: " << endl;
  cin >> quantity;

  ptr = new int[quantity];

  preencherArray(ptr, quantity);

  cout << "Conteúdo do array:" << endl;
  imprimeArray(ptr, quantity);

  cout << ptr << endl;

  liberarMemoria(ptr);

  cout << ptr << endl;

  return 0;
}