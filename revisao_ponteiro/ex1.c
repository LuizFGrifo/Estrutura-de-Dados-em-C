#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int num, *ptr;

    printf("Digite um número: ");
    scanf("%d", &num);

    ptr = &num;

    printf("O valor associado ao ponteiro é %d\n", *ptr);
    printf("O endereço apontado pelo ponteiro é %p\n", ptr);
    printf("O endereço de num é %p\n", &num);

    return 0;
}