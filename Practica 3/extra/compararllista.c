#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* arg[])
{
    
    FILE* uri;
    FILE* meri;
    
    if((uri=fopen(arg[1],"r"))==NULL) 
    {
        printf("Error\n");
        return 1;
    }
    
    if((meri=fopen(arg[2],"r"))==NULL) 
    {
        printf("Error\n");
        return 2;
    }
    
    double valorsmeri[181];
    double valorsuri[181];
    
    int k=0;
    
    while(k<181)
    {
        fscanf(uri, "%lf", &valorsuri[k]);
        k++;
    }
    
    k=0;

    while(k<181)
    {
        fscanf(meri, "%lf", &valorsmeri[k]);
        k++;
    }
    
    fclose(uri);
    fclose(meri);
    
    for(int i=0; i<181; i++)
    {
        printf("meri %lf uri %lf\n", valorsmeri[i], valorsuri[i]);
        if(valorsmeri[i]!=valorsuri[i]) printf("problema a %d\n", i);
    }
    return 0;
}