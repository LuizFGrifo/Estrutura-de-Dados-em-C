#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int num, *ptr;

    printf("Digite um n�mero: ");
    scanf("%d", &num);

    ptr = &num;

    printf("O valor associado ao ponteiro � %d\n", *ptr);
    printf("O endere�o apontado pelo ponteiro � %p\n", ptr);
    printf("O endere�o de num � %p\n", &num);

    return 0;
}