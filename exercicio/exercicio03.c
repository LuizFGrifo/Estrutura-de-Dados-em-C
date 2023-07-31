#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char nome[50];

    printf("Digite seu nome: ");
    //gets(nome);
    scanf("%[^\n]s", nome);

    printf("Seu nome é %s \n", nome);

    printf("%p\n", nome);
    printf("%p\n", &nome);
    printf("%p\n", &nome[2]);

    return 0;
}