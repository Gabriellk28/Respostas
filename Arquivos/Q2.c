#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[21];
    float nota;
}Aluno;

void preenche(Aluno *aluno, int n)
{
    int i;

    //Percorre o vetor de ponteiro e preenche os campos da struct.
    for(i = 0; i < n; i++){
        printf("Informe  o Nome: ");
        scanf(" %[^\n]", aluno[i].nome);
        printf("Informe a nota: ");
        scanf(" %f", &aluno[i].nota);
    }
}

void escreve(Aluno *aluno, int n)
{
    int i;
    FILE *fp;   

    //Abre o arquivo.
    fp = fopen("alunos.txt", "ww");
    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    //Escreve no arquivo.
    for(i = 0; i < n; i++){
        fprintf(fp, "%s\n%.1f\n", aluno[i].nome, aluno[i].nota);
    }

    //Fecha o arquivo.
    fclose(fp);
}

int main() 
{
    Aluno *alunos;
    int quant_alunos;

    printf("Informe a quantidade de alunos: ");
    scanf(" %d", &quant_alunos);

    alunos = (Aluno *) malloc(quant_alunos*sizeof(Aluno));
    if(alunos == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }


    preenche(alunos, quant_alunos);

    escreve(alunos, quant_alunos);

    free(alunos);

    return 0;
}