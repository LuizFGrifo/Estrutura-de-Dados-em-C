#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 30;
    int *ptr;

    ptr = &x; // Para atribuir valor, não utilizamos "*"

    printf("O valor de X é: %d\n", x);
    printf("O endereço de X é: %x\n", &x);
    printf("O endereço de X é: %p\n", &x);
    printf("O endereço de X é: %p\n", ptr);
    printf("O valor de X é: %d\n", *ptr);

    return 0;
}