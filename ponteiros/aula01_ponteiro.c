#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 30;
    int *ptr;

    ptr = &x; // Para atribuir valor, n�o utilizamos "*"

    printf("O valor de X �: %d\n", x);
    printf("O endere�o de X �: %x\n", &x);
    printf("O endere�o de X �: %p\n", &x);
    printf("O endere�o de X �: %p\n", ptr);
    printf("O valor de X �: %d\n", *ptr);

    return 0;
}