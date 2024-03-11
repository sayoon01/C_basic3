//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//void pick(int* item, int n, int* bucket, int bucketSize, int k, int result,int *count,int startIndex)
//{
//	int sum = 0;
//
//	for (int i = 0; i < k; i++)
//		sum += item[bucket[i]];
//
//	if (sum > result)
//		return; //메모리 아끼기!!
//
//	if (sum == result) { // 찾은 경우
//	/*	for (i = 0; i <= lastIndex; i++)
//			printf("%d ", item[bucket[i]]);
//		printf("\n");*/
//		*count += 1;
//		return;
//	}
//
//	if (k == 0)
//		return; // 다 뽑았는데 sum == result도 아닌 상황
//
//	for (int i = startIndex; i < n; i++)
//	{
//		bucket[k] = i;
//		pick(item, n, bucket, bucketSize, k + 1, result, count, i);
//	}
//}
//
//int main(void)
//{
//	int n, k;
//	int* item;
//	int* bucket;
//	int count = 0;
//
//	scanf("%d %d", &n, &k);
//
//	item = (int*)malloc(sizeof(int) * n);
//	bucket = (int*)malloc(sizeof(int) * k);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &item[i]);
//
//	pick(item, n, bucket, k, 0, k, &count, 0);
//	printf("%d", count);
//
//	free(item);
//	free(bucket);
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 100

int countCombination(int* coins, int n, int k)
{
    int dp[k + 1];
    for (int i = 0; i <= k; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            // 이전에 계산한 개수에 현재 동전을 추가하여 조합의 개수를 갱신
            dp[j] += dp[j - coins[i]];
        }
    }
    // 목표값을 만들 수 있는 동전 조합의 개수 반환
    return dp[k];
}

int main(void)
{
    int n, k;
    int coins[MAX_COINS];
    int count;

    
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    count = countCombination(coins, n, k);

    printf("%d\n", count);

    return 0;
}

