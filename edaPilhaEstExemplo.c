#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* vetor;
	int capacidade;
	int topo;
} Pilha;

Pilha* criar(int capacidade) {
	Pilha* pilha = malloc(sizeof(Pilha));
	pilha->vetor = malloc(sizeof(int) * capacidade);
	pilha->topo = 0;
	pilha->capacidade = capacidade;
	
	return pilha;
}

int vazia(Pilha* pilha) {
	return pilha->topo == 0;
}

int cheia(Pilha* pilha) {
	return pilha->topo == pilha->capacidade;
}

void empilhar(Pilha* pilha, int valor) {
	if (!cheia(pilha)) {
		pilha->vetor[pilha->topo] = valor;
		pilha->topo++;
	} else {
		printf("Capacidade maxima da pilha alcancada.");
		exit(0);
	}
}

int desempilhar(Pilha* pilha) {
	if (!vazia(pilha)) {
		int valor = pilha->vetor[pilha->topo - 1];
		pilha->topo--;
		
		return valor;
	} else {
		printf("Capacidade maxima da pilha alcancada.");
		exit(0);
	}
}

int espiar(Pilha* pilha) {
	if (!vazia(pilha)) {
		return pilha->vetor[pilha->topo - 1]; 
	} else {
		printf("Pilha vazia.");
		exit(0);
	}
}

int main (int argc, char const *argv[])
{
	int i, n = 10;
	
	Pilha *pilha = criar(n);
	
	printf("Empilhando -> ");
	for (i = 1; i <= n; i++) {
		empilhar(pilha, i);
		printf("%d ", espiar(pilha));
	}
	
	printf("\nDesempilhando -> ");
	while (!vazia(pilha)){
		printf("%d ", desempilhar(pilha));
	}
	
	printf("\n");
}
