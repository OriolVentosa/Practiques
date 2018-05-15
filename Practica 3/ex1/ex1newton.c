#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double mig(double, double, double, int, int);
double equi(double, double);

int main(int arg, char* argc[])
{
    FILE* sortida;
    if((sortida=fopen(argc[1],"w"))==NULL) 
    {
        printf("error\n");
        return 1;
    }
    
    int part;
    int a=1;
    printf("Indica el nombre de particions: ");
    scanf("%d",&part);
    int nnodes=part+1;
    double contador=nnodes;
    double polinomi[nnodes];
    double coeficients[nnodes];
    double nodes[nnodes];
    
    for(int i=0; i<nnodes; i++)
    {
        nodes[i]=equi(i, part);
    }
    
    for(int i=0;i<nnodes;i++)
    {
        coeficients[i]=f(nodes[i]);
    }
        
    polinomi[0]=coeficients[0];

    while(contador>1)
    {
        for(int i=0;i<contador-1;i++)
        {
            coeficients[i]=mig(coeficients[i], coeficients[i+1],part,i, i+a);
        }

        contador-=1;
        polinomi[a]=coeficients[0];

        a+=1;
    }
    
    double pxk=0;
    double xk;
    double aux=1;
    double errormax=0;
    
    for(int i=0; i<181; i++)
    {
        xk=-0.989+(i*0.011);
        for(int j=0; j<nnodes; j++)
        {
            pxk+=(polinomi[j]*aux);
            aux*=(xk-nodes[j]);
        }

        fprintf(sortida, "[%lf,%lf],",xk,pxk);  //S'escriu al fitxer de sortida d'aquesta forma per representar-ho mes facilment al maxima

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

double mig(double x, double y, double n, int a, int b)
{
    return (y-x)/(equi(b,n)-equi(a,n));
}

double equi(double x, double n)
{
    return -1.+(x*2./n);
}
