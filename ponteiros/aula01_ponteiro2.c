#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 0;
    int *ptr, **pptr;

    ptr = &x;
    pptr = &ptr;

    /*printf("O valor de X � %d\n", x);
    printf("O endere�o de X � %p\n", &x);
    printf("O endere�o de X � %p\n", ptr);
    printf("O valor de X � %d\n", *ptr);
    printf("O endere�o de X � %p\n", pptr); */

    *ptr =+ 20;
    printf("O valor de x � %d\n", x);
    printf("O endere�o de x � %p\n", &x);
    printf("O endere�o de ptr � %p\n", &ptr);
    printf("O endere�o apontado por ptr � %p\n", ptr);
    printf("O endere�o apontado por pptr � %p\n", pptr);
    printf("O valor ao qual o pptr faz referencia � %d\n", **pptr); // Vai dar o valor do ptr
     printf("O valor do endere�o do pptr � %p\n", &pptr);

    return 0;
}