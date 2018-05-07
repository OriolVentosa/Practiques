#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define error 1e-2

double f(double);
double er(int);

int main()
{
    int particions=0;
    double suma=0, aux=0, err=1;
    
    while(err>error)
    {
        particions+=1;
        err=er(particions);
    }

    double h=1./particions;
    double nodes[particions+1];
    double fnodes[particions+1];
    
    for(int i=0; i<particions+1; i++)
    {
        nodes[i]=1+aux*h;
        aux++;
    }
    
    for(int i=0; i<particions+1;i++)
    {
        fnodes[i]=f(nodes[i]);
    }
    
    for(int i=1; i<particions;i++)
    {
        if(i%2==0) suma+=fnodes[i]*2;
        else suma+=fnodes[i]*4;
    }
    
    suma= (suma+fnodes[0]+fnodes[particions])*h/3;
    
    printf("El resultat amb Simpson amb %d particions és %.16G\n", particions ,suma);
    
    return 0;
}

double f(double x)
{
    return log(x);
}

double er(int n)
{
    return 1./(30*n*n*n*n);
}