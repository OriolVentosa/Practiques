#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

double f(double);

int main()
{
    double suma=0, aux=0;
    int particions;
    double h;
    for(int j=2;j<7;j++)
    {
        particions=1;
        
        for(int i=0;i<j;i++)    //ens calcula les n, potències de 2
        {
            particions*=2;
        }
        
        h=4./particions;
        
        double nodes[particions+1];
        double fnodes[particions+1];
        
        for(int i=0; i<particions+1; i++)
        {
            nodes[i]=1+(aux*h);
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
        
        suma=(suma+fnodes[0]+fnodes[particions])*h/2;
        
        printf("El resultat %d és %.16G\n", particions, suma);
        
        suma=0;
        aux=0;
    }
    
    return 0;
}

double f(double x)
{
    return exp(x)/x;
}