#include <stdio.h>
#include <math.h>

void eq2grau(float [3], float [2]);

int main()
{   
    float coef[4],uv[2],eq2[3],solreal;
    
    coef[0]=-40;
    coef[1]=-1;
    coef[2]=0;
    coef[3]=1;
    
    eq2[0]=-(coef[1]*coef[1]*coef[1])/27;
    eq2[1]=coef[0];
    eq2[2]=1;
    
    eq2grau(eq2,uv);
    
    solreal= powf(uv[0], (float)1./3)+powf(uv[1], (float)1./3);
    
    printf("La solució real és %.8G\n", solreal);
    
    printf("L'error és %.8G\n",(solreal*solreal*solreal)-solreal-40);
    
}

void eq2grau(float coef[3], float res[2])
{
    res[0]=(-coef[1]+sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
    res[1]=(-coef[1]-sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
}
