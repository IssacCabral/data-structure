#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	int chave;
	struct No *prox;
} No;

typedef struct PilhaEnc {
	No *topo;
	int card; // Quantidade de elementos na Pilha
} PilhaEnc;

void inicializarPilhaEnc(PilhaEnc *pP) {
	pP->topo = NULL;
	pP->card = 0;
}

int inserirPilhaEnc(PilhaEnc *pP) {
	No* novo = (No*) malloc(sizeof(No));
	novo->prox = pP->topo;
	pP->topo = novo;
	pP->card++;
	return 1;
}

int removerPilhaEnc(PilhaEnc *pP) {
	if(pP->topo == NULL) return 0;
	No *aux = pP->topo;
	pP->topo = aux->prox;
	free(aux);
	pP->card--;
	return 1;
}

int main () {	
	PilhaEnc P;
	
	inicializarPilhaEnc(&P);
	
	
	return 0;
}