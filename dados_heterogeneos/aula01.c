#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {

    int idade;
    char situacao;
    char nome[30];

} Pessoa;

struct Pessoa2 {
    int idade;
    char situacao;
    char nome[30];
};

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int idade;
    char situacao;
    char nome[30];
    Data d;
} Pessoa3;



int main() {
    setlocale(LC_ALL, "Portuguese");

    Pessoa p;
    struct Pessoa2 p2;
    Pessoa3 p3;

    p.idade = 19;
    p.situacao = 'R';
    strcpy(p.nome, "Luiz Felipe Grifo");

    p2.idade = 18;
    p2.situacao = 'I';
    strcpy(p2.nome, "Maria Cecilia");
    
    printf("Digite o seu nome: ");
    //scanf("%[^\n]s", p3.nome);
    fgets(p3.nome, 30, stdin);
    //getchar();
    printf("Digite a data de nascimento: ");
    scanf("%d %d %d", &p3.d.dia, &p3.d.mes, &p3.d.ano);
    printf("Digite sua idade: ");
    scanf("%d", &p3.idade);
    getchar(); // Para limpar o buffer
    printf("Digite o estado [R] para Regular, [I] Irregular: ");
    scanf("%c", &p3.situacao);

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Situação: %c\n", p.situacao);

    printf("Nome: %s\n", p2.nome);
    printf("Idade: %d\n", p2.idade);
    printf("Situação: %c\n", p2.situacao);

    printf("Nome: %s\n", p3.nome);
    printf("Data de nascimento: %d/%d/%d\n", p3.d.dia, p3.d.mes, p3.d.ano);
    printf("Idade: %d\n", p3.idade);
    printf("Situação: %c\n", p3.situacao);

    return 0;
}