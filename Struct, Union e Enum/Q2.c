#include <stdio.h>
#include <string.h>

union tipos
{
    char alimento[20];
    char bebida[20];
    char eletronico[20];
};
typedef union tipos Tipo;

struct produto
{
    char nome[20];
    float preco;
    Tipo tipo;
};
typedef struct produto Produto;

int main(void)
{
    Produto produto;
    int aux;
    printf("Informe o nome do produto:\n");
    scanf(" %[^\n]", produto.nome);
    printf("Informe o preco do produto:\n");
    scanf(" %f", &produto.preco);
    printf("Informe o tipo do produto:\n");
    printf("1 - Alimento\n2 - Bebida\n3 - Eletronico\n");
    scanf(" %d", &aux);
    printf("Nome do produto: %s\n", produto.nome);
    printf("Preco do produto: %.2f\n", produto.preco);
    switch (aux)
    {
    case 1:
        strcpy(produto.tipo.alimento, "Alimento");
        printf("Tipo do produto: %s\n", produto.tipo.alimento);
         break;
    case 2:
        strcpy(produto.tipo.alimento, "Bebida");
        printf("Tipo do produto: %s\n", produto.tipo.bebida);
         break;
    case 3:
        strcpy(produto.tipo.alimento, "Eletronico");
        printf("Tipo do produto: %s\n", produto.tipo.eletronico);
         break;
    default:
        break;
    }
    return 0;
}