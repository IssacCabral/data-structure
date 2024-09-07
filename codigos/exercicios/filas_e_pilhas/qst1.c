#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * ALGORITMO: removeRepetidos
 * ENTRADA: nó cabeça V de uma pilha encadeada, e remove os nós com chaves repetidas.
 * SAIDA: pilha sem valores repetidos
 * COMPLEXIDADE: O(n)
 * 
 * *  SE V.proximo = NULL ENTÃO:
 * *    retorne // lista vazia
 * *  
 * *  encontrados[1000] = {false} // preenche todo o vetor com false
 * * 
 * *  atual = V.proximo
 * *  anterior = V
 * 
 * *  ENQUANTO atual != NULL FAÇA:
 * *    SE encontrados[atual.valor] ENTÃO:
 * *      anterior.proximo = atual.proximo
 * *      temp = atual
 * *      atual = atual.proximo
 * *      libera_memoria(temp)
 * *    SENÃO:
 * *      encontrados[atual.valor] = true
 * *      anterior = atual
 * *      atual = atual.proximo
 */

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Stack {
  int size;
  Node* headNode;
} Stack;

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Stack* createStack() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;

  stack->headNode = headNode;
  stack->size = 0;

  return stack;
}

void push(Stack* stack, int data) {
  Node* newNode = createNode(data);

  newNode->next = stack->headNode->next;
  stack->headNode->next = newNode;

  (stack->size)++;
}

void pop(Stack* stack) {
  if (stack->headNode->next == NULL) return; // pilha vazia

  Node* temp = stack->headNode->next;
  stack->headNode->next = temp->next;
  free(temp);
  (stack->size)--;
}

void displayStack(Stack* stack) {
  Node* current = stack->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

void removeRepeated(Stack* stack) {
  if (stack->headNode->next == NULL) return; // lista vazia

  bool found[1000] = {false};

  Node* current = stack->headNode->next;
  Node* prev = stack->headNode;

  while (current != NULL) {
    if (found[current->data]) { // se já encontramos o valor antes, removemos o nó atual
      prev->next = current->next;
      Node* temp = current;
      current = current->next;
      free(temp);
      (stack->size)--;
    } else {
      found[current->data] = true;
      prev = current;
      current = current->next;
    }
  }
}

int main () {
  Stack* stack = createStack();

  push(stack, 1);
  push(stack, 4);
  push(stack, 1);
  push(stack, 9);
  push(stack, 7);
  push(stack, 4);
  push(stack, 3);

  displayStack(stack);

  removeRepeated(stack);

  displayStack(stack);

  return 0;
}