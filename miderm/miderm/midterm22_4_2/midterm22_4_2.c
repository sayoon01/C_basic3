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
int pick(int items[], int n, int* bucket, int bucketSize, int toPick, int* n1, int* n2)
{
	int count = 0;
	int i, lastIndex, smallest, item;

	if (toPick == 0)
	{
		for (i = 0; i < bucketSize; i++)
			n2[i] = n1[i] + items[bucket[i]];
		
		if (isSequence(n2, bucketSize))
			return 1;
		else
			return 0;

	}

	lastIndex = bucketSize - toPick - 1;

	smallest = 0;

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		count += pick(items, 3, bucket, bucketSize, toPick - 1, n1, n2);
	}

	return count;
}
int main(void)
{
	int items[3] = { -1,0,1 };
	int n;
	int* bucket;
	int* num1;
	int* num2;

	printf("개수 입력 : ");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);
	num1 = (int*)malloc(sizeof(int) * n);
	num2 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num1[i]);

	printf("%d\n", pick(items, 3, bucket, n, n, num1, num2));

	free(bucket);
	free(num1);
	free(num2);
}