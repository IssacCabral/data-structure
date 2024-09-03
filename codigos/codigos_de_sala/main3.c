#include<stdio.h>
#include<stdlib.h>

typedef struct PilhaSeq {
	int *dados;
	int capacidade_max;
	int topo; // indice do topo da pilha
} PilhaSeq;

void criarPilhaSeq(PilhaSeq *pP, int capacidade_max) {
	pP->dados = (int *) malloc(sizeof(int)*capacidade_max);
	pP->capacidade_max = capacidade_max;
	pP->topo = -1;
}

int inserirPilhaSeq(PilhaSeq *pP, int x) {
	if(pP->topo + 1 == pP->capacidade_max) return 0; // Pilha cheia!	
	(pP->topo)++;
	pP->dados[pP->topo] = x;
	return 1; // Deu certo!
}

int removerPilhaSeq(PilhaSeq *pP) {
	if(pP->topo == -1) return 0; // Pilha vazia!
	(pP->topo)--;
	return 1; // Deu certo!
}

void imprimirPilha(PilhaSeq P) {
	for(; P.topo >= 0; P.topo--) printf("%d ", P.dados[P.topo]);
}

int main () {
	PilhaSeq P;
	
	criarPilhaSeq(&P,10);
	for(int i=0;i<5;i++) inserirPilhaSeq(&P,i+1);
	removerPilhaSeq(&P);
	imprimirPilha(P);
	
	return 0;
}