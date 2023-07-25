#include <stdio.h>

enum gen
{
    maculino,
    feminino
};
typedef enum gen Genero;

struct pessoa
{
    char nome[20];
    int idade;
    Genero genero;
};
typedef struct pessoa Pessoa;

int main(void)
{
    Pessoa pessoa;
    printf("Informe seu nome:\n");
    scanf(" %[^\n]", pessoa.nome);
    printf("Informe sua idade:\n");
    scanf(" %d", &pessoa.idade);
    printf("Informe seu genero:\n");
    printf("0 - Masculino\n1 - Feminino\n");
    scanf(" %d", &pessoa.genero);
    printf("Nome: %s\nIdade: %d\n", pessoa.nome, pessoa.idade);
    if(pessoa.genero==maculino){
        printf("Genero: Masculino\n");
    }
    else
        if(pessoa.genero==feminino)
        {
            printf("Genero: Feminino\n");
        }
        
    return 0;
}

