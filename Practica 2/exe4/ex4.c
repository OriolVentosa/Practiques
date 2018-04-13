#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI  3.14159265358979323
double ak(double, double);
double bk(double, double);
double sk(double, double, int);
double ck(double, double);
double pk(double, double);
double recurrenciat(double*, double*, double*, int);

int main(int argc, char* fitxers[])
{
    FILE* f;
    
    if((f=fopen(fitxers[1],"w"))==NULL) return 1;
    
    double error1=1, error1copia,error2;
    double an,bn,sn,pn;
    int iteracions,x=0,y=0;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);


    for(int j=1; j<4; j++)
    {
        an=1;   //a0
        bn=1/(sqrt(2)); //b0
        sn=1./2; //s0
        fprintf(f, "Ordre %d\n",j);

        for(int i=0; i<iteracions;i++)
        {
            error1=error2;
            error1copia=error1;
            pn=recurrenciat(&an,&bn,&sn,i);
            error2=fabs(PI-pn);
            if(y==0 && j!=1) 
            {
                printf("Error absolut iteració %d: %.16G\n", i+1, error2);
            }
            if(x==0 && i!=0 && j==1)
            {
                if(error1<error2) 
                {
                    printf("L'error absolut ha degenerat a la iteració %d \n",i+1);
                    x=1;
                }
            }
            for(int k=1;k<j;k++)
            {
                error1=error1*error1copia;
            }

            fprintf(f, "Iteració %d:    %.16G\n",i, error2/error1);
        }
        if(j!=1)
        {    
            y=1;
        }
    }
    
    printf("L'arrel és %.16G\n", pn);
    
    fclose(f);
    return 0;
}

double recurrenciat(double *an, double *bn, double *sn, int i)
{
     double ancopia=*an, cn, pn;
     *an=ak(*an,*bn);
     *bn=bk(ancopia,*bn);
     ancopia=*an;
     cn=ck(*an,*bn);
     *sn=sk(*sn,cn,i);
     pn=pk(*an,*sn);
     return pn;
}

double ak(double x, double y)
{
    return (x+y)/2;
}

double bk(double x, double y)
{
    return sqrt(x*y);
}

double sk(double x, double y, int k)  
{
    for(int i=0; i<k+1; i++)
    {
        y=y*2;
    }
    return x-y;
}

double ck(double x, double y)
{
    return (x*x)-(y*y);
}

double pk(double x, double y)
{
    return (2*x*x)/y;
}




