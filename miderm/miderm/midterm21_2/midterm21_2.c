// 9의 배수 하나씩
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printResult(int x)
{
	if (x > 0)
	{
		printResult(x / 10);
		printf("%d ", x % 10);
	}
}
int main(void)
{
	int n;

	scanf("%d", &n);

	printResult(n*9);
}