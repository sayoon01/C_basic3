#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3]);
void matrixAdd(int a[][3], int b[][3], int x[][3]);
void printMatrix(int a[][3]);
int main(void)
{
	int A[3][3], B[3][3], C[3][3];

	printf("( 3 X 3 ) 행렬 A 입력 : \n");
	readMatrix(A);
	printf("( 3 X 3 ) 행렬 B 입력 : \n");
	readMatrix(B);

	matrixAdd(A, B, C);
	printf("행렬 합:\n");
	printMatrix(C);
}
void readMatrix(int a[][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}
void matrixAdd(int a[][3], int b[][3], int x[][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int a[][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}