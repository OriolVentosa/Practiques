#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//posar que pari quan faci les iteracions suficients

double f(double);
double df(double);
double ddf(double);
double recu(double);

int main(int argc, char* fitxers[])
{
    FILE* f;
    
    if((f=fopen(fitxers[1],"w"))==NULL) return 1;
    
    double xn,xncopia,error1,error2,error1copia;
    printf("Per quin número comencem? ");
    scanf("%lf",&xn);
    int iteracions;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);

    for(int j=2;j<5;j++)
    {
        xncopia=xn;
//        fprintf(f,"Ordre %d\n",j);
        for(int i=0; i<iteracions; i++)
        {
            error1=fabs(xncopia-recu(xncopia)); //càlcul |x_n - x_n+1|
            xncopia=recu(xncopia);
            error2=fabs(xncopia-recu(xncopia)); //càlcul |x_n+1 - x_n+2|
            error1copia=error1;
            
            for(int k=1;k<j;k++)
            {
                error1=error1*error1copia;
            }
            
            fprintf(f, "%.16G\n", error2/error1);
        }
    }
    
    printf("L'arrel és %.16G\n",xncopia);
//     printf("El límit de l'ordre de conv és %.16G\n",error2/(error1*error1*error1));
    
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

double ddf(double x)
{
    return 6*x;
}

double recu(double xn)  //càlcul de la recurrència
{
    return xn-((2*f(xn)*df(xn))/((2*df(xn)*df(xn))-(f(xn)*ddf(xn))));
}
