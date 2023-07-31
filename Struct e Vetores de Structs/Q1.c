#include <stdio.h>

//Declaração da struct funcionario
typedef struct funcionario
{
    char nome[20];
    float salario;
    char identificador[20];
    char cargo[20];
}Funcionario;

//Função que preenche os campos
void preenche(Funcionario *fun)
{
    printf("Informe o nome:\n");
    scanf(" %[^\n]", fun->nome);
    printf("Informe o salário:\n");
    scanf(" %f", &fun->salario);
    printf("Informe o identificador:\n");
    scanf(" %[^\n]", fun->identificador);
    printf("Informe o cargo:\n");
    scanf(" %[^\n]", fun->cargo);
}

//Função que imprimi o conteúdo dos campos
void imprime(Funcionario *fun)
{
    printf("Nome: %s\n", fun->nome);
    printf("Salário: %.2f\n", fun->salario);
    printf("Identificador: %s\n",fun->identificador );
    printf("Cargo: %s\n", fun->cargo);
}

//Função que altera o salário
void altera(Funcionario *fun)
{
    float novo_salario;
    printf("Informe o novo salário:\n");
    scanf(" %f", &novo_salario);
    fun->salario = novo_salario;
}


//Função que preenche um vetor do tipo Funcionário
void preenche_vetor(Funcionario *fun, int quant)
{
    int i;
    for(i = 0; i < quant; i++){
        printf("Informe o nome:\n");
        scanf(" %[^\n]", fun[i].nome);
        printf("Informe o salário:\n");
        scanf(" %f", &fun[i].salario);
        printf("Informe o identificador:\n");
        scanf(" %[^\n]", fun[i].identificador);
        printf("Informe o cargo:\n");
        scanf(" %[^\n]", fun[i].cargo);
    }
}

//FUnção que calcula o maior e menor salário
void maior_menor(Funcionario *fun, int quant)
{
    int i;
    float maior_salario = fun[0].salario;
    float menor_salario = fun[0].salario;
    int indice_maior = 0;
    int indice_menor = 0;

    for(i = 1; i < quant; i++)
    {
        if(fun[i].salario > maior_salario)
        {
            maior_salario = fun[i].salario;
            indice_maior = i;
        }

        if(fun[i].salario < menor_salario)
        {
            menor_salario = fun[i].salario;
            indice_menor = i;
        }
    }

    printf("Funcionário com maior salário:\n");
    printf("Cargo: %s\n", fun[indice_maior].cargo);
    printf("Salário: %.2f\n", fun[indice_maior].salario);
    printf("Funcionário com menor salário:\n");
    printf("Cargo: %s\n", fun[indice_menor].cargo);
    printf("Salário: %.2f\n", fun[indice_menor].salario);
}

int main(void)
{
  
    Funcionario funcionario;

    preenche(&funcionario);
    imprime(&funcionario);
    altera(&funcionario);
    imprime(&funcionario);

    int quant;
    printf("Informe a quantidade de funcionarios:\n");
    scanf(" %d", &quant);
    Funcionario funcionarios[quant];
    preenche_vetor(funcionarios, quant);
    maior_menor(funcionarios, quant);

    return 0;
}