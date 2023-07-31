#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// Inserir no inicio da lista
void inseririInicio(No **lista, int entrada) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;  // Novo recebe o valor da entrada
        novo->proximo = *lista; // Recebe o proximo da lista
        *lista = novo;          // Alocando a lista na memória assim sendo o novo nó
    } else
        printf("ERRO: Não é possivel alocar memória!\n");
}

// Inserir no fim da lista
void inserirFim(No **lista, int entrada) {
    // Criamos um auxiliar para modificar o valor
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        novo->proximo = NULL; // Como é o final da lista, o próximo e NULL

        if (*lista == NULL)                   // A lista está vazia na primeira execução
            *lista = novo;                    // Ai lista vai salvar o valor de novo no inicio do nó
        else {                                // No proximo valor adicionado, ele entrara no else
            auxiliar = *lista;                // auxiliar recebe lista, para modificar o valor
            while (auxiliar->proximo) {       // Enquanto houver valores para continuar indo para o proximo
                auxiliar = auxiliar->proximo; // Auxiliar ira receber o próximo, até chegar ao fim da lista
            }
            auxiliar->proximo = novo; // O proximo do auxiliar recebe o valor de novo
        }
    } else
        printf("ERRO: Não é possivel alocar memória!\n");
}

// Inserir em qualquer lugar
void inserirMeio(No **lista, int entrada, int ant) {
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = entrada;
        // Lista está vazia ?
        if (*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo; // Vai adicionar o valor no inicio de nó
        } else {
            auxiliar = *lista;                                    // Faz uma cópia de lista para não perdemos os valores originais
            while (auxiliar->valor != ant && auxiliar->proximo) { // Vai percorrer até que um seja falso
                auxiliar = auxiliar->proximo;
            }
            novo->proximo = auxiliar->proximo; // Ele vai pegar o proximo do meio
            auxiliar->proximo = novo;          // Aqui ele insere no meio da lista
        }
    } else
        printf("ERRO: Não é possivel alocar memória!\n");
}

void imprimir_lista(No *lista) { // Atenção aqui, ele não é ponteiro para ponteiro
    printf("================== lista encadeada ==================\n");
    while (lista) {
        printf("[%d] ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n=================== fim da lista ===================\n");
}

// Remover da lista
No *remover_lista(No **lista, int entrada) {
    No *auxiliar, *remover = NULL;        // declaramos o remover como vazio
    if (*lista) {                         // Se lista for true
        if ((*lista)->valor == entrada) { // Se o valor do incio da lista for igual ao valor
            remover = *lista;             // Remove o valor
            *lista = remover->proximo;    // Vai para o proximo nó da lista
        } else {
            auxiliar = *lista; // Para ter uma cópia
            while (auxiliar->proximo && auxiliar->proximo->valor != entrada) {
                auxiliar = auxiliar->proximo;
            }
            if (auxiliar->proximo) {
                remover = auxiliar->proximo;
                auxiliar->proximo = remover->proximo;
            }
        }
    } else
        printf("Lista vazia!\n");
    return remover;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    No *remover, *lista = NULL;

    int opt, entrada, ant;

    do {
        printf("Lista Encadeada\n0 - Sair\n1 - inserir no inicio\n2 - Inserir no fim da lista\n3 - Inserir sabe se Deus onde\n4 - Imprimir\n5 - Excluir\nDigite uma opção: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Digite o valor do inicio: ");
            scanf("%d", &entrada);
            inseririInicio(&lista, entrada); // Sempre havera "&" nos inserts
            break;
        case 2:
            printf("Digite o valor do fim: ");
            scanf("%d", &entrada);
            inserirFim(&lista, entrada);
            break;
        case 3:
            printf("Digite o valor de sabe lá onde: ");
            scanf("%d", &entrada);
            printf("Antes de qual número você quer que ele vá ? ");
            scanf("%d", &ant);
            inserirMeio(&lista, entrada, ant);
            break;
        case 4:
            imprimir_lista(lista); // Aqui não tem "&"
            break;
        case 5:
            printf("Digite o valor que você quer excluir: ");
            scanf("%d", &entrada);
            remover = remover_lista(&lista, entrada);
            if (remover) {
                printf("O [%d] foi removido!\n", remover->valor);
                free(remover);
            } else
                printf("Não ha nada a remover!\n");
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n\n");
            break;
        }

    } while (opt != 0);

    return 0;
}