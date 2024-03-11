#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int* A, int n)
{
	int i, j, k, tmp;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (A[j] > A[i])
				break;
		}

		tmp = A[i];
		for (k = i; k > j; k--)
			A[k] = A[k - 1];
		A[j] = tmp;
	}
}
int main(void)
{
	int n;
	int* A;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);

	if (A == NULL)
		return 0;
	if (n <= 0)
		return 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		A[i] = rand() % 10 + 1;

	insertionSort(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
}