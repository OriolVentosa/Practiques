#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ak(double, double);
double bk(double, double);
double sk(double, double);
double ck(double, double);
double pk(double, double);

int main(int argc, char* fitxers[])
{
    FILE* f;
    
    if((f=fopen(fitxers[1],"w"))==NULL) return 1;
    
    double error1, error2, error1copia;
    double an,bn,sn,cn,pn,pncopia;
    int iteracions;
    printf("Escriu nombre màxim d'iteracions\n");
    scanf("%d",&iteracions);
    for(int j=1; j<5; j++)
    {
        an=1;   //a0
        bn=1/(sqrt(2)); //b0
        sn=1/2; //s0
        cn=ck(an,bn);   //c0
        pn=pk(an,sn);   //p0
        pncopia=pn;
        
        fprintf(f,"Ordre %d\n",j);
        
        for(int i=0; i<iteracions;i++)
        {
            an=ak(an,bn);   //a1
            bn=bk(an,bn);   //b1
            cn=ck(an,bn);   //c1
            sn=sk(sn,cn);   //s1
            pn=pk(an,sn);   //p1
            error1=fabs(pncopia-pn);
            
            pncopia=pn;
            an=ak(an,bn);
            bn=bk(an,bn);
            cn=ck(an,bn);
            sn=sk(sn,cn);
            pn=pk(an,sn);
            error2=fabs(pncopia-pn);

            error1copia=error1;

            for(int k=1;k<j;k++)
            {
                error1=error1*error1copia;
            }
        
            fprintf(f, "Iteració %d:    %.16G\n",i, error2/error1);
        }
    }

    printf("L'arrel és %.16G\n", pncopia);
    
    fclose(f);
    return 0;
}



double ak(double x, double y)
{
    return (x+y)/2;
}

double bk(double x, double y)
{
    return sqrt(x*y);
}

double sk(double x, double y)   //NO PODEM UTILITZAR POW
{
    return x-2*2*2*...*y;
}

double ck(double x, double y)
{
    return (x*x)-(y*y);
}

double pk(double x, double y)
{
    return (2*x*x)/y;
}
