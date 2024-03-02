#include <iostream>

/**
 * Um ponto no plano catersiano é definido pela sua coordenada x e sua
 * coordenada y. Seja Ponto um struct com dois campos x e y, do tipo float.
 * 
 * Implemente uma função que recebe dois valores do tipo Ponto como 
 * argumento e troca os valores dos pontos. Sua função deve obedecer o protótipo:
 * void troca(Ponto *p1, Ponto *p2);
 * 
 * Implemente uma função que recebe um valor do tipo Ponto como 
 * argumento e dobra os valores das suas coordenadas.
*/

struct Point {
  float x;
  float y;
};

void change(Point *p1, Point *p2) {
  Point tempPoint;

  tempPoint.x = p1->x;
  p1->x = p2->x;
  p2->x = tempPoint.x;

  tempPoint.y = p1->y;
  p1->y = p2->y;
  p2->y = tempPoint.y;
}

void doubleValues(Point *p) {
  (*p).x *= 2;
  (*p).y *= 2;
}

int main() {
  Point p1 = {1.0, 2.0};
  Point p2 = {3.0, 4.0};

  Point *ptr1 = &p1;
  Point *ptr2 = &p2;

  // Exibindo os pontos antes da troca
  printf("Antes da troca:\n");
  printf("Ponto 1: (%.2f, %.2f)\n", p1.x, p1.y);
  printf("Ponto 2: (%.2f, %.2f)\n", p2.x, p2.y);

  change(ptr1, ptr2);

  // Exibindo os pontos depois da troca
  printf("\nDepois da troca:\n");
  printf("Ponto 1: (%.2f, %.2f)\n", p1.x, p1.y);
  printf("Ponto 2: (%.2f, %.2f)\n", p2.x, p2.y);

  // Dobrando os valores do p1
  doubleValues(ptr1);

  std::cout << "Valores de p1:\n";
  std::cout << "x: " << p1.x << std::endl;
  std::cout << "y: " << p1.y << std::endl;

  return 0;
}