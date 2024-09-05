#include <stdio.h>
#include <stdlib.h>

/**
 * * complexidade O(n)
 * 
 * * pseudocódigo
 * 
 * ALGORITOMO: concat
 * ENTRADA: Nó cabeça headNodeL1 e Nó cabeça headNodeL2
 * SAIDA: Nó cabeça headNodeL1, com o último elemento da lista 1, 
 *        apontando para o primeiro elemento da lista 2
 * 
 * * current = headNodeL1
 * 
 * * enquanto current.next != NULL FAÇA:
 * *  current = current.next
 * 
 * * current.next = headNodeL2.next
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

void concat(Node* headNodeL1, Node* headNodeL2) {
  Node* current = headNodeL1;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = headNodeL2->next;
}

int main() {
  LinkedList* list1 = createLinkedList();
  LinkedList* list2 = createLinkedList();

  addLast(list1, 3);
  addLast(list1, 7);
  addLast(list1, 9);
  addLast(list1, 10);

  displayList(list1);

  addLast(list2, 2);
  addLast(list2, 1);
  addLast(list2, 4);
  addLast(list2, 13);

  displayList(list2);

  concat(list1->headNode, list2->headNode);

  displayList(list1);

  return 0;
}