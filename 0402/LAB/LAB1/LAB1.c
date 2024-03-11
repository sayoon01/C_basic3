//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main(void)
//{
//	int n;
//	int* A;
//
//	srand(time(NULL));
//	printf("Enter a number : ");
//	scanf("%d", &n);
//
//	if (n <= 0)
//		return 0;
//	A = (int*)malloc(sizeof(int) * n);
//	if (A == NULL)
//		return 0;
//
//	for (int i = 0; i < n; i++)
//		A[i] = rand() % 1000;
//
//	for (int i = 0; i < n; i++)
//		printf("%d ", A[i]);
//	printf("\n");
//	free(A);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* A, int n)
{
	int i, j;
	int max, max_idx, tmp;

	for (i = 0; i < n - 1; i++)
	{
		max = A[0];
		max_idx = 0;
		for (j = 1; j < n - i; j++)
		{
			if (max < A[j])
			{
				max = A[j];
				max_idx = j;
			}
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

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);

	if (A == NULL)
		return 0;
	if (n <= 0)
		return 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		A[i] = rand() % 1000;

	selectionSort(A, n);

	free(A);
}