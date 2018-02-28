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
    double s=0;
    for(int i=1;i<n+1;i++)
    {
        s=s+(1./(i*i));
    }
    printf("El sumatori creixent és: %.16G\n",s);
}

void sumatorid(int n)
{
    double s=0;
    for(int i=n;1<i+1;i--)
    {
        s=s+(1./(i*i));
    }
    printf("El sumatori decreixent és: %.16G\n",s);
}