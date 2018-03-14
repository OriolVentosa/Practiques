#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 1e-15


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
        if(fabs(xn1-xn)<=error) 
        {
            printf("Nombre d'iteracions %d\n", i);
            break;
        }
         
    }
    
    printf("xn = %.16G\n", xn);
//     printf("L'error és %.16G\n",(xn*xn*xn)-xn-40);
    
}

double mnewton(double xn)
{
    double xn1;
    xn1=((2*xn*xn*xn)+40)/((3*xn*xn)-1);
    return xn1;
}
