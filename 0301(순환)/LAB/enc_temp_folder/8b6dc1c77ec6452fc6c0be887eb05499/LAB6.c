#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* money, int n, int* bucket, int bucketSize, int toPick)
{
	int i, item, smallest, lastIndex;
	if (toPick == 0)
	{
		for(i=0;i<bucketSize;i++)
			if (money[bucket[i]] != 0)
				printf("%d ", money[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - toPick - 1;

	if (toPick == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; //중복 조합

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		pick(money, n, bucket, bucketSize, toPick - 1);
	}
}
int main(void)
{
	int* picked;
	int money[4] = { 1000,5000,10000,0 };
	int totalMoney, k;

	scanf("%d", &totalMoney);
	k = totalMoney / 1000;
	picked = (int*)malloc(sizeof(int) * 4);
	pick(money, 4, picked, k, k);
	free(pick);
}