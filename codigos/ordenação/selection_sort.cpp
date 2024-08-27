#include <iostream>

/**
 * ALGORITMO: SELECTION SORT(V)
 * ENTRADA: Vetor V
 * OBJETIVO: Ordenar V por selação (em ordem crescente)
 * 
 * * para i de 0 até |V|-1 faça:
 * *  imenor <-- Menor(V, i)
 * *  V[i] <--> V[imenor] 
*/

/**
 * ALGORITMO: Menor(V, i)
 * ENTRADA: Vetor V, índice i
 * SAIDA: índice do menor elemento em V[i...|V|-1] 
 * 
 * * imenor <-- i
 * * para j de i+1 até |V|-1 faça:
 * *  se V[j] < V[imenor] então
 * *    imenor <-- j  
 * * retorne imenor
*/

void selectionSort(int *arr, int size) {
  for(int i = 0; i < size - 1; i++) {
    int min_index = i;

    for(int j = i+1; j < size; j++) {
      if(arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    if(min_index != i) {
      int aux = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = aux;
    }
  }
}

int main () {
  int vec[] = {6, 8, 9, 4, 1, 7, 2};
  const int vec_size = sizeof(vec) / sizeof(vec[0]);

  std::cout << "Array antes da ordenação: " << std::endl;
  for(int i = 0; i < vec_size; i++) {
    std::cout << vec[i] << std::endl;
  }

  selectionSort(vec, vec_size);

  std::cout << "Array após a ordenação: " << std::endl;
  for(int i = 0; i < vec_size; i++) {
    std::cout << vec[i] << std::endl;
  }

  return 0;
}