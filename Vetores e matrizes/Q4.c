#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n_pessoas, contador, *idades;
    char **nomes;

    //Pede a quantida de pessoas.
    printf("Informe a quantidade de pessoas:\n");
    scanf(" %d", &n_pessoas);

    //Aloca memória para a matriz.
    //1.Linhas
    nomes = (char **) calloc(n_pessoas, sizeof(char*));
    if(nomes == NULL){
        printf("Erro ao alocar memória.");
        exit(1);
    }
    //2.Colunas.
    for(contador=0; contador < n_pessoas; contador++){
        nomes[contador] = (char*) calloc(50, sizeof(char));

    }

    //Alocando memória para o vetor.
    idades = (int *) calloc(n_pessoas, sizeof(int));
    if(idades == NULL){
        printf("Erro ao alocar memória.");
        exit(1);
    }

    //Recebe os nomes e as idades pessoas.
    for(contador = 0; contador < n_pessoas; contador++){
        printf("Informe o nome e a idade da pessoa:%d\n", contador+1);
        scanf(" %[^\n]", nomes[contador]);
        scanf(" %d", &idades[contador]);
    }

    //Realoca a matriz para o tamanho exato dos nomes e assim não disperdiçando memória.
    for(contador = 0; contador < n_pessoas; contador++){
        nomes[contador] = (char *) realloc(nomes[contador], (strlen(nomes[contador]) + 1) * sizeof(char));
    }

    //Imprimindo os nomes e as idades.
    for(contador = 0; contador < n_pessoas; contador++){
        printf("Pessoa:%d\n", contador+1);
        printf("Nome:%s Idade:%d\n", nomes[contador], idades[contador]);
    }

    //Liberando a memória alocada para a matriz.
    for(contador = 0; contador < n_pessoas; contador++){
        free(nomes[contador]);
    }
    free(nomes);

    //Liberando a memória alocada para o vetor.
    free(idades);
 
    return 0;
}