#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct No* anterior;
	int valor;
} No;

typedef struct {
	No* topo;
} Pilha;

Pilha* criar() {
	Pilha* pilha = malloc(sizeof(Pilha));
	pilha->topo = NULL;
	
	return pilha;
}

int vazia(Pilha* pilha) {
	return pilha->topo == NULL;
}

void empilhar(Pilha* pilha, int valor) {
	No *no = malloc(sizeof(No));
	no->valor = valor;
	no->anterior = pilha->topo;
	pilha->topo = no;
}

int desempilhar(Pilha* pilha) {
	int valor; 
	
	if (vazia(pilha)) {
		printf("Capacidade minima da pilha alcancada.");
		exit(-1);
		
	} else {
		No* no = pilha->topo;
		valor = no->valor;
		pilha->topo = no->anterior;
		
		free(no);	
	}
	
	return valor;
}

//int espiar(Pilha* pilha) {
//	if (!vazia(pilha)) {
//		return pilha->vetor[pilha->topo - 1]; 
//	} else {
//		printf("Pilha vazia.");
//		exit(0);
//	}
//}

//void busca(Pilha* pilha, int valor) {
//	if (!vazia(pilha)) {
//		if (pilha->vetor[pilha->topo - 1] == valor) {
//			printf("\nValor %d encontrado! \n", valor); 
//		}
//	} else {
//		printf("Pilha vazia.");
//		exit(0);
//	}
//}

void percorrer(Pilha* pilha) {
	while (vazia(pilha)) {
		int valor = pop(pilha);
		
		printf("%d\n", valor);
	}
}

void esvaziar(Pilha* pilha) {
	while (pilha->topo != NULL) {
		No *no = pilha->topo;
		pilha->topo = no->anterior;
		free(no);
	}
	
	free(p);
}

int main (int argc, char const *argv[])
{
//	Pilha *pilha = criar();
//	
//	printf("Empilhando -> ");
//	for (i = 1; i <= n; i++) {
//		empilhar(pilha, i);
//		printf("%d ", espiar(pilha));
//	}
//	
//	printf("\nDesempilhando -> ");
//	while (!vazia(pilha)){
//		busca(pilha, x);
//		printf("%d ", desempilhar(pilha));
//	}
//	
//	esvaziar(pilha);
//	
//	printf("\n");
}
