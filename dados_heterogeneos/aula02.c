#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, ("Portuguese"));

    int **mat, i, j, col, linha;

    printf("Digite o tamanho da coluna: ");
    scanf("%d", &col);

    printf("Digite o tamanho da linha: ");
    scanf("%d", &linha);

    mat = malloc(linha * sizeof(int *)); // Aloca as linhas

    for (i = 0; i < col; i++)
    {
        mat[i] = malloc(col * sizeof(int)); // Aloca as colunas
    }

    srand(time(NULL));

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < linha; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < linha; j++)
        {
            printf("%2d | ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < linha; i++)
    {
        free(mat[i]);
    }

    free(mat);

    return 0;
}