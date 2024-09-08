#include <stdio.h>
#include <stdlib.h>

/**
 * ALGORITMO: adicionarNoInicio
 * ENTRADA: lista encadeada L, chave do elemento chave
 * OBS: cada elemento novo, é adicionado no início da fila.
 * 
 * * novoNo = aloca_memoria(No)
 * 
 * * novoNo.chave = chave
 * * novoNo.proximo = L.noCabeca.proximo
 * 
 * * L.noCabeca.proximo = novoNo
 * * L.tamanho++
 */

/**
 * * complexidade: O(n)
 * 
 * ALGORITMO: listarInverso
 * ENTRADA: Nó cabeça V
 * SAIDA: impressão de todos os nós da lista na ordem inversa
 * 
 * * atual = V.proximo
 * * novaLista = criarListaEncadeada() // cria uma nova lista encadeada
 * 
 * * enquanto atual != NULL FAÇA:
 * *  adicionarNoInicio(novaLista, atual.chave) // vai adicionando os elementos no início da nova lista
 * *  atual = atual.proximo
 * 
 * * atual = novaLista.noCabeca.proximo
 * 
 * * enquanto atual != NULL FAÇA:
 * *  imprima(atual.chave)
 * *  atual = atual.proximo
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

void listInverse(Node* headNode) {
  Node* current = headNode->next;
  LinkedList* newList = createLinkedList();
  
  while (current != NULL) {
    addBegin(newList, current->data);
    current = current->next;
  }

  current = newList->headNode->next;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

// * solução recursiva
// void listInverse(Node* node) {
//   if (node == NULL) return;

//   listInverse(node->next);
//   printf("%d ", node->data);
// }

int main() {
  LinkedList* list = createLinkedList();

  addLast(list, 3);
  addLast(list, 7);
  addLast(list, 100);
  addLast(list, 12);
  addLast(list, 1);

  displayList(list);
  listInverse(list->headNode);

}