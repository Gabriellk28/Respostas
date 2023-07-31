#include <stdio.h>

typedef enum mes
{
   janeiro,
   fevereiro,
   março,
   abril,
   maio,
   junho,
   julho,
   agosto,
   setembro,
   outrubro,
   dezembro,
}Mes;

typedef struct data
{
    int dia;
    Mes mes;
    int ano;
}Data;

int main(void)
{
    Data data;

    printf("Informe o dia:\n");
    scanf(" %d", &data.dia);
    printf("Informe o mes:\n");
    scanf(" %d", &data.mes);
    printf("Informe o ano:\n");
    scanf(" %d", &data.ano);

    printf("Data:\n");
    printf("Data: %02d/%02d/%04d\n", data.dia, data.mes, data.ano);

    return 0;
}