#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int x, *ptr;

    printf("Digite um n�mero inteiro para X: ");
    scanf("%d", &x);

    ptr = &x;

    printf("O valor de X apontado por ptr � %d\n", *ptr);

    *ptr += *ptr;

    printf("O novo valor de X apontado por ptr � %d\n", *ptr);

    return 0;
}