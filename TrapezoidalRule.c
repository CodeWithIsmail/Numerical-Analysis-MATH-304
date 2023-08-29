#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)
int main()
{
    double a=0.0,b=2.0,h;
    int n=10,i;
    double sum=0,x=a;
    h=(b-a)/n;

    for(i=0; i<=n; i++)
    {
        if(i==0 || i==n)
            sum+=f(x)/2.0;
        else
            sum+=f(x);
        x+=h;
    }
    sum*=h;
    printf("Integral Value using Trapezoidal rule: %10.6lf",sum);

}
