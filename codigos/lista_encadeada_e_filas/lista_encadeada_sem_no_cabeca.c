#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *next; 
} Node;

typedef struct LinkedList {
  int length;
  Node *first;
} LinkedList;

LinkedList* createLinkedList() {
  LinkedList *list = malloc(sizeof(LinkedList));

  list->length = 0;
  list->first = NULL;

  return list;
}

Node* createNode(int key) {
  Node *newNode = malloc(sizeof(Node));

  newNode->key = key;
  newNode->next = NULL;

  return newNode;
}

void addLast(LinkedList *L, int key) {
  Node *newNode = createNode(key);

  if (L->first == NULL) {
    L->first = newNode;
  } else {
    Node *temp = L->first;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  (L->length)++;
}

void removeLast(LinkedList *L) {
  if (L->first == NULL) return; // lista vazia, nada para remover

  if (L->first->next == NULL) {
    free(L->first);
    L->first = NULL;
  } else {
    Node *current = L->first;

    while (current->next->next != NULL) {
      current = current->next;
    }

    free(current->next);
    current->next = NULL;
  }

  (L->length)--;
}

void removeBegin(LinkedList *L) {
  if (L->first == NULL) return; // lista vazia, nada para remover

  Node *elementToRemove = L->first;
  L->first = L->first->next;
  
  free(elementToRemove);
  (L->length)--;
}

void displayList(LinkedList *L) {
  Node *current = L->first;

  while(current != NULL) {
    printf("%d ", current->key);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  LinkedList *list = createLinkedList();

  addLast(list, 1);
  addLast(list, 3);
  addLast(list, 7);
  addLast(list, 9);
  addLast(list, 2);

  // displayList(list);

  // removeLast(list);
  removeBegin(list);
  removeBegin(list);
  removeBegin(list);
  removeBegin(list);
  removeBegin(list);

  displayList(list);

  return 0;
}