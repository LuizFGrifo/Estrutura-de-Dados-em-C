#include <stdio.h>

void bubblesort(int lista[], int size) {
    int aux;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

int main() {

    int lista[] = {20, 60, 89, 10, 5, 28, 90, 43, 30, 1};
    int size = sizeof(lista) / sizeof(lista[0]);

    printf("Lista ordenada:\n");
    bubblesort(lista, size);
    for (int i = 0; i < size; i++) {
        printf("[%d] ", lista[i]);
    }

    return 0;
}