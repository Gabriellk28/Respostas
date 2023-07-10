#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro)
{
    (*area) = (3*pow(l, 2))*sqrt(3)/2;
    (*perimetro) = 6*l;
}

int main(void)
{
    float lado, area, perimetro;
    printf("Informe o valor do lado do hexagono:\n");
    scanf(" %f", &lado);
    calcula_hexagono(lado, &area, &perimetro);
    
    printf("O valor da área: %.1f\nO valor do perimetro: %.1f\n", area, perimetro);
    return 0;
}