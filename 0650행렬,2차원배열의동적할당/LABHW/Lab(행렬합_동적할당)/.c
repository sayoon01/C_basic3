#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrixAdd(int** a, int** b, int** x, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
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
	int** X; // A + B
	int aRow, aCol;
	int i, j;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	// 동적으로 행렬 A(aRow x aCol)와 B(aRow x aCol)와
	// X(aRow x aCol)를 생성
	A = (int**)malloc(sizeof(int*) * aRow); //행 동적할당
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol); //각 행마다 열 동적할당

	B =  (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		B[i] = (int*)malloc(sizeof(int) * aCol);

	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * aCol);

	// A B 행렬값 입력 및 X 행렬 초기화
	printf("행렬 A 입력 : \n");
	readMatrix(A, aRow, aCol);
	printf("행렬 B 입력 : \n");
	readMatrix(B, aRow, aCol);
	for (i = 0; i < aRow; i++)
		for (j = 0; j < aCol; j++)
			X[i][j] = 0;

	matrixAdd(A, B, X, aRow, aCol);
	printf("행렬합:\n");
	printMatrix(X, aRow, aCol); 
	printf("\n");

	for (i = 0; i < aRow; i++)
		free(A[i]); //각 열을 반환
	free(A); //행 반환
	for (i = 0; i < aRow; i++)
		free(B[i]);
	free(B);
	for (i = 0; i < aRow; i++)
		free(X[i]);
	free(X);
}
