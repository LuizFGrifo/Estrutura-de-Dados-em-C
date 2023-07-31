#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vet[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor na posi��o %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", vet[i]);
    }

    return 0;
}