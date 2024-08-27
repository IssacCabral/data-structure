#include <iostream>

/**
 * Para acessarmos os campos de uma variável struct via um ponteiro,
 * podemos utilizar o operador ( * ) juntamente com o operador ( . ) como
 * de costume:
 * 
 * Em C também podemos usar o operador (->) para acessar campos de
 * uma estrutura via um ponteiro.
 * 
 * Para acessar campos de estruturas via ponteiros use um dos dois:
 * 
 * ponteiroEstrutura->campo
 * (*ponteiroEstrutura).camp
*/

struct Ponto {
  double x;
  double y;
};

int main() {
  Ponto p1, p2, *ptr1, *ptr2;

  ptr1 = &p1;
  ptr2 = &p2;

  p1.x = 1;
  p1.y = 2;

  p2.x = 3;
  p2.y = 4;

  (*ptr1).x = 2.5;
  (*ptr1).y = 2.5;

  ptr2->x = 4.5;
  ptr2->y = 4.5;

  std :: cout << "p1 = (" << p1.x << "," << p1.y << ")\n";
  std :: cout << "p2 = (" << p2.x << "," << p2.y << ")\n";

  return 0;
}