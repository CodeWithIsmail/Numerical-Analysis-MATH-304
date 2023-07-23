#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x+4*x*x-10)
#define eps 1e-6

int main()
{
   double a=1.25,b=1.5,c;
   int it=0;
   
   printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
   printf("Iter	   a		  b		   c		   f(a)		   f(b)		  f(c)\n");
   printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
   while(1)
   {
      c=(a*f(b)-b*f(a))/(f(b)-f(a));
      it++;
     
      printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",
         it,a,b,c,f(a),f(b),f(c));
      if(fabs(f(c))<=eps)
      {
         printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
         printf("Approximate root = %.6lf\n",c);
         break;
      }
      else if(f(a)*f(c)<0)
         b=c;
      else 
         a=c;
   }
}
