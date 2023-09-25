#include<stdio.h>
#define N 3
double L[N][N];
double U[N][N];
double Y[N][1];
double X[N][1];

void printMatrix(double mat[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
       for(j=0;j<N;j++)
          printf("%4.3lf ",mat[i][j]);
       printf("\n");
    }
    printf("\n");
}
void matMUl(double mat1[N][N],double mat2[N][N])
{
   int i,j,k;
   double mat[N][N];
   for(k=0;k<3;k++)
    {
       for(j=0;j<3;j++)
       {
          for(i=0;i<3;i++)
          {
              mat[i][j]+=mat1[i][k]*mat2[k][j];
          }
       }
    }
    printMatrix(mat);
}
void LU(double mat[N][N])
{
    int i,j,k;
  //  double U[N][N],I[N][N];
    for(i=0;i<N;i++)
    {
       for(j=0;j<N;j++)
       {
          U[i][j]=mat[i][j];
          if(i==j)
            L[i][j]=1;
          else
            L[i][j]=0;
       }
    }
    
   // printMatrix(U);
   // printMatrix(I);
   
   for(i=0;i<N-1;i++)
   {
      for(j=i+1;j<N;j++)
      {
         double ratio=U[j][i]/U[i][i];
         for(k=0;k<N;k++)
         {
            U[j][k]-=ratio*U[i][k];
         }
         L[j][i]=ratio;
      }
   }
   printf("Matrix L:\n");
   printMatrix(L);
   printf("Matrix U:\n");
   printMatrix(U);
   printf("Matrix LU:\n");
   matMUl(L,U);
}
void gaussianElimintion(double aug[N][N+1])
{
   int i,j,k;
   for ( i = 0; i <N-1; i++)
    {
        for ( j = i + 1; j < N; j++)
        {
            double ratio = aug[j][i] / aug[i][i];
            for ( k = 0; k <=N; k++)
            {
                aug[j][k] -= ratio * aug[i][k];
            }
        }
    }
    for(i=N-1;i>=0;i--)
    {
       for(j=i-1;j>=0;j--)
       {
          double ratio=aug[j][i]/aug[i][i];
          for(k=0;k<=N;k++)
          {
             aug[j][k]-=ratio*aug[i][k];
          }
       }
    }
    for(i=0;i<N;i++)
    {
        double div=aug[i][i];
        for(j=0;j<=N;j++)
        {
           aug[i][j]/=div;
        }
    }
    
    /*  for(i=0;i<N;i++)
      {
         for(j=0;j<=N;j++)
         {
           printf("%4.3lf ",aug[i][j]);
         }
           printf("\n");
      }
     */
}
void solveY(double matrix[N][N],double B[N][1])
{
    int i,j,k;
    double aug[N][N+1];
    for(i=0;i<N;i++)
      {
         for(j=0;j<N;j++)
         {
            aug[i][j]=matrix[i][j];
         }
         aug[i][j]=B[i][0];
      }
      
    printf("Matrix Y:\n");  
    gaussianElimintion(aug);
     for(i=0;i<N;i++)
      {
         Y[i][0]=aug[i][N];
         printf("%3.4lf ",Y[i][0]);
      }
}

void solveX(double matrix[N][N],double B[N][1])
{
    int i,j,k;
    double aug[N][N+1];
    for(i=0;i<N;i++)
      {
         for(j=0;j<N;j++)
         {
            aug[i][j]=matrix[i][j];
         }
         aug[i][j]=B[i][0];
      }
      
    printf("\nMatrix X:\n");  
    gaussianElimintion(aug);
    for(i=0;i<N;i++)
      {
         X[i][0]=aug[i][N];
         printf("%3.4lf ",X[i][0]);
      }
    /* for(i=0;i<N;i++)
      {
         X[i][0]=aug[i][N];
        printf("%3.4lf ",X[i][0]);
      }
    */
}
int main()
{
    double matrix[N][N]=
    {
          {4,1,1},
          {2,5,2},
          {1,2,4}  
    };
    double B[N][1]={
      {8},{3},{11}
    };
    printf("Matrix A:\n");
    printMatrix(matrix);
    LU(matrix);  
    solveY(L,B);
    solveX(U,Y);
}
