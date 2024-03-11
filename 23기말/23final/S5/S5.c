////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////
////int minGap = 10000;
////
////void pick(int *score,int scoreSize,int n,int *bucket,int bucketSize, int k,int total)
////{
////	int i, item, lastIndex, smallest;
////	int sum = 0;
////
////	if (k == 0)
////	{
////		int sumA = score[0], sumB = 0;
////		
////		for (i = 0; i < bucketSize; i++) {
////			//printf("%d ", score[bucket[i] + 1]);
////			sumA += score[bucket[i] + 1];
////		}
////		//printf("\n");
////
////		sumB = total - sumA;
////		//printf("%d %d\n", sumA, sumB);
////
////		int gap = sumA - sumB;
////
////		if (gap < 0)
////			gap = gap * -1;
////
////		if (minGap > gap)
////			minGap = gap;
////		
////		return;
////	}
////
////	lastIndex = bucketSize - k - 1;
////
////	if (k == bucketSize)
////		smallest = 0;
////	else
////		smallest = bucket[lastIndex] + 1;
////
////	for (item = smallest; item < n; item++)
////	{
////		bucket[lastIndex + 1] = item;
////		
////		pick(score, scoreSize, n, bucket, bucketSize, k - 1, total);
////
////	}
////}
////int main(void)
////{
////	//int* p;
////	int* score, * bucket;
////	int n;
////	int bucketSize;
////	int total = 0;
////
////	scanf("%d", &n);
////
////	bucketSize = n / 2 - 1;
////	bucket = (int*)malloc(sizeof(int) * bucketSize);
////	score = (int*)malloc(sizeof(int) * n);
////	for (int i = 0; i < n; i++)
////	{
////		scanf("%d", &score[i]);
////		total += score[i];
////	}
////
////	pick(score, n, n - 1, bucket, bucketSize, bucketSize, total);
////	printf("%d", minGap);
////	free(bucket);
////	free(score);
////}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
////void pick(int* item, int n, int* bucket, int bucketSize, int k)
////{
////	int i, lastIndex, smallest;
////
////	if (k == 0) {
////		//int sum_team1 = 0;
////		//int sum_team2 = 0;
////		//int diff = 0;
////
////		//for (i = 0; i < bucketSize; i++) {
////		//	//printf("%d ", bucket[i]);
////		//	sum_team1 += item[bucket[i]];
////		//}
////
////		//sum_team2 = total - sum_team1;
////
////		//diff = (sum_team1 > sum_team2) ? (sum_team1 - sum_team2) : (sum_team2 - sum_team1); //삼항 연산자
////		////printf("%d\n", diff);
////
////		//*minDiff = (*minDiff > diff) ? diff : *minDiff;
////		for (i = 0; i < bucketSize; i ++)
////			printf("%d", bucket[i]);
////		printf("\n");
////		return;
////	}
////
////	lastIndex = bucketSize - k - 1;
////
////	if (bucketSize == k)
////		smallest = 0;
////	else
////		smallest = bucket[lastIndex] + 1;
////
////	for (i = smallest; i < n; i++) {
////		bucket[lastIndex + 1] = i;
////		pick(item, n, bucket, bucketSize, k - 1);
////	}
////}
//int main(void)
//{
//	//int* item, * bucket;
//	int odd = 0, eve = 0, total = 0;
//	int n, m, l;
//	int sum = 0;
//	//int minDiff;
//
//	scanf("%d", &n);
//	odd = (n + 1) / 2;
//	//item = (int*)malloc(sizeof(int) * (n + 1) / 2);
//	/*for (int i = 0; i < (n + 1) / 2; i++)
//	{
//		item[i] = i * 2 + 1;
//	}*/
//	scanf("%d", &m);
//	scanf("%d", &l);
//
//	printf("%d", odd + (m - l) * odd * m - l);
//	
//
//	//bucket = (int*)malloc(sizeof(int) * m);
//
//	//pick(item, (n+1)/2, bucket, m-l, m-l);
//	//printf("%d\n", minDiff);
//	return 0;
//}

#include <stdio.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_L 100

int countMemo[MAX_N + 1][MAX_M + 1][MAX_M * 2 + 1];

void generateSequence(int current, int length, int evenCount, int n1, int n2, int n3) {
    if (length == n2) {
        if (evenCount >= n3) {
            countMemo[current][length][evenCount] = 1;
            return;
        }
        else {
            countMemo[current][length][evenCount] = 0;
            return;
        }
    }

    if (current > n1) {
        countMemo[current][length][evenCount] = 0;
        return;
    }

    if (countMemo[current][length][evenCount] != -1) {
        return;
    }

    generateSequence(current + 1, length + 1, evenCount + (current % 2 == 0), n1, n2, n3);
    generateSequence(current + 1, length, evenCount, n1, n2, n3);

    countMemo[current][length][evenCount] = countMemo[current + 1][length + 1][evenCount + (current % 2 == 0)] +
        countMemo[current + 1][length][evenCount];
}

int countSequences(int n1, int n2, int n3) {
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= n2 * 2; k++) {
                countMemo[i][j][k] = -1;
            }
        }
    }

    generateSequence(1, 0, 0, n1, n2, n3);
    return countMemo[1][0][0];
}

int main() {
    int numN, numM, numL;
    scanf("%d %d %d", &numN, &numM, &numL);
    printf("%d\n", countSequences(numN, numM, numL));

    return 0;
}