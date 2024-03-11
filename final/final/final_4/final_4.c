#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max = 0;

void pick(int n, int bucket[], int bucketSize, int k,int items[])
{
	int i, lastIndex, smallest;

	if (k == 0)
	{
		int sum = 0;
		for (i = 0; i < bucketSize; i++)
		{
			if (bucket[i] == 0)
				sum *= items[i];
			if (bucket[i] == 1)
				sum += items[i];
			if (bucket[i] == 2)
				sum -= items[i];
		}

		if (max < sum)
			max = sum;
		return 0;
	}

	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (i = smallest; i < n; i++)
	{
		if (lastIndex == -1 && i == 0)
			continue;
		
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1,items);
	}
}
int main(void)
{
	int bucket[100];
	int items[100];
		//int* picked;
	int n;

	scanf("%d", &n);

	//bucket = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &items[i]);

	pick(3, bucket, n, n,items);
	printf("%d", max);
}