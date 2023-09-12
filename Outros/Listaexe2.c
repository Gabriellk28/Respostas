#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frutas
{
    char nome[10]; //Nome da fruta
    float preco; //Preço da fruta
    struct frutas *proxima; //Endereço da próxima fruta
};

struct frutas *insere(struct frutas *fruta, char *nome, float preco)
{
    struct frutas *novaFruta = (struct frutas*) malloc(sizeof(struct frutas));
    strcpy(novaFruta->nome, nome);
    novaFruta->preco = preco;

    novaFruta->proxima = fruta;//Colocar o nó no inicio da lista

    //Colocar o nó no fim da lista
    //fruta-proxima = novaFruta;
    //novaFruta->proxima = NULL

    return novaFruta;
}

void imprime(struct frutas *fruta)
{
    struct frutas *p;
    for (p = fruta; p != NULL; p = p->proxima)
    {
        printf("Nome:%s, Preço: %.2f\n", p->nome, p->preco);
    }
}

int main(void)
{
    struct frutas *lista = NULL;

    lista = insere(lista, "maca", 3.99);
    lista = insere(lista, "abacate", 4.00);
    lista = insere(lista, "uva", 0.30);
    imprime(lista);
    free(lista);

    return 0;
}
