#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define tol 10.e-6
int main()
{
    double a=1.25,b=1.5,c;
    int it=0;

    while(1)
    {
        it++;
        if(f(a)*f(b)>0)
        {
            printf("No root in this bound.\n");
            break;
        }
        c=(a+b)/2;
        if(fabs(f(c))<=tol)
        {
            printf("Iteration: %d\n",it);
            printf("Root %10.6lf\n",c);
            break;
        }
        else if(f(a)*f(c)<0.0)
        {
            b=c;
        }
        else a=c;
    }
}
