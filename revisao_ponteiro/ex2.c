#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x, *ptr;

    printf("Digite um número: ");
    scanf("%d", &x);

    ptr = &x;

    printf("O valor associado ao ponteiro é: %d\n", *ptr);
    printf("O endereço associado ao ponteiro é: %p\n", ptr);

    *ptr *= 2;

    printf("O novo valor associado ao ponteiro é: %d\n", *ptr);
    printf("O endereço associado ao ponteiro ainda é: %p\n", ptr); 

    return 0;
}