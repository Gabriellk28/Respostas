#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(void)
{
    Ponto *p = pto_cria(2.0, 1.0);
    Ponto *q = pto_cria(3.4, 2.1);
    float pi = 3.14159;
    float x1 = 2.5, x2 = 3.5;
    float d = pto_distancia(p,q);
    printf("Distancia entre pontos: %f\n", d);
    Circulo *c = cric_cria(x1, x2, pi);
    circ_area(c);
    circ_interior(c, p);

    pto_libera(q);
    pto_libera(p);
    circ_libera(c);
    return 0;
}