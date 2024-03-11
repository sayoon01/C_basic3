#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A, int p, int q, int r)
{
	int i = p, j = q + 1, t = p;
	int* tmp = (int*)malloc(sizeof(int) * (r + 1));

	while (j <= r && i <= q) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}

	while (i <= q)
		tmp[t++] = A[i++];

	while (j <= r)
		tmp[t++] = A[j++];

	for (int a = p; a <= r; a++)
		A[a] = tmp[a];

	free(tmp);
}
void mergeSort(int* A, int p, int r)
{
	int q;

	if (p < r){
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int n;
	int* N;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	N = (int*)malloc(sizeof(int) * n);
	if (N == NULL)
		return 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		N[i] = rand() % 100;
	
	printList(N, 0, n - 1);
	mergeSort(N, 0, n - 1);
	printList(N, 0, n - 1);

	free(N);
	return 0;
}