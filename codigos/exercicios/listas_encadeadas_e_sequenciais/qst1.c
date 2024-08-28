#include <stdio.h>

// * complexidade: O(n)

// * pseudocódigo
/**
 *  ALGORITMO: removeTodos
 *  ENTRADA: Lista Sequencial L, elemento x
 *  SAIDA: Lista Sequencial L' sem as recorrências do elemento x
 * 
 * * indexEscrita = 0
 * * i = 0
 * * enquanto i < L.tamanho faça
 * *  se L[i] != x então:
 * *    L[indexEscrita] = L[i]
 * *    i++
 * *    indexEscrita++
 * * retorne L;
 */


int removeAll(int list[], int length, int element) {
  int writeIndex = 0;

  for (int i = 0; i < length; i++) {
    if(list[i] != element) {
      list[writeIndex] = list[i];
      writeIndex++;
    }
  }

  return writeIndex;
}

void printList(int list[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d\n", list[i]);
  }
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 2, 4, 7};
  int length = 8;

  int newLength = removeAll(list, length, 2);
  length = newLength;

  printList(list, length);


  return 0;
}