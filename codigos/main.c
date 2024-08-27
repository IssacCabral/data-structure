#include <stdio.h>

void main() {
  int a = 10;
  int *p = &a;

  printf("Valor para qual o ponteiro p aponta: %d\n", *p);
}