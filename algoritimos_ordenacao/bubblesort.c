#include <stdio.h>
#include <stdlib.h>

void bubblesort(int lista[], int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1; j++) {
            // O primeiro item, é maior que o segundo ?
            if (lista[j] > lista[j + 1]) {
                // Se for o auxiliar vai salvar o número
                aux = lista[j];
                // Atribui o valor do 2° Elemento ao primeiro, já que ele é menor
                lista[j] = lista[j + 1];
                // O 2° elemento recebe a cópia do valor do primeiro elemento
                lista[j + 1] = aux;
            }
        }
    }
}

int main() {
    int lista[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(lista) / sizeof(lista[0]);

    bubblesort(lista, size);

    printf("Lista ordenada:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] ", lista[i]);
    }

    return 0;
}