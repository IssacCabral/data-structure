#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node* next;
} Node;

typedef struct LinkedList {
  int length;
  Node* headNode;
} LinkedList;

LinkedList* createLinkedList() {
  LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;

  list->length = 0;
  list->headNode = headNode;

  return list;
}

Node* createNode(int key) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->key = key;
  newNode->next = NULL;

  return newNode;
}

void addLast(LinkedList* list, int key) {
  Node *newNode = createNode(key);
  Node *temp = list->headNode;

  while(temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  (list->length)++;
}

void addBegin(LinkedList* list, int key) {
  Node *newNode = createNode(key);

  newNode->next = list->headNode->next;
  list->headNode->next = newNode;

  (list->length)++;
}

void removeLast(LinkedList* list) {
  if (list->headNode->next == NULL) return; // lista vazia, nada para remover

  Node* current = list->headNode;

  while (current->next->next != NULL) {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
}

void removeBegin(LinkedList* list) {
  if (list->headNode->next == NULL) return; // lista vazia, nada para remover

  Node* elementToRemove = list->headNode->next;
  list->headNode->next = elementToRemove->next;

  free(elementToRemove);
  (list->length)--;
}

int main() {


  return 0;
}