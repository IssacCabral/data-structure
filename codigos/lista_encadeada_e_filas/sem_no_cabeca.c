#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
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

Node* createNode(int data) {
  Node *newNode = malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void addLast(LinkedList *list, int data) {
  Node *newNode = createNode(data);

  if(list->first == NULL) {
    list->first = newNode;
  } else {
    Node *temp = list->first;

    while(temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  list->length++;
}

// remove um elemento específico
bool removeElement(LinkedList *list, int element) {
  Node *current = list->first;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->data == element) {
      if (previous == NULL) { // Se o elemento a ser removido é o primeiro da lista
        list->first = current->next;
      } else { // Se o elemento está em outra posição
        previous->next = current->next;
      }
      free(current);
      list->length--;
      return true;
    }

    previous = current;
    current = current->next;
  }

  return false;
}

void displayList(LinkedList *list) {
  Node *current = list->first;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  LinkedList *list = createLinkedList();

  addLast(list, 2);
  addLast(list, 4);
  addLast(list, 1);
  addLast(list, 7);
  addLast(list, 11);

  removeElement(list, 11);

  displayList(list);

  free(list);

  return 0;
}