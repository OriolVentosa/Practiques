#include <stdio.h>

int main(int argc, char* arg[])
{
    FILE* entrada;
    FILE* sortida;
    double matriu[3][10];
    
    if((entrada = fopen(arg[1],"r"))==NULL)  //si no escrivim el nom de l'arxiu o l'escrivim malament
    {
        printf("Error\n");
        return 0;
    }
    
    if((sortida = fopen(arg[2],"w"))==NULL)  //si no escrivim el nom de l'arxiu o l'escrivim malament
    {
        printf("Error\n");
        return 0;
    }
    
    
    int n=0;
    int i=0;
    double a;
    while(EOF != fscanf(entrada, "%lf", &a))  //mirem el nombre de files que té l'arxiu per saber la llargada del vector
    {
        if(i==4) break;
        matriu[i][n%10]=a;
        n=n+1;
        if(n%10==0) 
        {
            i++;
            printf("%d ",i);
        }
    }
    
    fclose(entrada);
    
    for(int j=0; j<10; j++)
    {
        fprintf(sortida, "%chline %d & %.16G & %ctextbf{%.16G }& %.16G %c%c\n", 92,j+1, matriu[0][j], 92,matriu[1][j], matriu[2][j], 92,92);
        printf("%d ",j);
    }
    
    fclose(sortida);
}