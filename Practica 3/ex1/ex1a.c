#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

double cheb(int, double);
double f(double);

int main(int arg, char* argc[])
{
    FILE* entrada;
    FILE* sortida;
    
    if((entrada=fopen(argc[1],"r"))==NULL) return 1;
    if((sortida=fopen(argc[2],"w"))==NULL) return 2;
    
    double a;
    int n=0;
    while(EOF != fscanf(entrada, "%lf", &a))  //mirem el nombre de files que té l'arxiu per saber la llargada del vector
    {
        n=n+1;
    }
    
    fseek(entrada, 0, SEEK_SET);
    
    double coef[n];

    int j=0;
    
    while(EOF != fscanf(entrada, "%lf", &coef[j]))  //mirem el nombre de files que té l'arxiu per saber la llargada del vector
    {
        j=j+1;
    }
    
    fclose(entrada);
    
    double x[n-1];
    
    for(int i=0; i<n-1; i++)
    {
        x[i]=cheb(i, n);
    }
    
    double pxk=0;
    double xk;
    double aux=1;
    double errormax=0;
    for(int i=0; i<181; i++)
    {
        xk=-0.989+(i*0.011);
        for(int j=0; j<n; j++)
        {
            pxk+=(coef[j]*aux);
            aux*=(xk-x[j]);
        }
        fprintf(sortida, "%.16G: pxk= %.16G fxk= %.16G \n", xk, pxk, f(xk));
	if(fabs(pxk-f(xk))>errormax) errormax=fabs(pxk-f(xk));
    }
    printf("Error maxim %.16G\n",errormax);
    
    
    fclose(sortida);
    
}

double cheb(int j, double n)
{
    return cos((((2*j)+1)*PI)/((n)*2));
}

double f(double x)
{
    return 1/(1+(25*x*x));
}
