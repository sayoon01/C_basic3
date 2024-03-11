//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//void pick(int n, int picked[], int m, int toPick)
//{
//	int i, lastIndex, smallest;
//	if (toPick == 0)
//	{
//		for (i = 0; i < m; i++)
//			printf("%d ", picked[i]);
//		printf("\n");
//		return;
//	}
//
//	lastIndex = m - toPick - 1;
//
//	if (toPick == m)
//		smallest = 0;
//	else
//		smallest = picked[lastIndex] + 1;
//
//	for (i = smallest; i < n; i++)
//	{
//		picked[lastIndex + 1] = i;
//		pick(n, picked, m, toPick - 1);
//	}
//}
//int main(void)
//{
//	int n, m;
//	int* p;
//
//	printf("Enter n and m : ");
//	scanf("%d %d", &n, &m);
//	p = (int*)malloc(sizeof(int) * m);
//
//	pick(n, p, m, m);
//	free(p);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int* score, int n, int* info, int infoSize, int k, int sum, int startIndex)

{
	int* yours;
	yours = (int*)malloc(sizeof(int) * infoSize);

	int total = 0;

	for (int i = 0; i < k; i++)
		total += yours[i];

if (total > sum)
return; //메모리 아끼기!!

	if (total == sum) { // 찾은 경우
		int scoreSum = 0;
		for (int i = 0; i < k; i++) {
			scoreSum += score[i] * yours[i];
			printf("%d ", yours[i]);

			
		}
		printf("// %d\n",scoreSum);
		return;
	}

	if (k == infoSize)
		return; // 다 뽑았는데 sum == result도 아닌 상황


	for (int i = startIndex; i < n; i++)
	{
		yours[k] = i;
		pick(score, n,info, infoSize, k + 1, sum, i);
	}
}
int main(void)
{
	int score[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int info[11];
	int myScore = 0;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 11; i++) {
		scanf("%d", &info[i]);
	}
	for (int i = 0; i < 11; i++)
		myScore += score[i] * info[i];
	printf("// %d\n", myScore);
	pick(score, n, info, 10, 0, n, 0);
}