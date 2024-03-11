#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char items[8] = "ABCDEFG";

void pick(int n, int* bucket, int bucketSize, int k)
{
	int i, item, smallest, lastIndex;
	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++)
			printf("%c ", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int bucket[3];

	pick(7, bucket, 3, 3);
}
