#include<stdio.h>
#include<stdlib.h>

typedef struct FilaSeq {
	int *dados;
	int capacidade_max;
	int ini; // indice de inicio da fila
	int fim; // indice de fim da fila
	int card; // cardinalidade
} FilaSeq;

void criarFilaSeq(FilaSeq *pF, int capacidade_max) {
	pF->dados = (int *) malloc(sizeof(int)*capacidade_max);
	pF->capacidade_max = capacidade_max;
	pF->ini = 0;
	pF->fim = pF->capacidade_max-1;
	pF->card = 0;
}

int inserirFilaSeq(FilaSeq *pF, int x) {
	if(pF->card == pF->capacidade_max) return 0; // Fila cheia!
	pF->fim = (pf->fim + 1)%(pF->capacidade_max);
	pF->dados[pF->fim] = x;
	(pF->card)++;
	return 1; // Deu certo!
}

int removerFilaSeq(FilaSeq *pF) {
	if(pF->card == 0) return 0; // Fila vazia!
	pF->ini = (pf->ini + 1)%(pF->capacidade_max);
	(pF->card)--;
	return 1; // Deu certo!
}

int main () {
	FilaSeq F;
	
	criarFilaSeq(&F,10);
	
	return 0;
}