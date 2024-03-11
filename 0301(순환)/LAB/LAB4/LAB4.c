#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* bucket, int bucketSize, int k)
{
	int i, item, smallest, lastIndex;

	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int n;
	int* p;

	printf("몇자리 수 나열 ? : ");
	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	pick(4, p, n, n); // 4진수니까 0 1 2 3 숫자 사용 가능

	free(p);
}
