#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double varianza(double*, int);
double varianza2(double*, int);

int main(int fitx, char *nom[])
{
    double a;
    FILE* fitxer;
    
    if((fitxer = fopen(nom[1],"r"))==NULL)  //si no escrivim el nom de l'arxiu o l'escrivim malament
    {
        printf("Error\n");
        return 0;
    }
    
    int n=0;
    while(EOF != fscanf(fitxer, "%lf", &a))  //mirem el nombre de files que té l'arxiu per saber la llargada del vector
    {
        n=n+1;
    }
    
    fseek(fitxer, 0, SEEK_SET);
    
    double *llista = (double*) malloc(n*sizeof(double));
    
    double* punter = llista;
    while(EOF != fscanf(fitxer,"%lf",punter))    //guardem els elements de l'arxiu
    {
        punter=punter+sizeof(double);
    }
    fclose(fitxer);

    double resultat,resultat2;

    resultat=varianza(llista, n);
    printf("La variança amb 2 bucles és %.16G\n", resultat);
    
    resultat2=varianza2(llista, n);
    printf("La variança amb 1 bucle és %.16G\n", resultat2);
    
    return 0;
}

double varianza(double* a, int n) //funció varinça en 2 bucles
{
    double llista[n];
    for(int i=0; i<n; i++)  //distingim els termes de la llista
    {
        llista[i]= *a;
        a=a+sizeof(double);
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

double varianza2(double* a, int n)    //funció variança en 1 bucle
{
    double llista[n];
    for(int i=0; i<n; i++)  //distingim els termes de la llista
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