#include <stdio.h>
#include <stdlib.h>

/**
 * * complexidade O(n)
 * 
 * ALGORITMO: removeTodos
 * ENTRADA: Nó cabeça V, e elemento a ser removido X
 * OBS: a função deve remover todas as ocorrências de x na lista encadeada
 * 
 * * atual = V
 * 
 * * ENQUANTO atual.proximo != NULL FAÇA:
 * *  SE atual.proximo.chave = x ENTÃO:
 * *    temp = atual.proximo
 * *    atual.proximo = atual.proximo.proximo
 * *    libera_memoria(temp)
 * *  SENÃO
 * *    atual = atual.proximo
 * *
 */

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList {
  int size;
  Node* headNode;
} LinkedList;

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;

  list->headNode = headNode;
  list->size = 0;

  return list;
}

void addLast(LinkedList* list, int data) {
  Node* newNode = createNode(data);
  Node* current = list->headNode;

  while (current->next != NULL) {
    current = current->next;
  }

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

void removeAll(LinkedList* list, int x) {
  Node* current = list->headNode;

  while (current->next != NULL) {
    if (current->next->data == x) {
      Node* temp = current->next;// no que será removido
      current->next = current->next->next;

      free(temp);
      (list->size)--;
    } else {
      current = current->next;
    }
  }
}

int main() {
  LinkedList* list = createLinkedList();

  addLast(list, 3);
  addLast(list, 7);
  addLast(list, 100);
  addLast(list, 100);
  addLast(list, 12);
  addLast(list, 7);
  addLast(list, 1);

  removeAll(list, 7);

  displayList(list);


  return 0;
}