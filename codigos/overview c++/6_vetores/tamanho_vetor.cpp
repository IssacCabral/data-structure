#include <iostream>

using namespace std;

int main() {
  int arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 4};
  int res = sizeof(arr) / sizeof(arr[0]);

  cout << "Tamanho do vetor: ";
  cout << res << endl; // 9 elementos

  return 0;
}