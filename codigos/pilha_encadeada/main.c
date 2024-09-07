#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Stack {
  int size;
  Node* headNode;
} Stack;

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

Stack* createStack() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  Node* headNode = (Node*) malloc(sizeof(Node));

  headNode->next = NULL;

  stack->headNode = headNode;
  stack->size = 0;

  return stack;
}

void push(Stack* stack, int data) {
  Node* newNode = createNode(data);

  newNode->next = stack->headNode->next;
  stack->headNode->next = newNode;

  (stack->size)++;
}

void pop(Stack* stack) {
  if (stack->headNode->next == NULL) return; // pilha vazia

  Node* temp = stack->headNode->next;
  stack->headNode->next = temp->next;
  free(temp);
  (stack->size)--;
}

void displayStack(Stack* stack) {
  Node* current = stack->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

void freeStack(Stack* stack) {
  while (stack->headNode->next != NULL) {
    pop(stack);
  }
  free(stack->headNode); // libera o nó cabeça
  free(stack);           // libera a pilha
}

int main() {
  Stack* stack = createStack();

  push(stack, 1);
  push(stack, 4);
  push(stack, 2);
  push(stack, 9);
  push(stack, 7);

  displayStack(stack);

  pop(stack);
  pop(stack);

  displayStack(stack);
  freeStack(stack);

  return 0;
}