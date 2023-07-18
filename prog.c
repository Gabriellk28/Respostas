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

void inicializa(int n, Aluno **tab)
{
    int i;
    for(i = 0; i < n; i++){
        tab[i] = NULL;
    }
}

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

void imprime_tudo(int n, Aluno **tab)
{
    int i;
    for(i = 0; i < n; i++){
        imprime(n, tab, i);
    }
}

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