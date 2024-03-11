/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#include <stdio.h>

int total(int n)
{
	int r = 0;
	for (int i = 1; i <= n; i++)
		r += i;

	return r;
}

int main(void)
{
	int num, result;

	printf("Input a number(-1 for exit) : ");
	scanf_s("%d", &num);

	if (num != -1)
	{
		result = total(num);
		printf("%d부터 %d까지의 합은 %d\n", 1, num, result);
	}

	return 0;
}