#include <iostream>

/**
 * ALGORITMO: INSERTION SORT(V)
 * ENTRADA: Vetor V
 * 
 * * para k de 1 até |V|-1 faça:
 * *  InserirOrdenado(V, k)
 * 
 * ALGORITMO: INSERIR ORDENADO(V, i)
 * ENTRADA: Vetor V, índice i
 * REQUISITO: V[0... i-1] ordenado
 * 
 * * temp <-- V[i]
 * * i <-- i-1
 * * enquanto i >= 0 e V[i] > temp faça:
 * *  V[i+1] <-- V[i]
 * *  i <-- i-1
 * * V[i+1] <-- temp 
 * 
*/

void insertionSort(int *arr, int size) {
  for(int i = 1; i < size - 1; i++) {
    int key = arr[i]; 
    int j = i - 1; 

    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = key;
  }
}

int main() {
  int arr[] = {2, 4, 8, 7, 6, 3, 5, 1, 9, 10};

  const int arr_size = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Array antes da ordenação: " << std::endl;
  for(int i = 0; i < arr_size; i++) {
    std::cout << arr[i] << std::endl;
  }

  insertionSort(arr, arr_size);

  std::cout << "Array após a ordenação: " << std::endl;
  for(int i = 0; i < arr_size; i++) {
    std::cout << arr[i] << std::endl;
  }

  return 0;
}