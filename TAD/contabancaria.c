#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contabancaria
{
    char titular[21];
    int numero;
    float saldo;
};

ContaBancaria *cria_conta(char *nome, int numero, float saldo)
{
    ContaBancaria *cb;
    cb = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    if(cb == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    strcpy(cb->titular, nome);
    cb->numero = numero;
    cb->saldo = saldo;

    return cb;
}

void deposita(ContaBancaria *cb, float valor)
{
    cb->saldo = cb->saldo + valor;
}

void saca(ContaBancaria *cb, float valor)
{
    float diferenca;
    if(cb->saldo > valor){
        diferenca = cb->saldo - valor;
        cb->saldo = diferenca;
    }
    else{
        printf("Saldo Insuficiente para sacar\n");
    }
}

void transfere(ContaBancaria *cb1, ContaBancaria *cb2, float valor)
{
    if(cb1->saldo > 0){
        cb2->saldo = cb2->saldo + valor;
    }
}

float saldo(ContaBancaria *cb)
{
    return cb->saldo;
}

void exclui_conta(ContaBancaria *cb)
{
    free(cb);
}