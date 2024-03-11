#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int n, int* bucket, int bucketSize, int k, int result,int *count)
{
	int i, lastIndex, smallest;
	int sum = 0;

	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++)
	sum += items[bucket[i]];

	if (sum == result) {
		*count = *count + 1;

		for (i = 0; i <= lastIndex; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}
	if (sum > result)
		return; //메모리 아끼기!!
	if (k == 0) // 다 뽑았는데 조건 만족X
		return;

	/*if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}*/

	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, n, bucket, bucketSize, k - 1, result, count);
	}

}
int main(void)
{
	int* bucket;
	int items[2] = { 1,2 };
	int n;
	int count = 0;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 2, bucket, n, n, n, &count);
	printf("%d", count);
	free(bucket);
}