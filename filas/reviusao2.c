#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void push(No **fila, int entrada) {
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = NULL;

        if (*fila == NULL) {
            *fila = novo;
        } else {
            while (auxiliar->proximo) {
                auxiliar = auxiliar->proximo;
            }
        }
        auxiliar->proximo = novo;
    }
}

No *pop(No **fila) {
    No *remover = NULL;

    if (*fila) {
        remover = *fila;
        *fila = remover->proximo;
        printf("Valor removido: [%d]\n", remover->valor);
    } else {
        printf("Fila vazia!\n");
    }
    return remover;
}

void imprimir(No *fila) {
    while (fila) {
        printf("[%d] ", fila->valor);
        fila = fila->proximo;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    return 0;
}