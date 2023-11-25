#include<stdio.h>
int main()
{
    double matrix[3][3],aug[3][6];
    int i,j,k;

    //input take
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%lf",&matrix[i][j]);
            aug[i][j]=matrix[i][j];
        }
    }
    //make augmanted matrix
    for(i=0; i<3; i++)
    {
        for(j=3; j<6; j++)
        {
            if(i+3==j)
                aug[i][j]=1;
            else aug[i][j]=0;
        }
    }

// gaussian elimination
    for(i=0; i<3; i++)
    {
        double pivot=aug[i][i];
        for(j=0; j<3; j++)
        {
            if(i!=j)
            {
                double div=aug[j][i]/pivot;
                for(k=0; k<6; k++)
                {
                    aug[j][k]-=div*aug[i][k];
                }
            }
        }
    }

    for(i=0; i<3; i++)
    {
        double div=aug[i][i];
        for(j=0; j<6; j++)
        {
            aug[i][j]/=div;
        }
    }

    printf("Inverse matrix:\n\n");
    for(i=0; i<3; i++)
    {
        for(j=3; j<6; j++)
        {
            printf("%10.6lf ",aug[i][j]);
        }
        printf("\n");
    }
}
