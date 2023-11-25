#include<stdio.h>
int main()
{
    double aug[3][4]=
    {
        {-3,2,-1,-1},
        {6,-6,7,-7},
        {3,-4,4,-6}
    };

    int i,j,k;
// gaussian
    /*
    for(i=0; i<2; i++)
      {
          double pivot=aug[i][i];
          for(j=i+1; j<3; j++)
          {
              double div=aug[j][i]/pivot;
              for(k=0; k<=3; k++)
              {
                  aug[j][k]-=aug[i][k]*div;
              }
          }
      }
       */

// gauss jordan

    for(i=0; i<3; i++)
    {
        double pivot=aug[i][i];
        for(j=0; j<3; j++)
        {
            if(i!=j)
            {
                double div=aug[j][i]/pivot;
                for(k=0; k<=3; k++)
                {
                    aug[j][k]-=aug[i][k]*div;
                }
            }
        }
    }

    for(i=0; i<3; i++)
    {
        double div=aug[i][i];
        for(j=0; j<=3; j++)
        {
            aug[i][j]/=div;
        }
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%10.4\lf ",aug[i][j]);
        }
        printf("\n");
    }

    printf("\nSolution: %10.4lf %10.4lf %10.4lf\n",aug[0][3],aug[1][3],aug[2][3]);
}
