#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

No *empilhar(No *topo, int valor) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = valor;
        novo->proximo = topo;
        return novo;
    } else {
        printf("Erro: Não é possivel alocar memoria.\n");
    }
}

typedef struct {
    No *topo;
} Pilha;

void lista_elementos(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia!\n");
        return;
    }

    printf("Elementos da pilha:\n");

    No *atual = pilha->topo;
    while (atual != NULL) {
        printf("[%d]\n", atual->valor);
        atual = atual->proximo;
    }
}

void clear(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia!\n");
        return;
    }

    No *atual = pilha->topo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    pilha->topo = NULL;

    printf("A pilha foi limpa!\n");
}

void empilhar_elemento(Pilha *pilha) {
    int valor;
    printf("Informar o valor: ");
    scanf("%d", &valor);

    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    lista_elementos(pilha);
}

void desempilhar_elemento(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia!\n");
        return;
    }

    No *topo_antigo = pilha->topo;
    int valor = topo_antigo->valor;
    pilha->topo = topo_antigo->proximo;
    free(topo_antigo);

    printf("Valor removido: %d\n", valor);
    lista_elementos(pilha);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha pilha = {NULL};

    int opcao = 0;

    do {
        printf("Selecione a opção: ");
        printf("\n[1] - Inserir (push)\n");
        printf("[2] - Remover (pop)\n");
        printf("[3] - Listar\n");
        printf("[4] - Limpar a pilha\n");
        printf("[-1] - Sair\n:");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            empilhar_elemento(&pilha);
            break;
        case 2:
            desempilhar_elemento(&pilha);
            break;
        case 3:
            lista_elementos(&pilha);
            break;
        case 4:
            clear(&pilha);
            break;
        case -1:
            break;
        default:
            printf("Erro, opção invalida!\n");
        }
    } while (opcao != -1);

    return 0;
}