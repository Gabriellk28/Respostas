#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    char nome[21];
    int idade;
    char cargo[21];
    struct funcionario *proximo;
}Funcionario;

Funcionario *preencheLista(Funcionario *funcionario)
{
    Funcionario *novoFuncionario;
    char nome[21], cargo[21];
    int idade;

    novoFuncionario = (Funcionario*) malloc(sizeof(Funcionario));
    if(novoFuncionario == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    printf("Informe o Nome: ");
    scanf(" %[^\n]", novoFuncionario->nome);
    printf("Informe a Idade: ");
    scanf(" %d", &novoFuncionario->idade);
    printf("Informe o Cargo: ");
    scanf(" %[^\n]", novoFuncionario->cargo);

    novoFuncionario->proximo = funcionario;

    return novoFuncionario;
}

void imprimeLista(Funcionario *funcionario)
{
    Funcionario *p;
    for(p = funcionario; p != NULL; p = p->proximo){
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
        printf("Cargo: %s\n", p->cargo);
    }
}

int main(void)
{
    Funcionario *listaFuncionarios;
    int opcao;

    do
    {
        printf("\nMENU\n");
        printf("1 - Registar Novo Funcionario\n");
        printf("2 - Listar os Funcionarios\n");
        printf("3 - Sair\n");
        scanf(" %d", &opcao);
        switch(opcao)
        {
            case 1:
                listaFuncionarios = preencheLista(listaFuncionarios);
                printf("Funcionário Registrado Com Sucesso!\n");
            break;

            case 2:
                imprimeLista(listaFuncionarios);
            break;


        }
    }while(opcao != 3);

    free(listaFuncionarios);
    return 0;
}