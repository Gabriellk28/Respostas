#include <stdio.h>

typedef struct pessoa
{
    char nome[20];
    char documento[20];
    int idade;
}Pessoa;

//Função que preenche os campos
void preenche(Pessoa *pessoa)
{
    printf("Informe o nome:\n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe o número do documento:\n");
    scanf(" %[^\n]", pessoa->documento);
    printf("Informe a idade:\n");
    scanf(" %d", &pessoa->idade);
}

//Função que imprimi o conteúdo dos campos
void imprime(Pessoa *pessoa)
{
    printf("Nome: %s\n", pessoa->nome);
    printf("Documento: %s\n", pessoa->documento);
    printf("Idade: %d\n",pessoa->idade);
}

//Função que altera a idade
void altera(Pessoa *pessoa)
{
    int nova_idade;
    printf("Informe a nova:\n");
    scanf(" %d", &nova_idade);
    pessoa->idade = nova_idade;
}

//Função que preenche um vetor do tipo Pessoa
void preenche_vetor(Pessoa *pessoa, int quant)
{
    int i;
    for(i = 0; i < quant; i++){
        printf("Informe o nome:\n");
        scanf(" %[^\n]", pessoa[i].nome);
        printf("Informe o número do documento:\n");
        scanf(" %[^\n]", pessoa[i].documento);
        printf("Informe a idade:\n");
        scanf(" %d", &pessoa[i].idade);

    }
}

//FUnção que calcula a maior e menor idade
void maior_menor(Pessoa *pessoa, int quant)
{
    int i;
    float maior_idade = pessoa[0].idade;
    float menor_idade = pessoa[0].idade;
    int indice_maior = 0;
    int indice_menor = 0;

    for(i = 1; i < quant; i++)
    {
        if(pessoa[i].idade > maior_idade)
        {
            maior_idade = pessoa[i].idade;
            indice_maior = i;
        }

        if(pessoa[i].idade < menor_idade)
        {
            menor_idade = pessoa[i].idade;
            indice_menor = i;
        }
    }

    printf("A pessoa mais nova:\n");
    printf("Idade: %d\n", pessoa[indice_menor].idade);

    printf("A pessoa mais velha:\n");
    printf("Idade: %d\n", pessoa[indice_maior].idade);
}

int main(void)
{
    Pessoa pessoa;
    preenche(&pessoa);

    imprime(&pessoa);

    altera(&pessoa);

    imprime(&pessoa);

    int quant;
    printf("Informe a quantidade de funcionarios:\n");
    scanf(" %d", &quant);
    Pessoa pessoas[quant];
    preenche_vetor(pessoas, quant);
    maior_menor(pessoas, quant);
    return 0;
}
