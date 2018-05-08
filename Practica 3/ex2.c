#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mig(double, double, double, double);

int main(int argc, char* arg[])
{
    FILE* entrada;
    
    if((entrada=fopen(arg[1],"r"))==NULL) 
    {
        printf("Error\n");
        return 1;
    }
    
    double nodes[12], fnodes[12];
    int k=0;
    while(k<25)
    {
        if(k<13) 
        {
            fscanf(entrada, "%lf", &nodes[k]);
        }    
        else fscanf(entrada, "%lf", &fnodes[k%12]);
        k++;
    }
    
    fclose(entrada);
    
//     for(int i=0;i<12;i++)
//     {
//         printf("%.16G %.16G\n", nodes[i], fnodes[i]);
//     }
    
    double part=11;
    int a;
    part=part+1;
    double contador=part;
    
//     printf("coeficient %d: %.16G\n", 0, fnodes[0]);
    
    int grau, exercici=1;
    while(exercici<4)
    {
        grau=1;
        printf("Apartat %d:\n",exercici);
        for(grau<6)
        {
            double coeficients[grau+1];
            double nousnodes[grau+1];
            if(exercici==1)
            {
                for(int i=0; i<grau+1; i++)
                {
                    coeficients[i]=fnodes[6-grau-1+i];
                    nousnodes[i]=nodes[6-grau-1+i];
//                     printf("nodes[%i]=%.16G\n",i,nousnodes[i]);
//                     printf("coef[%i]=%.16G\n",i,coeficients[i]);
                }
            }
            
            if(exercici==2)
            {
                for(int i=0; i<grau+1; i++)
                {
                    coeficients[i]=fnodes[6+i];
                    nousnodes[i]=nodes[6+i];
//                     printf("nodes[%i]=%.16G\n",i,nousnodes[i]);
//                     printf("coef[%i]=%.16G\n",i,coeficients[i]);
                }            
            }
            
            if(exercici==3)
            {
                for(int i=0; i<grau+1; i++)
                {
                    coeficients[i]=fnodes[((11-grau)/2)+i];
                    nousnodes[i]=nodes[((11-grau)/2)+i];
//                     printf("nodes[%i]=%.16G\n",i,nousnodes[i]);
//                     printf("coef[%i]=%.16G\n",i,coeficients[i]);
                }            
            }
            
            double polinomi[grau+1];

            polinomi[0]=coeficients[0];
            
            contador=grau+1;
            
            a=1;
            
            while(contador>1)
            {
                for(int i=0;i<contador-1;i++)
                {
                    coeficients[i]=mig(coeficients[i], coeficients[i+1], nousnodes[i],nousnodes[i+a]);
                }

 //               printf("coeficient %d: %.16G\n", a, coeficients[0]);
                contador-=1;
                polinomi[a]=coeficients[0];
                a+=1;
            }
            
            double pxk=0;
            double xk=0;
            double aux=1;
            
            for(int j=0; j<grau+1; j++)
            {
                pxk+=(polinomi[j]*aux);
                aux*=(xk-nousnodes[j]);
            }
            printf("Grau %d dóna %.16G\n",grau, pxk);
            grau+=2;
        }
        
        exercici+=1;
    }

    return 0;
}

double mig(double x, double y, double a, double b)
{
    return (y-x)/(b-a);
}
