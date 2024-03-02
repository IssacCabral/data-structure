#include <iostream>

// ! Quando modifica array() é chamado, vec 
// ! decai em um ponteiro e o valor desse ponteiro é copiado no parâmetro ptr.

void modifica_array(int ptr[]) {
  *ptr = 5;
}

int main() {
  int v[] = {1, 4, 2, 3, 7, 8, 13, 21};

  modifica_array(v);

  int v_length = sizeof(v) / sizeof(v[0]);

  for (int i = 0; i < v_length; i++) {
    std :: cout << " v [" << i << "] = " << v [i] << "\n";
  }

  return 0;
}