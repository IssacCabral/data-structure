#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// * complexidade: O(n^2)

// * pseudocódigo
/**
 * ALGORITMO: removerOcorrencias
 * ENTRADA: Lista sequencial L
 * SAIDA: Lista Sequencial L', sem nenhum elemento repetido
 * 
 * * se L.tamanho <= 1 então:
 * *  retorne L;
 * 
 * * indexEscrita = 0
 * * i = 0
 * 
 * * enquanto i < L.tamanho faça:
 * *  encontrouDuplicado = false
 * *  j = 0
 * 
 * *  enquanto j < indexEscrita faça:
 * *    se L[i] == L[j] então: // encontrou um duplicado
 * *      encontrouDuplicado = true
 * *      saia do loop
 * *    j++
 * *  
 * *  se !encontrouDuplicado então:
 * *    L[indexEscrita] = L[i]
 * *    indexEscrita++
 * *  i++
 * 
 * * L.tamanho = indexEscrita
 * 
 * * retorne L  
 * *  
 */

void removeOccurrences(int *L, int *length) {
  if (*length <= 1) return;

  int writeIndex = 0;

  for (int i = 0; i < *length; i++) {
    int isDuplicated = 0;
    for (int j = 0; j < writeIndex; j++) {
      if (L[i] == L[j]) {
        isDuplicated = 1;
        break;
      }
    }

    if (!isDuplicated) {
      L[writeIndex] = L[i];
      writeIndex++;
    }
  }

  *length = writeIndex;
}

void printList(int *L, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", L[i]);
  }
  printf("\n");
}

int main() {
  int list[] = {1, 2, 3, 4, 1, 5, 2, 4, 0, 7}; // * [1, 2, 3, 4, 5, 0, 7]
  int length = sizeof(list) / sizeof(list[0]);

  removeOccurrences(list, &length);
  printList(list, length);

  return 0;
}