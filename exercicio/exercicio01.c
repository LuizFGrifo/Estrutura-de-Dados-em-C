#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese");

    int x, *ptr;
    
    printf("Digite um número inteiro para X: ");
    scanf("%d",&x);

    ptr = &x;

    printf("O endereço de X é %p\n", &x);
    printf("O valor que o ptr está apontando é %d\n", *ptr);
    printf("O endereço de X que o ptr está apontando é %p\n", ptr);
    printf("O endereço do ponteiro é %p\n", &ptr);

    return 0;
}