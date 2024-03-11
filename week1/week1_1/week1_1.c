/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#include <stdio.h>

int main(void)
{
	int n, result;

	printf("Enter a number : ");
	scanf_s("%d", &n);

	result = 1;
	for (int i = 0; i < n; i++)
		result *= 2;

	printf("%d\n", result);

	return 0;
}