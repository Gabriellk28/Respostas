#include <stdio.h>

typedef struct professor
{
    char nome[21];
    char disciplinas[51];
    int regime_de_trabalho;
}Professor;

void preenche(Professor *professor)
{
    printf("Informe o nome:");
    scanf(" %[^\n]", professor->nome);
    printf("Informe as disciplinas:");
    scanf(" %[^\n]", professor->disciplinas);
    printf("Informe o regime de trabalho:");
    scanf(" %d", &professor->regime_de_trabalho);
}

void imprime(Professor *professor)
{
    printf("%s\n", professor->nome);
    printf("%s\n", professor->disciplinas);
    printf("%d\n", professor->regime_de_trabalho);
}

void altera(Professor *professor)
{
    int novo_regime;
    printf("Informe o novo regime de trabalho:");
    scanf(" %d", &novo_regime);
    professor->regime_de_trabalho = novo_regime;
    printf("Novo regime de trabalho: %d\n", professor->regime_de_trabalho);
}

int main(void)
{
    Professor professor;

    preenche(&professor);
    imprime(&professor);
    altera(&professor);
   
    return 0;
}