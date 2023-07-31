#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int tamanho, l, c, **matriz;;

    //Recebe o número digito pelo usuário.
    printf("Informe um número inteiro positivo:\n");
    scanf(" %d", &tamanho);

    //Aloca memória para a matriz.
    //1.Linhas
    matriz = (int **) calloc(tamanho, sizeof(int *));
    if(matriz == NULL){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    //2.Colunas
    for(l = 0; l < tamanho; l++){
        matriz[l] = (int*) calloc(tamanho, sizeof(int));
    }

    for(l = 0; l < tamanho; l++){
        for(c = 0; c < tamanho; c++){
            matriz[l][c] = rand() % 101;
        }
    }

    // Imprime os valores da matriz.
    printf("Valores da matriz:\n");
    for (l = 0; l < tamanho; l++) {
        for (c = 0; c < tamanho; c++) {
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }

    // Libera a memória alocada para a matriz.
    for (l = 0; l < tamanho; l++) {
        free(matriz[l]);
    }
    free(matriz);

    return 0;
}