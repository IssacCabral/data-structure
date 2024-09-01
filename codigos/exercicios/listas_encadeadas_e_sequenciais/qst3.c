#include <stdio.h>

/**
 * * Sim, podemos reescrever de maneira mais eficiente, caso a lista passada ja esteja ordenada,
 * * pois só precisamos comparar o elemento atual com o próximo elemento, sem a necessidade de um outro loop interno.
 * * reduzindo assim, a complexidade.
 * * NOVA COMPLEXIDADE: O(n) 
 * 
 * * pseudocódigo
 * 
 * ALGORITMO: removerOcorrencias
 * ENTRADA: Lista sequencial L, ordenada, com elementos duplicados
 * SAIDA: Lista Sequencial L', ordenada, e sem nenhum elemento repetido
 * 
 * * se L.tamanho <= 1 então:
 * *  retorne L;
 * 
 * * indexEscrita = 0
 * * i = 0
 * 
 * * enquanto i < L.tamanho - 1 faça:
 * *  se L[i] != L[i + 1] então:
 * *    L[indexEscrita] = L[i]
 * *    indexEscrita++
 * *  i++
 * 
 * * L[indexEscrita] = L[L.tamanho - 1]  
 */

void removeSortedListOccurrences(int *L, int *length) {
  if (*length <= 1) return;

  int writeIndex = 0;

  for (int i = 0; i < *length - 1; i++) {
    if (L[i] != L[i + 1]) {
      L[writeIndex] = L[i];
      writeIndex++;
    }
  }

  L[writeIndex] = L[*length - 1];
  writeIndex++;

  *length = writeIndex;
}

void printList(int *L, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", L[i]);
  }
  printf("\n");
}

int main() {
  int list[] = {1, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 9, 9};
  int listLength = sizeof(list) / sizeof(list[0]);

  removeSortedListOccurrences(list, &listLength);
  printList(list, listLength);

  return 0;
}