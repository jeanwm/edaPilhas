#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No* anterior;
    char valor;
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

void empilhar(Pilha* pilha, char valor) {
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->anterior = pilha->topo;
    pilha->topo = no;
}

char desempilhar(Pilha* pilha) {
    char valor; 

    if (vazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        exit(-1);

    } else {
        No* no = pilha->topo;
        valor = no->valor;
        pilha->topo = no->anterior;
        free(no);	
    }

    return valor;
}

void esvaziar(Pilha* pilha) {
    while (pilha->topo != NULL) {
        No *no = pilha->topo;
        pilha->topo = no->anterior;
        free(no);
    }

    free(pilha);
}

int verificarBalanceamento(char expressao[]) {
    Pilha* pilha = criar();

    int i = 0;
    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            empilhar(pilha, '(');
        } else if (expressao[i] == ')') {
            if (vazia(pilha)) {
                esvaziar(pilha);
                return 0;
            }
            desempilhar(pilha);
        }
        i++;
    }

    int balanceado = vazia(pilha);
    esvaziar(pilha);

    return balanceado;
}

int main() {
    char expressao[100];
    
    printf("Digite a expressao (max 100 caracteres) ou '0' para sair: ");
    scanf("%s", expressao);

    if (expressao[0] == '0') {
        printf("Expressão vazia.");
        return 0;
    }

    int balanceado = verificarBalanceamento(expressao);
    if (balanceado) {
        printf("true\n");
        
    } else {
        printf("false\n");
    }

    return 0;
}
