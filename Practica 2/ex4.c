#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359
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
    
    double error1, error2;
    double an,bn,sn,pn,pncopia;
    int iteracions;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);

    an=1;   //a0
    bn=1/(sqrt(2)); //b0
    sn=1./2; //s0
        
    for(int i=0; i<iteracions;i++)
    {
        pn=recurrenciat(&an,&bn,&sn,i);
        error2=fabs(PI-pn);
        pncopia=pn;
//         canvi(&an, &bn, &sn,i);
        error1=error1*error1;

        fprintf(f, "Iteració %d:    %.16G\n",i, error2/error1);
        
        error1=error2;
            
        printf("L'arrel és %.16G\n", pncopia);

    }

    
    fclose(f);
    return 0;
}

double recurrenciat(double *an, double *bn, double *sn, int i)
{
     double ancopia=*an, cn, pn;
     *an=ak(*an,*bn);
     printf("an: %lf\n", *an);
     *bn=bk(ancopia,*bn);
     printf("bn: %lf\n", *bn);
     ancopia=*an;
     cn=ck(*an,*bn);
     printf("cn: %lf\n", cn);
     *sn=sk(*sn,cn,i);
     printf("sn: %lf\n", *sn);
     pn=pk(*an,*sn);
//      printf("an: %lf bn: %lf cn: %lf sn: %lf pn: %lf", *an,*bn,cn,*sn,pn);
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



