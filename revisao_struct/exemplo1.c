#include <stdio.h>
#include <locale.h>

typedef struct {
    int ano;
    char cor[30];
    char modelo[50];
    int potencia;
    float torque;
} Carro;


int main() {
    setlocale(LC_ALL, "Portuguese");

    Carro Nissan;
    Carro Toyota;

    printf("Digite o ano do carro: ");
    scanf("%d", &Nissan.ano);
    getchar(); // Precisa limpar o buffer
    printf("Digite a cor do carro: ");
    scanf("%[^\n]s", Nissan.cor);
    getchar();
    printf("Digite o modelo do carro: ");
    scanf("%[^\n]s", Nissan.modelo);

    printf("Digite a potência do carro: ");
    scanf("%d", & Nissan.potencia);

    printf("Digite o torque em KG: ");
    scanf("%f", &Nissan.torque);

    printf("\nNissan: modelo %s, da cor %s, ano %d, com potência de %dWHP e %1.fKg de torque\n", Nissan.modelo, Nissan.cor, Nissan.ano, Nissan.potencia, Nissan.torque);

    printf("Digite o ano do carro: ");
    scanf("%d", &Toyota.ano);
    getchar(); // Precisa limpar o buffer
    printf("Digite a cor do carro: ");
    scanf("%[^\n]s", Toyota.cor);
    getchar();
    printf("Digite o modelo do carro: ");
    scanf("%[^\n]s", Toyota.modelo);

    printf("Digite a potência do carro: ");
    scanf("%d", & Toyota.potencia);

    printf("Digite o torque em KG: ");
    scanf("%f", &Toyota.torque);

    printf("\nToyota: modelo %s, da cor %s, ano %d, com potência de %dWHP e %1.fKg de torque\n", Toyota.modelo, Toyota.cor, Toyota.ano, Toyota.potencia, Toyota.torque);

    return 0;
}