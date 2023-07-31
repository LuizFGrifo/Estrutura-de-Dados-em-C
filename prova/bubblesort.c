#include <stdio.h>
#include <stdlib.h>

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

    int arr[] = {10, 90, 56, 2, 7, 35, 21, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, size);
    printf("Lista ordenada:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] ", arr[i]);
    }

    return 0;
}