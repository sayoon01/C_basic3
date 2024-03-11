// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isSequence(int* a, int size)
{
	int d0 = 0;
	int d = a[0] - a[1];
	for (int i = 0; i < size - 1; i++)
	{
		d0 = a[i] - a[i + 1];
			if (d0 != d)
				return 0;
	}
		return 1;
}
int main(void)
{
	int* a;
	int n, d;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
		return 0;

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", isSequence(a, n));
	free(a);
	return 0;
}