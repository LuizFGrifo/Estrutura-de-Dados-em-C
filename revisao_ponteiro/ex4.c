#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vet[5], *ptr;

    for(int i = 0; i < 5; i++) {
        printf("Digite o valor na posição %d: ", i);
        scanf("%d", &vet[i]);
    }

    ptr = &vet;

    for(int i = 0; i < 5; i++) {
        printf("O valor dos vetores é %d | e o endereço é %p\n", *(ptr+i), ptr+i);
    }

    return 0;
}