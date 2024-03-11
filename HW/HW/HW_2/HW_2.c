#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			scanf("%d", &matrix[i][j]);
	}
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%5d ", matrix[i][j]);
		printf("\n");
	}
}

void multiplyMatrix(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int rows2, int cols2) {
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int k = 0; k < cols1; k++)
				result[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
}

void transposeMatrix(int** matrix, int** result, int rows, int cols) {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++)
			result[i][j] = matrix[j][i];
	}
}

int main(void) {
	int** matrixA, ** matrixC;
	int** matrixX, ** matrixY;
	int rowsA, colsA;
	int rowsC, colsC;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &rowsA, &colsA);
	printf("Enter 행렬 C의 행과 열의 개수(C의 행은 4이어야): ");
	scanf("%d %d", &rowsC, &colsC);

	matrixA = (int**)malloc(sizeof(int*) * rowsA);
	for (int i = 0; i < rowsA; i++)
		matrixA[i] = (int*)malloc(sizeof(int) * colsA);

	matrixC = (int**)malloc(sizeof(int*) * rowsC);
	for (int i = 0; i < rowsC; i++)
		matrixC[i] = (int*)malloc(sizeof(int) * colsC);

	matrixX = (int**)malloc(sizeof(int*) * rowsA);
	for (int i = 0; i < rowsA; i++)
		matrixX[i] = (int*)calloc(colsC, sizeof(int));

	printf("\n%d x %d 행렬 A 입력:\n", rowsA, colsA);
	readMatrix(matrixA, rowsA, colsA);
	printf("\n%d x %d 행렬 C 입력:\n", rowsC, colsC);
	readMatrix(matrixC, rowsC, colsC);

	printf("\n행렬곱:\n");
	multiplyMatrix(matrixA, matrixC, matrixX, rowsA, colsA, rowsC, colsC);
	printMatrix(matrixX, rowsA, colsC);

	printf("\n전치행렬:\n");
	matrixY = (int**)malloc(sizeof(int*) * colsA);
	for (int i = 0; i < colsA; i++)
		matrixY[i] = (int*)malloc(sizeof(int) * rowsA);

	transposeMatrix(matrixA, matrixY, rowsA, colsA);
	printMatrix(matrixY, colsA, rowsA);

	return 0;
}