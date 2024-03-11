#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int A[],int p,int r);
int partition(int A[], int p, int r);
//void printList(int A[], int s, int e);
int main(void)
{
	int n;
	int* A;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 101;
		printf("%d ", A[i]);
	}
	printf("\n");

	quickSort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
}

void quickSort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int partition(int *A, int p, int r)
{
	int i = p - 1, j = p;
	int tmp;

	while (j < r) {
		if (A[j] < A[r]) {
			tmp = A[j];
			A[j] = A[i + 1];
			A[i + 1] = tmp;
			i++;
		}
		j++;
	}

	tmp = A[j];
	A[j] = A[i + 1];
	A[i + 1] = tmp;
	return i + 1;
}
//void printList(int A[], int s, int e)
//{
//	int i;
//	for (i = s; i <= e; i++)
//		printf("%d ", A[i]);
//	//printf("\n");
//}