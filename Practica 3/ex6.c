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
    
    double polinomi[particions+1];
    double coeficients[particions+1];
    
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
    
    
    for(int i=0;i<particions+1;i++)
    {
        coeficients[i]=fnodes[i];
    }
    
    polinomi[0]=coeficients[0];
    
    while(contador>1)
    {
//         printf("%d: \n", a);

        for(int i=0;i<contador-1;i++)
        {
            coeficients[i]=mig(coeficients[i], coeficients[i+1],i, i+a);
        }

        printf("coeficient %d: %lf\n", a, coeficients[0]);
        contador-=1;
        polinomi[a]=coeficients[0];
        a+=1;
    }
    
    double nodesnou[29];
    double fnodesnou[29];
    
    for(int i=0; i<15; i++)
    {
        nodesnou[2*i]=nodes[i];
        fnodesnou[2*i]=fnodes[i];
    }
    
    double pxk=0;
    int xk;
    double aux=1;    
    
    for(int i=0; i<13; i++)
    {
        xk=3+(i*6);
        for(int j=0; j<particions+1; j++)
        {
            pxk+=(polinomi[j]*aux);
            aux*=(xk-fnodes[j]);
        }
        
        nodesnou[(2*i)-1]=xk;
        fnodesnou[(2*i)-1]=pxk;
        
        pxk=0;
        aux=1;
    }
    
    double h=84./28;
    
    for(int i=1; i<27;i++)
    {
        if(i%2==0) suma+=fnodesnou[i]*2;
        else suma+=fnodesnou[i]*4;
    }
    
    suma= (suma+fnodesnou[0]+fnodesnou[28])*h/3;
    
    printf("El resultat amb Simpson amb %d particions és %.16G\n", particions ,suma);
    
    return 0;
}



double mig(double x, double y, int a, int b) // y ,x es diferencies dividides n particions a i b nodes
{
    return (y-x)/(equi(b)-equi(a));
}

double equi(int x) //x és la i de la formula i n nombre de particions
{
    return x*6;
}
