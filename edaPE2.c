#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* vetor;
    int capacidade;
    int topo;
} Pilha;

Pilha* criar(int capacidade) {
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->vetor = malloc(sizeof(char) * capacidade);
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

void empilhar(Pilha* pilha, char valor) {
    if (!cheia(pilha)) {
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
    } else {
        printf("Capacidade maxima da pilha alcancada.");
        exit(0);
    }
}

char desempilhar(Pilha* pilha) {
    if (!vazia(pilha)) {
        char valor = pilha->vetor[pilha->topo - 1];
        pilha->topo--;

        return valor;
    } else {
        printf("Capacidade maxima da pilha alcancada.");
        exit(0);
    }
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tam = 0;
    while (palavra[tam] != '\0') {
        tam++;
    }

    Pilha *pilha = criar(tam);

    for (int i = 0; i < tam; i++) {
        empilhar(pilha, palavra[i]);
    }

    char palavraInversa[100];
    for (int i = 0; i < tam; i++) {
        palavraInversa[i] = desempilhar(pilha);
    }
    palavraInversa[tam] = '\0';

    int ehPalindromo = 1;
    for (int i = 0; i < tam; i++) {
        if (palavra[i] != palavraInversa[i]) {
            ehPalindromo = 0;
            break;
        }
    }

    if (ehPalindromo) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
