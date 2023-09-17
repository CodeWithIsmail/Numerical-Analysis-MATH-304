#include <stdio.h>
#define N 3

void printMatrix(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        // Find pivot for column i
        double maxEl = matrix[i][i];
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (matrix[k][i] > maxEl) {
                maxEl = matrix[k][i];
                maxRow = k;
            }
        }

        // Swap maximum row with current row (if needed)
        if (maxRow != i) {
            for (int k = i; k < N + 1; k++) {
                double temp = matrix[i][k];
                matrix[i][k] = matrix[maxRow][k];
                matrix[maxRow][k] = temp;
            }
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < N; k++) {
            double factor = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < N + 1; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += factor * matrix[i][j];
                }
            }
        }
    }

    // Back substitution
    double x[N]; // Solution vector
    for (int i = N - 1; i >= 0; i--) {
        x[i] = matrix[i][N] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][N] -= matrix[k][i] * x[i];
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }
}

int main() {
    double matrix[N][N + 1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    printf("Original augmented matrix:\n");
    printMatrix(matrix);

    gaussianElimination(matrix);

    return 0;
}

