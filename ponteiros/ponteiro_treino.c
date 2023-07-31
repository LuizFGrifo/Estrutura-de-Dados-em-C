#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int x = 20;
    int *ptr, **pptr;

    ptr = &x;
    pptr = &ptr;

    printf("O valor de X é: %d\n", x);
    printf("O valor apontado pelo ptr é: %d\n", *ptr);
    printf("O endereço de X é: %p\n", &x);
    printf("O endereço apontado pelo ptr é: %p\n", ptr);
    printf("\nO endereço do pptr é: %p\n", &pptr);
    printf("O endereço do ptr é: %p\n", &ptr);
    printf("O endereço apontado por pptr é: %p\n", pptr); // Porque o pptr está apontando para o ptr
    printf("O valor de ptr é: %d\n", ptr);
    printf("O valor que pptr está apontando é do ptr: %d\n", ptr);
    printf("O valor que pptr está apontando é o valor de X: %d\n", **pptr);

    *ptr += *ptr;
    printf("\nO valor de ptr é %d\n", *ptr);
    
    return 0;
}