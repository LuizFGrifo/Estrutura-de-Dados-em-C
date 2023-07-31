#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tam, *vet, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = malloc(tam * sizeof(int));

    if (vet) {
        printf("Alocado com sucesso!\n");
        for (i = 0; i < tam; i++) {
            *(vet + i) = rand();
        }

        for (int i = 0; i < tam; i++) {
            printf("%d  ", *(vet + i));
        }

        printf("\nDigite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam);

        for (int i = 0; i < tam; i++) {
            printf("%d  ", *(vet + i));
        }

        free(vet);
    }
    else {
        printf("Erro de alocação\n");
    }

    return 0;
}