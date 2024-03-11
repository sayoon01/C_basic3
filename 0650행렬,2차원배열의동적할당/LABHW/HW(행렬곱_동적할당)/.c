#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrixMultiple(int** a, int** b, int** x, int r, int c, int n)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < n; k++)
				x[i][j] += a[i][k] * b[k][j];
}
void matrixTransposed(int** a, int** y, int r, int c)
{
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			y[i][j] = a[j][i];
}
void printMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
void readMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
int main(void)
{
	int** A, ** B;
	int** X, ** Y;// X : A * B, Y : 전치행렬
	int aRow, aCol, bRow, bCol;
	int i, j;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	A = (int**)malloc(sizeof(int*) * aRow); //행 동적할당
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol); //각 행마다 열 동적할당

	printf("Enter 행렬 B의 행과 열의 개수: ");
	scanf("%d %d", &bRow, &bCol);
	B = (int**)malloc(sizeof(int*) * bRow);
	for (i = 0; i < bRow; i++)
		B[i] = (int*)malloc(sizeof(int) * bCol);
	// 동적으로 행렬 A(aRow x aCol)와 B(aRow x aCol)와
	
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * bCol);
	// X(aRow x bCol)를 생성
	
	Y = (int**)malloc(sizeof(int*) * aCol);
	for (i = 0; i < aCol; i++)
		Y[i] = (int*)malloc(sizeof(int) * aRow);
	// Y(aCol x aRow)를 생성
	
	// A B 행렬값 입력 및 X Y행렬 초기화
	printf("(%d x %d) 행렬 A 입력 : \n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("(%d x %d) 행렬 B 입력 : \n", bRow, bCol);
	readMatrix(B, bRow, bCol);

	for (i = 0; i < aRow; i++)
		for (j = 0; j < bCol; j++)
			X[i][j] = 0;
	for (i = 0; i < aCol; i++) 
		for (j = 0; j < aRow; j++) 
			Y[i][j] = 0;

	matrixMultiple(A, B, X, aRow, bCol, aCol);
	printf("행렬곱:\n");
	printMatrix(X, aRow, bCol);
	printf("\n");

	matrixTransposed(A, Y, aRow, aCol);
	printf("전치행렬:\n");
	printMatrix(Y, aCol, aRow);
	printf("\n");

	for (i = 0; i < aRow; i++)
		free(A[i]); //각 열을 반환
	free(A); //행 반환
	for (i = 0; i < bRow; i++)
		free(B[i]);
	free(B);
	for (i = 0; i < aRow; i++)
		free(X[i]);
	free(X);
	for (i = 0; i < aCol; i++)
		free(Y[i]);
	free(Y);
}
