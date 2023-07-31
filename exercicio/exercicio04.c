#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vet[5], *ptr;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor na posição %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", vet[i]);
    }

    ptr = vet;

    for (int i = 0; i < 5; i++) {
        printf("O valor é %d | O endereço é %p\n", *(vet+i), vet+i);
    }

    return 0;
}