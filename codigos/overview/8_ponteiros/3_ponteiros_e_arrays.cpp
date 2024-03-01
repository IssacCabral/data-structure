#include <iostream>

using namespace std;

int main() {
  int array[5] = {9, 5, 6, 7, 1};

  // valor do primeiro elemento de 'array'
  cout << "array[0]: " <<  array[0] << endl;

  // imprime o endereco do primeiro elemento de 'array'
  cout << "Endereço de array[0]: " << &array[0] << endl;

  // imprime o valor do ponteiro para o qual 'array' decai
  cout << "Array decai para um ponteiro com endereco : ";
  cout << array << endl;

  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    cout << i << ": " << array [i] << endl ;
  }

  return 0;
}