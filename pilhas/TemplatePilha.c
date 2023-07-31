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
Aqui temos uma fun��o para ler as structs do tipo
pessoa e data, mas como pessoa j� tem acesso a struct
data, referenciamos apenas o tipo pessoa.

legenda:
* %49 = "%49" � o limite de caracteres da string que definimos
* [^\n] = especificamos que queremos ler todos os caracteres da entrada do usu�rio at� o final da linha
* p.nome = N�o precisa do "&", porque o vetor j� � um ponteiro

como � uma fun��o do tipo Pessoa, temos que retornar o valor de p
*/
Pessoa ler_pessoa() {
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

// Procedimento para imprimir as informa��es de uma Pessoa

void imprimir_pessoa(Pessoa p) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

/*
Estrutura  que ira compor nossa pilha.
Chamamos a estrutura pessoa, que sera
o valor que vamos armazenar em nossa pilha
logo depois, criamos um ponteiro do tipo n�,
que vai apontar para o proximo n� da pilha
*/

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

/*
fun��o para a opera��o push (empilhar)
Criamos uma fun��o do tipo empilhar,
que possui um ponteiro para o topo da fila.

Alocamos mem�ria dinamicamente com o Malloc,
no ponteiro do tipo "No" chamado "novo".

verificamos se foi possivel alocar mem�ria,
se foi possivel, novo vai apontar para p, que
vai acessar a fun��o ler pessoa.

Novo vai apontar para o proximo valor da pilha,
e vai receber o topo, que no caso � o valor que
cadastramos no "ler_pessoa".

E por ultimo retornamos o ponteiro novo.

Caso n�o seja possivel alocar a mem�ria, ser�
printado na tela, um aviso e sera retornado NULL.
 */

No *empilhar(No *topo) {
    No *novo = malloc(sizeof(No));

    if (novo) {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    } else
        printf("\nERRO: N�o � poss�vel alocar mem�ria!\n");

    return NULL;
}

/*
fun��o para a opera��o pop (desempilhar)

Criamos uma fun��o do tipo struct, chamada de desempilhar,
que recebe um ponteiro de ponteiro do tipo No, chamada "topo"

Ent�o verificamos se o valor do ponteiro � diferente de NULL,
caso ele seja, n�s criamos um ponterio do tipo No, chamada "remover"
que vai receber o valor do ponteiro "topo".

Ent�o o topo recebe o proximo valor, que � apontada por remover.

E por ultimo retornamos o remover.

Caso o ponteiro topo esteja vazio, ser� printado um aviso dizendo
que a pilha est� vazia e retornamos NULL
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
fun��o para imprimir a pilha

Essa fun��o implementa a opera��o de imprimir a pilha,
e recebe como par�metro um ponteiro "topo" para o topo da pilha.
A fun��o come�a imprimindo uma mensagem indicando o topo da pilha,
e em seguida entra em um la�o de repeti��o que vai imprimir
os valores dos n�s da pilha enquanto o ponteiro "topo" tiver valor
(ou seja, enquanto ainda houver n�s na pilha). Dentro do la�o, a fun��o
chama a fun��o "imprimir_pessoa" passando como argumento o valor do n� apontado
por "topo". Em seguida, o ponteiro "topo" � atualizado para apontar para o pr�ximo
n� da pilha (ou para NULL, caso seja o �ltimo n�), e o la�o se repete at� que o ponteiro
"topo" seja NULL. Por fim, a fun��o imprime uma mensagem indicando o in�cio da pilha.
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
        printf("0 - Sair\n1 - Push\n2 - Pop\n3 - Imprimir\nDigite a op��o: ");
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
                printf("N�o h� elementos para remover!\n");
            free(remover);
            break;
        case 3:
            imprimirPilha(topo);
            break;
        case 0:
            printf("Saindo...");
        default:
            printf("Op��o inv�lida!\n");
        }
    } while (opt != 0);

    return 0;
}