#include <iostream>

using namespace std;

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