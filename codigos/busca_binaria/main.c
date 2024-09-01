#include <stdio.h>

int linearSearch(int *L, int length, int target) {
  for (int i = 0; i < length; i++) {
    if (L[i] == target) {
      return i;
    }
  }

  return -1; // elemento não encontrado
}

int main() {
  int list[] = {1, 3, 6, 8, 9, 10, 10, 11, 14, 16, 17};
  int listLength = sizeof(list) / sizeof(list[0]);

  

  return 0;
}