#include <stdio.h>
#include <locale.h>

typedef struct {
int id;
char nome[50];
int cpf;
} Cliente;

Cliente cadastro() {
Cliente c;
getchar();

printf("Digite o id do cliente: ");
scanf("%d", &c.id);
getchar();
printf("Digite o nome: ");
scanf("%[^\n]s", c.nome);
getchar();
printf("Digite o CPF: ");
scanf("%d", &c.cpf);

return c;
}

void imprimirCliente(Cliente cl) {
printf("ID: %d", cl.id);
printf("Nome: %s", cl.nome);
printf("CPF: %d", cl.cpf);

printf("\n");
}
int main(){
setlocale(LC_ALL,"Portuguese");

int qtd;

printf("Quantos clientes você deseja cadastrar: ");
scanf("%d", &qtd);

Cliente vet[qtd];

for(int i = 0; i < qtd; i++){
  vet[i] = cadastro();
}

for(int i = 0; i < qtd; i++){
  imprimirCliente(vet[i]);
}

return 0;
}