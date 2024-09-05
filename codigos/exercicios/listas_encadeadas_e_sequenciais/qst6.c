#include <stdio.h>
#include <stdlib.h>

/**
 * * complexidade O(n)
 * 
 * * pseudocódigo
 * 
 * ALGORITMO: getSize
 * ENTRADA: Nó cabeça headNode de uma lista sequencial L
 * SAIDA: Quantidade de nós da lista
 * 
 * * current = headNode
 * * count = 0
 * 
 * * enquanto current.next != NULL FAÇA:
 * *  count++
 * *  current = current.next
 * 
 * * retorne count
 */

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList {
  Node* headNode;
} LinkedList;

LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;
  list->headNode = headNode;

  return list;
}

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void addLast(LinkedList* list, int data) {
  Node* newNode = createNode(data);
  Node* temp = list->headNode;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}

int getSize(Node* headNode) {
  Node* current = headNode;
  int count = 0;

  while (current->next != NULL) {
    count++;
    current = current->next;
  }

  return count;
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

  addLast(list, 3);
  addLast(list, 7);
  addLast(list, 8);
  addLast(list, 10);

  displayList(list);

  int listSize = getSize(list->headNode);

  printf("Tamanho da lista: %d\n", listSize);

  return 0;
}