#include <stdio.h> 
#include <stdlib.h>

union indice
{
    float IG;
    float IRA;
    float IRT;
};
typedef union indice IA;

struct aluno
{
    char nome[20];
    int matricula;
    char curso[20];
    IA indices;
};
typedef struct aluno Aluno;

int main(void)
{
    Aluno *aluno;
    aluno = (Aluno *) malloc(sizeof(Aluno));
    if(aluno == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    int op=0;

    printf("Informe o nome:\n");
    scanf(" %[^\n]s", aluno->nome);

    printf("Informe a matricula:\n");
    scanf("%d", &aluno->matricula);

    printf("Informe o curso:\n");
    scanf(" %[^\n]s", aluno->curso);

    printf("Digite 0 - IG\nDigite 1 - IRA\nDigite 2 - IRT\n");
    scanf(" %d", &op);
    switch (op)
    {
    case 0:
        printf("Informe o IG\n");
        scanf(" %f", &aluno->indices.IG);
        break;
    case 1:
        printf("Informe o IRA\n");
        scanf(" %f", &aluno->indices.IRA);
        break;
    case 2:
        printf("Informe o IRT\n");
        scanf(" %f", &aluno->indices.IRT);
        break;
    default:
        break;
    }
    printf("Nome:%s\nMatricula:%d\nCurso:%s\nÍndice:%f\n");

    return 0;
}