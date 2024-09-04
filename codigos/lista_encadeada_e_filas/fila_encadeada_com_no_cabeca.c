#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Queue {
  int size;
  struct Node* headNode;
  struct Node* last;
} Queue;

Node* createNode(int data) {
  Node* newNode = (Node *) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Queue* createQueue() {
  Queue* queue = (Queue *) malloc(sizeof(Queue));
  Node* headNode = (Node *) malloc(sizeof(Node));

  headNode->next = NULL;

  queue->headNode = headNode;
  queue->last = headNode;
  queue->size = 0;

  return queue;
}

void enqueue(Queue* queue, int data) {
  Node* newNode = createNode(data);

  queue->last->next = newNode;
  queue->last = newNode;

  (queue->size)++;
}

void dequeue(Queue* queue) {
  if (queue->headNode->next == NULL) return; // lista vazia

  Node* elementToRemove = queue->headNode->next;
  queue->headNode->next = elementToRemove->next;

  if (queue->headNode->next == NULL) { // fila ficou vazia
    queue->last = queue->headNode;
  }

  free(elementToRemove);
  (queue->size)--;
}

void displayQueue(Queue* queue) {
  Node *current = queue->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
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

  displayQueue(queue);

  return 0;
}