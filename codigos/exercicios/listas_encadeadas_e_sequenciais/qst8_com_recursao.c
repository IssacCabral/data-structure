#include <stdio.h>
#include <stdlib.h>

/**
 * * complexidade: O(n)
 * 
 * ALGORITMO: listarInverso
 * ENTRADA: Nó cabeça V
 * SAIDA: impressão de todos os nós da lista na ordem inversa
 *  
 * *  se V.proximo == NULL então
 * *    retorne
 * 
 * *  listarInverso(V.proximo)
 * *  print(V.proximo.valor)
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

void addBegin(LinkedList* list, int data) {
  Node* newNode = createNode(data);

  newNode->next = list->headNode->next;
  list->headNode->next = newNode;

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

// * solução recursiva
void listInverse(Node* headNode) {
    if (headNode->next == NULL) {
        return;  // Caso o nó cabeça seja NULL ou não haja mais nós
    }

    listInverse(headNode->next);  // Chama recursivamente o próximo nó
    printf("%d ", headNode->next->data);  // Imprime o valor na volta da recursão
}

int main() {
  LinkedList* list = createLinkedList();

  addLast(list, 3);
  addLast(list, 7);
  addLast(list, 100);
  addLast(list, 12);
  addLast(list, 1);

  // displayList(list);
  listInverse(list->headNode);

}