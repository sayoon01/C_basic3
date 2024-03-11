#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//char actor[5][50] = { "공유","김수현","송중기","지성","현빈" };
void pick(char *actor[],int n, int* bucket, int bucketSize, int k)
{
	int i, item, smallest, lastIndex;
	if (k == 0)
	{
		for (i = 0; i < bucketSize; i++)
			printf("%10s", actor[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < n; item++)
	{
		bucket[lastIndex + 1] = item;
		pick(actor, n, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	char* actor[] = { "공유","김수현","송중기","지성","현빈"};
	int n;
	int* p;

	printf("인기상 몇명? ");
	scanf("%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	pick(actor,5, p, n, n);
	free(p);

	return 0;
}