#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//parar de fer iteracions

double f(double);
double df(double);
double bk(double,double);
double serie(double, double);

int main(int argc, char* fitxers[])
{
    double xn, xncopia;
    printf("Per quin número comencem? "); // minim 5.7
    scanf("%lf",&xn);
    
    FILE* f;
    
    if((f=fopen(fitxers[1],"w"))==NULL) return 1;
    double bn;
    double error1, error2, error1copia;
    int iteracions;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);
    for(int j=1; j<5; j++)
    {
        xncopia=xn;
        bn=1/df(xn);

        fprintf(f,"Ordre %d\n",j);
        for(int i=0; i<iteracions;i++)
        {
            error1=fabs(xncopia-serie(xncopia,bn));
            xncopia=serie(xncopia, bn);
            bn=bk(xncopia,bn);
            error2=fabs(xncopia-serie(xncopia,bn));
            error1copia=error1;

            for(int k=1;k<j;k++)
            {
                error1=error1*error1copia;
            }
        
            fprintf(f, "Iteració %d:    %.16G\n",i, error2/error1);
        }
    }

    printf("L'arrel és %.16G\n", xncopia);
    
    fclose(f);
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
    return xn-bn*f(xn);
}
