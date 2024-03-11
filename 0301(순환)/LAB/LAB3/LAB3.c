#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(char *actor[], int n, int* bucket, int bucketSize, int k)
{
	int i, item, smallest, lastIndex;

	if (k == bucketSize)
		for (i = 0; i < bucketSize; i++)
			printf("\t상%d", i + 1);

	if (k == 0)
	{
		printf("\n");
		for (i = 0; i < bucketSize; i++)
			printf("%10s", actor[bucket[i]]);
		return;
	}

	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < n; item++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          .                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
	{
		int j = 0;
		int flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (bucket[j] == item)
				flag = 1;
		if (flag)
			continue;

		bucket[lastIndex + 1] = item;
		pick(actor, n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	char* actor[] = { "공유","김수현","송중기","지성","현빈" };
	int* p;
	int n;

	printf("상의 종류는? ");
	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	pick(actor, 5, p, n, n);

	free(p);
	return 0;
}