#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int key;
  struct Node* next;
} Node;

typedef struct Queue {
  Node* headNode;
} Queue;

Queue* createQueue() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;
  queue->headNode = headNode;

  return queue;
}

Node* createNode(int key) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->key = key;
  newNode->next = NULL;

  return newNode;
}

void enqueue(Queue* queue, int key) {
  Node* newNode = createNode(key);
  Node* current = queue->headNode;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

void dequeue(Queue* queue) {
  if (queue->headNode->next == NULL) {
    return; // fila vazia
  }
 
  Node* temp = queue->headNode->next;
  queue->headNode->next = queue->headNode->next->next;
  free(temp);
}

void removeRepeated(Queue* queue) {
  if(queue->headNode->next == NULL) {
    return;
  }

  int count = 0;
  Node* iterator = queue->headNode->next;

  while(iterator != NULL) {
    count++;
    iterator = iterator->next;
  }

  int* found = (int*) malloc(sizeof(int) * count);
  int foundSize = 0;

  Node* current = queue->headNode->next;
  Node* prev = queue->headNode;
  
  while (current != NULL) {
    bool alreadyFound = false;
    
    for (int i = 0; i < foundSize; i++) {
      if (found[i] == current->key) {
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
      found[foundSize] = current->key;
      foundSize++;
      prev = current;
      current = current->next;
    }
  }

  free(found);
}

void displayQueue(Queue* queue) {
  Node* current = queue->headNode->next;

  while (current != NULL) {
    printf("%d ", current->key);
    current = current->next;
  }

  printf("\n");
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 3);
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 1);

  displayQueue(queue);

  // dequeue(queue);
  // dequeue(queue);
  // dequeue(queue);

  // displayQueue(queue);

  removeRepeated(queue);
  displayQueue(queue);

  return 0;
}