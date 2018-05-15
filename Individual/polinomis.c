#include <stdio.h>
#include <math.h>

double polleg(int, double); //troba els quocients de polinomi grau n
double polcheb(int, double);
void intervals(int, double [][2]);

int main()
{
    int n;
    scanf("%d",&n);
    double inter[n][2];
    intervals(n, inter);
    for(int i=0; i<n;i++)
    {
        printf("Interval %d [%lf,%lf]\n", i, inter[i][0],inter[i][1]);
    }
    
    
    return 0;
}

double polleg(int n, double x)
{
    double quo1=1, quo2=x,quo;
    if (n==0) return quo1;
    if(n==1) return quo2;
      
    for(int i=2; i<n+1; i++)
    {
        quo=(((2*(i-1))+1)*x*quo2)-((i-1)*quo1);
        quo=quo/i;
        quo1=quo2;
        quo2=quo;
    }
        
    return quo;
}

double polcheb(int n, double x)
{
    double quo1=1, quo2=x,quo;
    if (n==0) return quo1;
    if(n==1) return quo2;
    
    for(int i=2; i<n+1; i++)
    {
        quo=(2*x*quo2)-quo1;
        quo1=quo2;
        quo2=quo;
    }
    return quo;
}


void intervals(int n, double inter[][2])
{
    int sig=0;
    int part=2;
    double p;
    
    while(sig<n)
    {
        sig=0;
        double vals[part+1];
        
        for(int i=0; i<part+1;i++)
        {
            p=i;
            vals[i]=polcheb(n,-1+(2*p/part));
        }
            
        for(int i=0;i<part;i++)
        {
            if(vals[i]*vals[i+1]<0) 
            {
                sig+=1;
            }
        }
        
        if(n%2==0)
        {
            if(sig==n)
            {
                int k=0;
                for(int i=0;i<part+1;i++)
                {
                    if(vals[i]*vals[i+1]<=0)
                    {
                        p=i;
                        inter[k][0]=-1+(2*p/part);
                        inter[k][1]=-1+(2*(p+1)/part);
                        k++;
                    }
                }
            }
        }
        
        else
        {
            if(sig==(n-1))
            {
                int k=0;
                inter[k][0]=0;
                inter[k][1]=0;
                k++;
                for(int i=0;i<part+1;i++)
                {
                    if(vals[i]*vals[i+1]<0)
                    {
                        p=i;
                        inter[k][0]=-1+(2*p/part);
                        inter[k][1]=-1+(2*(p+1)/part);
                        k++;
                    }
                }
                break;
            }
                
        }
        
        part*=2;
    }
}