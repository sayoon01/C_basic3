#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* money, int n, int* bucket, int bucketSize, int k,int result)
{
	int i, item, lastIndex, smallest;
	int sum = 0;

	if (k == 0  /*&& result == sum*/)
	{
		for (i = 0; i < bucketSize; i++) {
			printf("%d ", money[bucket[i]]);
			//sum += money[bucket[i]];
		}
		printf("\n");
		
		/*if (sum == result) {
			for (i = 0; i < bucketSize; i++) {
				if (money[bucket[i]] != 0)
					printf("%d ", money[bucket[i]]);
			}
			printf("\n");
		}*/
		return;
	}

	lastIndex = bucketSize - k - 1;
	for (i = 0; i <= lastIndex; i++) {
		sum += money[bucket[i]];
	}

	if (sum > result)
		return; //메모리 아끼기!!

	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		//sum += money[item];
		pick(money, n, bucket, bucketSize, k - 1, result);

	}
}
int main(void)
{
	int* p;
	int money[4] = { 1000,5000,10000,0 };
	int totalMoney;
	int p_size;

	scanf("%d", &totalMoney);
	p_size = totalMoney / money[0];

	p = (int*)malloc(sizeof(int) * p_size);

	pick(money, 4, p, p_size, p_size, totalMoney);
	free(p);
}