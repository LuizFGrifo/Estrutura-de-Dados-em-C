#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char palavra[60];

    printf("Digite qualquer coisa que você quiser: ");
    scanf("%[^\n]s", palavra); // Não precisa do &, porque vetor ja é um ponteiro

    printf("O texto digitado foi:\n%s", palavra);
    printf("\nO endereço de palavra é: %p\n", &palavra);
    printf("\nO caracter da palavra no indice 2 é: %c\n", palavra[2]);
    printf("\nO endereço de palavra é: %p\n", palavra);

    return 0;
}