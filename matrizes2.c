#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    //Recebe a quantidade de linhas e colunas para a matriz.
    int linhas, colunas, n, m;
    printf("Informe a quantidade de linhas e colunas de uma matriz:\n");
    scanf("%d %d", &linhas, &colunas);

    //Aloca memória para as linhas da matriz.
    int **matriz;
    matriz = (int **) calloc(linhas, sizeof(int *));
    if (matriz == NULL) {
        printf("Sem memória!\n");
        exit(1);
    }

    // Aloca memória para as colunas da matriz.
    for (n = 0; n < linhas; n++) {
        matriz[n] = (int *) calloc(colunas, sizeof(int));
        if (matriz[n] == NULL) {
            printf("Sem memória!\n");
            exit(1);
        }
    }

    // Recebe os elementos para a matriz.
    printf("Informe valores para a matriz:\n");
    for (n = 0; n < linhas; n++) {
        for (m = 0; m < colunas; m++) {
            scanf("%d", &matriz[n][m]);
        }
    }

    // Imprime os valores da matriz.
    printf("Valores da matriz:\n");
    for (n = 0; n < linhas; n++) {
        for (m = 0; m < colunas; m++) {
            printf("%d ", matriz[n][m]);
        }
        printf("\n");
    }

    // Cria a matriz transposta.
    int **matriz_transposta;
    matriz_transposta = (int **) calloc(colunas, sizeof(int *));
    if (matriz_transposta == NULL) {
        printf("Sem memória!\n");
        exit(1);
    }
    for (n = 0; n < colunas; n++) {
        matriz_transposta[n] = (int *) calloc(linhas, sizeof(int));
        if (matriz_transposta[n] == NULL) {
            printf("Sem memória!\n");
            exit(1);
        }
    }

    // Gera a matriz transposta.
    for (n = 0; n < linhas; n++) {
        for (m = 0; m < colunas; m++) {
            matriz_transposta[m][n] = matriz[n][m];
        }
    }

    // Imprime os valores da matriz transposta.
    printf("Valores da matriz transposta:\n");
    for (n = 0; n < colunas; n++) {
        for (m = 0; m < linhas; m++) {
            printf("%d ", matriz_transposta[n][m]);
        }
        printf("\n");
    }

    // Libera a memória alocada para a matriz.
    for (n = 0; n < linhas; n++) {
        free(matriz[n]);
    }
    free(matriz);

    // Libera a memória alocada para a matriz transposta.
    for (n = 0; n < colunas; n++) {
        free(matriz_transposta[n]);
    }
    free(matriz_transposta);

    return 0;
}
