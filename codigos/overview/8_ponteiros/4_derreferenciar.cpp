#include <iostream>

using namespace std;

int main() {
  int array[5] = {9, 5, 6, 7, 1};

  // dereferenciar um array retorna o primeiro elemento
  cout << *array << endl;

  // Dada essa propriedade dos arrays , podemos declarar
  // um ponteiro do tipo int e fazer ele apontar para array
  int *ptr = array;
  cout << *ptr << endl;

  return 0;
}