#include <stdio.h>
#include <stdlib.h>

/**
 * *  PilhaDupla {
 * *    int arr
 * *    int top1
 * *    int top2
 * *    int tamanho
 * *  }
 *  
 * ALGORITMO: criarPilhaDupla
 * *  ENTRADA: tamanho n da pilha
 * *  SAIDA: PilhaDupla criada
 * 
 * *  pilhaDupla = aloca_memoria(PilhaDupla)
 * *  pilhaDupla.arr = aloca_memoria(int * n)
 * *  pilhaDupla.top1 = -1
 * *  pilhaDupla.top2 = n
 * *  pilhaDupla.tamanho = n
 * 
 * *  retorne pilhaDupla
 * 
 * ALGORITMO: inserirNaPilha1
 * ENTRADA: uma PilhaDupla pd, elemento a ser inserido x
 * COMPLEXIDADE: O(1)  
 * 
 * *  se pd.top1 + 1 == pd.top2 então:
 * *    retorne // pilha cheia
 * *  pd.arr[++(pd.top1)] = x
 * 
 * ALGORITMO: inserirNaPilha2
 * ENTRADA: uma PilhaDupla pd, elemento a ser inserido x
 * COMPLEXIDADE: O(1)
 * 
 * *  se pd.top2 - 1 == pd.top1 então
 * *    retorne
 * 
 * *  pd.arr[--(pd.top2)] = x
 * 
 * ALGORITMO: removerDaPilha1
 * ENTRADA: uma PilhaDupla pd
 * SAIDA: elemento removido
 * COMPLEXIDADE: O(1)
 * 
 * *  se pd.top1 = -1 então
 * *    retorne
 * 
 * *  retorne pd.arr[(pd.top1)--]
 * 
 * ALGORITMO: removerDaPilha2
 * ENTRADA: uma PilhaDupla pd
 * SAIDA: elemento removido
 * COMPLEXIDADE: O(1)
 * 
 * *  se pd.top2 = pd.tamanho então
 * *    retorne
 * 
 * *  retorne pd.arr[(pd.top2)++]
 * 
 * ALGORITMO: top1
 * ENTRADA: uma PilhaDupla pd
 * SAIDA: elemento do topo da pilha 1
 * COMPLEXIDADE: O(1)
 * 
 * *  se pd.top1 == -1 então
 * *    retorne
 * 
 * *  retorne pd.arr[pd.top1]
 * 
 * ALGORITMO: top2
 * ENTRADA: uma PilhaDupla pd
 * SAIDA: elemento do topo da pilha 2
 * COMPLEXIDADE: O(1)
 * 
 * *  se pd.top2 == pd.tamanho então
 * *    retorne
 * 
 * *  retorne pd.arr[pd.top2]
 */

typedef struct DualStack {
  int* arr;
  int top1;
  int top2;
  int size;
} DualStack;

DualStack* createDualStack(int n) {
  DualStack* dualStack = (DualStack*) malloc(sizeof(DualStack));
  
  dualStack->arr = (int*) malloc(sizeof(int) * n);
  dualStack->size = n;
  dualStack->top1 = -1;
  dualStack->top2 = n;

  return dualStack;
}

void push1(DualStack* dualStack, int data) {
  if (dualStack->top1 + 1 == dualStack->top2) { // verifica se as duas filas estão cheias
    return;
  }
  dualStack->arr[++(dualStack->top1)] = data;
}

void push2(DualStack* dualStack, int data) {
  if (dualStack->top2 -1 == dualStack->top1) {
    return;
  }
  dualStack->arr[--(dualStack->top2)] = data;
}

int pop1(DualStack* dualStack) {
  if (dualStack->top1 == -1) {
    return;
  }
  return dualStack->arr[(dualStack->top1)--];
}

int pop2(DualStack* dualStack) {
  if(dualStack->top2 == dualStack->size) {
    return;
  }
  return dualStack->arr[(dualStack->top2)++];
}

int top1(DualStack* dualStack) {
  if (dualStack->top1 == -1) {
    return;
  }
  return dualStack->arr[dualStack->top1];
}

int top2(DualStack* dualStack) {
  if (dualStack->top2 == dualStack->size) {
    return;
  }
  return dualStack->arr[dualStack->top2];
}

void printDualStack(DualStack* dualStack) {
    printf("Elementos da Pilha 1 (do topo para o fundo): ");
    for (int i = dualStack->top1; i >= 0; i--) {
        printf("%d ", dualStack->arr[i]);
    }
    printf("\n");

    printf("Elementos da Pilha 2 (do topo para o fundo): ");
    for (int i = dualStack->top2; i < dualStack->size; i++) {
        printf("%d ", dualStack->arr[i]);
    }
    printf("\n");
}

int main() {
  DualStack* dualStack = createDualStack(20);

  push1(dualStack, 1);
  push1(dualStack, 2);
  push1(dualStack, 3);
  push1(dualStack, 4);
  push1(dualStack, 5);

  push2(dualStack, 6);
  push2(dualStack, 5);
  push2(dualStack, 4);
  push2(dualStack, 3);
  push2(dualStack, 2);

  printDualStack(dualStack);

  return 0;
}