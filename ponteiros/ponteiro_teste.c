#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 10;
    int *ptr;

    ptr = &x; // Vai apontar para o endere�o do x

    printf("O valor de 5 � %d\n", x);
    printf("O endere�o de X � %p\n", ptr);
    printf("O endere�o do ptr � %p\n", &ptr);
    printf("O valor apontado de ptr � %d\n", *ptr);

    *ptr = *ptr / 2;
    printf("O novo valor de X � %d\n", *ptr);
    printf("O endere�o do X continua sendo %p\n", ptr);
    printf("O endere�o de ptr %p", &ptr);

    return 0;
}