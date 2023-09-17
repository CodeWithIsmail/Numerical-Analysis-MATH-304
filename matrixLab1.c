#include<stdio.h>
#include<math.h>
#define N 3
float matrix[3][4]=
{
    {4,1,1,8},
    {2,5,2,3},
    {1,2,4,11}
};

void gaussianElimination()
{
    int i,j,k;
    for (i=0; i<N-1; i++)
    {
        for (j=i+1; j<N; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for(k=i; k<=N; k++)
                matrix[j][k] -= factor * matrix[i][k];
        }
    }
}

float det()
{
    int i;
    float det=1.0;
    for(i=0; i<3; i++)
        det*=matrix[i][i];
    return det;
}


void printMatrix()
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
        {
            printf("%4.2lf ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    gaussianElimination();
    printMatrix();
    printf("%4.6lf\n",det());
}

