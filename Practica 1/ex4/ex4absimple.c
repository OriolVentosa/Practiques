#include <math.h>
#include <stdio.h>

void sumatoric(int);
void sumatorid(int);

int main()
{
    int n;
    
    printf("Nombre termes a sumar\n");
    scanf("%d",&n);
    
    sumatoric(n);
    sumatorid(n);   

    return 0;
}

void sumatoric(int n)
{
    float s=0;
    float igran=1;
    for(int i=1;i<n+1;i++)
    {
        s=s+(1/(igran*igran));
        igran=igran+1;
    }
    printf("El sumatori creixent és: %f\n",s);
}

void sumatorid(int n)
{
    float s=0;
    float igran=n;
    
    for(int i=n;1<i+1;i--)
    {
        s=s+(1/(igran*igran));
        igran=igran-1;
    }
    printf("El sumatori decreixent és: %f\n",s);
}