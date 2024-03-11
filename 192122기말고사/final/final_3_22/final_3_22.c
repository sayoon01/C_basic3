#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int* bucket, int bucketSize, int k, int target,int *min)
{
	int i, lastIndex, smallest;
	int sum = 0;

	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++) {
		sum += item[bucket[i]] * item[bucket[i]];
	}

	if ((lastIndex + 1) > *min)
		return;

	if (sum == target) {

		*min = (*min > lastIndex + 1) ? (lastIndex + 1) : *min;

		for (i = 0; i <= lastIndex; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	if (sum > target)
		return; //메모리 아끼기!!


	if (k == 0)
		return; // 다 뽑았는데 sum == target도 아닌 상황

	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, bucketSize, k - 1, target, min);
	}

}
int main(void)
{
	int* bucket, * item;
	int min = 0;
	int n;
	int i;

	scanf("%d", &n);
	
	bucket = (int*)malloc(sizeof(int) * n);
	item = (int*)malloc(sizeof(int) * (n - 1));

	for (i = n - 2; i >= 1; i--)
		item[i] = i;
	
	min = n;
	pick(item, n - 1, bucket, n, n, n, &min);
	printf("%d", min);
	free(item);
	free(bucket);
}