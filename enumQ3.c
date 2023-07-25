#include <stdio.h>

typedef enum mes
{
   janeiro = 01,
   fevereiro = 02,
   março= 2,
   abril= 02,
   maio= 02,
   junho= 02,
   julho= 02,
   agosto= 02,
   setembro= 02,
   outrubro= 02,
   dezembro= 02
}Mes;


typedef struct data
{
    char dia[5];
    Mes mes;
    char ano[5];
}Data;

int main(void)
{
    Data data;

    printf("Informe o dia:\n");
    scanf(" %[^\n]", &data.dia);
    printf("Informe o mes:\n");
    scanf(" %d", &data.mes);
    printf("Informe o ano:\n");
    scanf(" %f", &data.ano);

    printf("Data:\n");

    return 0;
}