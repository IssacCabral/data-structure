#include <stdio.h>
#include <stdlib.h>

/**
 * ALGORITMO: orderLinkedList
 * ENTRADA: Nó cabeça V de uma lista encadeada, e a ordena
 * COMPLEXIDADE: O(n^2)
 *  
 * * atual = V.proximo
 * 
 * * ENQUANTO atual != NULL FAÇA:
 * *  menorNo = atual
 * *  proximoNo = atual.proximo
 * 
 * *  ENQUANTO proximoNo != NULL FAÇA:
 * *    SE proximoNo.valor < menorNo.valor ENTÃO:
 * *      menorNo = proximoNo
 * *    proximoNo = proximoNo.proximo
 * 
 * *  SE menorNo.valor != atual.valor ENTÃO:
 * *    temp = atual.valor
 * *    atual.valor = menorNo.valor
 * *    menorNo.valor = temp
 * 
 * *  atual = atual.proximo
 * 
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

  list->size = 0;
  list->headNode = headNode;

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

void sort(LinkedList* list) {
  Node* current = list->headNode->next;

  while (current != NULL) {
    Node* minNode = current;
    Node* nextNode = current->next;

    while (nextNode != NULL) {
      if (nextNode->data < minNode->data) {
        minNode = nextNode;
      }
      nextNode = nextNode->next;
    }

    if (minNode->data != current->data) {
      int temp = current->data;
      current->data = minNode->data;
      minNode->data = temp;
    }

    current = current->next;
  }

  
}

int main() {
  LinkedList* list = createLinkedList();

  addLast(list, 5);
  addLast(list, 4);
  addLast(list, 5);
  addLast(list, 2);
  addLast(list, -5);
  addLast(list, 3);
  addLast(list, 1);

  displayList(list);

  sort(list);

  displayList(list);

  return 0;
}