#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

double f(double);
double cheb(int, double);

double mig(double, double, double, int, int);

int main(int arg, char* argc[])
{
    FILE* sortida;
    if((sortida=fopen(argc[1],"w"))==NULL) 
    {
        printf("error\n");
        return 1;
    }
    
    double part;
    int a=1;
    printf("Indica el nombre de particions: ");
    scanf("%lf",&part);
    part=part+1;
    double contador=part;
    int dim=part;
    double polinomi[dim];
    double quoficients[dim];
    for(int i=0;i<dim;i++)
    {
        quoficients[i]=f(cheb(i, part));
    }
    
    printf("quoficient %d: %lf\n", 0, quoficients[0]);
    
    polinomi[0]=quoficients[0];
    
    
    while(contador>1)
    {
//         printf("%d: \n", a);

        for(int i=0;i<contador-1;i++)
        {
            quoficients[i]=mig(quoficients[i], quoficients[i+1],part,i, i+a);
        }

        printf("quoficient %d: %lf\n", a, quoficients[0]);
        contador-=1;
        polinomi[a]=quoficients[0];
        a+=1;
    }
    
    for(int i=0; i<part; i++)
    {
        fprintf(sortida," %.16G ", polinomi[i]);
    }
    
    fprintf(sortida,"\n");
    return 0;
}

double f(double x)
{
    return 1/(1+(25*x*x));
}

double cheb(int j, double n)
{
    return cos((((2*j)+1)*PI)/((n)*2));
}


double mig(double x, double y, double n, int a, int b)
{
    return (y-x)/(cheb(b,n)-cheb(a,n));
}
