#include <locale.h>
#include <stdio.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserirInicio(No **lista, int entrada) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("ERRO; N�o � possivel alocar mem�ria!\n");
    }
}

void inserirFim(No **lista, int entrada) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = NULL;

        if (*lista == NULL) {
            *lista = novo;
        } else {
            aux = *lista;
            // Agora temos que percorrer a lista at� o final
            while (aux->proximo) {
                aux = aux->proximo; // Vai percorrer
            }
            aux->proximo = novo;
        }
    }
}

void inserirMeio(No **lista, int entrada, int anterior) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;

        // Aqui o novo -> proximo fica dentro do if
        if (*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != anterior && aux->proximo) {
                aux = aux->proximo; // Para andar na lista
            }
            novo->proximo = aux->proximo; // So lebrar que novo e aux, apontam para proximo
            aux = aux->proximo;
        }
    } else {
        printf("ERRO: N�o � possivel alocar mem�ria!\n");
    }
}

No *removerDaLista(No **lista, int entrada) {
    No *aux, *remover = NULL;
    if (*lista) {
        if ((*lista)->valor = entrada) {
            remover = *lista; // Copia da lista
            *lista = remover->proximo;
        } else {
            aux = *lista; // Tamb�m � uma c�pia
            while (aux->proximo && aux->proximo->valor != entrada) {
                aux = aux->proximo;
            }
            if (aux->proximo) {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    } else {
        printf("Lista vazia!\n");
    }
    return remover; // N�o pode esquecer dessa melda
}

void imprimirLista(No *lista) {
    printf("----------------- Lista Encadeada -----------------\n");
    while (lista) {
        printf("[%d] ", lista->valor);
        lista = lista->proximo; // Para percorrer a lista
    }
    printf("\n------------------ Fim da Lista ------------------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    No *remover, *lista = NULL;
    int opt, entrada, ant;

    do {
        printf("Lista encadeada\n\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Imprimir lista\n5 - Remover\n0 - Sair\n\nDigite uma op��o: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Digite um n�mero: ");
            scanf("%d", &entrada);
            inserirInicio(&lista, entrada);
            break;
        case 2:
            printf("Digite um n�mero para inserir no final: ");
            scanf("%d", &entrada);
            inserirFim(&lista, entrada);
            break;
        case 3:
            printf("Digite um n�mero: ");
            scanf("%d", &entrada);
            printf("Digite o valor de referencia: ");
            scanf("%d", &ant);
            inserirMeio(&lista, entrada, ant);
            break;
        case 4:
            imprimirLista(lista);
            break;
        case 5:
            printf("Digite o valor que voc� deseja remover: ");
            scanf("%d", &entrada);
            remover = removerDaLista(&lista, entrada);
            if (remover) {
                printf("[%d] removido!\n", remover->valor);
                free(remover);
            }
            break;
        case 0:
            printf("Saindo...\n");
            break;
        }
    } while (opt != 0);

    return 0;
}