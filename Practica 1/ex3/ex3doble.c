#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double varianza(double*, int);
double varianza2(double*, int);

int main(int fitx, char *nom[])
{
    double a;
    FILE* fitxer;
    
    if((fitxer = fopen(nom[1],"r"))==NULL)
    {
        printf("Error\n");
        return 0;
    }
    
    int n=0;
    while(EOF != fscanf(fitxer, "%lf", &a))
    {
        n=n+1;
    }
    
    fseek(fitxer, 0, SEEK_SET);
    
    double *llista = (double*) malloc(n*sizeof(double));
    
    double* punter = llista;
    while(EOF != fscanf(fitxer,"%lf",punter))
    {
        punter=punter+sizeof(double);
    }
    fclose(fitxer);

    double resultat,resultat2;

    resultat=varianza(llista, n);
    printf("La variança es %.16G\n", resultat);
    
    resultat2=varianza2(llista, n);
    printf("La variança 2 es %.16G\n", resultat2);
    
    return 0;
}

double varianza(double* a, int n)
{
    double llista[n];
    for(int i=0; i<n; i++)
    {
        llista[i]= *a;
        a=a+sizeof(double);
        printf("Terme %d de la llista %.16G\n",i, llista[i]);
    }
    
    double mitjana=0;
    for(int i=0;i<n;i++)
    {
        mitjana=mitjana+llista[i];        
    }
    mitjana=mitjana/n;
    
    double sn2=0;
    for(int i=0; i<n; i++)
    {
        sn2=sn2+(llista[i]-mitjana)*(llista[i]-mitjana);
    }
    sn2=sn2/(n-1);
    
    return sn2;
}

double varianza2(double* a, int n)
{
    double llista[n];
    for(int i=0; i<n; i++)
    {
        llista[i]= *a;
        a=a+sizeof(double);
    }
    double mitjana=0;
    double mitjana2=0;
    
    double sn2=0;
    for(int i=0; i<n; i++)
    {
        mitjana=mitjana+llista[i];
        mitjana2=mitjana2+(llista[i]*llista[i]);
    }

    sn2=(mitjana2-((mitjana*mitjana)/n))/(n-1);
    
    return sn2;
}