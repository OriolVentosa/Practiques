#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 1e-8

float mnewton(float xn);

int main()
{
    float xn, xn1;
    int n;
    printf("Introdueix el valor inicial: ");
    scanf("%f", &xn);
    printf("Introdueix nombre d'iteracions màximes: ");
    scanf("%i", &n);
    
    for(int i=0; i<n+1; i++)
    {
        xn1=xn;
        xn=mnewton(xn);
        if(fabs(xn-xn1)<=error) 
        {
            printf("Nombre d'iteracions %d\n", i);
            break;
        }
            
    }
    
    printf("xn = %.8G\n", xn);
//     printf("L'error és %.8G\n",(xn*xn*xn)-xn-40);
    
    
}

float mnewton(float xn)
{
    float xn1;
    xn1=((2*xn*xn*xn)+40)/((3*xn*xn)-1);
    return xn1;
}
