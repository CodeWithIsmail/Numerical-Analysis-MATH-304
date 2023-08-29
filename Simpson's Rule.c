#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)
int main()
{
    double a=0.0,b=2.0,h,x;
    int i,n=10;
    h=(b-a)/n;
    x=a;

    double X=0.0,E=0.0,O=0.0;
    for(i=0; i<=n; i++)
    {
        if(i==0 || i==n)
            X+=f(x);
        else if(i%2)
            O+=f(x);
        else
            E+=f(x);
        x+=h;
    }
    double sum=(h*(X+4*O+2*E))/3.0;
    printf("Integral value using Simpson's 1/3 rule: %10.6lf",sum);
}
