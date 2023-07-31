#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data data;
} Pessoa;

Pessoa ler_pessoa() {
    Pessoa p;

    printf("Digite seu nome: ");
    scanf("%49[^\n]", p.nome);
    printf("Digite a data de nascimento (dd/mm/aaa)\n");
    scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("O %s nasceu em %d/%d/%d\n\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

No *push(No *topo) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->p = ler_pessoa();
        novo->proximo = topo;

        return novo;
    } else {
        printf("Não é possivel alocar memória!\n");
        return NULL;
    }
}

No *pop(No **topo) {
    No *remover = *topo;

    if (*topo != NULL) {
        *topo = remover->proximo;
        return remover;
    } else {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

void imprimir(No *topo) {
    printf("================= Info =================\n");

    while (topo) {
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    No *remover = NULL, *topo = NULL;

    int opt;

    do {
        printf("Bem vindo a Pilha!\n\n1 - Push\n2 - Pop\n3 - Imprimir\nDigite uma opção: ");
        scanf("%d", &opt);
        getchar();

        switch (opt) {
        case 1:
            topo = push(topo);
            break;
        case 2:
            remover = pop(&topo);
            if (remover) {
                printf("Elemento removido com sucesso: ");
                imprimir_pessoa(remover->p);
            } else {
                printf("Não há elementos para remover!\n");
            }
            free(remover);
            break;
        case 3:
            imprimir(topo);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }
    } while (opt != 0);

    return 0;
}