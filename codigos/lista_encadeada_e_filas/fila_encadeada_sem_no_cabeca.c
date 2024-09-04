#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node* next;
} Node;

typedef struct Queue {
  int length;
  Node* first;
  Node* last;
} Queue;

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->key = data;
  newNode->next = NULL;

  return newNode;
}

Queue* createQueue() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));

  queue->first = NULL;
  queue->last = NULL;
  queue->length = 0;

  return queue;
}

void enqueue(Queue* queue, int data) {
  Node* newNode = createNode(data);

  if (queue->first == NULL) { // lista vazia
    queue->first = newNode;
    queue->last = newNode;
  } else {
    queue->last->next = newNode;
    queue->last = newNode;
  }

  (queue->length)++;
}

void dequeue(Queue *queue) {
  if (queue->first == NULL) return;// LISTA VAZIA

  Node* elementToRemove = queue->first;

  queue->first = queue->first->next;

  if (queue->first == NULL) { // fila ficou vazia
    queue->last = NULL;
  }

  free(elementToRemove);
  (queue->length)--;
}

void displayQueue(Queue* queue) {
  Node *current = queue->first;

  while(current != NULL) {
    printf("%d ", current->key);
    current = current->next;
  }

  printf("NULL\n");
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 7);
  enqueue(queue, 2);
  enqueue(queue, 1);
  enqueue(queue, 9);
  enqueue(queue, 8);

  displayQueue(queue);

  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  displayQueue(queue);

  free(queue);

  return 0;
}