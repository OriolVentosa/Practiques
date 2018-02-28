#include <stdio.h>
#include <math.h>


void formulausual(double [3], double [2]);
void formulanova(double [3], double [2]);

int main(void)
{
    double coef[3];
    double fnormal[2];
    double fnova[2];
    
    for(int i=0; i<3;i++)
    {    
    printf("Introdueix component x^%d ", i);
    scanf("%lf", &coef[i]);    
    }
    
    formulausual(coef, fnormal);
    formulanova(coef, fnova);
    printf("Forma usual: %.16G,%.16G \nNova forma: %.16G,%.16G\n", fnormal[0], fnormal[1], fnova[0], fnova[1]);
    
    return 0;
}

void formulausual(double coef[3], double res[2])
{
    res[0]=(-coef[1]+sqrt((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
    res[1]=(-coef[1]-sqrt((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
}


void formulanova(double coef[3], double res[2])
{
    res[0]= -2*coef[0]/(coef[1]+sqrt(coef[1]*coef[1]-4*coef[0]*coef[2]));
    res[1]= -2*coef[0]/(coef[1]-sqrt(coef[1]*coef[1]-4*coef[0]*coef[2]));
}