#include<stdio.h>
#include<math.h>

#define eps 10.e-6
#define fx(x,y,z) (85-6*y+z)/27
#define fy(x,y,z) (72-6*x-2*z)/15
#define fz(x,y,z) (110-x-y)/54

int main()
{
    double x0=0.0,y0=0.0,z0=0.0,x1,y1,z1;

    for(int i=0; i<100; i++)
    {
        x1=fx(x0,y0,z0);
        y1=fy(x0,y0,z0);
        z1=fz(x0,y0,z0);

        /*  x1=fx(x0,y0,z0);
          y1=fy(x1,y0,z0);
          z1=fz(x1,y1,z0); */

        if(fabs(x0-x1)<eps && fabs(y0-y1)<eps && fabs(z0-z1)<eps)
        {
            printf("%d\n",i+1);
            printf("%10.6lf  %10.6lf  %10.6lf\n",x1,y1,z1);
            break;
        }
        x0=x1;
        y0=y1;
        z0=z1;
    }
}
