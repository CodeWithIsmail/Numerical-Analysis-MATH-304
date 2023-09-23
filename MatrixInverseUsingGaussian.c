#include <stdio.h>
#define N 3
void printMatrix(double mat[N][2 * N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            printf("%3.3f ", mat[i][j]);
        }
        printf("\n");
    }
}
void forwardElimination(double inverse[N][2 * N])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double ratio = inverse[j][i] / inverse[i][i];
            for (int k = 0; k < 2 * N; k++)
            {
                inverse[j][k] -= ratio * inverse[i][k];
            }
        }
    }
}
void backwordElimination(double inverse[N][2 * N])
{
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            double ratio = inverse[j][i] / inverse[i][i];
            for (int k = 0; k < 2 * N; k++)
            {
                inverse[j][k] -= ratio * inverse[i][k];
            }
        }
    }
}
void gaussElimination(double inverse[N][2 * N])
{
    forwardElimination(inverse);
    backwordElimination(inverse);

    for (int i = 0; i < N; i++)
    {
        double div = inverse[i][i];
        for (int j = 0; j < 2 * N; j++)
        {
            inverse[i][j] /= div;
        }
    }
}
int main()
{
    double matrix[N][N + 1] = {
        {4, 1, 1, 8},
        {2, 5, 2, 3},
        {1, 2, 4, 11}};
    double inverse[N][2 * N] = {
        {4, 1, 1, 1, 0, 0},
        {2, 5, 2, 0, 1, 0},
        {1, 2, 4, 0, 0, 1}};

    gaussElimination(inverse);
    printMatrix(inverse);
}