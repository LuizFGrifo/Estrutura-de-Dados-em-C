#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char palavra[60];

    printf("Digite qualquer coisa que voc� quiser: ");
    scanf("%[^\n]s", palavra); // N�o precisa do &, porque vetor ja � um ponteiro

    printf("O texto digitado foi:\n%s", palavra);
    printf("\nO endere�o de palavra �: %p\n", &palavra);
    printf("\nO caracter da palavra no indice 2 �: %c\n", palavra[2]);
    printf("\nO endere�o de palavra �: %p\n", palavra);

    return 0;
}