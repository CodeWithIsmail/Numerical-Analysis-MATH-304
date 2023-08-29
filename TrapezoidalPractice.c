#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)
int main()
{
    int i,n=10;
    double a=0.0,b=2.0,h,x,sum=0.0;
    h=(b-a)/n;
    x=a;

    for(i=0;i<=n;i++)
    {
        if(i==0 || i==n)
            sum+=f(x)/2.0;
        else
            sum+=f(x);
        x+=h;
    }
    sum*=h;
    printf("Integral Value using Trapezoidal Rule: %10.6lf\n",sum);
}
