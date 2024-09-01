#include <stdio.h>

int binarySearch(int *L, int length, int target) {
  int low = 0, high = length - 1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if (L[mid] == target) {
      return mid;
    }

    if (L[mid] < target) {
      low = mid + 1; // o elemento está na metade direita
    } else {
      high = mid - 1; // o elemento está na metade esquerda
    }
  }

  return -1; // elemento não encontrado
}

int main() {
  int list[] = {1, 3, 6, 8, 9, 10, 10, 11, 14, 16, 17};
  int listLength = sizeof(list) / sizeof(list[0]);

  int result = binarySearch(list, listLength, 3);
  printf("Resultado: %d\n", result);

  return 0;
}