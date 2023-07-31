#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// Inser��o do valor

void inserirValor(No **fila, int dados) {
    No *auxiliar, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = dados;
        novo->proximo = NULL;
        if (*fila == NULL) { // Aonde eu vou colocar o valor, caso ele esteja vazio
            *fila = novo;
        } else {
            auxiliar = *fila; // A vari�vel auxiliar vai verificar a fila, e vai para o ultimo valor
            while (auxiliar->proximo) {
                auxiliar = auxiliar->proximo; // Como se fosse um contador
            }
            auxiliar->proximo = novo; // Lugar que o auxiliar parar;
        }
    } else {
        printf("ERRO: N�o � possivel alocar mem�ria!\n");
    }
}

// Remo��o da fila

No *removerValor(No **fila) {
    No *remover = NULL;
    if (*fila) {                  // Quando for dois **, temos que usar um s� na hora de verificar ele, que no caso e o valor apontado
        remover = *fila;          // T� recebendo o valor do primeiro da fila
        *fila = remover->proximo; // O fila que � uma c�pia, est� recebendo o pr�ximo valor da fila
        printf("Valor removido %d", remover->valor);
    } else {
        printf("ALERTA!: Fila vazia!\n");
    }
    return remover; // Para retornar quem eu removi
}

void imprimirFila(No *fila) {
    printf("\n===============Inicio===============\n");
    while (fila) { // Enquanto tiver coisas na fila, fa�a
        printf("[%d] ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n================Fim=================\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int dado, opt;

    No *fila = NULL, *remover = NULL;

    do {
        printf("Fila\n1 - Inserir valor\n2 - Remover valor\n3 - Imprimir\n0 - Sair\nDigite a op��o: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("Digite um n�mero: ");
            scanf("%d", &dado);
            inserirValor(&fila, dado);
            break;
        case 2:
            remover = removerValor(&fila);
            free(remover);
        case 3:
            imprimirFila(fila);
            break;
        case 0:
            printf("Saindo...");
        default:
            printf("Op��o inv�lida!\n");
            break;
        }

    } while (opt != 0);

    return 0;
}