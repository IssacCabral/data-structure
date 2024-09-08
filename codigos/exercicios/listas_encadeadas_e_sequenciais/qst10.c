#include <stdio.h>
#include <stdlib.h>

/**
 * * complexidade: O(n)
 * 
 * ALGORITMO: IncluirOrdenado
 * ENTRADA: Nó cabeça V de uma lista encadeada ordenada, elemento X para inserir
 * OBS: deve ser inserido o elemento X de maneira ordenada na lista encadeada
 * 
 * *  novoNo = aloca_memoria(No)
 * *  novoNo.chave = X
 * *  novoNo.proximo = NULL
 * 
 * *  atual = V
 * *  enquanto atual.proximo != NULL E atual.proximo.chave <= x faça:
 * *    atual = atual.proximo
 * 
 * *  novoNo.proximo = atual.proximo
 * *  atual.proximo = novoNo
 */

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList {
  int size;
  Node* headNode;
} LinkedList;

LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;

  list->headNode = headNode;
  list->size = 0;

  return list;
}

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void includeOrdered(LinkedList* list, int x) {
  Node* newNode = createNode(x);
  Node* current = list->headNode;

  while (current->next != NULL && current->next->data <= x) {
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;

  (list->size)++;
}

void displayList(LinkedList* list) {
  Node* current = list->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  LinkedList* list = createLinkedList();

  includeOrdered(list, 3);
  includeOrdered(list, 7);
  includeOrdered(list, 100);
  includeOrdered(list, 100);
  includeOrdered(list, 12);
  includeOrdered(list, 7);
  includeOrdered(list, 1);

  displayList(list);

  return 0;
}