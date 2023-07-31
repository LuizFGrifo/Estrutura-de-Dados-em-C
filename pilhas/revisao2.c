#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

No *push(No *topo, int entrada) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = topo;

        return novo;
    } else {
        printf("ERRO: Não é possivel alocar memória!\n");
        return NULL;
    }
}

No *pop(No **topo) {
    No *remover = *topo;

    if (*topo != NULL) {
        *topo = remover->proximo;
        return remover;
    } else {
        printf("ALERTA!: Pilha vazia!\n");
        return NULL;
    }
}

void print(No *topo) {
    printf("=============== Primeiro ===============\n");

    while (topo) {
        printf("[%d]\n", topo->valor);
        topo = topo->proximo;
    }

    printf("\n================ Ultimo ================\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No *remover = NULL, *topo = NULL;
    int opt, entrada;

    do {
        printf("1 - Push\n2 - Pop\n3 - Imprimir\n4 - Sair\nDigite uma opção: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &entrada);
            topo = push(topo, entrada);
            break;
        case 2:
            remover = pop(&topo);
            printf("Removido [%d]\n", remover->valor);
            free(remover);
            break;
        case 3:
            print(topo);
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }

    } while (opt != 0);

    return 0;
}