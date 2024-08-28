#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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