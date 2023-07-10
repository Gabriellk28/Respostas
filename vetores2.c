#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, j, quant_questoes, acertos, nota, porcentagem_aprovados;
    char *gabarito, *respostas;;

    //Recebe a quantidade de questões da prova.
    printf("Informe a quantidade de questões da prova:");
    scanf(" %d", &quant_questoes);

    //Aloca memória para o vetor.
    gabarito = (char*) calloc(quant_questoes, sizeof(char));
    if(gabarito == NULL){
        printf("Erro: Memoria Insuficiente!\n");
        exit(1);
    }
    
    //Recebe o gabarito da prova.
    printf("\n");
    printf("Informe o gabarito da prova:\n");
    for(i = 0; i < quant_questoes; i++){
        scanf(" %c", gabarito+i);
    }

    //Imprime o gabarito da prova.
    printf("\n");
    printf("Gabarito:\n");
    for(i = 0; i < quant_questoes; i++){
        printf("Questão %d - %c\n", i+1, gabarito[i]);
    }


    //Aloca memória para o vetor que irá receber o gabarito das provas dos alunos.
    respostas = (char*) calloc(quant_questoes, sizeof(char));
    printf("\n");

    //Recebe os gabaritos dos alunos.
    printf("Gabarito dos alunos:\n");
    for(i = 0; i < 10; i++){
        printf("Informe o gabarito do aluno %d:\n", i+1);
        for(j = 0; j < quant_questoes; j++){
            scanf(" %c", respostas+j);

            //Compara as alternativas dos gabaritos são as mesmas.
            if(gabarito[j] == respostas[j]){
                acertos = acertos+1;
            }
        }

        //Calcula a nota dos alunos.
        nota = (acertos*100)/quant_questoes;

        //Condição para o aluno ser aprovado.
        if(nota >= 60){
            porcentagem_aprovados = porcentagem_aprovados+1;
        }

        //Imprime os dados dos alunos.
        printf("Acertos: %d\n", acertos);
        printf("Nota do aluno %d: %d\n", i+1, nota);
        printf("\n");
        acertos=0;
    }

    //Imprime a porcentagem de alunos aprovados.
    printf("\n");
    printf("Porcentagem de aprovação: %d%%\n", (porcentagem_aprovados*100)/10);

    //Libera a memória alucada pelos vetores.
    free(gabarito);
    free(respostas);
    return 0;
}