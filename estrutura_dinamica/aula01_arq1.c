#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    //int *x;
    //char *c;
    float *x;

    //x = malloc(sizeof(int));
    //x = calloc(1, sizeof(char));
    x = calloc(1, sizeof(float));

    if(x) { // Verifica se est� cheio
        printf("Alocado com sucesso!\n");
        printf("O valor de X � %f\n", *x);
        *x = 70;
        printf("O valor de X � %f\n", *x);
    } else {
        printf("Valor n�o alocado!\n");
    }

    return 0;
}