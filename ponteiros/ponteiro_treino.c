#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int x = 20;
    int *ptr, **pptr;

    ptr = &x;
    pptr = &ptr;

    printf("O valor de X �: %d\n", x);
    printf("O valor apontado pelo ptr �: %d\n", *ptr);
    printf("O endere�o de X �: %p\n", &x);
    printf("O endere�o apontado pelo ptr �: %p\n", ptr);
    printf("\nO endere�o do pptr �: %p\n", &pptr);
    printf("O endere�o do ptr �: %p\n", &ptr);
    printf("O endere�o apontado por pptr �: %p\n", pptr); // Porque o pptr est� apontando para o ptr
    printf("O valor de ptr �: %d\n", ptr);
    printf("O valor que pptr est� apontando � do ptr: %d\n", ptr);
    printf("O valor que pptr est� apontando � o valor de X: %d\n", **pptr);

    *ptr += *ptr;
    printf("\nO valor de ptr � %d\n", *ptr);
    
    return 0;
}