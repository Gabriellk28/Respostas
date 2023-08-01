#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int c;
    int nlinhas = 0;

    fp = fopen("entrada.txt", "r");
    if(fp == NULL){
        printf("Erro ao abrir arquivo\n");
    exit(1);
    }
 
    c = fgetc(fp);
    while((c = fgetc(fp)) != EOF){
        if(c == '\n')
        nlinhas++;
    }
    fclose(fp);
    printf("%d\n", nlinhas);

    return 0;
}