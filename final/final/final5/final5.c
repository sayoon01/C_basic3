#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* A, * B;
	int N, K, L;
	int tmp;

	scanf("%d %d %d", &N, &K, &L);
	A = malloc(sizeof(int) * N);
	B = malloc(sizeof(int) * K);

	for (int i = 0; i < N; i++)
		A[i] = i;
	for (int i = 0; i < K; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (B[i] == A[j])
			{
				if (j != 0)
				{
					tmp = A[j - 1];
					A[j - 1] = A[j];
					A[j] = tmp;
				}
			}
		}
	}

	printf("%d", A[L]);

	free(A);
	free(B);
}