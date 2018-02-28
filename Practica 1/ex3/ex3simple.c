#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float varianza(float*, int);
float varianza2(float*, int);

int main(int fitx, char *nom[])
{
    float a;
    FILE* fitxer;
    
    if((fitxer = fopen(nom[1],"r"))==NULL)
    {
        printf("Error\n");
        return 0;
    }
    
    int n=0;
    while(EOF != fscanf(fitxer, "%f", &a))
    {
        n=n+1;
    }
    
    fseek(fitxer, 0, SEEK_SET);
    
    float *llista = (float*) malloc(n*sizeof(float));
    
    float* punter = llista;
    while(EOF != fscanf(fitxer,"%f",punter))
    {
        punter=punter+sizeof(float);
    }
    fclose(fitxer);

    float resultat,resultat2;

    resultat=varianza(llista, n);
    printf("La variança es %f\n", resultat);
    
    resultat2=varianza2(llista, n);
    printf("La variança 2 es %f\n", resultat2);
    
    return 0;
}

float varianza(float* a, int n)
{
    float llista[n];
    for(int i=0; i<n; i++)
    {
        llista[i]= *a;
        a=a+sizeof(float);
        printf("Terme %d de la llista %f\n",i, llista[i]);
    }
    
    float mitjana=0;
    for(int i=0;i<n;i++)
    {
        mitjana=mitjana+llista[i];        
    }
    mitjana=mitjana/n;
    
    float sn2=0;
    for(int i=0; i<n; i++)
    {
        sn2=sn2+(llista[i]-mitjana)*(llista[i]-mitjana);
    }
    sn2=sn2/(n-1);
    
    return sn2;
}

float varianza2(float* a, int n)
{
    float llista[n];
    for(int i=0; i<n; i++)
    {
        llista[i]= *a;
        a=a+sizeof(float);
    }
    float mitjana=0;
    float mitjana2=0;
    
    float sn2=0;
    for(int i=0; i<n; i++)
    {
        mitjana=mitjana+llista[i];
        mitjana2=mitjana2+(llista[i]*llista[i]);
    }

    sn2=(mitjana2-((mitjana*mitjana)/n))/(n-1);
    
    return sn2;
}