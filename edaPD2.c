#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int topo;
    int itens[TAMANHO_MAX];
} PilhaEstatica;

typedef struct No {
    int valor;
    struct No* anterior;
} No;

typedef struct {
    No* topo;
} PilhaDinamica;

void inicializarPilhaEstatica(PilhaEstatica* pilha) {
    pilha->topo = -1;
}

int pilhaEstaticaVazia(PilhaEstatica* pilha) {
    return (pilha->topo == -1);
}

int pilhaEstaticaCheia(PilhaEstatica* pilha) {
    return (pilha->topo == TAMANHO_MAX - 1);
}

void empilharPilhaEstatica(PilhaEstatica* pilha, int valor) {
    if (pilhaEstaticaCheia(pilha)) {
        printf("Erro: Pilha estática cheia.\n");
        exit(EXIT_FAILURE);
    }
    pilha->itens[++pilha->topo] = valor;
}

int desempilharPilhaEstatica(PilhaEstatica* pilha) {
    if (pilhaEstaticaVazia(pilha)) {
        printf("Erro: Pilha estática vazia.\n");
        exit(EXIT_FAILURE);
    }
    return pilha->itens[pilha->topo--];
}

PilhaDinamica* criarPilhaDinamica() {
    PilhaDinamica* pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int pilhaDinamicaVazia(PilhaDinamica* pilha) {
    return (pilha->topo == NULL);
}

void empilharPilhaDinamica(PilhaDinamica* pilha, int valor) {
    No* no = malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro: Falha ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    no->valor = valor;
    no->anterior = pilha->topo;
    pilha->topo = no;
}

int desempilharPilhaDinamica(PilhaDinamica* pilha) {
    if (pilhaDinamicaVazia(pilha)) {
        printf("Erro: Pilha dinâmica vazia.\n");
        exit(EXIT_FAILURE);
    }
    No* no = pilha->topo;
    int valor = no->valor;
    pilha->topo = no->anterior;
    free(no);
    return valor;
}

void liberarPilhaDinamica(PilhaDinamica* pilha) {
    while (!pilhaDinamicaVazia(pilha)) {
        desempilharPilhaDinamica(pilha);
    }
    free(pilha);
}

int main() {
    PilhaEstatica pilhaEstatica;
    PilhaDinamica* pilhaDinamica;

    inicializarPilhaEstatica(&pilhaEstatica);

    int n, valor;
    
    printf("Digite o tamanho do conjunto de números inteiros (max %d): ", TAMANHO_MAX);
    scanf("%d", &n);

    printf("Digite os números inteiros:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        empilharPilhaEstatica(&pilhaEstatica, valor);
    }

    pilhaDinamica = criarPilhaDinamica();

    while (!pilhaEstaticaVazia(&pilhaEstatica)) {
        valor = desempilharPilhaEstatica(&pilhaEstatica);
        empilharPilhaDinamica(pilhaDinamica, valor);
    }

    printf("Dados da pilha dinâmica:\n");
    while (!pilhaDinamicaVazia(pilhaDinamica)) {
        valor = desempilharPilhaDinamica(pilhaDinamica);
        printf("%d ", valor);
    }
    printf("\n");

    liberarPilhaDinamica(pilhaDinamica);

    return 0;
}
