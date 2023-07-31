#include <stdio.h>
#include <stdlib.h>
#define MAX 3

struct aluno{
    int mat;
    char nome[81];
    char end[121];
    char tel[21];
};
typedef struct aluno Aluno;

//Esta função está inicializando cada incide do vetor diniâmico com NULL.
void inicializa(int n, Aluno **tab)
{
    int i;
    for(i = 0; i < n; i++){
        tab[i] = NULL;
    }
}

//Esta função está alocando memeória para o tipo struct, acessando e preenchendo com os informações. 
void preenche(int n, Aluno **tab, int i)
{
    if(i < 0 || i >= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] == NULL){
        tab[i] = (Aluno*) malloc(sizeof(Aluno));
    }

    printf("Entre com a matricula:");
    scanf(" %d", &tab[i]->mat);
    printf("Entre com o nome:");
    scanf(" %80[^\n]", tab[i]->nome);
    printf("Entre com o endereco:");
    scanf(" %120[^\n]", tab[i]->end);
    printf("Entre com o telefone:");
    scanf(" %20[^\n]", tab[i]->tel);
}

//Esta função acessa um determinado indice do vetor, retira os dados e preenche novamente com NULL.
void retira(int n, Aluno **tab, int i)
{
    if(i < 0 || i>= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL;
    }
}

//Esta função acessa um determinado indice do vetor e imprime o conteúdo.
void imprime(int n, Aluno **tab, int i)
{
    if(i < 0 || i >= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if(tab[i] != NULL){
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome %s\n", tab[i]->nome);
        printf("Enderco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

//Esta função chama a função imprime para imprimir todos os valores.
void imprime_tudo(int n, Aluno **tab)
{
    int i;
    for(i = 0; i < n; i++){
        imprime(n, tab, i);
    }
}

//Na função principal é feita a criação do ponteiro e as chamadas das funções.
int main(void)
{
    Aluno *tab[MAX];
    inicializa(MAX, tab);
    preenche(MAX, tab, 0);
    preenche(MAX, tab, 1);
    preenche(MAX, tab, 2);
    imprime_tudo(MAX, tab);
    retira(MAX, tab, 0);
    retira(MAX, tab, 1);
    retira(MAX, tab, 2);
    return 0;
}