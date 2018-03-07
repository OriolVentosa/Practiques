#include <stdio.h>
#include <math.h>

void formulausual(float [3], float [2]);
void formulanova(float [3], float [2]);

int main(void)
{
    float coef[3];  //llista dels 3 coeficients
    float fnormal[2];   //resultats de la fórmula estàndard
    float fnova[2]; //resultats de la fórmula proposada
    
    for(int i=0; i<3;i++)
    {    
    printf("Introdueix component x^%d ", i);    //coef[0] = c, coef[1] = b i coef[2] = a
    scanf("%f", &coef[i]);    
    }
    
    formulausual(coef, fnormal);
    formulanova(coef, fnova);
    printf("Resultats forma usual: %f, %f \nResultats forma nova: %f,%f\n", fnormal[0], fnormal[1], fnova[0], fnova[1]);
    
    return 0;
}

void formulausual(float coef[3], float res[2])  //fórmula per resoldre equacions de 2n grau 
{
    res[0]=(-coef[1]+sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
    res[1]=(-coef[1]-sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
}


void formulanova(float coef[3], float res[2])   //la nova fórmula que hem proposat
{
    res[0]= -2*coef[0]/(coef[1]+sqrtf(coef[1]*coef[1]-4*coef[0]*coef[2]));
    res[1]= -2*coef[0]/(coef[1]-sqrtf(coef[1]*coef[1]-4*coef[0]*coef[2]));
}