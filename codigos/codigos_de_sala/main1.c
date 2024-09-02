#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	int chave;
	struct No *prox;
} NO;

int card=0;
NO *fim = NULL;

NO* criaFila() {
	NO *cabeca = malloc(sizeof(NO));
	cabeca->prox = NULL;
	fim = cabeca;
	card = 0;
	return cabeca;
}

void inserirFilaEncadeada(NO *F, int x) {
	NO *novo = malloc(sizeof(NO));
	novo->chave = x;
	novo->prox = NULL;
	fim->prox = novo;
	fim = novo;
	card++;
}

int tamanhoEncadeado(NO *F) {
	int qtd=0;
	
	while(F->prox != NULL) {
		qtd++;
		F = F->prox;
	}
	return qtd;
}

int main () {	
	NO *F = NULL;
	
	F = criaFila();
	inserirFilaEncadeada(F,10);
	tamanhoEncadeado(F);

	
	return 0;
}