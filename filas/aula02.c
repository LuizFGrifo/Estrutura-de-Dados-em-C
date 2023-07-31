#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void push(int **fila, int entrada) {
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = NULL;

        if (*fila == NULL) {
            *fila = novo;
        } else {
            auxiliar = *fila;
            while (auxiliar->proximo) {
                auxiliar = auxiliar->proximo;
            }
            auxiliar->proximo = novo;
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
        printf("O valor removido foi [%d]\n", remover->valor);
    } else {
        printf("ALERTA: Fila vazia!\n");
    }
    return remover;
}

// Inserir a fila com prioridade
void inserirPrioridade(No **fila, int num) {
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if (*fila == NULL) {
            *fila = novo;
        } else {
            if (num > 59) {
                if ((*fila)->valor < 60) {
                    novo->proximo = *fila;
                    *fila = novo;
                } else {
                    auxiliar = *fila;
                    while (auxiliar->proximo && auxiliar->proximo->valor > 59) {
                        auxiliar = auxiliar->proximo;
                    }
                    novo->proximo = auxiliar->proximo;
                    auxiliar->proximo = novo;
                }
            } else {
                auxiliar = *fila;
                while (auxiliar->proximo) {
                    auxiliar = auxiliar->proximo;
                }
                auxiliar->proximo = novo;
            }
        }
    } else {
        printf("ERRO: Não é possivel alocar memória!\n");
    }
}

void print(No *fila) {
    printf("================== Inicio ==================\n");
    while (fila) {
        printf("[%d] ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n=================== Fim ====================\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No *remover = NULL, *fila = NULL;

    int opt, entrada;

    do {
        printf("Exemplo fila\n1 - push\n2 - push com prioridade\n3 - pop\n4 - print\nDigite uma opção: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("Digite um número: ");
            scanf("%d", &entrada);
            push(&fila, entrada);
            break;
        case 2:
            printf("Digite um número: ");
            scanf("%d", &entrada);
            inserirPrioridade(&fila, entrada);
            break;
        case 3:
            remover = pop(&fila);
            free(remover);
            break;
        case 4:
            print(fila);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opt != 0);

    return 0;
}
