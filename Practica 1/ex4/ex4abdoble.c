#include <math.h>
#include <stdio.h>

void sumatoric(int);
void sumatorid(int);
void nousumatori(int);
int main()
{
    int n;
    
    printf("Nombre termes a sumar\n");
    scanf("%d",&n);
    
    sumatoric(n);
    sumatorid(n);   
    nousumatori(n);
    return 0;
}

void sumatoric(int n)
{
    double s=0;
    double igran=1;
    for(int i=1;i<n+1;i++)
    {
        s=s+(1/(igran*igran));
        igran=igran+1;
    }
    printf("El sumatori creixent és: %.16G\n",s);
}

void sumatorid(int n)
{
    double s=0;
    double igran=n;
    
    for(int i=n;1<i+1;i--)
    {
        s=s+(1/(igran*igran));
        igran=igran-1;
    }
    printf("El sumatori decreixent és: %.16G\n",s);
}

void nousumatori(int n)
{
    int r[n+1];
    int i, k;
    int b, d;
    long long int resultatint=0, digits=1, copia;
    int c = 0;
    for (i = 0; i < n; i++) {
        r[i] = 2000;
    }

    for (k = n; k > 0; k -= 14) { //k-=14 es perquè obtenim quatre digits extra cada catorze iteracions
        d = 0;

        i = k;
        for (;;) { //implementació  de l'aproximació de pi de Beeler
            d += r[i] * 10000;
            b = 2 * i - 1;

            r[i] = d % b;
            d /= b;
            i--;
            if (i == 0) break; 
            d *= i;
        }
//         printf("%.4d\n", c + d / 10000);
        resultatint=(resultatint*10000)+(c + d / 10000); //guardar els digits de pi en un enter
//         printf("resultatint %lld\n",resultatint);
        c = d % 10000;
    }
    
    copia=resultatint;
    d=1;
    while(copia != 0) //trobar els digis de l'aproximació de pi
    {
        copia /= 10;
        digits=digits*10;
    }
    
    double resultat=resultatint;
    
    resultat=(resultatint/(digits/10.)); //expressar pi com a decimal
     printf("pi es %.16G\n", resultat);
    resultat=(resultat*resultat)/6; //utilitzar l'aproximació que hem trobat per calcula pi^2/6
    
    printf("Amb la nova formula el resultat és %.16G\n",resultat);

}
