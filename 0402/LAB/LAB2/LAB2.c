#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* A, int n)
{
	int i, j, tmp;
	int max, max_idx;
	for (i = 0; i < n - 1; i++)
	{
		max = A[0];
		max_idx = 0;
		for(j=1;j<n-i;j++)
			if (max < A[j])
			{
				max = A[j];
				max_idx = j;
			}
		tmp = A[max_idx];
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = tmp;
	}
}
int main(void)
{
	int n;
	int* A;

	printf("Enter a number : ");
	scanf("%d", &n);

	/*if (n <= 0)
		return 0;*/
	A = (int*)malloc(sizeof(int) * n);
	/*if (A == NULL)
		return 0;*/

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		A[i] = rand() % 1000; // 난수 생성

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	selectionSort(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
}