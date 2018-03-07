#include <stdio.h>
#include <math.h>

double operacio(double);

int main(void)
{
    double valor;
    printf("Introdueix valor\n");
    scanf("%lf",&valor);
    printf("El valor de la funció a %.16G és %.16G\n",valor, operacio(valor));
    return 0;
    
}

double operacio(double x)   //funció f(x) com a double
{
    if (x==0)
    {
        return 0.5;
    }
    return (1-cos(x))/(x*x);
}