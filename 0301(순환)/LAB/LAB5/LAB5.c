#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int op[2] = { 1,-1 };
void pick(int n, int* bucket, int bucketSize, int k)
{
	int i, item, smallest, lastIndex;
	int sum;

	if (k == 0)
	{
		sum = 0;
		for (i = 0; i < bucketSize; i++)
		{
			if (op[bucket[i]] == 1)
				printf("+");
			printf("%d", (i + 1) * op[bucket[i]]);
			sum += ((i + 1) * op[bucket[i]]);
		}
		printf(" = %d\n", sum);
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

	printf("1부터 n까지 연속되어 있는 수 : ");
	scanf("%d", &n);
	
	p = (int*)malloc(sizeof(int) * n);

	pick(2, p, n, n);
	free(p);
}
