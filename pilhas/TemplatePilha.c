#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
Aqui temos uma struct do tipo Data.
*/
typedef struct {
    int dia, mes, ano;
} Data;

/*
Aqui temos uma struct do tipo Pessoa
ela recebe a struct Data, para podermos
acessar o seus valores.
*/
typedef struct {
    char nome[50];
    Data data;
} Pessoa;

/*
Aqui temos uma função para ler as structs do tipo
pessoa e data, mas como pessoa já tem acesso a struct
data, referenciamos apenas o tipo pessoa.

legenda:
* %49 = "%49" é o limite de caracteres da string que definimos
* [^\n] = especificamos que queremos ler todos os caracteres da entrada do usuário até o final da linha
* p.nome = Não precisa do "&", porque o vetor já é um ponteiro

como é uma função do tipo Pessoa, temos que retornar o valor de p
*/
Pessoa ler_pessoa() {
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

// Procedimento para imprimir as informações de uma Pessoa

void imprimir_pessoa(Pessoa p) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

/*
Estrutura  que ira compor nossa pilha.
Chamamos a estrutura pessoa, que sera
o valor que vamos armazenar em nossa pilha
logo depois, criamos um ponteiro do tipo nó,
que vai apontar para o proximo nó da pilha
*/

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

/*
função para a operação push (empilhar)
Criamos uma função do tipo empilhar,
que possui um ponteiro para o topo da fila.

Alocamos memória dinamicamente com o Malloc,
no ponteiro do tipo "No" chamado "novo".

verificamos se foi possivel alocar memória,
se foi possivel, novo vai apontar para p, que
vai acessar a função ler pessoa.

Novo vai apontar para o proximo valor da pilha,
e vai receber o topo, que no caso é o valor que
cadastramos no "ler_pessoa".

E por ultimo retornamos o ponteiro novo.

Caso não seja possivel alocar a memória, será
printado na tela, um aviso e sera retornado NULL.
 */

No *empilhar(No *topo) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    } else
        printf("\nERRO: Não é possível alocar memória!\n");

    return NULL;
}

/*
função para a operação pop (desempilhar)

Criamos uma função do tipo struct, chamada de desempilhar,
que recebe um ponteiro de ponteiro do tipo No, chamada "topo"

Então verificamos se o valor do ponteiro é diferente de NULL,
caso ele seja, nós criamos um ponterio do tipo No, chamada "remover"
que vai receber o valor do ponteiro "topo".

Então o topo recebe o proximo valor, que é apontada por remover.

E por ultimo retornamos o remover.

Caso o ponteiro topo esteja vazio, será printado um aviso dizendo
que a pilha está vazia e retornamos NULL
*/
No *desempilhar(No **topo) {
    if (*topo != NULL) {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

/*
função para imprimir a pilha

Essa função implementa a operação de imprimir a pilha,
e recebe como parâmetro um ponteiro "topo" para o topo da pilha.
A função começa imprimindo uma mensagem indicando o topo da pilha,
e em seguida entra em um laço de repetição que vai imprimir
os valores dos nós da pilha enquanto o ponteiro "topo" tiver valor
(ou seja, enquanto ainda houver nós na pilha). Dentro do laço, a função
chama a função "imprimir_pessoa" passando como argumento o valor do nó apontado
por "topo". Em seguida, o ponteiro "topo" é atualizado para apontar para o próximo
nó da pilha (ou para NULL, caso seja o último nó), e o laço se repete até que o ponteiro
"topo" seja NULL. Por fim, a função imprime uma mensagem indicando o início da pilha.
 */
void imprimirPilha(No *topo) {
    printf("\n----------TOPO DA PILHA----------\n");
    while (topo) {
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n----------INICIO DA PILHA----------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    No *remover, *topo = NULL;
    int opt;

    do {
        printf("0 - Sair\n1 - Push\n2 - Pop\n3 - Imprimir\nDigite a opção: ");
        scanf("%d", &opt);
        getchar();

        switch (opt) {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if (remover) {
                printf("Elemento removido com sucesso!\n");
                printf("================ Pessoa removida ================\n");
                imprimir_pessoa(remover->p);
                printf("\n=================================================\n");
            } else
                printf("Não há elementos para remover!\n");
            free(remover);
            break;
        case 3:
            imprimirPilha(topo);
            break;
        case 0:
            printf("Saindo...");
        default:
            printf("Opção inválida!\n");
        }
    } while (opt != 0);

    return 0;
}