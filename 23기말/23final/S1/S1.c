#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* bucket;
	//int bucketSize;
	int* item;
	int m, n, k;
	int i = 0, j = 0;
	int count = 0;

	scanf("%d", &m);
	item = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		scanf("%d", &item[i]);

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);

	k = 0;
	for (j = 0; j < n; j++)
	{
		scanf("%d", &bucket[j]);
		for (i = k; i < m; i++)
		{
			if (bucket[j] == item[i])
				count++;
			k = j;
		}
	}

	
	//for (i = 0; i < m; i++)
	//{
	//
	//	for (j = k; j < n; j++)
	//	{
	//		if (item[i] == bucket[j])
	//			count++;
	//	}
	//	if (count == n)
	//		break;
	//}

	printf("%d", count);
	free(item);
	free(bucket);
}