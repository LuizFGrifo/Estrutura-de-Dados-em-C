#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int x, *ptr;
    
    printf("Digite um n�mero inteiro para X: ");
    scanf("%d",&x);

    ptr = &x;

    printf("O endere�o de X � %p\n", &x);
    printf("O valor que o ptr est� apontando � %d\n", *ptr);
    printf("O endere�o de X que o ptr est� apontando � %p\n", ptr);
    printf("O endere�o do ponteiro � %p\n", &ptr);

    return 0;
}