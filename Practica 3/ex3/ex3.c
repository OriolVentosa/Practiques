#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);

int main()
{
    int particions=4;
    double suma=0, aux=0;
    double nodes[particions+1];
    double fnodes[particions+1];
    double h=1./particions;
    
    for(int i=0; i<particions+1; i++)
    {
        nodes[i]=aux/particions;
        aux++;
    }
    
    for(int i=0; i<particions+1;i++)
    {
        fnodes[i]=f(nodes[i]);
    }
    for(int i=1; i<particions;i++)
    {
        suma+=fnodes[i]*2;
    }
    
    suma= (suma+fnodes[0]+fnodes[particions])*h/2;
    
    printf("El resultat amb trapezi és %.16G\n", suma);
    
    suma=0;
    
    for(int i=1; i<particions;i++)
    {
        if(i%2==0) suma+=fnodes[i]*2;
        else suma+=fnodes[i]*4;
    }
    
    suma= (suma+fnodes[0]+fnodes[particions])*h/3;
    
    printf("El resultat amb Simpson és %.16G\n", suma);
    
    return 0;
}

double f(double x)
{
    return 1./(1+(x*x));
}