#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Recebe o tamanho do vetor inserido pelo usuário.
    int tamanho_vetor;
    printf("Informe o tamanho para o vetor:");
    scanf(" %d", &tamanho_vetor);

    //Aloca a memória para o vetor.
    int * vetor = (int *) calloc(tamanho_vetor, sizeof(int));
    if(vetor == NULL){
        printf("Sem memória!\n");
        exit(1);
    }

    //Recebe elementos inseridos pelo usuário.
    int cont;
    printf("Informe os valores para o vetor:\n");
    for(cont = 0; cont < tamanho_vetor; cont++){
        scanf(" %d", &vetor[cont]);
    }

    //Imprime os elemntos do vetor na ordem inversa.
    for(cont = 0; cont < tamanho_vetor; cont++){
        printf("%d\n", vetor[tamanho_vetor - cont -1]);
    }

    free(vetor);
    return 0;
}