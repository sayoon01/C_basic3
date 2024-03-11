#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrixAdd(int** matrix1, int** matrix2, int** result, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void readMatrix(int** matrix, int rows, int cols);

int main(void) {
    int** matrixA, ** matrixB;
    int** matrixC;
    int rows, cols;

    printf("배열의 행의 개수(rows)와 열의 개수(cols): ");
    scanf("%d %d", &rows, &cols);

    matrixA = (int**)malloc(rows * sizeof(int*));
    matrixB = (int**)malloc(rows * sizeof(int*));
    matrixC = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrixA[i] = (int*)malloc(cols * sizeof(int));
        matrixB[i] = (int*)malloc(cols * sizeof(int));
        matrixC[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("\n(%d x %d) 행렬 A 입력:\n", rows, cols);
    readMatrix(matrixA, rows, cols);

    printf("\n(%d x %d) 행렬 B 입력:\n", rows, cols);
    readMatrix(matrixB, rows, cols);

    matrixAdd(matrixA, matrixB, matrixC, rows, cols);

    printf("\n행렬합:\n");
    printMatrix(matrixC, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(matrixC[i]);
    }
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}

void matrixAdd(int** matrix1, int** matrix2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void readMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
