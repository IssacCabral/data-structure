#include <stdio.h>

/**
 * * complexidade: O(n)
 * 
 * * pseudocódigo
 * 
 * ALGORITMO: incluirOrdenado
 * ENTRADA: Lista sequencial L ordenada, elemento x a ser inserido
 * SAIDA: Lista sequencial L' ordenada, com o elemento x inserido
 * 
 * * i = L.tamanho - 1
 * 
 * * enquanto i >= 0 E L[i] > x faça:
 * *  L[i + 1] = L[i]
 * *  i--
 * 
 * * L[i + 1] = x
 * * L.tamanho += 1
 */

void includeOrdered(int *L, int *length, int x) {
  int i = *length - 1;

  while (i >= 0 && L[i] > x) {
    L[i + 1] = L[i];
    i--;
  }

  L[i + 1] = x;
  (*length)++;
}

void printList(int *L, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", L[i]);
  }
  printf("\n");
}

int main() {
  int list[100] = {};
  int listLength = 0;

  includeOrdered(list, &listLength, 3);
  printList(list, listLength);
  printf("Tamanho da lista: %d\n", listLength);

  return 0;
}