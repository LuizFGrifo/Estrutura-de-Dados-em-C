#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x = 0;
    int *ptr, **pptr;

    ptr = &x;
    pptr = &ptr;

    /*printf("O valor de X é %d\n", x);
    printf("O endereço de X é %p\n", &x);
    printf("O endereço de X é %p\n", ptr);
    printf("O valor de X é %d\n", *ptr);
    printf("O endereço de X é %p\n", pptr); */

    *ptr =+ 20;
    printf("O valor de x é %d\n", x);
    printf("O endereço de x é %p\n", &x);
    printf("O endereço de ptr é %p\n", &ptr);
    printf("O endereço apontado por ptr é %p\n", ptr);
    printf("O endereço apontado por pptr é %p\n", pptr);
    printf("O valor ao qual o pptr faz referencia é %d\n", **pptr); // Vai dar o valor do ptr
     printf("O valor do endereço do pptr é %p\n", &pptr);

    return 0;
}