#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int var[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite o n�mero na linha %d, na coluna %d: ", i, j);
            scanf("%d", &var[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("[%d] ", var[i][j]);

            if (var[i][j] % 2 == 0) {
                printf("� par\n");
            }
            else {
                printf("� impar\n");
            }
        }
    }

    return 0;
}