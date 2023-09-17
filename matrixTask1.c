#include<stdio.h>
#include<math.h>
#define NMAX 4
int main()
{
    int r,c,i,j,k;
    double mij;
    r=4,c=4;
    double matrics[NMAX][NMAX+1]=
    {
      {1,-1,2,-1,-8},
      {2,-2,3,-3,-20},
      {1,1,1,0,-2},
      {1,-1,4,3,4}
    };
    
     for(i=0;i<NMAX-1;i++)
    {
       for(j=i+1;j<NMAX;j++)
       {
       
           mij=matrics[j][i]/matrics[i][i];
           for(k=i;k<=NMAX;k++)
           {
              matrics[j][k]-=mij*matrics[i][k];
           }
       }
    }
                                                                                                                                                                          
                                                                                                                                                                        for(i=0;i<NMAX;i++)
    {
       for(j=0;j<=NMAX;j++)
       {
           printf("%7.2lf ",matrics[i][j]);
       }
       printf("\n");
    }
    
    for(i=0;i<NMAX;i++)
    {
       for(j=0;j<=NMAX;j++)
       {
           printf("%7.2lf ",matrics[i][j]);
       }
       printf("\n");
    }
}
