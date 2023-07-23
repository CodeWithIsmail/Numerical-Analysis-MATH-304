#include<stdio.h>
#include<math.h>
#define eps 10.e-6
#define f(x) (x*x*x+4*x*x-10)
#define df(x) (3*x*x+8*x)

int main()
{
    int it=0;
    double x=1.5,root;
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
   printf("Iter	   x0		  x1		   f(x)		   f'(x)	  f(x1)\n");
   printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    while(1)
    {
       it++;
       root=x-f(x)/df(x);
       printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",it,x,root,f(x),df(x),f(root));
       
       if(f(root)<=eps)
       {
          printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - \n");
         printf("Approximate root = %.6lf\n",root);
         break;
       }
       else 
         x=root;
    }
}

