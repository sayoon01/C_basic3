#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//등차수열 최소 연산 개수
int min;
int solution(int* num, int size)
{
	int d = num[1] - num[0];
	for (int i = 0; i < size - 1; i++)
	{
		if ((num[i + 1] - num[i]) != d)
			return 0;
	}
	return 1;
}
void pick(int *item,int n, int* picked, int m, int toPick,int *num)
{
	int lastIndex, smallest;

	if (toPick == 0)
	{
		int op_count = 0;
		for (int i = 0; i < m; i++)
			if (item[picked[i]] != 0)
				op_count++;

		for (int i = 0; i < m; i++)
			num[i] = num[i] + item[picked[i]];

		if (solution(num, m))
			if (op_count < min)
				min = op_count;
		

		for (int i = 0; i < m; i++)
			num[i] = num[i] - item[picked[i]];
		return;
	}

	lastIndex = m - toPick - 1;

	smallest = 0;

	for (int i = smallest; i < n; i++)
	{
		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, toPick - 1, num);
	}
}
int main(void)
{
	int n;
	int item[] = { -1,0,1 };
	int* A;
	int* picked;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);
	picked = (int*)malloc(sizeof(int) * n);
	min = n + 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	pick(item, 3, picked, n, n, A);
	if (min == n + 1)
		printf("-1");
	else
		printf("%d", min);
	free(A);
	free(picked);
}