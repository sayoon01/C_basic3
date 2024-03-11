//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int minGap = 10000;
//
//void pick(int *score,int scoreSize,int n,int *bucket,int bucketSize, int k,int total)
//{
//	int i, item, lastIndex, smallest;
//	int sum = 0;
//
//	if (k == 0)
//	{
//		int sumA = score[0], sumB = 0;
//		
//		for (i = 0; i < bucketSize; i++) {
//			//printf("%d ", score[bucket[i] + 1]);
//			sumA += score[bucket[i] + 1];
//		}
//		//printf("\n");
//
//		sumB = total - sumA;
//		//printf("%d %d\n", sumA, sumB);
//
//		int gap = sumA - sumB;
//
//		if (gap < 0)
//			gap = gap * -1;
//
//		if (minGap > gap)
//			minGap = gap;
//		
//		return;
//	}
//
//	lastIndex = bucketSize - k - 1;
//
//	if (k == bucketSize)
//		smallest = 0;
//	else
//		smallest = bucket[lastIndex] + 1;
//
//	for (item = smallest; item < n; item++)
//	{
//		bucket[lastIndex + 1] = item;
//		
//		pick(score, scoreSize, n, bucket, bucketSize, k - 1, total);
//
//	}
//}
//int main(void)
//{
//	//int* p;
//	int* score, * bucket;
//	int n;
//	int bucketSize;
//	int total = 0;
//
//	scanf("%d", &n);
//
//	bucketSize = n / 2 - 1;
//	bucket = (int*)malloc(sizeof(int) * bucketSize);
//	score = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &score[i]);
//		total += score[i];
//	}
//
//	pick(score, n, n - 1, bucket, bucketSize, bucketSize, total);
//	printf("%d", minGap);
//	free(bucket);
//	free(score);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int bucketSize, int k, int total,int *minDiff)
{
	int i, lastIndex, smallest;

	if (k == 0) {
		int sum_team1 = 0;
		int sum_team2 = 0;
		int diff = 0;

		for (i = 0; i < bucketSize; i++) {
			//printf("%d ", bucket[i]);
			sum_team1 += item[bucket[i]];
		}
		
		sum_team2 = total - sum_team1;

		diff = (sum_team1 > sum_team2) ? (sum_team1 - sum_team2):(sum_team2 - sum_team1); //삼항 연산자
		//printf("%d\n", diff);

		*minDiff = (*minDiff > diff) ? diff : *minDiff;
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, bucketSize, k - 1, total, minDiff);
	}
}
int main(void)
{
	int* capacity, * bucket;
	int n;
	int sum = 0;
	int minDiff;

	scanf("%d", &n);

	capacity = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * n / 2);

	for (int i = 0; i < n; i++) {
		scanf("%d", &capacity[i]);
		sum += capacity[i];
	}

	bucket[0] = 0;
	minDiff = sum;
	pick(capacity, n, bucket, n / 2, n / 2 - 1, sum, &minDiff);
	printf("%d\n", minDiff);
	return 0;
}