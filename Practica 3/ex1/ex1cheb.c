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
    double coeficients[dim];
    for(int i=0;i<dim;i++)
    {
        coeficients[i]=f(cheb(i, part));
    }
    
    printf("quoficient %d: %lf\n", 0, coeficients[0]);
    
    polinomi[0]=coeficients[0];
    
    
    while(contador>1)
    {
//         printf("%d: \n", a);

        for(int i=0;i<contador-1;i++)
        {
            coeficients[i]=mig(coeficients[i], coeficients[i+1],part,i, i+a);
        }

        printf("quoficient %d: %.16G\n", a, coeficients[0]);
        contador-=1;
        polinomi[a]=coeficients[0];
        a+=1;
    }
    
    double x[dim-1];
    
    for(int i=0; i<dim-1; i++)
    {
        x[i]=-cheb(i, dim);
    }
    
    double pxk=0;
    double xk;
    double aux=1;
    double errormax=0;
    for(int i=0; i<181; i++)
    {
        xk=-0.989+(i*0.011);
        for(int j=0; j<dim; j++)
        {
            pxk+=(polinomi[j]*aux);
            aux*=(xk-x[j]);
//	    printf("aux %lf ", aux);
        }
        fprintf(sortida, "%.16G: pxk= %.16G fxk= %.16G \n", xk, pxk, f(xk));
	if(fabs(pxk-f(xk))>errormax) errormax=fabs(pxk-f(xk));
	pxk=0;
	aux=1;
    }
    printf("Error maxim %.16G\n",errormax);
    
    
    fclose(sortida);
    
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
