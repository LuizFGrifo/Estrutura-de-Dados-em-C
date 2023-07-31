#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float temp[4], soma = 0, media = 0;

    for (int i = 0; i < 4; i++) {
        printf("Digite a temperatura na posi��o %d: ", i);
        scanf("%f", &temp[i]);

        soma += temp[i];
        media = soma / 4;
    }

    printf("A m�dia das temperaturas � %.2f\n", media);

    return 0;
}