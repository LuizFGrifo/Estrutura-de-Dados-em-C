#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int **mat;
    float avg = 0, cont = 0, sum = 0;

    mat = malloc(3 * sizeof(int)); // Aloca as linhas

    if (mat == NULL) // Verifica se a alocação de memória está correta
    {
        printf("Erro ao alocar memória!\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) // Aloca as colunas
    {
        mat[i] = malloc(3 * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2d%% ", mat[i][j]);
            if (i == j)
            {
                sum += mat[i][j];
                cont++;
            }
        }
        printf("\n");
    }

    avg = sum / cont;

    printf("\nA probabilidade de terremotos no Japão é de: %.2f%%\n", avg);

    for (int i = 0; i < 3; i++)
    {
        free(mat[i]);
    }

    free(mat);

    return 0;
}
