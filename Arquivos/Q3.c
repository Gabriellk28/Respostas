#include <stdio.h>
#include <stdlib.h>

typedef struct fruta
{
    char nome[21];
    float preco;
}Fruta;

void preenche(Fruta *fruta, int cont)
{
    int i;
    for(i=0; i<cont; i++){
        printf("Informe  o Nome: ");
        scanf(" %[^\n]", fruta[i].nome);
        printf("Informe a Preço ");
        scanf(" %f", &fruta[i].preco);
    }
}

void escreve(Fruta *fruta, int cont)
{
    int i;
    FILE *fp;   

    //Abre o arquivo.
    fp = fopen("frutas.txt", "wt");
    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    //Escreve no arquivo.
    for(i=0; i<cont; i++){
        fprintf(fp, "%s, %.1f\n", fruta[i].nome, fruta[i].preco);
    }

    //Fecha o arquivo.
    fclose(fp);
}

int main(void)
{
    Fruta *frutas;
    int opcao, cont = 1;

    frutas = (Fruta *) malloc(cont*sizeof(Fruta));
    if(frutas == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    do
    {
        printf("MENU\n");
        printf("1 - Cadastrar Fruta\n");
        printf("2 - Parar Cadastro\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            frutas = realloc(frutas, cont*sizeof(Fruta));
            printf("Informe o nome da fruta:\n");
            preenche(frutas, cont);
            escreve(frutas, cont);
            cont++;
            break;
        default:
            break;
        }
    } while (opcao != 2);

    printf("Cadastro Encerrado\n");
    
    free(frutas);
    return 0;
}