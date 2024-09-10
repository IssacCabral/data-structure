#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * ALGORITMO: removeRepetidos
 * ENTRADA: nó cabeça V de uma pilha, e remove os elementos repetidos
 * mantendo apenas o que está mais acima da pilha
 * COMPLEXIDADE: O(n^2)
 * 
 * *  se V.proximo == NULL então:
 * *    retorne // lista vazia
 * 
 * *  contador = 0
 * *  iterador = V.proximo
 * 
 * *  enquanto iterador != NULL faça:
 * *    contador++
 * *    iterador = iterador.proximo
 * 
 * *  encontrados = aloca_memoria(int * contador)
 * *  tamanhoEncontrados = 0
 * 
 * *  atual = V.proximo
 * *  anterior = V
 * 
 * *  enquanto atual != NULL faça:
 * *    jaEncontrado = false
 * *    i = 0
 * 
 * *    enquanto i < tamanhoEncontrados faça:
 * *      se encontrados[i] == atual.chave então:
 * *        jaEncontrado = true
 * *        saia do laço
 * *      i++
 * 
 * *    se jaEncontrado então: // se já encontrou, remove o nó
 * *      temp = atual
 * *      anterior.proximo = atual.proximo
 * *      atual = atual.proximo
 * *      libera_memoria(temp)
 * *    senão // se não encontrou, então adiciona no array
 * *      encontrados[tamanhoEncontrados] = atual.chave
 * *      tamanhoEncontrados++
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
  if(stack->headNode->next == NULL) {
    return;
  }

  int count = 0;
  Node* iterator = stack->headNode->next;

  while(iterator != NULL) {
    count++;
    iterator = iterator->next;
  }

  int* found = (int*) malloc(sizeof(int) * count);
  int foundSize = 0;

  Node* current = stack->headNode->next;
  Node* prev = stack->headNode;
  
  while (current != NULL) {
    bool alreadyFound = false;
    
    for (int i = 0; i < foundSize; i++) {
      if (found[i] == current->data) {
        alreadyFound = true;
        break;
      }
    }

    if (alreadyFound) {// se ja encontrou, então remove o nó
      Node* temp = current;
      prev->next = current->next;
      current = current->next;
      free(temp);
    } else { //se não encontrou, então adiciona no array
      found[foundSize] = current->data;
      foundSize++;
      prev = current;
      current = current->next;
    }
  }

  free(found);
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