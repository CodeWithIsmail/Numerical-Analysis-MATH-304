#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define TOL 10.e-6
int main()
{
    double x0=1.25,x1=2.0,x2;
    int it=0;
    while(1)
    {
        it++;
        x2=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);
        if(fabs(f(x2))<=TOL)
        {
            printf("Iteration: %d\n",it);
            printf("Root: %10.6lf\n",x2);
            break;
        }
        x0=x1;
        x1=x2;
    }
}
