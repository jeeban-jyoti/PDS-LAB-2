#include <stdio.h>
#include <stdlib.h>

void matrixMultiplication(int **mat1, int **mat2, int **result, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the dimensions of the first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    int **mat1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        mat1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the dimensions of the second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    int **mat2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        mat2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    matrixMultiplication(mat1, mat2, result, rows1, cols1, rows2, cols2);

    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows1; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < rows2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
