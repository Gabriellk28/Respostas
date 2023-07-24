#include <stdio.h>

enum boolean{false, true};
typedef enum boolean Bool;

int main(void)
{
    Bool val;
    printf("Digite 0 ou 1\n");
    scanf(" %d", &val);

    if(val==true){
        printf("Verdadeiro\n");
    }
    else{
        printf("Falso\n");
    }
    return 0;
}