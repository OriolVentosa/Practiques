#include <stdio.h>
#include <math.h>

void formulausual(float [3], float [2]);
void formulanova(float [3], float [2]);

int main(void)
{
    float coef[3];
    float fnormal[2];
    float fnova[2];
    
    for(int i=0; i<3;i++)
    {    
    printf("Introdueix component x^%d ", i);
    scanf("%f", &coef[i]);    
    }
    
    formulausual(coef, fnormal);
    formulanova(coef, fnova);
    printf("Forma usual: %f, %f \nNova forma: %f,%f\n", fnormal[0], fnormal[1], fnova[0], fnova[1]);
    
    return 0;
}

void formulausual(float coef[3], float res[2])
{
    res[0]=(-coef[1]+sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
    res[1]=(-coef[1]-sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
}


void formulanova(float coef[3], float res[2])
{
    res[0]= -2*coef[0]/(coef[1]+sqrtf(coef[1]*coef[1]-4*coef[0]*coef[2]));
    res[1]= -2*coef[0]/(coef[1]-sqrtf(coef[1]*coef[1]-4*coef[0]*coef[2]));
}