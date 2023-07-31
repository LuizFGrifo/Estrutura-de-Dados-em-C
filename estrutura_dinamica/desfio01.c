#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *x;

    int vet[3];

    x = &vet;

    x = calloc(3, sizeof(int));

    for (int i = 0; i < 3; i++) {
        printf("Digite o valor na posição %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (x) { // Verifica se estÃ¡ cheio
            printf("Alocado com sucesso!\n");
            printf("O valor de X é %d\n", *x);
            *x = vet[i];
            printf("O valor de X é %d\n", *x);
        }
        else {
            printf("Valor não alocado!\n");
        }
    }

    return 0;
}