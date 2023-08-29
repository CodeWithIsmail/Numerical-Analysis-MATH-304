#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)
int main()
{
    double a=0.0,b=2.0,h,x;
    int i,n=10;
    h=(b-a)/n;
    x=a;
    double X[n+1],fx[n+1],dfx[n+1];
    for(i=0;i<=n;i++)
    {
        X[i]=x;
        fx[i]=f(x);
        x+=h;
    }
    for(i=1;i<=n;i++)
    {
        dfx[i]=(fx[i]-fx[i-1])/h;
    }
    dfx[0]=0;
    for(i=0;i<=n;i++)
    {
        printf("%2d  %10.6lf  %10.6lf %10.6lf\n",i,X[i],fx[i],dfx[i]);
    }
}
