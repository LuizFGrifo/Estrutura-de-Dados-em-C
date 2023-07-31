#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no { // Esse "no" � um apelido
    char caracter;
    struct no *proximo;
} No;

No *empilhar(No *pilha, char valor) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->caracter = valor; // Usamos o -> para acessar o ponteiro, pois ele � um ponteiro e n�o um tipo primitivo
        novo->proximo = pilha;  // Recebe o topo
        return novo;
    } else
        printf("Erro de aloca��o");
    return NULL;
}

No *desempilhar(No **pilha) {
    No *remover = NULL;

    if (*pilha) {
        remover = *pilha;
        *pilha = remover->proximo;
    } else
        printf("Pilha vazia");
    return remover; // Porque remover est� como NULL, enquanto n�o houver valor para remover
}

void imprimir(No *pilha) {
    printf("\nTopo da Pilha\n");

    while (pilha) {
        printf("%c", pilha->caracter);
        pilha = pilha->proximo;
    }

    printf("\nBase da Pilha\n");
}

int par(char a, char f) {
    switch (f) {
    case ')':
        if (a == '(')
            return 1;
        else
            return 0;
        break;
    case '}':
        if (a == '{')
            return 1;
        else
            return 0;
    case ']':
        if (a == '[')
            return 1;
        else
            return 0;
    default:
        printf("Erro!");
        break;
    }
}

int valida(char x[]) {
    int i = 0;
    No *remover, *pilha = NULL;

    while (x[i] != '\0') { // O barra 0 indica o fim do vetor
        if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        } else if (x[i] == ')' || x[i] == ']' || x[i] == '}') {
            remover = desempilhar(&pilha);

            if (par(x[i], remover->caracter) == 0) {
                printf("\nExpress�o Mal formada\n");
                return 1;
            }
            free(remover);
        }
        i++;
    }

    imprimir(pilha);

    if (pilha) {
        printf("\nExpress�o Mal Formada\n");
        return 1;
    } else {
        printf("\nExpress�o Bem Formada\n");
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char expressao[50];

    printf("Digite uma express�o: ");
    scanf("%49[^\n]", expressao);

    printf("\nExpress�o: %s \nRetorno: %d", expressao, valida(expressao));

    return 0;
}
