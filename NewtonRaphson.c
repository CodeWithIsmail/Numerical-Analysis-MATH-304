#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)-3*(x)+2)
#define df(x) (2*(x)-3)
#define tol 10.e-6
int main()
{
    double x0=0.0,x1;
    int iter=0;

    while(1)
    {
        iter++;
        x1=x0-(f(x0)/df(x0));
        printf("%10.6lf %10.6lf %10.6lf\n",x1,f(x0),df(x0));

        if(fabs(f(x1))<=tol)
        {
            printf("Iteration: %d\n",iter);
            printf("Root: %10.6lf\n",x1);
            break;
        }
        x0=x1;
    }
}
