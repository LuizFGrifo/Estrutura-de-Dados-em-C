#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void push(No **fila, int entrada) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = NULL; // Aqui tem uma diferença da pilha

        if (*fila == NULL) {
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("ERRO: Não é possivel alocar memória!\n");
    }
}

No *pop(No **fila) {
    No *remover = NULL;

    if (*fila) {
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("Fila vazia!\n");
    }
    return remover;
}

void imprimir(No *fila) {
    printf("--------------- Fila ---------------\n");

    while (fila) {
        printf("[%d] ", fila->valor);
        fila = fila->proximo;
    }

    printf("\n---------------- Fim ----------------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    No *remover, *fila = NULL;
    int opcao, entrada;

    do {

        printf("0 - Sair\n1 - Push\n2 - Pop\n3 - Imprimir\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &entrada);
            push(&fila, entrada);
            break;
        case 2:
            remover = pop(&fila);
            if (remover) {
                printf("Removido: [%d]\n", remover->valor);
                free(remover);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}