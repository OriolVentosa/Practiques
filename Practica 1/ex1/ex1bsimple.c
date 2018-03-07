#include <stdio.h>
#include <math.h>

float operacio(float);

int main(void)
{
    float valor;
    printf("Introdueix valor\n");
    scanf("%f",&valor);
    printf("El valor de la funció a %f és %f\n",valor, operacio(valor));
    return 0;
    
}

float operacio(float x) //funció f(x) com a float
{
    if (x==0)
    {
        return 1./2.;
    }
    return (1-cosf(x))/(x*x);
}