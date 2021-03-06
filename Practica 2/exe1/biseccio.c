#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 1e-15

double f(double);

double secant(double,double);
int biseccio(double[2]);


int main()
{
    double inter[2];
    int n;
    int intcanviat;
    printf("Interval inicial: ");
    scanf("%lf %lf", &inter[0], &inter[1]);
//     double estimacio = inter[1]-inter[0]
    double interval0;
    printf("Introdueix nombre d'iteracions màximes: ");
    scanf("%i", &n);
    
    for(int i=0; i<n+1; i++)
    {
        interval0=inter[intcanviat];
        intcanviat=biseccio(inter);
//         estimacio=estimacio/2;
        if(fabs(interval0-inter[intcanviat])<=error) 
        {
            printf("Nombre d'iteracions biseccio %d\n", i);            
            break;
        }
            
    }
    printf("L'aproximació és = %.16G\n", inter[intcanviat]);
    
    double x1=2, x2=8;
    double x2cop;
    for(int i=0; i<n+1; i++)
    {
        x2cop=x2;
        x2=secant(x1, x2);
        x1=x2cop;
        
        if(fabs(x1-x2)<=error) 
        {
            printf("Nombre d'iteracions per la secant %d\n", i);
            break;
        }
            
    }
    
    printf("L'aproximació és = %.16G\n", x2);


//     printf("L'error és %.8G\n",(xn*xn*xn)-xn-40);
    
    return 0;
}

double f(double x)
{
    return (x*x*x)-x-400;
}

int biseccio(double inter[2])
{
    double mig = (inter[0]+inter[1])/2;
    double signe= f(inter[0])*f(mig);
    if(signe<0) 
    {
        inter[1] = mig;
        return 1;
    }
    
    inter[0]=mig;
    return 0;
    
}

double secant(double x1,double x2)
{
    double xn;
    xn= ((x1*f(x2))-(x2*f(x1)))/(f(x2)-f(x1));
    return xn;
}
