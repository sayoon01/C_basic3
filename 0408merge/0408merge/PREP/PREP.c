#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r)
{
	int i = p, j = q + 1, t = p;
	int* tmp = (int*)malloc(sizeof(int) * (r + 1));

	while (j <= r && i <= q) {
		if (A[i] < A[j]) 
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

void printList(int A[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(void)
{
	int list1[] = { 10,20,30,70,80,11,33,44,55,66 };
	int list2[] = { 10,20,30,70,80,11,33,44,55,66 };

	//test#1
	printList(list1, 0, 9);
	merge(list1, 0, 4, 9);
	printList(list1, 0, 9);

	//test#2
	printList(list2, 2, 7);
	merge(list2, 2, 4, 7);
	printList(list2, 2, 7);
}