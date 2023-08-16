#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main(void)
{
    char titular1[21], titular2[21];
    int numero1, numero2;
    float saldo1, saldo2, transferencia;

    printf("Digite os dados da primeira conta:\n");
    printf("Titular: ");
    scanf("%[^\n]", titular1);
    printf("Número: ");
    scanf(" %d", &numero1);
    printf("Saldo: ");
    scanf(" %f", &saldo1);

    printf("Digite os dados da segunda conta:\n");
    printf("Titular: ");
    scanf(" %[^\n]", titular2);
    printf("Número: ");
    scanf(" %d", &numero2);
    printf("Saldo: ");
    scanf(" %f", &saldo2);

    ContaBancaria *conta1 = cria_conta(titular1, numero1, saldo1);
    ContaBancaria *conta2 = cria_conta(titular2, numero2, saldo2);
    deposita(conta1);
    deposita(conta2);
    saca(conta1);
    saca(conta2);
    printf("Informe o valor da transferencia:");
    scanf(" %f", &transferencia);
    transfere(conta1, conta2, transferencia);
    saldo(conta1);
    saldo(conta2);
    exclui_conta(conta1);
    exclui_conta(conta2);
    return 0;
}