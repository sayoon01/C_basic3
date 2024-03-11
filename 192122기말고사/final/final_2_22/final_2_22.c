#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items,int n, int* bucket, int bucketSize, int k,int result,int* count)
{
	int i, lastIndex, smallest, item;
	int sum = 0;

	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++)
		sum += items[bucket[i]]; // 매번 뽑힌 수까지의 합을 구해봄


	if (sum > result)
		return; //메모리 아끼기!!

	if (sum == result) {
		// 찾은 경우
		*count = *count + 1;

		/*for (i = 0; i <= lastIndex; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");*/
		return;
	}

	if (k == 0)
		return; // 다 뽑았는데 sum == bucketSize도 아닌 상황
	
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		//sum += item[i];
		pick(items, n, bucket, bucketSize, k - 1, result, count);
	}

}
int main(void)
{
	int* bucket;
	int bucketSize;
	int items[3] = { 1,2,3 };
	int n;
	int count = 0;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	bucketSize = n;

	pick(items, 3, bucket, bucketSize, n, n, &count);
	
	printf("%d", count);
	free(bucket);
}