#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define error 1e-2

double mig(double, double, int, int); // y ,x es diferencies dividides n particions a i b nodes
double equi(int);

int main(int argc, char* arg[])
{
    int particions=14,k=0;
    double suma=0;
    
    double nodes[particions+1];
    double fnodes[particions+1];
    
    
    int contador = particions+1, a=1;
    
    FILE* entrada;
    
    if((entrada=fopen(arg[1],"r"))==NULL) 
    {
        printf("Error\n");
        return 1;
    }
    
    while(k<31)
    {
        if(k<16) 
        {
            fscanf(entrada, "%lf", &nodes[k]);
        }    
        else fscanf(entrada, "%lf", &fnodes[k%15]);
        k++;
    }
    
    fclose(entrada);
    
    fnodes[0]=37.2;
    
    double h=84./14;
        
    for(int i=1; i<particions;i++)
    {
        if(i%2==0) suma+=fnodes[i]*2;
        else suma+=fnodes[i]*4;
    }
    
    suma= (suma+fnodes[0]+fnodes[particions])*h/3;
    
    printf("El resultat amb Simpson amb %d particions és %.16G\n", particions ,suma);
    
    return 0;
}