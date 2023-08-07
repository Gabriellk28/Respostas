#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declração da struct Funcionario.
typedef struct funcionario
{
    char funcional[3];
    char nome[21];
    char departamento;
    float salario;
}Funcionario;

//Função que copia dos dados do arquino em um vetor do tipo Funcionario.
void copia_dados(FILE* fl, int n, Funcionario** pessoal)
{
    int i;

    //Percorre o vetor, acessa os índices e copias os dados do arquivo.
    for(i = 0; i < n; i++){
        fscanf(fl, "%s %s %c %f", pessoal[i]->funcional, pessoal[i]->nome, &pessoal[i]->departamento, &pessoal[i]->salario);
    }
}

//Função que imprime os dados do vetor.
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto)
{
    int i;
    float total_pag = 0;

    printf("\nFOLHA DE PAGAMENTO DEPTO %c\n", depto);

    //Percorre o vetor e imprime os dados acessador no índice.
    for(i = 0; i < n; i++){
        if (pessoal[i]->departamento == depto){
            printf("FUNCIONAL\tNOME\tDEPTO\tSALARIO\n");
            printf("%s\t\t%s\t%c\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
            total_pag = pessoal[i]->salario+total_pag;
        }
    }

    printf("VALOR TOTAL: R$ %.2f\n\n", total_pag);
}

int main(void)
{   
    FILE *arquivo = NULL;
    char str[10], depto;
    int quant_func, i, quant_depto;
    Funcionario **pessoal;

    //O ponteiro recebe o ponteiro para o arquivo.
    arquivo = fopen("funcionarios.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    //Lê a primeira linha do arquivo e armazena na string 'str'.
    fgets(str, 10, arquivo);

    //A função 'atoi' transforma o conteúdo da string em inteiro.
    quant_func = atoi(str);

    //Aloca memória para o vetor de ponteiros para ponteiros.
    pessoal = (Funcionario **) malloc(quant_func*(sizeof(Funcionario *)));
    if (pessoal == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    //Alocando memória para os ponteiros para estruturas.
    for (i = 0; i < quant_func; i++){
        pessoal[i] = (Funcionario *) malloc(sizeof(Funcionario));
        if (pessoal[i] == NULL){
            printf("Erro ao alocar memória!\n");
            exit(1);
        }
    }
    
    //Passa os argumentos para a função 'copia_dados'.
    copia_dados(arquivo, quant_func, pessoal);

    //Recebe a quantidade de deptos.
    printf("INFORME A QUATIDADE DE DEPTOS:");
    scanf(" %d", &quant_depto);

    //Recebe os deptos.
    for(i = 0; i < quant_depto; i++){
        printf("INFORME O DEPTO:");
        scanf(" %c", &depto);
        imprime_folha_pagamento(quant_func, pessoal, depto);
    }

    //Fecha o arquivo.
    fclose(arquivo);

    //Libera a memória alocada.
    for (i = 0; i < quant_func; i++) {
        free(pessoal[i]);
    }
    free(pessoal);

    return 0;
}