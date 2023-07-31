#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 10;
    int *ptr;

    ptr = &x; // Vai apontar para o endereço do x

    printf("O valor de 5 é %d\n", x);
    printf("O endereço de X é %p\n", ptr);
    printf("O endereço do ptr é %p\n", &ptr);
    printf("O valor apontado de ptr é %d\n", *ptr);

    *ptr = *ptr / 2;
    printf("O novo valor de X é %d\n", *ptr);
    printf("O endereço do X continua sendo %p\n", ptr);
    printf("O endereço de ptr %p", &ptr);

    return 0;
}