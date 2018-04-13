#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 5e-16


double mnewton(double xn);

int main()
{
    double xn,xn1;
    int n;
    printf("Introdueix el valor inicial: ");
    scanf("%lf", &xn);
    printf("Introdueix nombre d'iteracions: ");
    scanf("%i", &n);
    
    for(int i=0; i<n+1; i++)
    {
        xn1=xn;
        xn=mnewton(xn);
        if(fabs(xn1-xn)<=error) //mirem l'error absolut  
        {
            printf("Nombre d'iteracions necessàries: %d\n", i);
            break;
        }
         
    }
    
    printf("xn = %.16G\n", xn);
    
}

double mnewton(double xn) //mètode de Newton per x^3-x-40
{
    double xn1;
    xn1=((2*xn*xn*xn)+40)/((3*xn*xn)-1);
    return xn1;
}
