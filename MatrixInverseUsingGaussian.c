#include <stdio.h>
#define N 3
void printMatrix(int n, int m, double mat[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3.3f ", mat[i][j]);
        }
        printf("\n");
    }
}
void forwardElimination(int n, int m, double mat[n][m])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k < m; k++)
            {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }
}
void backwardElimination(int n, int m, double mat[n][m])
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k < m; k++)
            {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }
}
void gaussElimination(int n, int m, double mat[n][m])
{
    forwardElimination(n, m, mat);
    backwardElimination(n, m, mat);
    for (int i = 0; i < n; i++)
    {
        double div = mat[i][i];
        for (int j = 0; j < m; j++)
        {
            mat[i][j] /= div;
        }
    }
}
double determinant(double matrix[N][N + 1])
{
    double det = 1.0;
    for (int i = 0; i < N; i++)
        det *= matrix[i][i];
    return det;
}
void inverseMatrix(int n, int m, double mat[n][m])
{
    int i, j;
    double inverse[n][2 * n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            inverse[i][j] = mat[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 3; j < 2 * n; j++)
        {
            if (i + n == j)
                inverse[i][j] = 1;
            else
                inverse[i][j] = 0;
        }
    }
    gaussElimination(n, 2 * n, inverse);
    // printMatrix(n,2*n,inverse);
    printf("Inverse matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 3; j < 2 * n; j++)
        {
            printf("%3.3lf ", inverse[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    double matrix[N][N + 1], mat[N][N + 1];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= N; j++)
        {
            scanf("%lf", &matrix[i][j]);
            mat[i][j] = matrix[i][j];
        }
    }

    forwardElimination(N, N + 1, matrix);
    double deter = determinant(matrix);
    printf("Determinant: %3.3f\n", deter);
    printf("Solution of linear system:\n");
    printf("X= %3.3f\tY= %3.3f\tZ=%3.3f\n", matrix[0][0], matrix[1][1], matrix[2][2]);

    if (deter == 0.0)
        printf("No inverse matrix\n");
    else
        inverseMatrix(N, N + 1, mat);
    // gaussElimination(3, 6, inverse);
    // printMatrix(3, 6, inverse);
}