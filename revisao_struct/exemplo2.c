#include <stdio.h>
#include <locale.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int idade;
    char situacao;
    char nome[30];
    Data d;
} Pessoa;

Pessoa lerPessoa() {
    Pessoa p;
    getchar(); // Tem que limpar o buffer, pois antes ele le a quantidade de pessoas

    printf("Digite o seu nome: ");
    scanf("%[^\n]s", &p.nome);
    printf("Digite a data de nascimento: ");
    scanf("%d %d %d", &p.d.dia, &p.d.mes, &p.d.ano);
    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Digite o estado [R] para regular, [I] para irregular: ");
    scanf("%c", &p.situacao);

    return p;
}

void imprimirPessoa(Pessoa pes) {
    printf("Nome: %s\n", pes.nome);
    printf("Data nascimento: %d/%d/%d\n", pes.d.dia, pes.d.mes, pes.d.ano);
    printf("Idade: %d\n", pes.idade);
    printf("Situação: %c\n", pes.situacao);

    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int qtd;

    printf("Digite a quantidade de pessoas que deseja cadastrar: ");
    scanf("%d", &qtd);

    Pessoa vet[qtd];

    for(int i = 0; i < qtd; i++) {
        vet[i] = lerPessoa();
    }

    for(int i = 0; i < qtd; i++) {
        imprimirPessoa(vet[i]);
    }

    return 0;
}