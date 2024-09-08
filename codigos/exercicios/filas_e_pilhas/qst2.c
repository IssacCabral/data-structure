#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * O método removeRepeated utilizado na fila encadeada 
 * vai funcionar corretamente e removerá os nós com chaves 
 * repetidas, mantendo apenas o que está mais à frente na fila.
 * 
 * Comparação com a pilha: Na pilha, a função percorre os nós 
 * do topo para o fundo e remove os elementos duplicados. 
 * Na fila, a função percorre os nós da cabeça para a cauda, 
 * mas o processo de verificação e remoção dos nós repetidos permanece o mesmo.
 * 
 * Fila: Como a fila é uma estrutura FIFO (First In, First Out), 
 * os elementos que foram inseridos primeiro estão "mais à frente". 
 * O algoritmo, ao encontrar uma repetição, remove o elemento que 
 * está mais "atrás" na fila.
 * 
 */

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Queue {
  int size;
  Node* headNode;
  Node* last;
} Queue;

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Queue* createQueue() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  Node* headNode = (Node*) malloc(sizeof(Node));

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

  if (queue->headNode->next == NULL) {
    queue->last = queue->headNode;
  }

  free(elementToRemove); 
  (queue->size)--;
}

void displayQueue(Queue* queue) {
  Node* current = queue->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

void removeRepeated(Queue* queue) {
  if (queue->headNode->next == NULL) return; // lista vazia

  bool found[1000] = {false};

  Node* current = queue->headNode->next;
  Node* prev = queue->headNode;

  while (current != NULL) {
    if (found[current->data]) { // se já encontramos o valor antes, removemos o nó atual
      prev->next = current->next;
      Node* temp = current;
      current = current->next;
      free(temp);
      (queue->size)--;
    } else {
      found[current->data] = true;
      prev = current;
      current = current->next;
    }
  }
}

int main() {
  Queue* queue = createQueue();

  enqueue(queue, 4);
  enqueue(queue, 1); // prev
  enqueue(queue, 4); 
  enqueue(queue, 7); // current
  enqueue(queue, 9);
  enqueue(queue, 5);

  displayQueue(queue);

  removeRepeated(queue);

  displayQueue(queue);

  return 0;
}