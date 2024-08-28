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
 * 
 * * enquanto i < L.tamanho faça:
 * *  j = 0
 * 
 * *  enquanto j < indexEscrita faça:
 * *    se L[i] == L[j] então: // encontrou um duplicado
 * *      saia do loop
 * *    j++
 * *  
 * *  se j == indexEscrita então:
 * *    L[indexEscrita] = L[i]
 * *    indexEscrita++
 * 
 * *  i++
 * 
 * * retorne L  
 * *  
 */

void removeOccurrences(int list[], int *length) {
  if (*length <= 1) return exit(1);

  int writeIndex = 0;
  
  for (int i = 0; i < *length; i++) {
    int j;
    for (j = 0; j < writeIndex; j++) {
      if(list[i] == list[j]) {
        break; // Encontrou um duplicado, saia do loop
      }
    }

    if (j == writeIndex) {
      // não encontrou duplicado, adiciona o elemento
      list[writeIndex] = list[i];
      writeIndex++; // 6
    }
  }

  *length = writeIndex;
}

void printList(int list[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

int main() {
  // int list[] = {0, 2, 3, 4, 5, 2, 4, 0, 7};
  int list[] = {1, 2, 3, 4, 5, 2, 4, 0, 7};
  int length = sizeof(list) / sizeof(list[0]);

  removeOccurrences(list, &length);
  printList(list, length);

  return 0;
}