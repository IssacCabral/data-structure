#include <stdio.h>

void removeOccurrences(int *L1, int *lengthL1, int *L2, int lengthL2) {
  if (*lengthL1 <= 1) return;
  
  int writeIndex = 0;
  
  for (int i = 0; i < *lengthL1; i++) {
    int isDuplicated = 0;

    for (int j = 0; j < lengthL2; j++) {
      if(L1[i] == L2[j]) {
        isDuplicated = 1;
        break;
      }
    }

    if (!isDuplicated) {
      L1[writeIndex] = L1[i];
      writeIndex++;
    }
  }

  *lengthL1 = writeIndex;
}

void printList(int *L, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", L[i]);
  }
  printf("\n");
}

int main() {
  int l1[] = {1, 4, 7, 8, 9, 10}; // * [7, 8, 9, 10]
  int l2[] = {1, 2, 3, 4, 9}; 
  int l1Length = sizeof(l1) / sizeof(l1[0]);
  int l2Length = sizeof(l2) / sizeof(l2[0]);

  removeOccurrences(l1, &l1Length, l2, l2Length);
  printList(l1, l1Length);

  return 0;
}