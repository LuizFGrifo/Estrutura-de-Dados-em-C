#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int x, *ptr;

    printf("Digite um n�mero: ");
    scanf("%d", &x);

    ptr = &x;

    printf("O valor associado ao ponteiro �: %d\n", *ptr);
    printf("O endere�o associado ao ponteiro �: %p\n", ptr);

    *ptr *= 2;

    printf("O novo valor associado ao ponteiro �: %d\n", *ptr);
    printf("O endere�o associado ao ponteiro ainda �: %p\n", ptr); 

    return 0;
}