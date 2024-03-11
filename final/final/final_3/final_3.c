#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubbleSort (int A[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}
int main(void)
{
	int i;
	int n, k;
	int A[100], B[100];
	int N[200];
	int sum = 0;


	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &B[i]);

	bubbleSort(A, n);
	bubbleSort(B, n);

	for (i = 0; i < k; i++)
		sum += A[n - 1 - i];

	for (i = k; i < n; i++)
		sum += B[i];

	printf("%d", sum);
}