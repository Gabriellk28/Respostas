#include <stdio.h>
#include <stdlib.h>

//Declaração da struct Funcionario.
typedef struct funcionario
{
    char id[21];
    char nome[21];
    float salario;
}Funcionario;

//Função que recebe um vetor de ponteiros para a struct Funcionario.
void preenche(Funcionario *func, int n)
{
    int i;

    //Percorre o vetor de ponteiro e preenche os campos da struct.
    for(i = 0; i < n; i++){
        printf("Informe  o ID: ");
        scanf(" %[^\n]", func[i].id);
        printf("Informe  o NOME: ");
        scanf(" %[^\n]", func[i].nome);
        printf("Informe  o SALARIO: ");
        scanf(" %f", &func[i].salario);
    }
}

void escreve(Funcionario *func, int n)
{
    int i;
    FILE *fp;   

    //Abre o arquivo.
    fp = fopen("funcionarios.txt", "ww");
    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    //Escreve no arquivo.
    for(i = 0; i < n; i++){
        fprintf(fp, "%s\n%s\n%.2f\n", func[i].id, func[i].nome, func[i].salario);
    }

    //Fecha o arquivo.
    fclose(fp);
}

int main(void)
{   
    int quant_func;
    Funcionario *funcionario;

    //Recebe a quantidade de funcionarios.
    printf("Informe a quantidade de funcionários: \n");
    scanf(" %d", &quant_func);

    //Alocação de memória para o vetor de ponteiros.
    funcionario = (Funcionario *) malloc(quant_func*sizeof(Funcionario));
    if(funcionario == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    //Chamada da função para preencher os dados dos funcionários
    preenche(funcionario, quant_func);

    escreve(funcionario, quant_func);

    //Libera a memória alocada.
    free(funcionario);

    return 0;
}