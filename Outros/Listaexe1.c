#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frutas
{
    char nome[10]; //Nome da fruta
    struct frutas *proxima; //Endereço da próxima fruta
};

int main(void)
{
    //Aloca memória para armazenar os nomes das frutas
    struct frutas *fruta1 = malloc(sizeof(struct frutas));
    struct frutas *fruta2 = malloc(sizeof(struct frutas));
    struct frutas *fruta3 = malloc(sizeof(struct frutas));

    //Inicializa os nomes das frutas
    strcpy(fruta1->nome, "maca");
    strcpy(fruta2->nome, "abacate");
    strcpy(fruta3->nome, "uva");

    //Encadea os espaços de memória
    fruta1->proxima = fruta2;
    fruta2->proxima = fruta3;
    fruta3->proxima = NULL;

    struct frutas *p;
    for(p = fruta1->proxima; p != NULL; p = p->proxima){
        printf("%s\n", p->proxima);
    }
    
    return 0;
}