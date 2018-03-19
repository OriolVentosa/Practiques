#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double);
double df(double);
double bk(double,double);
double serie(double, double);

int main()
{
    double xn=7;
    double bn=1/df(xn);
    int iteracions;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);
    for(int i=0; i< iteracions;i++)
    {
        xn=serie(xn, bn);
        bn=bk(xn,bn);
    }
    
    printf("L'arrel és %f\n", xn);

    return 0;
}



double f(double x)
{
    return (x*x*x)-x-400;
}

double df(double x)
{
    return (3*x*x)-1;
}

double bk(double xn, double y) 
{
    return y*(2-df(xn)*y);
}

double serie(double xn, double bn)
{
    double x = f(xn);
//     printf("f(xn) %f", x);
    x=xn-x;
    return xn-bn*f(xn);
}
