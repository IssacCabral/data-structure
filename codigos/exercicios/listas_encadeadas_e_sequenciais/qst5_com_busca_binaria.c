#include <stdio.h>

// * complexidade: O(m log n), onde m é o tamanho de L1 e n é o tamanho de L2.

int binarySearch(int *L, int length, int target) {
  int low = 0, high = length - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (L[mid] == target) {
      return mid;
    }

    if (L[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

void removeOccurrences(int *L1, int *lengthL1, int *L2, int lengthL2) {
  if (*lengthL1 <= 1) return;
  
  int writeIndex = 0;
  
  for (int i = 0; i < *lengthL1; i++) {
    int searchResult = binarySearch(L2, lengthL2, L1[i]);
    if (searchResult != -1) {
      continue;
    }

    L1[writeIndex] = L1[i];
    writeIndex++;
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
  int l1[] = {1, 4, 7, 8, 9, 10};
  int l2[] = {1, 2, 3, 4, 9}; 
  int l1Length = sizeof(l1) / sizeof(l1[0]);
  int l2Length = sizeof(l2) / sizeof(l2[0]);

  removeOccurrences(l1, &l1Length, l2, l2Length);
  printList(l1, l1Length);

  return 0;
}