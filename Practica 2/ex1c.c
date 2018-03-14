#include <stdio.h>
#include <math.h>

void eq2grau(double [3], double [2]);

int main()
{   
    double coef[4],uv[2],eq2[3],solreal;
    
    coef[0]=-400;
    coef[1]=-1;
    coef[2]=0;
    coef[3]=1;
    
    eq2[0]=-(coef[1]*coef[1]*coef[1])/27;
    eq2[1]=coef[0];
    eq2[2]=1;
    
    eq2grau(eq2,uv);
    
    solreal= powf(uv[0], (double)1./3)+powf(uv[1], (double)1./3);
    
    printf("La solució real és %.16G\n", solreal);
    
    printf("L'error és %.16G\n",(solreal*solreal*solreal)-solreal-40);
    
}

void eq2grau(double coef[3], double res[2])
{
    res[0]=(-coef[1]+sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
    res[1]=(-coef[1]-sqrtf((coef[1]*coef[1]-4*coef[0]*coef[2])))/(2*coef[2]);
}
